#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	class Setting
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		enum class Type
		{
			kBool              = 0, // b
			kCharacter         = 1, // c
			kUnsignedCharacter = 2, // h
			kInteger           = 3, // i
			kUnsignedInteger   = 4, // u
			kFloat             = 5, // f
			kString            = 6, // s: statically allocated, S: dynamically allocated
			kColorRGB          = 7, // r
			kColorRGBA         = 8, // a
		};

		union Value
		{
		public:
			// Member variables
			bool          b;
			std::int8_t   c;
			std::uint8_t  h;
			std::int32_t  i;
			std::uint32_t u;
			float         f;
			const char*   s{ nullptr };
			std::uint32_t r;
			std::uint32_t a;
		};
		static_assert(sizeof(Value) == 0x8);

		// Add
		virtual ~Setting() = default;             // 0
		virtual bool IsPreferenceSetting() const; // 1

		Setting()               = delete;
		Setting(const Setting&) = delete;
		Setting(Setting&&)      = delete;

		Setting& operator=(const Setting&) = delete;
		Setting& operator=(Setting&&)      = delete;

		Setting(const char* name, bool value);
		Setting(const char* name, const char* value);
		Setting(const char* name, float value);
		Setting(const char* name, std::int8_t value);
		Setting(const char* name, std::int32_t value);
		Setting(const char* name, std::uint8_t value);
		Setting(const char* name, std::uint32_t value);

		// Member functions
		bool          GetBool() const;
		std::int8_t   GetCharacter() const;
		float         GetFloat() const;
		std::int32_t  GetInteger() const;
		const char*   GetString() const;
		std::uint8_t  GetUnsignedCharacter() const;
		std::uint32_t GetUnsignedInteger() const;

		void SetBool(bool value);
		void SetCharacter(std::int8_t value);
		void SetFloat(float value);
		void SetInteger(std::int32_t value);
		void SetUnsignedCharacter(std::uint8_t value);
		void SetUnsignedInteger(std::uint32_t value);

	private:
		// Member variables
		Value       value_;           // 8
		const char* name_{ nullptr }; // 10
	};
	static_assert(sizeof(Setting) == 0x18);
}
