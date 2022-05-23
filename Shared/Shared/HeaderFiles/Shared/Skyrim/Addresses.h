#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace Skyrim::Addresses
{
	namespace AccumulatingValueModifierEffect
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636880, 1.6.318.0: SkyrimSE.exe + 0x172C5A0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(257549, 205803) };
	}

	namespace Actor
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F560, 1.6.318.0: SkyrimSE.exe + 0x655190</summary>
		inline const std::uintptr_t AddSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37771, 38716) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x621350, 1.6.318.0: SkyrimSE.exe + 0x6468C0</summary>
		inline const std::uintptr_t GetActorValueModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(37524, 38469) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62EBC0, 1.6.318.0: SkyrimSE.exe + 0x6546F0</summary>
		inline const std::uintptr_t GetMount{ Relocation::AddressLibrary::GetSingleton().GetAddress(37757, 38702) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F170, 1.6.318.0: SkyrimSE.exe + 0x654CC0</summary>
		inline const std::uintptr_t GetMovementActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(37762, 38707) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6348A0, 1.6.318.0: SkyrimSE.exe + 0x65A970</summary>
		inline const std::uintptr_t GetSoulLevel{ Relocation::AddressLibrary::GetSingleton().GetAddress(37862, 38817) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1656058, 1.6.318.0: SkyrimSE.exe + 0x174C360</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(260542, 207519) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6213D0, 1.6.318.0: SkyrimSE.exe + 0x646940</summary>
		inline const std::uintptr_t ModifyActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(37525, 38470) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x621590, 1.6.318.0: SkyrimSE.exe + 0x646B00</summary>
		inline const std::uintptr_t RemoveActorValueModifiers{ Relocation::AddressLibrary::GetSingleton().GetAddress(37527, 38476) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x632270, 1.6.318.0: SkyrimSE.exe + 0x658170</summary>
		inline const std::uintptr_t RevertSelectedSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37819, 38768) };
	}

	namespace ActorValueOwner
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C1700, 1.6.318.0: SkyrimSE.exe + 0x3D9160</summary>
		inline const std::uintptr_t GetDualCastingEffectiveness{ Relocation::AddressLibrary::GetSingleton().GetAddress(25931, 26518) };
	}

	namespace BGSDecalManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EC4320, 1.6.318.0: SkyrimSE.exe + 0x1F5EA88</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514414, 400561) };
	}

	namespace BGSEntryPointPerkEntry
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x32ECE0, 1.6.318.0: SkyrimSE.exe + 0x3444C0</summary>
		inline const std::uintptr_t HandleEntryPoint{ Relocation::AddressLibrary::GetSingleton().GetAddress(23073, 23526) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1598610, 1.6.318.0: SkyrimSE.exe + 0x1690078</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(241053, 195299) };
	}

	namespace BGSFootstepManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F27150, 1.6.318.0: SkyrimSE.exe + 0x2FC1C20</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(517045, 403553) };
	}

	namespace BGSImpactDataSet
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2C3490, 1.6.318.0: SkyrimSE.exe + 0x2D6460</summary>
		inline const std::uintptr_t GetImpactData{ Relocation::AddressLibrary::GetSingleton().GetAddress(20408, 20860) };
	}

	namespace BGSImpactManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x5A2930, 1.6.318.0: SkyrimSE.exe + 0x5C3AD0</summary>
		inline const std::uintptr_t PlaySound{ Relocation::AddressLibrary::GetSingleton().GetAddress(35317, 36212) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F003F0, 1.6.318.0: SkyrimSE.exe + 0x2F9AB00</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(515123, 401262) };
	}

	namespace BGSMaterialType
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2C73F0, 1.6.318.0: SkyrimSE.exe + 0x2DA4D0</summary>
		inline const std::uintptr_t GetMaterialTypeFromMaterialID{ Relocation::AddressLibrary::GetSingleton().GetAddress(20529, 20968) };
	}

	namespace BGSSaveGameBuffer
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x599DB0, 1.6.318.0: SkyrimSE.exe + 0x5BB190</summary>
		inline const std::uintptr_t Write{ Relocation::AddressLibrary::GetSingleton().GetAddress(35163, 36053) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x5999B0, 1.6.318.0: SkyrimSE.exe + 0x5BAD90</summary>
		inline const std::uintptr_t WriteFormID{ Relocation::AddressLibrary::GetSingleton().GetAddress(35158, 36048) };
	}

	namespace bhkNiCollisionObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1424F0, 1.6.318.0: SkyrimSE.exe + 0x2B20F0</summary>
		inline const std::uintptr_t GetRigidBody{ Relocation::AddressLibrary::GetSingleton().GetAddress(12784, 20014) };
	}

	namespace bhkWorld
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x154064C, 1.6.318.0: SkyrimSE.exe + 0x1637AA0</summary>
		inline const std::uintptr_t Scale{ Relocation::AddressLibrary::GetSingleton().GetAddress(231896, 188105) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1536BA0, 1.6.318.0: SkyrimSE.exe + 0x162DF48</summary>
		inline const std::uintptr_t ScaleInverse{ Relocation::AddressLibrary::GetSingleton().GetAddress(230692, 187407) };
	}

	namespace BSFixedString
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC28BF0, 1.6.318.0: SkyrimSE.exe + 0xC4E920</summary>
		inline const std::uintptr_t Initialize{ Relocation::AddressLibrary::GetSingleton().GetAddress(67819, 69161) };
	}

	namespace BSInputDeviceManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F257A8, 1.6.318.0: SkyrimSE.exe + 0x2FBFD88</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(516574, 402776) };
	}

	namespace BSPointerHandleManagerInterface
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EE670, 1.6.318.0: SkyrimSE.exe + 0x1FA210</summary>
		inline const std::uintptr_t GetHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(15967, 16212) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1329D0, 1.6.318.0: SkyrimSE.exe + 0x139160</summary>
		inline const std::uintptr_t GetSmartPointer{ Relocation::AddressLibrary::GetSingleton().GetAddress(12204, 12332) };
	}

	namespace BSReadWriteLock
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC072D0, 1.6.318.0: SkyrimSE.exe + 0xC2BEF0</summary>
		inline const std::uintptr_t ReadLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66976, 68233) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07590, 1.6.318.0: SkyrimSE.exe + 0xC2C1B0</summary>
		inline const std::uintptr_t ReadUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66982, 68239) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07350, 1.6.318.0: SkyrimSE.exe + 0xC2BF70</summary>
		inline const std::uintptr_t WriteLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66977, 68234) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC075A0, 1.6.318.0: SkyrimSE.exe + 0xC2C1C0</summary>
		inline const std::uintptr_t WriteUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66983, 68240) };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC29E80, 1.6.318.0: SkyrimSE.exe + 0xC4FCF0</summary>
			inline const std::uintptr_t Release{ Relocation::AddressLibrary::GetSingleton().GetAddress(67847, 69192) };
		}
	}

	namespace BSTArray
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8634C0, 1.6.318.0: SkyrimSE.exe + 0x890C80</summary>
		inline const std::uintptr_t AddEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(50282, 51207) };
	}

	namespace BSTEventSource
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D600, 1.6.318.0: SkyrimSE.exe + 0x588440</summary>
		inline const std::uintptr_t AddEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(14705, 35182) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D7C0, 1.6.318.0: SkyrimSE.exe + 0x43C490</summary>
		inline const std::uintptr_t RemoveEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(14707, 29117) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D270, 1.6.318.0: SkyrimSE.exe + 0x181D70</summary>
		inline const std::uintptr_t SendEvent{ Relocation::AddressLibrary::GetSingleton().GetAddress(14703, 13889) };
	}

	namespace Character
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x165E468, 1.6.318.0: SkyrimSE.exe + 0x1754098</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(261401, 207894) };
	}

	namespace CraftingSubMenus
	{
		namespace EnchantConstructMenu
		{
			namespace CreateEffectFunctor
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x16AFEB8, 1.6.318.0: SkyrimSE.exe + 0x17A2ED8</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(268497, 215178) };
			}
		}
	}

	namespace Effect
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xF8550, 1.6.318.0: SkyrimSE.exe + 0x1028E0</summary>
		inline const std::uintptr_t SetDuration{ Relocation::AddressLibrary::GetSingleton().GetAddress(10924, 11012) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xF8490, 1.6.318.0: SkyrimSE.exe + 0x102820</summary>
		inline const std::uintptr_t SetMagnitude{ Relocation::AddressLibrary::GetSingleton().GetAddress(10920, 11008) };
	}

	namespace EnchantmentItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C0DE0, 1.6.318.0: SkyrimSE.exe + 0x3D8810</summary>
		inline const std::uintptr_t ModifyPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(25910, 26493) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x15217E0, 1.6.318.0: SkyrimSE.exe + 0x161B920</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228570, 186389) };
	}

	namespace ExtraDataList
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x126650, 1.6.318.0: SkyrimSE.exe + 0x12D230</summary>
		inline const std::uintptr_t IsQuestItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(11913, 12052) };
	}

	namespace FindMaxMagnitudeVisitor
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636990, 1.6.318.0: SkyrimSE.exe + 0x172C6B0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(257550, 205805) };
	}

	namespace GameSettingCollection
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE5258, 1.6.318.0: SkyrimSE.exe + 0x1E79338</summary>
		inline const std::uintptr_t ActiveEffectConditionUpdateInterval{ Relocation::AddressLibrary::GetSingleton().GetAddress(506258, 376160) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0D88, 1.6.318.0: SkyrimSE.exe + 0x1E74E68</summary>
		inline const std::uintptr_t ArrowBowMinimumTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(505061, 374219) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0DE8, 1.6.318.0: SkyrimSE.exe + 0x1E74EC8</summary>
		inline const std::uintptr_t ArrowMinimumPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(505069, 374231) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0DD0, 1.6.318.0: SkyrimSE.exe + 0x1E74EB0</summary>
		inline const std::uintptr_t BowDrawTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(505067, 374228) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE34A0, 1.6.318.0: SkyrimSE.exe + 0x1E77580</summary>
		inline const std::uintptr_t PlayerMaximumResistance{ Relocation::AddressLibrary::GetSingleton().GetAddress(505721, 375300) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE18C8, 1.6.318.0: SkyrimSE.exe + 0x1E759A8</summary>
		inline const std::uintptr_t PowerAttackStaminaPenalty{ Relocation::AddressLibrary::GetSingleton().GetAddress(505283, 374565) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1898, 1.6.318.0: SkyrimSE.exe + 0x1E75978</summary>
		inline const std::uintptr_t StaminaAttackWeaponBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(505279, 374559) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE18B0, 1.6.318.0: SkyrimSE.exe + 0x1E75990</summary>
		inline const std::uintptr_t StaminaAttackWeaponMultiplier{ Relocation::AddressLibrary::GetSingleton().GetAddress(505281, 374562) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1580, 1.6.318.0: SkyrimSE.exe + 0x1E75660</summary>
		inline const std::uintptr_t StaminaBashBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(505217, 374460) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1598, 1.6.318.0: SkyrimSE.exe + 0x1E75678</summary>
		inline const std::uintptr_t StaminaPowerBashBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(505219, 374463) };
	}

	namespace hkReferencedObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C6730, 1.6.318.0: SkyrimSE.exe + 0x9EAF20</summary>
		inline const std::uintptr_t AddReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(56606, 57010) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C67F0, 1.6.318.0: SkyrimSE.exe + 0x9EAFE0</summary>
		inline const std::uintptr_t RemoveReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(56607, 57011) };
	}

	namespace INIPrefSettingCollection
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DB3230, 1.6.318.0: SkyrimSE.exe + 0x1E472A0</summary>
		inline const std::uintptr_t Decals{ Relocation::AddressLibrary::GetSingleton().GetAddress(501084, 359377) };
	}

	namespace INISettingCollection
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DB3260, 1.6.318.0: SkyrimSE.exe + 0x1E472D0</summary>
		inline const std::uintptr_t ForceAllDecals{ Relocation::AddressLibrary::GetSingleton().GetAddress(501087, 359382) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DEA0E8, 1.6.318.0: SkyrimSE.exe + 0x1E7E1C8</summary>
		inline const std::uintptr_t NumberActorsAllowedToMorph{ Relocation::AddressLibrary::GetSingleton().GetAddress(507579, 378641) };
	}

	namespace InitTESThread
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x164D900, 1.6.318.0: SkyrimSE.exe + 0x1744760</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(259694, 207137) };
	}

	namespace Inventory3DManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x16B3AC8, 1.6.318.0: SkyrimSE.exe + 0x17A6978</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(268974, 215473) };
	}

	namespace InventoryChanges
	{
		namespace FindBestSoulGemVisitor
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1658668, 1.6.318.0: SkyrimSE.exe + 0x174E2D0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(260831, 207680) };
		}
	}

	namespace InventoryEntryData
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D66E0, 1.6.318.0: SkyrimSE.exe + 0x1E1F60</summary>
		inline const std::uintptr_t GetValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(15757, 15995) };
	}

	namespace MagicItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x101A30, 1.6.318.0: SkyrimSE.exe + 0x10BCB0</summary>
		inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(11213, 11321) };
	}

	namespace NiAVObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xD41970, 1.6.318.0: SkyrimSE.exe + 0xD79A80</summary>
		inline const std::uintptr_t GetBoneFromName{ Relocation::AddressLibrary::GetSingleton().GetAddress(74481, 76207) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3A6140, 1.6.318.0: SkyrimSE.exe + 0x3BCAB0</summary>
		inline const std::uintptr_t GetCollisionObject{ Relocation::AddressLibrary::GetSingleton().GetAddress(25482, 26022) };
	}

	namespace NiMatrix33
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC544E0, 1.6.318.0: SkyrimSE.exe + 0xC7B890</summary>
		inline const std::uintptr_t EulerAnglesToRotationMatrixXYZ{ Relocation::AddressLibrary::GetSingleton().GetAddress(68874, 70221) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC55AE0, 1.6.318.0: SkyrimSE.exe + 0xC7CF10</summary>
		inline const std::uintptr_t EulerAnglesToRotationMatrixZXY{ Relocation::AddressLibrary::GetSingleton().GetAddress(68886, 70233) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC53EB0, 1.6.318.0: SkyrimSE.exe + 0xC7B240</summary>
		inline const std::uintptr_t RotationMatrixToEulerAnglesXYZ{ Relocation::AddressLibrary::GetSingleton().GetAddress(68868, 70215) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC559E0, 1.6.318.0: SkyrimSE.exe + 0xC7CE10</summary>
		inline const std::uintptr_t RotationMatrixToEulerAnglesZXY{ Relocation::AddressLibrary::GetSingleton().GetAddress(68885, 70232) };
	}

	namespace NiNode
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1AFB10, 1.6.318.0: SkyrimSE.exe + 0x1BB530</summary>
		inline const std::uintptr_t ApplyDecal{ Relocation::AddressLibrary::GetSingleton().GetAddress(15060, 15234) };
	}

	namespace PersistentFormManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEAE8, 1.6.318.0: SkyrimSE.exe + 0x1F592E8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514172, 400320) };
	}

	namespace PlayerCharacter
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1664030, 1.6.318.0: SkyrimSE.exe + 0x175A500</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(261920, 208048) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26EF8, 1.6.318.0: SkyrimSE.exe + 0x2FC19C8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(517014, 403521) };
	}

	namespace ScriptEventSourceHolder
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x186790, 1.6.318.0: SkyrimSE.exe + 0x1941C0</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(14108, 14298) };
	}

	namespace ScrollItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1524FF0, 1.6.318.0: SkyrimSE.exe + 0x161F150</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228867, 186591) };
	}

	namespace Sky
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x177790, 1.6.318.0: SkyrimSE.exe + 0x1818D0</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(13789, 13878) };
	}

	namespace SpellItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1525720, 1.6.318.0: SkyrimSE.exe + 0x161F8A8</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228888, 186619) };
	}

	namespace TES
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x155090, 1.6.318.0: SkyrimSE.exe + 0x15E310</summary>
		inline const std::uintptr_t GetCell{ Relocation::AddressLibrary::GetSingleton().GetAddress(13177, 13322) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x156CD0, 1.6.318.0: SkyrimSE.exe + 0x160030</summary>
		inline const std::uintptr_t GetMaterialID{ Relocation::AddressLibrary::GetSingleton().GetAddress(13203, 13349) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26B20, 1.6.318.0: SkyrimSE.exe + 0x2FC1658</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(516923, 403450) };
	}

	namespace TESBoundObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1A1730, 1.6.318.0: SkyrimSE.exe + 0x1ACFE0</summary>
		inline const std::uintptr_t GetWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(14809, 14988) };
	}

	namespace TESCondition
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x4447A0, 1.6.318.0: SkyrimSE.exe + 0x45D940</summary>
		inline const std::uintptr_t IsTrue{ Relocation::AddressLibrary::GetSingleton().GetAddress(29074, 29888) };
	}

	namespace TESDataHandler
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x194230, 1.6.318.0: SkyrimSE.exe + 0x19F110</summary>
		inline const std::uintptr_t GetForm{ Relocation::AddressLibrary::GetSingleton().GetAddress(14461, 14617) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBE428, 1.6.318.0: SkyrimSE.exe + 0x1F58C28</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514141, 400269) };
	}

	namespace TESForm
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x190D50, 1.6.318.0: SkyrimSE.exe + 0x19B880</summary>
		inline const std::uintptr_t GetEnchantment{ Relocation::AddressLibrary::GetSingleton().GetAddress(14411, 14563) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x196E10, 1.6.318.0: SkyrimSE.exe + 0x1A1C90</summary>
		inline const std::uintptr_t GetFormName{ Relocation::AddressLibrary::GetSingleton().GetAddress(14548, 14720) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x190DC0, 1.6.318.0: SkyrimSE.exe + 0x19B8F0</summary>
		inline const std::uintptr_t GetMaximumCharge{ Relocation::AddressLibrary::GetSingleton().GetAddress(14412, 14564) };
	}

	namespace TESFurniture
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1553E58, 1.6.318.0: SkyrimSE.exe + 0x164B400</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(233784, 189309) };
	}

	namespace TESObjectCELL
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x44B9A0, 1.6.318.0: SkyrimSE.exe + 0x465370</summary>
		inline const std::uintptr_t CreateTemporaryEffectParticle{ Relocation::AddressLibrary::GetSingleton().GetAddress(29218, 30071) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2654C0, 1.6.318.0: SkyrimSE.exe + 0x2772D0</summary>
		inline const std::uintptr_t GetHavokWorld{ Relocation::AddressLibrary::GetSingleton().GetAddress(18536, 18995) };
	}

	namespace TESObjectREFR
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D8E40, 1.6.318.0: SkyrimSE.exe + 0x1E4880</summary>
		inline const std::uintptr_t GetInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(15802, 16040) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2945E0, 1.6.318.0: SkyrimSE.exe + 0x2A6CB0</summary>
		inline const std::uintptr_t GetReferenceFrom3D{ Relocation::AddressLibrary::GetSingleton().GetAddress(19323, 19750) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x296460, 1.6.318.0: SkyrimSE.exe + 0x2A8B00</summary>
		inline const std::uintptr_t GetReferenceName{ Relocation::AddressLibrary::GetSingleton().GetAddress(19355, 19782) };
	}

	namespace TESObjectWEAP
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EFF868, 1.6.318.0: SkyrimSE.exe + 0x2F99F50</summary>
		inline const std::uintptr_t UnarmedWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(514923, 401061) };
	}

	namespace TESSoulGem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x237A90, 1.6.318.0: SkyrimSE.exe + 0x247E20</summary>
		inline const std::uintptr_t GetSoulLevelValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(17753, 18166) };
	}

	namespace UI
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8DA3D0, 1.6.318.0: SkyrimSE.exe + 0x909870</summary>
		inline const std::uintptr_t Notification{ Relocation::AddressLibrary::GetSingleton().GetAddress(52050, 52933) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEB20, 1.6.318.0: SkyrimSE.exe + 0x1F59320</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514178, 400327) };
	}
}
