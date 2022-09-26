#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class TESForm;

	class BGSSaveGameBuffer
	{
	public:
		// Add
		virtual ~BGSSaveGameBuffer();              // 0
		virtual void Unknown1(BGSSaveGameBuffer*); // 1
		virtual void Unknown2(BGSSaveGameBuffer*); // 2
		virtual void Unknown3(BGSSaveGameBuffer*); // 3

		// Member functions
		void Write(const void* source, std::uint32_t length);
		void WriteFormID(TESForm* form);

		// Member variables
		void*         address;  // 8
		std::uint32_t size;     // 10
		std::uint32_t position; // 14
	};
	static_assert(offsetof(BGSSaveGameBuffer, address) == 0x8);
	static_assert(offsetof(BGSSaveGameBuffer, size) == 0x10);
	static_assert(offsetof(BGSSaveGameBuffer, position) == 0x14);
	static_assert(sizeof(BGSSaveGameBuffer) == 0x18);
}
