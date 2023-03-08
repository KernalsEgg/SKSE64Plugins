#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace Skyrim
{
	namespace Addresses
	{
		namespace AbsorbEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16366D0, 1.6.318.0: SkyrimSE.exe + 0x172C3F0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257544, 205801)) };
		}

		namespace AccumulatingValueModifierEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636880, 1.6.318.0: SkyrimSE.exe + 0x172C5A0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257549, 205803)) };
		}

		namespace ActiveEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636EE0, 1.6.318.0: SkyrimSE.exe + 0x172CD18</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257579, 205813)) };
		}

		namespace Actor
		{
			namespace MagicTarget
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1656058, 1.6.318.0: SkyrimSE.exe + 0x174C360</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(260542, 207519)) };
			}

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F560, 1.6.318.0: SkyrimSE.exe + 0x655190</summary>
			inline const std::uintptr_t AddSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37771, 38716)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5E4800, 1.6.318.0: SkyrimSE.exe + 0x60A730</summary>
			inline const std::uintptr_t AdjustHealthDamageToDifficulty{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36506, 37506)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5D0F40, 1.6.318.0: SkyrimSE.exe + 0x5F5520</summary>
			inline const std::uintptr_t CanBeKilledBy{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36247, 37229)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x621350, 1.6.318.0: SkyrimSE.exe + 0x6468C0</summary>
			inline const std::uintptr_t GetActorValueModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37524, 38469)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x692CD0, 1.6.318.0: SkyrimSE.exe + 0x6BA9A0</summary>
			inline const std::uintptr_t GetArmorRating{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(39175, 40249)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F170, 1.6.318.0: SkyrimSE.exe + 0x654CC0</summary>
			inline const std::uintptr_t GetControllingActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37762, 38707)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5FD5B0, 1.6.318.0: SkyrimSE.exe + 0x624490</summary>
			inline const std::uintptr_t GetLineOfSightLocation{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36755, 37771)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6348A0, 1.6.318.0: SkyrimSE.exe + 0x65A970</summary>
			inline const std::uintptr_t GetSoulLevel{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37862, 38817)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x693050, 1.6.318.0: SkyrimSE.exe + 0x6BAD10</summary>
			inline const std::uintptr_t GetWeaponDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(39179, 40253)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6213D0, 1.6.318.0: SkyrimSE.exe + 0x646940</summary>
			inline const std::uintptr_t HandleActorValueModified{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37525, 38470)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5FCCB0, 1.6.318.0: SkyrimSE.exe + 0x623C10</summary>
			inline const std::uintptr_t IsActorInLineOfSight{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36752, 37768)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5FD2C0, 1.6.318.0: SkyrimSE.exe + 0x6241F0</summary>
			inline const std::uintptr_t IsPositionInLineOfSight{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36754, 37770)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5FCB90, 1.6.318.0: SkyrimSE.exe + 0x623AF0</summary>
			inline const std::uintptr_t IsReferenceInLineOfSight{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36751, 37767)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x621120, 1.6.318.0: SkyrimSE.exe + 0x6466A0</summary>
			inline const std::uintptr_t ModifyActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37523, 38468)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x621590, 1.6.318.0: SkyrimSE.exe + 0x646B00</summary>
			inline const std::uintptr_t RemoveActorValueModifiers{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37527, 38476)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5F9F20, 1.6.318.0: SkyrimSE.exe + 0x620DE0</summary>
			inline const std::uintptr_t RemoveBasePerks{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(36695, 37704)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x632270, 1.6.318.0: SkyrimSE.exe + 0x658170</summary>
			inline const std::uintptr_t SetSelectedSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37819, 38768)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1655640, 1.6.318.0: SkyrimSE.exe + 0x174B948</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(260538, 207511)) };
		}

		namespace ActorEquipManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x637A80, 1.6.318.0: SkyrimSE.exe + 0x65D710</summary>
			inline const std::uintptr_t EquipItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37938, 38894)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EC4838, 1.6.318.0: SkyrimSE.exe + 0x2F5EF88</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514494, 400636)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x638190, 1.6.318.0: SkyrimSE.exe + 0x65DF00</summary>
			inline const std::uintptr_t UnequipItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(37945, 38901)) };
		}

		namespace ActorValueInfo
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3E1420, 1.6.318.0: SkyrimSE.exe + 0x3FA090</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(26569, 27202)) };
		}

		namespace ActorValueOwner
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C1700, 1.6.318.0: SkyrimSE.exe + 0x3D9160</summary>
			inline const std::uintptr_t GetDualCastingEffectiveness{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(25931, 26518)) };
		}

		namespace AITimer
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F3A644, 1.6.318.0: SkyrimSE.exe + 0x2FD530C</summary>
			inline const std::uintptr_t Timer{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(517597, 404125)) };
		}

		namespace BanishEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D8D0, 1.6.318.0: SkyrimSE.exe + 0x1733940</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258030, 206133)) };
		}

		namespace BGSCreatedObjectManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEAE8, 1.6.318.0: SkyrimSE.exe + 0x1F592E8</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514172, 400320)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x59F6E0, 1.6.318.0: SkyrimSE.exe + 0x5C0B20</summary>
			inline const std::uintptr_t DecrementReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(35269, 36171)) };
		}

		namespace BGSDecalManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EC4320, 1.6.318.0: SkyrimSE.exe + 0x1F5EA88</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514414, 400561)) };
		}

		namespace BGSDefaultObjectManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xF7210, 1.6.318.0: SkyrimSE.exe + 0x182100</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(10878, 13894)) };
		}

		namespace BGSEntryPoint
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DD2EA0, 1.6.318.0: SkyrimSE.exe + 0x1E66F90</summary>
			inline const std::uintptr_t EntryPoints{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(675707, 368994)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x32ECE0, 1.6.318.0: SkyrimSE.exe + 0x3444C0</summary>
			inline const std::uintptr_t HandleEntryPoint{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(23073, 23526)) };
		}

		namespace BGSEntryPointFunction
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DD3BA0, 1.6.318.0: SkyrimSE.exe + 0x1E67C90</summary>
			inline const std::uintptr_t EntryPointFunctionTypeArgumentCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(502187, 369210)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x32EEE0, 1.6.318.0: SkyrimSE.exe + 0x3446C0</summary>
			inline const std::uintptr_t ExecuteFunction{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(23075, 23528)) };
		}

		namespace BGSEntryPointPerkEntry
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1598610, 1.6.318.0: SkyrimSE.exe + 0x1690078</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(241053, 195299)) };
		}

		namespace BGSFootstepManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F27150, 1.6.318.0: SkyrimSE.exe + 0x2FC1C20</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(517045, 403553)) };
		}

		namespace BGSImpactDataSet
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2C3490, 1.6.318.0: SkyrimSE.exe + 0x2D6460</summary>
			inline const std::uintptr_t GetImpactData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(20408, 20860)) };
		}

		namespace BGSImpactManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5A2930, 1.6.318.0: SkyrimSE.exe + 0x5C3AD0</summary>
			inline const std::uintptr_t PlaySound{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(35317, 36212)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F003F0, 1.6.318.0: SkyrimSE.exe + 0x2F9AB00</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(515123, 401262)) };
		}

		namespace BGSMaterialType
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2C73F0, 1.6.318.0: SkyrimSE.exe + 0x2DA4D0</summary>
			inline const std::uintptr_t GetMaterialTypeFromMaterialID{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(20529, 20968)) };
		}

		namespace BGSPerk
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3386A0, 1.6.318.0: SkyrimSE.exe + 0x34EAC0</summary>
			inline const std::uintptr_t ApplyPerk{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(23353, 23822)) };
		}

		namespace BGSSaveGameBuffer
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x599DB0, 1.6.318.0: SkyrimSE.exe + 0x5BB190</summary>
			inline const std::uintptr_t Write{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(35163, 36053)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5999B0, 1.6.318.0: SkyrimSE.exe + 0x5BAD90</summary>
			inline const std::uintptr_t WriteFormID{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(35158, 36048)) };
		}

		namespace bhkNiCollisionObject
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1424F0, 1.6.318.0: SkyrimSE.exe + 0x2B20F0</summary>
			inline const std::uintptr_t GetRigidBody{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(12784, 20014)) };
		}

		namespace bhkWorld
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x154064C, 1.6.318.0: SkyrimSE.exe + 0x1637AA0</summary>
			inline const std::uintptr_t Scale{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(231896, 188105)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1536BA0, 1.6.318.0: SkyrimSE.exe + 0x162DF48</summary>
			inline const std::uintptr_t ScaleInverse{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(230692, 187407)) };
		}

		namespace BoundItemEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16377C8, 1.6.318.0: SkyrimSE.exe + 0x172D608</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257627, 205842)) };
		}

		namespace BSAudioManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xBEE580, 1.6.318.0: SkyrimSE.exe + 0xC132D0</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66391, 67652)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xBEF020, 1.6.318.0: SkyrimSE.exe + 0xC13F50</summary>
			inline const std::uintptr_t GetSoundHandleFromName{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66403, 67665)) };
		}

		namespace BSFixedString
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC28BF0, 1.6.318.0: SkyrimSE.exe + 0xC4E920</summary>
			inline const std::uintptr_t Initialize{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(67819, 69161)) };
		}

		namespace BSInputDeviceManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F257A8, 1.6.318.0: SkyrimSE.exe + 0x2FBFD88</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(516574, 402776)) };
		}

		namespace BSPointerHandleManagerInterface
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EE670, 1.6.318.0: SkyrimSE.exe + 0x1FA210</summary>
			inline const std::uintptr_t GetHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15967, 16212)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1329D0, 1.6.318.0: SkyrimSE.exe + 0x139160</summary>
			inline const std::uintptr_t GetSmartPointer{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(12204, 12332)) };
		}

		namespace BSReadWriteLock
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC072D0, 1.6.318.0: SkyrimSE.exe + 0xC2BEF0</summary>
			inline const std::uintptr_t ReadLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66976, 68233)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07590, 1.6.318.0: SkyrimSE.exe + 0xC2C1B0</summary>
			inline const std::uintptr_t ReadUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66982, 68239)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07350, 1.6.318.0: SkyrimSE.exe + 0xC2BF70</summary>
			inline const std::uintptr_t WriteLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66977, 68234)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC075A0, 1.6.318.0: SkyrimSE.exe + 0xC2C1C0</summary>
			inline const std::uintptr_t WriteUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66983, 68240)) };
		}

		namespace BSSoundHandle
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xBED530, 1.6.318.0: SkyrimSE.exe + 0xC12290</summary>
			inline const std::uintptr_t Play{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66355, 67616)) };
		}

		namespace BSStringPool
		{
			namespace Entry
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0xC29E80, 1.6.318.0: SkyrimSE.exe + 0xC4FCF0</summary>
				inline const std::uintptr_t Release{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(67847, 69192)) };
			}
		}

		namespace CalmEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D9E8, 1.6.318.0: SkyrimSE.exe + 0x1733A58</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258031, 206135)) };
		}

		namespace Character
		{
			namespace MagicTarget
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x165E468, 1.6.318.0: SkyrimSE.exe + 0x1754098</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(261401, 207894)) };
			}

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x165DA40, 1.6.318.0: SkyrimSE.exe + 0x1753670</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(261397, 207886)) };
		}

		namespace CloakEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1637990, 1.6.318.0: SkyrimSE.exe + 0x172D7F8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257635, 205849)) };
		}

		namespace CommandEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1637C10, 1.6.318.0: SkyrimSE.exe + 0x172DA50</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257648, 205855)) };
		}

		namespace CommandSummonedEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1637D58, 1.6.318.0: SkyrimSE.exe + 0x172DB98</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257652, 205857)) };
		}

		namespace ConcussionEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638C98, 1.6.318.0: SkyrimSE.exe + 0x172EB80</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257699, 205885)) };
		}

		namespace Console
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F4C31C, 1.6.318.0: SkyrimSE.exe + 0x2FE6FE4</summary>
			inline const std::uintptr_t SelectedReferenceHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(519394, 405935)) };
		}

		namespace ConsoleLog
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x85C290, 1.6.318.0: SkyrimSE.exe + 0x889650</summary>
			inline const std::uintptr_t PrintLine{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(50179, 51109)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F000F0, 1.6.318.0: SkyrimSE.exe + 0x2F9A800</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(515064, 401203)) };
		}

		namespace ContainerMenu
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F4C3F0, 1.6.318.0: SkyrimSE.exe + 0x2FE70B8</summary>
			inline const std::uintptr_t TargetReferenceHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(519421, 405962)) };
		}

		namespace CraftingSubMenus
		{
			namespace EnchantConstructMenu
			{
				namespace CreateEffectFunctor
				{
					/// <summary>1.5.97.0: SkyrimSE.exe + 0x16AFEB8, 1.6.318.0: SkyrimSE.exe + 0x17A2ED8</summary>
					inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(268497, 215178)) };
				}
			}
		}

		namespace CureEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1637EC8, 1.6.318.0: SkyrimSE.exe + 0x172DD08</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257657, 205859)) };
		}

		namespace DarknessEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1637FC0, 1.6.318.0: SkyrimSE.exe + 0x172DE00</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257659, 205861)) };
		}

		namespace DemoralizeEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D6A0, 1.6.318.0: SkyrimSE.exe + 0x1733710</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258028, 206129)) };
		}

		namespace DetectLifeEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16380F8, 1.6.318.0: SkyrimSE.exe + 0x172DF10</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257661, 205863)) };
		}

		namespace DisarmEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16381F0, 1.6.318.0: SkyrimSE.exe + 0x172E048</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257663, 205865)) };
		}

		namespace DisguiseEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638438, 1.6.318.0: SkyrimSE.exe + 0x172E2C8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257673, 205870)) };
		}

		namespace DispelEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638558, 1.6.318.0: SkyrimSE.exe + 0x172E3E8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257676, 205872)) };
		}

		namespace DualValueModifierEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16386B8, 1.6.318.0: SkyrimSE.exe + 0x172E548</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257681, 205876)) };
		}

		namespace EffectArchetypes
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DB0020, 1.6.318.0: SkyrimSE.exe + 0x1E44020</summary>
			inline const std::uintptr_t Archetypes{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(500623, 358289)) };
		}

		namespace EffectItem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xF8630, 1.6.318.0: SkyrimSE.exe + 0x1029C0</summary>
			inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(10929, 11017)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xF87F0, 1.6.318.0: SkyrimSE.exe + 0x102B50</summary>
			inline const std::uintptr_t ResetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(10932, 11021)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xF86A0, 1.6.318.0: SkyrimSE.exe + 0x102A30</summary>
			inline const std::uintptr_t SetConditions{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(10930, 11018)) };
		}

		namespace EffectSetting
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C1250, 1.6.318.0: SkyrimSE.exe + 0x3D8CD0</summary>
			inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(25921, 26504)) };
		}

		namespace EnchantmentItem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C0DE0, 1.6.318.0: SkyrimSE.exe + 0x3D8810</summary>
			inline const std::uintptr_t ModifyPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(25910, 26493)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x15217E0, 1.6.318.0: SkyrimSE.exe + 0x161B920</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(228570, 186389)) };
		}

		namespace EnhanceWeaponEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1647FF0, 1.6.318.0: SkyrimSE.exe + 0x173EE50</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(259119, 206860)) };
		}

		namespace EtherealizationEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638800, 1.6.318.0: SkyrimSE.exe + 0x172E690</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257683, 205878)) };
		}

		namespace ExtraDataList
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x126650, 1.6.318.0: SkyrimSE.exe + 0x12D230</summary>
			inline const std::uintptr_t IsQuestItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(11913, 12052)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x111D30, 1.6.318.0: SkyrimSE.exe + 0x11DC40</summary>
			inline const std::uintptr_t SetLockList{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(11517, 11663)) };
		}

		namespace FindAppropriateDisplaceEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636FC8, 1.6.318.0: SkyrimSE.exe + 0x172CE00</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257581, 205817)) };
		}

		namespace FindMaxMagnitudeVisitor
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636990, 1.6.318.0: SkyrimSE.exe + 0x172C6B0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257550, 205805)) };
		}

		namespace FrenzyEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163DB00, 1.6.318.0: SkyrimSE.exe + 0x1733B70</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258032, 206137)) };
		}

		namespace GameSettingCollection
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1FCA30, 1.6.318.0: SkyrimSE.exe + 0x325330</summary>
			inline const std::uintptr_t GetSetting{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(16195, 22788)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xF9980, 1.6.318.0: SkyrimSE.exe + 0x103B70</summary>
			inline const std::uintptr_t InitializeCollection{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(10962, 11040)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EC58B0, 1.6.318.0: SkyrimSE.exe + 0x2F60000</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514622, 400782)) };
		}

		namespace GetMagicItemDescriptionFunctor
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16B4AD8, 1.6.318.0: SkyrimSE.exe + 0x17A7788</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(269117, 215554)) };
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0xEC83A0, 1.6.318.0: SkyrimSE.exe + 0xF0AA10</summary>
				inline const std::uintptr_t AttachMovie{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80197, 82219)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xEC9490, 1.6.318.0: SkyrimSE.exe + 0xF0BC40</summary>
				inline const std::uintptr_t DeleteMember{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80207, 82230)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xEC9BD0, 1.6.318.0: SkyrimSE.exe + 0xF0C310</summary>
				inline const std::uintptr_t GetArraySize{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80214, 82237)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xEC9C20, 1.6.318.0: SkyrimSE.exe + 0xF0C370</summary>
				inline const std::uintptr_t GetDisplayInformation{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80216, 82239)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xEC9F30, 1.6.318.0: SkyrimSE.exe + 0xF0C690</summary>
				inline const std::uintptr_t GetElement{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80218, 82241)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECA150, 1.6.318.0: SkyrimSE.exe + 0xF0C8B0</summary>
				inline const std::uintptr_t GetMember{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80222, 82245)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECA570, 1.6.318.0: SkyrimSE.exe + 0xF0CCC0</summary>
				inline const std::uintptr_t GotoAndPlay{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80230, 82253)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECA620, 1.6.318.0: SkyrimSE.exe + 0xF0CD60</summary>
				inline const std::uintptr_t HasMember{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80231, 82254)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECA860, 1.6.318.0: SkyrimSE.exe + 0xF0CFD0</summary>
				inline const std::uintptr_t Invoke{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80233, 82256)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECB080, 1.6.318.0: SkyrimSE.exe + 0xF0D6A0</summary>
				inline const std::uintptr_t ObjectAddReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80244, 82269)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECB0E0, 1.6.318.0: SkyrimSE.exe + 0xF0D700</summary>
				inline const std::uintptr_t ObjectRelease{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80245, 82270)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECB300, 1.6.318.0: SkyrimSE.exe + 0xF0D920</summary>
				inline const std::uintptr_t PushBack{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80248, 82273)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECB6C0, 1.6.318.0: SkyrimSE.exe + 0xF0DDB0</summary>
				inline const std::uintptr_t RemoveElements{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80252, 82280)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECBD20, 1.6.318.0: SkyrimSE.exe + 0xF0E120</summary>
				inline const std::uintptr_t SetArraySize{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80261, 82285)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECBDB0, 1.6.318.0: SkyrimSE.exe + 0xF0E1A0</summary>
				inline const std::uintptr_t SetDisplayInformation{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80263, 82287)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECC960, 1.6.318.0: SkyrimSE.exe + 0xF0EF70</summary>
				inline const std::uintptr_t SetElement{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80265, 82289)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECCBA0, 1.6.318.0: SkyrimSE.exe + 0xF0F1C0</summary>
				inline const std::uintptr_t SetMember{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80268, 82292)) };

				/// <summary>1.5.97.0: SkyrimSE.exe + 0xECCCF0, 1.6.318.0: SkyrimSE.exe + 0xF0F2C0</summary>
				inline const std::uintptr_t SetText{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80270, 82293)) };
			}
		}

		namespace GMemory
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3032C50, 1.6.318.0: SkyrimSE.exe + 0x30CC600</summary>
			inline const std::uintptr_t GlobalHeap{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(525584, 412058)) };
		}

		namespace GrabActorEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638A10, 1.6.318.0: SkyrimSE.exe + 0x172E760</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257692, 205880)) };
		}

		namespace GString
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xED3A50, 1.6.318.0: SkyrimSE.exe + 0xF1ACC0</summary>
			inline const std::uintptr_t Constructor{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(80446, 82562)) };
		}

		namespace GuideEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638F48, 1.6.318.0: SkyrimSE.exe + 0x172ECB8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257712, 205887)) };
		}

		namespace HandleEntryPointVisitor
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1595B98, 1.6.318.0: SkyrimSE.exe + 0x168D578</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(240863, 195172)) };
		}

		namespace hkReferencedObject
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C6730, 1.6.318.0: SkyrimSE.exe + 0x9EAF20</summary>
			inline const std::uintptr_t AddReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(56606, 57010)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C67F0, 1.6.318.0: SkyrimSE.exe + 0x9EAFE0</summary>
			inline const std::uintptr_t RemoveReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(56607, 57011)) };
		}

		namespace IFormFactory
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x191B70, 1.6.318.0: SkyrimSE.exe + 0x19C630</summary>
			inline const std::uintptr_t GetFormFactory{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14432, 14587)) };
		}

		namespace INIPrefSettingCollection
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x165830, 1.6.318.0: SkyrimSE.exe + 0x16F7D0</summary>
			inline const std::uintptr_t InitializeCollection{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13551, 13668)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F6BA48, 1.6.318.0: SkyrimSE.exe + 0x30065D0</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(523673, 410219)) };
		}

		namespace INISettingCollection
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3104D0, 1.6.318.0: SkyrimSE.exe + 0x3252B0</summary>
			inline const std::uintptr_t GetSetting{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(22315, 22787)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x14EB90, 1.6.318.0: SkyrimSE.exe + 0x157CB0</summary>
			inline const std::uintptr_t InitializeCollection{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13098, 13254)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x301D758, 1.6.318.0: SkyrimSE.exe + 0x30B82D8</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(524557, 411155)) };
		}

		namespace InitTESThread
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x164D900, 1.6.318.0: SkyrimSE.exe + 0x1744760</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(259694, 207137)) };
		}

		namespace InterfaceStrings
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EC0A78, 1.6.318.0: SkyrimSE.exe + 0x1F5B278</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514286, 400446)) };
		}

		namespace Inventory3DManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F27180, 1.6.318.0: SkyrimSE.exe + 0x2FC1C50</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(517051, 403559)) };
		}

		namespace InventoryChanges
		{
			namespace FindBestSoulGemVisitor
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1658668, 1.6.318.0: SkyrimSE.exe + 0x174E2D0</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(260831, 207680)) };
			}
		}

		namespace InventoryEntryData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D73C0, 1.6.318.0: SkyrimSE.exe + 0x1E2C10</summary>
			inline const std::uintptr_t GetName{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15780, 16018)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D66E0, 1.6.318.0: SkyrimSE.exe + 0x1E1F60</summary>
			inline const std::uintptr_t GetValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15757, 15995)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D7590, 1.6.318.0: SkyrimSE.exe + 0x1E2EA0</summary>
			inline const std::uintptr_t IsOwnedBy{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15782, 16020)) };
		}

		namespace InvisibilityEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1639040, 1.6.318.0: SkyrimSE.exe + 0x172EF78</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257714, 205890)) };
		}

		namespace ItemList
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x856400, 1.6.318.0: SkyrimSE.exe + 0x883290</summary>
			inline const std::uintptr_t GetSelectedItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(50086, 51017)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x856A50, 1.6.318.0: SkyrimSE.exe + 0x883930</summary>
			inline const std::uintptr_t Update{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(50099, 51031)) };
		}

		namespace LightEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16392D0, 1.6.318.0: SkyrimSE.exe + 0x172F1E0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257725, 205894)) };
		}

		namespace LockEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16393E0, 1.6.318.0: SkyrimSE.exe + 0x172F2F0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257728, 205898)) };
		}

		namespace MagicItem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x101A30, 1.6.318.0: SkyrimSE.exe + 0x10BCB0</summary>
			inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(11213, 11321)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x101CC0, 1.6.318.0: SkyrimSE.exe + 0x10BF30</summary>
			inline const std::uintptr_t GetCostliestEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(11216, 11335)) };
		}

		namespace Main
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DEEBE0, 1.6.318.0: SkyrimSE.exe + 0x1E82F60</summary>
			inline const std::uintptr_t FrameCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(508776, 380737)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26BF8, 1.6.318.0: SkyrimSE.exe + 0x2FC1650</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(516943, 403449)) };
		}

		namespace MemoryManager
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC02260, 1.6.318.0: SkyrimSE.exe + 0xC26F00</summary>
			inline const std::uintptr_t Allocate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66859, 68115)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC02560, 1.6.318.0: SkyrimSE.exe + 0xC27350</summary>
			inline const std::uintptr_t Deallocate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66861, 68117)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xFCFE0, 1.6.318.0: SkyrimSE.exe + 0x106EC0</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(11045, 11141)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC01800, 1.6.318.0: SkyrimSE.exe + 0xC264A0</summary>
			inline const std::uintptr_t GetThreadScrapHeap{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66841, 68088)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC024B0, 1.6.318.0: SkyrimSE.exe + 0xC27150</summary>
			inline const std::uintptr_t Reallocate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66860, 68116)) };
		}

		namespace NiAVObject
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xD41970, 1.6.318.0: SkyrimSE.exe + 0xD79A80</summary>
			inline const std::uintptr_t GetBoneFromName{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(74481, 76207)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3A6140, 1.6.318.0: SkyrimSE.exe + 0x3BCAB0</summary>
			inline const std::uintptr_t GetCollisionObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(25482, 26022)) };
		}

		namespace NiBooleanExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC84190, 1.6.318.0: SkyrimSE.exe + 0xCAD3B0</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69934, 71358)) };
		}

		namespace NiExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC6E860, 1.6.318.0: SkyrimSE.exe + 0xC96F30</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69477, 70859)) };
		}

		namespace NiFloatExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC84F30, 1.6.318.0: SkyrimSE.exe + 0xCAE3E0</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69971, 71398)) };
		}

		namespace NiFloatsExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC853A0, 1.6.318.0: SkyrimSE.exe + 0xCAE950</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69981, 71409)) };
		}

		namespace NightEyeEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163A978, 1.6.318.0: SkyrimSE.exe + 0x1730980</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257853, 205968)) };
		}

		namespace NiIntegerExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC85E80, 1.6.318.0: SkyrimSE.exe + 0xCAF630</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(70009, 71439)) };
		}

		namespace NiIntegersExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC86310, 1.6.318.0: SkyrimSE.exe + 0xCAFBA0</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(70019, 71450)) };
		}

		namespace NiMatrix33
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC544E0, 1.6.318.0: SkyrimSE.exe + 0xC7B890</summary>
			inline const std::uintptr_t EulerAnglesToRotationMatrixXYZ{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(68874, 70221)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC55AE0, 1.6.318.0: SkyrimSE.exe + 0xC7CF10</summary>
			inline const std::uintptr_t EulerAnglesToRotationMatrixZXY{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(68886, 70233)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC53EB0, 1.6.318.0: SkyrimSE.exe + 0xC7B240</summary>
			inline const std::uintptr_t RotationMatrixToEulerAnglesXYZ{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(68868, 70215)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC559E0, 1.6.318.0: SkyrimSE.exe + 0xC7CE10</summary>
			inline const std::uintptr_t RotationMatrixToEulerAnglesZXY{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(68885, 70232)) };
		}

		namespace NiNode
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1AFB10, 1.6.318.0: SkyrimSE.exe + 0x1BB530</summary>
			inline const std::uintptr_t AddDecal{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15060, 15234)) };
		}

		namespace NiObjectNET
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60990, 1.6.318.0: SkyrimSE.exe + 0xC88310</summary>
			inline const std::uintptr_t AddExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69148, 70509)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60900, 1.6.318.0: SkyrimSE.exe + 0xC88260</summary>
			inline const std::uintptr_t AddNamedExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69147, 70508)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC612B0, 1.6.318.0: SkyrimSE.exe + 0xC88CA0</summary>
			inline const std::uintptr_t DeleteExtraDataAt{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69159, 70520)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60AD0, 1.6.318.0: SkyrimSE.exe + 0xC88460</summary>
			inline const std::uintptr_t GetExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69149, 70510)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC61110, 1.6.318.0: SkyrimSE.exe + 0xC88B00</summary>
			inline const std::uintptr_t InsertExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69158, 70519)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60D10, 1.6.318.0: SkyrimSE.exe + 0xC886C0</summary>
			inline const std::uintptr_t RemoveAllExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69152, 70513)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60BB0, 1.6.318.0: SkyrimSE.exe + 0xC88550</summary>
			inline const std::uintptr_t RemoveExtraData{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69150, 70511)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC60CA0, 1.6.318.0: SkyrimSE.exe + 0xC88650</summary>
			inline const std::uintptr_t RemoveExtraDataAt{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69151, 70512)) };
		}

		namespace NiStringExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC6C190, 1.6.318.0: SkyrimSE.exe + 0xC94780</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69420, 70795)) };
		}

		namespace NiStringsExtraData
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC64280, 1.6.318.0: SkyrimSE.exe + 0xC8BF90</summary>
			inline const std::uintptr_t CreateObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(69243, 70607)) };
		}

		namespace OpenEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163AE88, 1.6.318.0: SkyrimSE.exe + 0x1730EB8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257868, 206009)) };
		}

		namespace ParalysisEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163AF80, 1.6.318.0: SkyrimSE.exe + 0x1730FB0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257870, 206011)) };
		}

		namespace PeakValueModifierEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163B108, 1.6.318.0: SkyrimSE.exe + 0x1731138</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257874, 206014)) };
		}

		namespace PlayerCharacter
		{
			namespace MagicTarget
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1664030, 1.6.318.0: SkyrimSE.exe + 0x175A500</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(261920, 208048)) };
			}

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C1200, 1.6.318.0: SkyrimSE.exe + 0x3D8C80</summary>
			inline const std::uintptr_t GetDifficultyMultiplier{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(25920, 26503)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26EF8, 1.6.318.0: SkyrimSE.exe + 0x2FC19C8</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(517014, 403521)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16635E0, 1.6.318.0: SkyrimSE.exe + 0x1759AB0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(261916, 208040)) };
		}

		namespace PoisonedWeapon
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6C7F40, 1.6.318.0: SkyrimSE.exe + 0x6F0190</summary>
			inline const std::uintptr_t GetEventSource{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(40058, 41069)) };
		}

		namespace Precipitation
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F013C8, 1.6.318.0: SkyrimSE.exe + 0x2F9BAE8</summary>
			inline const std::uintptr_t RainDirection{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(515509, 401648)) };
		}

		namespace RallyEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D588, 1.6.318.0: SkyrimSE.exe + 0x17335F8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258027, 206127)) };
		}

		namespace ReanimateEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163B2B8, 1.6.318.0: SkyrimSE.exe + 0x1731248</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257879, 206016)) };
		}

		namespace ScrapHeap
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC034A0, 1.6.318.0: SkyrimSE.exe + 0xC28310</summary>
			inline const std::uintptr_t Allocate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66884, 68144)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC03AC0, 1.6.318.0: SkyrimSE.exe + 0xC28910</summary>
			inline const std::uintptr_t Deallocate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(66885, 68146)) };
		}

		namespace Script
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2E3C30, 1.6.318.0: SkyrimSE.exe + 0x2F7FC0</summary>
			inline const std::uintptr_t ClearCachedValues{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(21329, 21788)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2E75F0, 1.6.318.0: SkyrimSE.exe + 0x2FBA00</summary>
			inline const std::uintptr_t CompileAndRun{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(21416, 21890)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2E8400, 1.6.318.0: SkyrimSE.exe + 0x2FC890</summary>
			inline const std::uintptr_t ParseParameters{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(21425, 21910)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2E6ED0, 1.6.318.0: SkyrimSE.exe + 0x2FB2E0</summary>
			inline const std::uintptr_t SetCommand{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(21409, 21883)) };
		}

		namespace ScriptCompiler
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EDC60, 1.6.318.0: SkyrimSE.exe + 0x301E10</summary>
			inline const std::uintptr_t GetFunctionDefinition{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(21484, 21963)) };
		}

		namespace ScriptedRefEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163BD18, 1.6.318.0: SkyrimSE.exe + 0x1731B50</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257920, 206027)) };
		}

		namespace ScriptEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163BC48, 1.6.318.0: SkyrimSE.exe + 0x1731E00</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257919, 206031)) };
		}

		namespace ScriptEventSourceHolder
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x186790, 1.6.318.0: SkyrimSE.exe + 0x1941C0</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14108, 14298)) };
		}

		namespace ScrollItem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1524FF0, 1.6.318.0: SkyrimSE.exe + 0x161F150</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(228867, 186591)) };
		}

		namespace Sky
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x177790, 1.6.318.0: SkyrimSE.exe + 0x1818D0</summary>
			inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13789, 13878)) };
		}

		namespace SlowTimeEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163C870, 1.6.318.0: SkyrimSE.exe + 0x17328E0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257978, 206066)) };
		}

		namespace SoulTrapEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163CA18, 1.6.318.0: SkyrimSE.exe + 0x1732A88</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257985, 206070)) };
		}

		namespace SpawnHazardEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x164E778, 1.6.318.0: SkyrimSE.exe + 0x17453A8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(259802, 207209)) };
		}

		namespace SpellItem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1525720, 1.6.318.0: SkyrimSE.exe + 0x161F8A8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(228888, 186619)) };
		}

		namespace StaggerEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163CB38, 1.6.318.0: SkyrimSE.exe + 0x1732BA8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257988, 206072)) };
		}

		namespace SummonCreatureEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163CFF8, 1.6.318.0: SkyrimSE.exe + 0x17330D0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258015, 206083)) };
		}

		namespace TargetValueModifierEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D470, 1.6.318.0: SkyrimSE.exe + 0x17334E0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(546854, 206092)) };
		}

		namespace TaskQueueInterface
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5C1E40, 1.6.318.0: SkyrimSE.exe + 0x5E8AC0</summary>
			inline const std::uintptr_t QueueScriptFunctionCall{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(35918, 36893)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x63F810, 1.6.318.0: SkyrimSE.exe + 0x665DD0</summary>
			inline const std::uintptr_t ShouldQueueTask{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(38079, 39033)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F38978, 1.6.318.0: SkyrimSE.exe + 0x2FD3650</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(517228, 403759)) };
		}

		namespace TelekinesisEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163DCB8, 1.6.318.0: SkyrimSE.exe + 0x1733C88</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258037, 206139)) };
		}

		namespace TES
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x155090, 1.6.318.0: SkyrimSE.exe + 0x15E310</summary>
			inline const std::uintptr_t GetCell{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13177, 13322)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x156970, 1.6.318.0: SkyrimSE.exe + 0x15FCB0</summary>
			inline const std::uintptr_t GetLandColor{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13200, 13346)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x156CD0, 1.6.318.0: SkyrimSE.exe + 0x160030</summary>
			inline const std::uintptr_t GetMaterialID{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13203, 13349)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26B20, 1.6.318.0: SkyrimSE.exe + 0x2FC1658</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(516923, 403450)) };
		}

		namespace TESBoundObject
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1A1730, 1.6.318.0: SkyrimSE.exe + 0x1ACFE0</summary>
			inline const std::uintptr_t GetWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14809, 14988)) };
		}

		namespace TESCondition
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x444710, 1.6.318.0: SkyrimSE.exe + 0x45D8B0</summary>
			inline const std::uintptr_t Clear{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(29072, 29886)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x4447A0, 1.6.318.0: SkyrimSE.exe + 0x45D940</summary>
			inline const std::uintptr_t IsTrue{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(29074, 29888)) };
		}

		namespace TESDataHandler
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16AE70, 1.6.318.0: SkyrimSE.exe + 0x174B20</summary>
			inline const std::uintptr_t EnumerateReferencesCloseToPoint{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13604, 13700)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x16AF00, 1.6.318.0: SkyrimSE.exe + 0x174BB0</summary>
			inline const std::uintptr_t EnumerateReferencesCloseToReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13605, 13701)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x194230, 1.6.318.0: SkyrimSE.exe + 0x19F110</summary>
			inline const std::uintptr_t GetForm{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14461, 14617)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBE428, 1.6.318.0: SkyrimSE.exe + 0x1F58C28</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514141, 400269)) };
		}

		namespace TESForm
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x190D50, 1.6.318.0: SkyrimSE.exe + 0x19B880</summary>
			inline const std::uintptr_t GetEnchantment{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14411, 14563)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1944E0, 1.6.318.0: SkyrimSE.exe + 0x19F2E0</summary>
			inline const std::uintptr_t GetFormFromEditorID{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14464, 14620)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x196E10, 1.6.318.0: SkyrimSE.exe + 0x1A1C90</summary>
			inline const std::uintptr_t GetFormName{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14548, 14720)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x190DC0, 1.6.318.0: SkyrimSE.exe + 0x19B8F0</summary>
			inline const std::uintptr_t GetMaximumCharge{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14412, 14564)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x194D20, 1.6.318.0: SkyrimSE.exe + 0x19FA90</summary>
			inline const std::uintptr_t SetTemporary{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(14485, 14642)) };
		}

		namespace TESFurniture
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1553E58, 1.6.318.0: SkyrimSE.exe + 0x164B400</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(233784, 189309)) };
		}

		namespace TESObjectCELL
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x44B9A0, 1.6.318.0: SkyrimSE.exe + 0x465370</summary>
			inline const std::uintptr_t CreateTemporaryEffectParticle{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(29218, 30071)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2654C0, 1.6.318.0: SkyrimSE.exe + 0x2772D0</summary>
			inline const std::uintptr_t GetHavokWorld{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(18536, 18995)) };
		}

		namespace TESObjectREFR
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x296C00, 1.6.318.0: SkyrimSE.exe + 0x2A9180</summary>
			inline const std::uintptr_t Activate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(19369, 19796)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D8E40, 1.6.318.0: SkyrimSE.exe + 0x1E4880</summary>
			inline const std::uintptr_t GetInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(15802, 16040)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2945E0, 1.6.318.0: SkyrimSE.exe + 0x2A6CB0</summary>
			inline const std::uintptr_t GetReferenceFrom3D{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(19323, 19750)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2961F0, 1.6.318.0: SkyrimSE.exe + 0x2A88A0</summary>
			inline const std::uintptr_t GetReferenceName{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(19354, 19781)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x29A330, 1.6.318.0: SkyrimSE.exe + 0x2AC9E0</summary>
			inline const std::uintptr_t IsCrimeToActivate{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(19400, 19827)) };
		}

		namespace TESObjectWEAP
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EFF868, 1.6.318.0: SkyrimSE.exe + 0x2F99F50</summary>
			inline const std::uintptr_t UnarmedWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514923, 401061)) };
		}

		namespace TESSoulGem
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x237A90, 1.6.318.0: SkyrimSE.exe + 0x247E20</summary>
			inline const std::uintptr_t GetSoulLevelValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(17753, 18166)) };
		}

		namespace TurnUndeadEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163D7B8, 1.6.318.0: SkyrimSE.exe + 0x1733828</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258029, 206131)) };
		}

		namespace UI
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xEBE150, 1.6.318.0: SkyrimSE.exe + 0xF044A0</summary>
			inline const std::uintptr_t IsMenuOpen{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(79937, 82074)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8DA860, 1.6.318.0: SkyrimSE.exe + 0x909EE0</summary>
			inline const std::uintptr_t PlaySound{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(52054, 52939)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8AB180, 1.6.318.0: SkyrimSE.exe + 0x8DA780</summary>
			inline const std::uintptr_t ShowMessageBox{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(51420, 52269)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8DA3D0, 1.6.318.0: SkyrimSE.exe + 0x909870</summary>
			inline const std::uintptr_t ShowNotification{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(52050, 52933)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEB20, 1.6.318.0: SkyrimSE.exe + 0x1F59320</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514178, 400327)) };
		}

		namespace UIMessageQueue
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8D5710, 1.6.318.0: SkyrimSE.exe + 0x905CD0</summary>
			inline const std::uintptr_t AddInventoryUpdateMessage{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(51911, 52849)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1652D0, 1.6.318.0: SkyrimSE.exe + 0x16ECD0</summary>
			inline const std::uintptr_t AddMessage{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(13530, 13631)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EC0A70, 1.6.318.0: SkyrimSE.exe + 0x1F5B270</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514285, 400445)) };
		}

		namespace UserEvents
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F25250, 1.6.318.0: SkyrimSE.exe + 0x2FBF640</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(516458, 402638)) };
		}

		namespace ValueAndConditionsEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163DDB0, 1.6.318.0: SkyrimSE.exe + 0x1733E60</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258039, 206141)) };
		}

		namespace ValueModifierEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163DF38, 1.6.318.0: SkyrimSE.exe + 0x1733FE8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258043, 206143)) };
		}

		namespace VampireLordEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1638BA0, 1.6.318.0: SkyrimSE.exe + 0x172E9F8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(257697, 205883)) };
		}

		namespace VATS
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EC5C60, 1.6.318.0: SkyrimSE.exe + 0x2F603B0</summary>
			inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(514725, 400883)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x759420, 1.6.318.0: SkyrimSE.exe + 0x7873C0</summary>
			inline const std::uintptr_t GetPlayerUpdateMultiplier{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(43104, 44301)) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x759360, 1.6.318.0: SkyrimSE.exe + 0x787300</summary>
			inline const std::uintptr_t SetMagicTimeSlowdown{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(43103, 44300)) };
		}

		namespace WerewolfEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163E0F0, 1.6.318.0: SkyrimSE.exe + 0x17340F8</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258048, 206145)) };
		}

		namespace WerewolfFeedEffect
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x163E1C0, 1.6.318.0: SkyrimSE.exe + 0x1734200</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(258049, 206147)) };
		}

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3497408, 1.6.318.0: SkyrimSE.exe + 0x3531398</summary>
		inline const std::uintptr_t ThreadLocalStorageIndex{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(528600, 415542)) };
	}
}
