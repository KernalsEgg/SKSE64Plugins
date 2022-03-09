#include "PCH.h"

#include "Fixes/MovementSpeed.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace BugFixesSSE::Fixes
{
	void MovementSpeed::Fix(bool& movementSpeed)
	{
		if (!Patterns::Fixes::MovementSpeed::CompareMovementType())
		{
			movementSpeed = false;

			return;
		}

		Utility::Trampoline::GetSingleton().RelativeCallBranch(Addresses::Fixes::MovementSpeed::CompareMovementType + 0x5,
			0x48ui8, 0x39ui8, 0x44ui8, 0x24ui8, 0x78ui8, // cmp [rsp+78], rax
			0x0Fui8, 0x85ui8, 0x96ui32,                  // jne 96
			0x8Bui8, 0x44ui8, 0x24ui8, 0x40ui8,          // mov eax, [rsp+40]
			0x39ui8, 0x84ui8, 0x24ui8, 0x80ui32,         // cmp [rsp+80], eax
			0x0Fui8, 0x85ui8, 0x80ui32,                  // jne 80
			0x8Bui8, 0x44ui8, 0x24ui8, 0x44ui8,          // mov eax, [rsp+44]
			0x39ui8, 0x84ui8, 0x24ui8, 0x84ui32,         // cmp [rsp+84], eax
			0x75ui8, 0x73ui8,                            // jne 73
			0x8Bui8, 0x44ui8, 0x24ui8, 0x48ui8,          // mov eax, [rsp+48]
			0x39ui8, 0x84ui8, 0x24ui8, 0x88ui32,         // cmp [rsp+88], eax
			0x75ui8, 0x66ui8,                            // jne 66
			0x8Bui8, 0x44ui8, 0x24ui8, 0x4Cui8,          // mov eax, [rsp+4C]
			0x39ui8, 0x84ui8, 0x24ui8, 0x8Cui32,         // cmp [rsp+8C], eax
			0x75ui8, 0x59ui8,                            // jne 59
			0x8Bui8, 0x44ui8, 0x24ui8, 0x50ui8,          // mov eax, [rsp+50]
			0x39ui8, 0x84ui8, 0x24ui8, 0x90ui32,         // cmp [rsp+90], eax
			0x75ui8, 0x4Cui8,                            // jne 4C
			0x8Bui8, 0x44ui8, 0x24ui8, 0x54ui8,          // mov eax, [rsp+54]
			0x39ui8, 0x84ui8, 0x24ui8, 0x94ui32,         // cmp [rsp+94], eax
			0x75ui8, 0x3Fui8,                            // jne 3F
			0x8Bui8, 0x44ui8, 0x24ui8, 0x58ui8,          // mov eax, [rsp+58]
			0x39ui8, 0x84ui8, 0x24ui8, 0x98ui32,         // cmp [rsp+98], eax
			0x75ui8, 0x32ui8,                            // jne 32
			0x8Bui8, 0x44ui8, 0x24ui8, 0x5Cui8,          // mov eax, [rsp+5C]
			0x39ui8, 0x84ui8, 0x24ui8, 0x9Cui32,         // cmp [rsp+9C], eax
			0x75ui8, 0x25ui8,                            // jne 25
			0x8Bui8, 0x44ui8, 0x24ui8, 0x60ui8,          // mov eax, [rsp+60]
			0x39ui8, 0x84ui8, 0x24ui8, 0xA0ui32,         // cmp [rsp+A0], eax
			0x75ui8, 0x18ui8,                            // jne 18
			0x8Bui8, 0x44ui8, 0x24ui8, 0x64ui8,          // mov eax, [rsp+64]
			0x39ui8, 0x84ui8, 0x24ui8, 0xA4ui32,         // cmp [rsp+A4], eax
			0x75ui8, 0x0Bui8,                            // jne B
			0x8Bui8, 0x44ui8, 0x24ui8, 0x68ui8,          // mov eax, [rsp+68]
			0x39ui8, 0x84ui8, 0x24ui8, 0xA8ui32,         // cmp [rsp+A8], eax
			0x48ui8, 0x8Bui8, 0x44ui8, 0x24ui8, 0x38ui8, // mov rax, [rsp+38]
			0xC3ui8                                      // ret
		);
	}
}
