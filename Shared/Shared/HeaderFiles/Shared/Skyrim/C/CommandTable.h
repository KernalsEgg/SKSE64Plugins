#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct ScriptCompileData;

	class Script;
	class TESForm;
	class TESObjectREFR;

	enum class ScriptParameterType : std::uint32_t
	{
	};
	static_assert(sizeof(ScriptParameterType) == 0x4);

	enum class ScriptOutput : std::uint32_t
	{
	};
	static_assert(sizeof(ScriptOutput) == 0x4);

	enum class ScriptError : std::uint32_t
	{
	};
	static_assert(sizeof(ScriptError) == 0x4);

	struct ScriptHeader
	{
	public:
		// Member variables
		std::uint32_t variableCount;        // 0
		std::uint32_t referenceObjectCount; // 4
		std::uint32_t dataSize;             // 8
		std::uint32_t lastID;               // C
		bool          isQuestScript;        // 10
		bool          isMagicEffectScript;  // 11
		bool          isCompiled;           // 12
		std::uint8_t  padding13;            // 13
	};
	static_assert(offsetof(ScriptHeader, variableCount) == 0x0);
	static_assert(offsetof(ScriptHeader, referenceObjectCount) == 0x4);
	static_assert(offsetof(ScriptHeader, dataSize) == 0x8);
	static_assert(offsetof(ScriptHeader, lastID) == 0xC);
	static_assert(offsetof(ScriptHeader, isQuestScript) == 0x10);
	static_assert(offsetof(ScriptHeader, isMagicEffectScript) == 0x11);
	static_assert(offsetof(ScriptHeader, isCompiled) == 0x12);
	static_assert(sizeof(ScriptHeader) == 0x14);

	struct ScriptParameter
	{
	public:
		// Member variables
		const char*                                              parameterName; // 0
		Utility::Enumeration<ScriptParameterType, std::uint32_t> parameterType; // 8
		bool                                                     optional;      // C
		std::uint8_t                                             paddingD;      // D
		std::uint16_t                                            paddingE;      // E
	};
	static_assert(offsetof(ScriptParameter, parameterName) == 0x0);
	static_assert(offsetof(ScriptParameter, parameterType) == 0x8);
	static_assert(offsetof(ScriptParameter, optional) == 0xC);
	static_assert(sizeof(ScriptParameter) == 0x10);

	struct ScriptReferencedObject
	{
	public:
		// Member variables
		BSString      editorID;   // 0
		TESForm*      form;       // 10
		std::uint32_t variableID; // 18
		std::uint32_t padding1C;  // 1C
	};
	static_assert(offsetof(ScriptReferencedObject, editorID) == 0x0);
	static_assert(offsetof(ScriptReferencedObject, form) == 0x10);
	static_assert(offsetof(ScriptReferencedObject, variableID) == 0x18);
	static_assert(sizeof(ScriptReferencedObject) == 0x20);

	struct ActionObject
	{
	public:
		// Member variables
		TESForm*      form;     // 0
		std::uint32_t flags;    // 8
		std::uint32_t paddingC; // C
	};
	static_assert(offsetof(ActionObject, form) == 0x0);
	static_assert(offsetof(ActionObject, flags) == 0x8);
	static_assert(sizeof(ActionObject) == 0x10);

	struct ScriptLocal
	{
	public:
		// Member variables
		std::uint32_t id;        // 0
		float         value;     // 4
		bool          isInteger; // 8
		std::uint8_t  padding9;  // 9
		std::uint16_t paddingA;  // A
	};
	static_assert(offsetof(ScriptLocal, id) == 0x0);
	static_assert(offsetof(ScriptLocal, value) == 0x4);
	static_assert(offsetof(ScriptLocal, isInteger) == 0x8);
	static_assert(sizeof(ScriptLocal) == 0xC);

	struct ScriptEffectData
	{
	public:
		// Member variables
		bool          scriptEffectStart;  // 0
		bool          scriptEffectFinish; // 1
		std::uint16_t padding2;           // 2
		float         elapsedTime;        // 4
	};
	static_assert(offsetof(ScriptEffectData, scriptEffectStart) == 0x0);
	static_assert(offsetof(ScriptEffectData, scriptEffectFinish) == 0x1);
	static_assert(offsetof(ScriptEffectData, elapsedTime) == 0x4);
	static_assert(sizeof(ScriptEffectData) == 0x8);

	struct ScriptLocals
	{
	public:
		// Member variables
		Script*                      masterScript;     // 0
		char                         flags;            // 8
		std::uint8_t                 padding9;         // 9
		std::uint16_t                paddingA;         // A
		std::uint32_t                paddingC;         // C
		BSSimpleList<ActionObject*>* actionObjects;    // 10
		BSSimpleList<ScriptLocal*>*  scriptLocals;     // 18
		ScriptEffectData*            scriptEffectData; // 20
	};
	static_assert(offsetof(ScriptLocals, masterScript) == 0x0);
	static_assert(offsetof(ScriptLocals, flags) == 0x8);
	static_assert(offsetof(ScriptLocals, actionObjects) == 0x10);
	static_assert(offsetof(ScriptLocals, scriptLocals) == 0x18);
	static_assert(offsetof(ScriptLocals, scriptEffectData) == 0x20);
	static_assert(sizeof(ScriptLocals) == 0x28);

	struct ScriptVariable
	{
	public:
		// Member variables
		ScriptLocal   data;     // 0
		std::uint32_t paddingC; // C
		BSString      name;     // 10
	};
	static_assert(offsetof(ScriptVariable, data) == 0x0);
	static_assert(offsetof(ScriptVariable, name) == 0x10);
	static_assert(sizeof(ScriptVariable) == 0x20);

	struct ScriptLine
	{
	public:
		// Member variables
		std::uint32_t                                     lineNumber;            // 0
		char                                              line[512];             // 4
		std::uint32_t                                     size;                  // 204
		std::uint32_t                                     offset;                // 208
		char                                              output[512];           // 20C
		std::uint32_t                                     outputSize;            // 40C
		Utility::Enumeration<ScriptOutput, std::uint32_t> expression;            // 410
		std::uint32_t                                     referencedObjectIndex; // 414
		Utility::Enumeration<ScriptError, std::uint32_t>  scriptError;           // 418
	};
	static_assert(offsetof(ScriptLine, lineNumber) == 0x0);
	static_assert(offsetof(ScriptLine, line) == 0x4);
	static_assert(offsetof(ScriptLine, size) == 0x204);
	static_assert(offsetof(ScriptLine, offset) == 0x208);
	static_assert(offsetof(ScriptLine, output) == 0x20C);
	static_assert(offsetof(ScriptLine, outputSize) == 0x40C);
	static_assert(offsetof(ScriptLine, expression) == 0x410);
	static_assert(offsetof(ScriptLine, referencedObjectIndex) == 0x414);
	static_assert(offsetof(ScriptLine, scriptError) == 0x418);
	static_assert(sizeof(ScriptLine) == 0x41C);

	struct ScriptFunction
	{
	public:
		struct IntegerChunk;
		struct StringChunk;

		struct Chunk
		{
		public:
			// Member functions
			IntegerChunk* AsInteger();
			StringChunk*  AsString();
		};
		static_assert(std::is_empty_v<Chunk>);

#pragma pack(push, 1)
		struct IntegerChunk :
			public Chunk // 0
		{
		public:
			// Member functions
			std::int32_t GetInteger() const;
			Chunk*       GetNext();

			// Member variables
			char         magic;   // 0
			std::int32_t integer; // 1
		};
		static_assert(offsetof(IntegerChunk, magic) == 0x0);
		static_assert(offsetof(IntegerChunk, integer) == 0x1);
		static_assert(sizeof(IntegerChunk) == 0x5);
#pragma pack(pop)

		struct StringChunk :
			public Chunk // 0
		{
			// Member functions
			Chunk*      GetNext();
			std::string GetString() const;

			// Member variables
			std::uint16_t length; // 0
#pragma warning(suppress : 4200)
			char string[0]; // 2
		};
		static_assert(offsetof(StringChunk, length) == 0x0);
		static_assert(offsetof(StringChunk, string) == 0x2);
		static_assert(sizeof(StringChunk) == 0x2);

		struct ScriptData
		{
		public:
			// Member functions
			Chunk*        GetChunk();
			IntegerChunk* GetIntegerChunk();
			StringChunk*  GetStringChunk();

			// Member variables
			std::uint16_t opcode;         // 0
			std::uint16_t chunkSize;      // 2
			std::uint16_t parameterCount; // 4
		};
		static_assert(offsetof(ScriptData, opcode) == 0x0);
		static_assert(offsetof(ScriptData, chunkSize) == 0x2);
		static_assert(offsetof(ScriptData, parameterCount) == 0x4);
		static_assert(sizeof(ScriptData) == 0x6);

		using ExecuteFunction   = bool(const ScriptParameter* scriptParameters, ScriptData* scriptData, TESObjectREFR* object, TESObjectREFR* containingObject, Script* script, ScriptLocals* scriptLocals, double& result, std::uint32_t& opcodeOffset);
		using CompileFunction   = bool(std::uint16_t parameterCount, const ScriptParameter* scriptParameters, ScriptLine* scriptLineBuffer, ScriptCompileData* scriptBuffer);
		using ConditionFunction = bool(TESObjectREFR* object, void* parameter1, void* parameter2, double& result);

		// Member variables
		const char*                                       functionName;       // 0
		const char*                                       shortName;          // 8
		Utility::Enumeration<ScriptOutput, std::uint32_t> scriptOutput;       // 10
		std::uint32_t                                     padding14;          // 14
		const char*                                       helpString;         // 18
		bool                                              referenceFunction;  // 20
		std::uint8_t                                      padding21;          // 21
		std::uint16_t                                     parameterCount;     // 22
		std::uint32_t                                     padding24;          // 24
		ScriptParameter*                                  scriptParameters;   // 28
		ExecuteFunction*                                  executeFunction;    // 30
		CompileFunction*                                  compileFunction;    // 38
		ConditionFunction*                                conditionFunction;  // 40
		bool                                              editorFilter;       // 48
		bool                                              invalidateCellList; // 49
		std::uint16_t                                     padding4A;          // 4A
		std::uint32_t                                     padding4C;          // 4C
	};
	static_assert(offsetof(ScriptFunction, functionName) == 0x0);
	static_assert(offsetof(ScriptFunction, shortName) == 0x8);
	static_assert(offsetof(ScriptFunction, scriptOutput) == 0x10);
	static_assert(offsetof(ScriptFunction, helpString) == 0x18);
	static_assert(offsetof(ScriptFunction, referenceFunction) == 0x20);
	static_assert(offsetof(ScriptFunction, parameterCount) == 0x22);
	static_assert(offsetof(ScriptFunction, scriptParameters) == 0x28);
	static_assert(offsetof(ScriptFunction, executeFunction) == 0x30);
	static_assert(offsetof(ScriptFunction, compileFunction) == 0x38);
	static_assert(offsetof(ScriptFunction, conditionFunction) == 0x40);
	static_assert(offsetof(ScriptFunction, editorFilter) == 0x48);
	static_assert(offsetof(ScriptFunction, invalidateCellList) == 0x49);
	static_assert(sizeof(ScriptFunction) == 0x50);
}
