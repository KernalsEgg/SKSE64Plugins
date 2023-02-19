#include "PrecompiledHeader.h"

#include "Fixes/MovementSpeed.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Conversion.h"



namespace BugFixesSSE::Fixes
{
	void MovementSpeed::Fix(bool& movementSpeed)
	{
		if (!Patterns::Fixes::MovementSpeed::CompareMovementType())
		{
			movementSpeed = false;

			return;
		}

		auto movementTypeID    = offsetof(Skyrim::BGSMovementType::Data, movementTypeID);
		auto defaultData       = offsetof(Skyrim::BGSMovementType::Data, defaultData);
		auto leftWalk          = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kLeft)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kWalk)]);
		auto leftRun           = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kLeft)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kRun)]);
		auto rightWalk         = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kRight)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kWalk)]);
		auto rightRun          = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kRight)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kRun)]);
		auto forwardWalk       = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kForward)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kWalk)]);
		auto forwardRun        = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kForward)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kRun)]);
		auto backWalk          = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kBack)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kWalk)]);
		auto backRun           = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kBack)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kRun)]);
		auto rotateInPlaceWalk = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kRotateInPlace)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kWalk)]);
		auto rotateInPlaceRun  = offsetof(Skyrim::BGSMovementType::Data::DefaultData, velocity[Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Direction::kRotateInPlace)][Utility::Conversion::ToUnderlying(Skyrim::BGSMovementType::Data::DefaultData::Speed::kRun)]);
		auto rotateWhileMoving = offsetof(Skyrim::BGSMovementType::Data::DefaultData, rotateWhileMoving);

		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5Branch(Addresses::Fixes::MovementSpeed::CompareMovementType + 0x5,
			0x48ui8, 0x39ui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x78ui8 + movementTypeID),           // cmp [rsp+78], rax
			0x0Fui8, 0x85ui8, 0x96ui32,                                                                        // jne 96
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + leftWalk),            // mov eax, [rsp+40]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + leftWalk),          // cmp [rsp+80], eax
			0x0Fui8, 0x85ui8, 0x80ui32,                                                                        // jne 80
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + leftRun),             // mov eax, [rsp+44]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + leftRun),           // cmp [rsp+84], eax
			0x75ui8, 0x73ui8,                                                                                  // jne 73
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + rightWalk),           // mov eax, [rsp+48]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + rightWalk),         // cmp [rsp+88], eax
			0x75ui8, 0x66ui8,                                                                                  // jne 66
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + rightRun),            // mov eax, [rsp+4C]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + rightRun),          // cmp [rsp+8C], eax
			0x75ui8, 0x59ui8,                                                                                  // jne 59
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + forwardWalk),         // mov eax, [rsp+50]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + forwardWalk),       // cmp [rsp+90], eax
			0x75ui8, 0x4Cui8,                                                                                  // jne 4C
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + forwardRun),          // mov eax, [rsp+54]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + forwardRun),        // cmp [rsp+94], eax
			0x75ui8, 0x3Fui8,                                                                                  // jne 3F
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + backWalk),            // mov eax, [rsp+58]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + backWalk),          // cmp [rsp+98], eax
			0x75ui8, 0x32ui8,                                                                                  // jne 32
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + backRun),             // mov eax, [rsp+5C]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + backRun),           // cmp [rsp+9C], eax
			0x75ui8, 0x25ui8,                                                                                  // jne 25
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + rotateInPlaceWalk),   // mov eax, [rsp+60]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + rotateInPlaceWalk), // cmp [rsp+A0], eax
			0x75ui8, 0x18ui8,                                                                                  // jne 18
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + rotateInPlaceRun),    // mov eax, [rsp+64]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + rotateInPlaceRun),  // cmp [rsp+A4], eax
			0x75ui8, 0x0Bui8,                                                                                  // jne B
			0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + defaultData + rotateWhileMoving),   // mov eax, [rsp+68]
			0x39ui8, 0x84ui8, 0x24ui8, static_cast<std::uint32_t>(0x78ui32 + defaultData + rotateWhileMoving), // cmp [rsp+A8], eax
			0x48ui8, 0x8Bui8, 0x44ui8, 0x24ui8, static_cast<std::uint8_t>(0x38ui8 + movementTypeID),           // mov rax, [rsp+38]
			0xC3ui8                                                                                            // ret
		);
	}
}
