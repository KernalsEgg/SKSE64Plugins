#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESFile.h"



namespace Skyrim
{
	void TESFile::AdjustFormIDFileIndex(FormID& formID) const
	{
		if (this->IsSmallFile())
		{
			formID &= 0xFFF;
			formID |= 0xFE000000;
			formID |= this->smallFileCompileIndex << 12;
		}
		else
		{
			formID &= 0xFFFFFF;
			formID |= this->compileIndex << 24;
		}
	}

	bool TESFile::IsCompiledFile() const
	{
		return this->compileIndex != 0xFF;
	}

	bool TESFile::IsSmallFile() const
	{
		return this->recordFlags.all(Skyrim::TESFile::RecordFlags::kSmallFile);
	}
}
