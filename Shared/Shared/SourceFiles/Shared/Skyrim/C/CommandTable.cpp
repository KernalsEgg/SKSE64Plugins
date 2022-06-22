#include "Shared/PCH.h"

#include "Shared/Skyrim/C/CommandTable.h"



namespace Skyrim
{
	ScriptFunction::IntegerChunk* ScriptFunction::Chunk::AsInteger()
	{
		return static_cast<IntegerChunk*>(this);
	}

	ScriptFunction::StringChunk* ScriptFunction::Chunk::AsString()
	{
		return static_cast<StringChunk*>(this);
	}

	std::int32_t ScriptFunction::IntegerChunk::GetInteger() const
	{
		return this->integer;
	}

	ScriptFunction::Chunk* ScriptFunction::IntegerChunk::GetNext()
	{
		return reinterpret_cast<Chunk*>(this + 1);
	}

	ScriptFunction::Chunk* ScriptFunction::StringChunk::GetNext()
	{
		return reinterpret_cast<Chunk*>(this->string + this->length);
	}

	std::string ScriptFunction::StringChunk::GetString() const
	{
		return this->length ? std::string(this->string, this->length) : "";
	}

	ScriptFunction::Chunk* ScriptFunction::ScriptData::GetChunk()
	{
		return reinterpret_cast<Chunk*>(this + 1);
	}

	ScriptFunction::IntegerChunk* ScriptFunction::ScriptData::GetIntegerChunk()
	{
		return static_cast<IntegerChunk*>(this->GetChunk());
	}

	ScriptFunction::StringChunk* ScriptFunction::ScriptData::GetStringChunk()
	{
		return static_cast<StringChunk*>(this->GetChunk());
	}
}
