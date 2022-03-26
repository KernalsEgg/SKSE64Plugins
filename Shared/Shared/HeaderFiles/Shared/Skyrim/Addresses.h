#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace Skyrim::Addresses
{
	namespace AccumulatingValueModifierEffect
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636880 (257549), 1.6.318.0: SkyrimSE.exe + 0x172C5A0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(205803) };
	}

	namespace Actor
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F560 (37771), 1.6.318.0: SkyrimSE.exe + 0x655190</summary>
		inline const std::uintptr_t AddSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38716) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x621350 (37524), 1.6.318.0: SkyrimSE.exe + 0x6468C0</summary>
		inline const std::uintptr_t GetActorValueModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(38469) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62EBC0 (37757), 1.6.318.0: SkyrimSE.exe + 0x6546F0</summary>
		inline const std::uintptr_t GetMount{ Relocation::AddressLibrary::GetSingleton().GetAddress(38702) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x62F170 (37762), 1.6.318.0: SkyrimSE.exe + 0x654CC0</summary>
		inline const std::uintptr_t GetMovementActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(38707) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6348A0 (37862), 1.6.318.0: SkyrimSE.exe + 0x65A970</summary>
		inline const std::uintptr_t GetSoulLevel{ Relocation::AddressLibrary::GetSingleton().GetAddress(38817) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1656058 (260542), 1.6.318.0: SkyrimSE.exe + 0x174C360</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(207519) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6213D0 (37525), 1.6.318.0: SkyrimSE.exe + 0x646940</summary>
		inline const std::uintptr_t ModifyActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(38470) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x621590 (37527), 1.6.318.0: SkyrimSE.exe + 0x646B00</summary>
		inline const std::uintptr_t RemoveActorValueModifiers{ Relocation::AddressLibrary::GetSingleton().GetAddress(38476) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x632270 (37819), 1.6.318.0: SkyrimSE.exe + 0x658170</summary>
		inline const std::uintptr_t RevertSelectedSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38768) };
	}

	namespace ActorValueOwner
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C1700 (25931), 1.6.318.0: SkyrimSE.exe + 0x3D9160</summary>
		inline const std::uintptr_t GetDualCastingEffectiveness{ Relocation::AddressLibrary::GetSingleton().GetAddress(26518) };
	}

	namespace BGSEntryPointPerkEntry
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x32ECE0 (23073), 1.6.318.0: SkyrimSE.exe + 0x3444C0</summary>
		inline const std::uintptr_t HandleEntryPoint{ Relocation::AddressLibrary::GetSingleton().GetAddress(23526) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1598610 (241053), 1.6.318.0: SkyrimSE.exe + 0x1690078</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(195299) };
	}

	namespace BGSSaveGameBuffer
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x599DB0 (35163), 1.6.318.0: SkyrimSE.exe + 0x5BB190</summary>
		inline const std::uintptr_t Write{ Relocation::AddressLibrary::GetSingleton().GetAddress(36053) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x5999B0 (35158), 1.6.318.0: SkyrimSE.exe + 0x5BAD90</summary>
		inline const std::uintptr_t WriteFormID{ Relocation::AddressLibrary::GetSingleton().GetAddress(36048) };
	}

	namespace BSFixedString
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC28BF0 (67819), 1.6.318.0: SkyrimSE.exe + 0xC4E920</summary>
		inline const std::uintptr_t Initialize{ Relocation::AddressLibrary::GetSingleton().GetAddress(69161) };
	}

	namespace BSPointerHandleManagerInterface
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EE670 (15967), 1.6.318.0: SkyrimSE.exe + 0x1FA210</summary>
		inline const std::uintptr_t GetHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(16212) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1329D0 (12204), 1.6.318.0: SkyrimSE.exe + 0x139160</summary>
		inline const std::uintptr_t GetSmartPointer{ Relocation::AddressLibrary::GetSingleton().GetAddress(12332) };
	}

	namespace BSReadWriteLock
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC072D0 (66976), 1.6.318.0: SkyrimSE.exe + 0xC2BEF0</summary>
		inline const std::uintptr_t ReadLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(68233) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07590 (66982), 1.6.318.0: SkyrimSE.exe + 0xC2C1B0</summary>
		inline const std::uintptr_t ReadUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(68239) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC07350 (66977), 1.6.318.0: SkyrimSE.exe + 0xC2BF70</summary>
		inline const std::uintptr_t WriteLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(68234) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xC075A0 (66983), 1.6.318.0: SkyrimSE.exe + 0xC2C1C0</summary>
		inline const std::uintptr_t WriteUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(68240) };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0xC29E80 (67847), 1.6.318.0: SkyrimSE.exe + 0xC4FCF0</summary>
			inline const std::uintptr_t Release{ Relocation::AddressLibrary::GetSingleton().GetAddress(69192) };
		}
	}

	namespace BSTArray
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8634C0 (50282), 1.6.318.0: SkyrimSE.exe + 0x890C80</summary>
		inline const std::uintptr_t AddEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(51207) };
	}

	namespace BSTEventSource
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D600 (14705), 1.6.318.0: SkyrimSE.exe + 0x588440</summary>
		inline const std::uintptr_t AddEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(35182) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D7C0 (14707), 1.6.318.0: SkyrimSE.exe + 0x43C490</summary>
		inline const std::uintptr_t RemoveEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(29117) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x19D270 (14703), 1.6.318.0: SkyrimSE.exe + 0x181D70</summary>
		inline const std::uintptr_t SendEvent{ Relocation::AddressLibrary::GetSingleton().GetAddress(13889) };
	}

	namespace Character
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x165E468 (261401), 1.6.318.0: SkyrimSE.exe + 0x1754098</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(207894) };
	}

	namespace CraftingSubMenus
	{
		namespace EnchantConstructMenu
		{
			namespace CreateEffectFunctor
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x16AFEB8 (268497), 1.6.318.0: SkyrimSE.exe + 0x17A2ED8</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(215178) };
			}
		}
	}

	namespace Effect
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0xF8550 (10924), 1.6.318.0: SkyrimSE.exe + 0x1028E0</summary>
		inline const std::uintptr_t SetDuration{ Relocation::AddressLibrary::GetSingleton().GetAddress(11012) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0xF8490 (10920), 1.6.318.0: SkyrimSE.exe + 0x102820</summary>
		inline const std::uintptr_t SetMagnitude{ Relocation::AddressLibrary::GetSingleton().GetAddress(11008) };
	}

	namespace EnchantmentItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x3C0DE0 (25910), 1.6.318.0: SkyrimSE.exe + 0x3D8810</summary>
		inline const std::uintptr_t ModifyPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(26493) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x15217E0 (228570), 1.6.318.0: SkyrimSE.exe + 0x161B920</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(186389) };
	}

	namespace ExtraDataList
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x126650 (11913), 1.6.318.0: SkyrimSE.exe + 0x12D230</summary>
		inline const std::uintptr_t IsQuestItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(12052) };
	}

	namespace FindMaxMagnitudeVisitor
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1636990 (257550), 1.6.318.0: SkyrimSE.exe + 0x172C6B0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(205805) };
	}

	namespace GameSettingCollection
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE5258 (506258), 1.6.318.0: SkyrimSE.exe + 0x1E79338</summary>
		inline const std::uintptr_t ActiveEffectConditionUpdateInterval{ Relocation::AddressLibrary::GetSingleton().GetAddress(376160) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0D88 (505061), 1.6.318.0: SkyrimSE.exe + 0x1E74E68</summary>
		inline const std::uintptr_t ArrowBowMinimumTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(374219) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0DE8 (505069), 1.6.318.0: SkyrimSE.exe + 0x1E74EC8</summary>
		inline const std::uintptr_t ArrowMinimumPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(374231) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE0DD0 (505067), 1.6.318.0: SkyrimSE.exe + 0x1E74EB0</summary>
		inline const std::uintptr_t BowDrawTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(374228) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE34A0 (505721), 1.6.318.0: SkyrimSE.exe + 0x1E77580</summary>
		inline const std::uintptr_t PlayerMaximumResistance{ Relocation::AddressLibrary::GetSingleton().GetAddress(375300) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE18C8 (505283), 1.6.318.0: SkyrimSE.exe + 0x1E759A8</summary>
		inline const std::uintptr_t PowerAttackStaminaPenalty{ Relocation::AddressLibrary::GetSingleton().GetAddress(374565) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1898 (505279), 1.6.318.0: SkyrimSE.exe + 0x1E75978</summary>
		inline const std::uintptr_t StaminaAttackWeaponBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(374559) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE18B0 (505281), 1.6.318.0: SkyrimSE.exe + 0x1E75990</summary>
		inline const std::uintptr_t StaminaAttackWeaponMultiplier{ Relocation::AddressLibrary::GetSingleton().GetAddress(374562) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1580 (505217), 1.6.318.0: SkyrimSE.exe + 0x1E75660</summary>
		inline const std::uintptr_t StaminaBashBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(374460) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DE1598 (505219), 1.6.318.0: SkyrimSE.exe + 0x1E75678</summary>
		inline const std::uintptr_t StaminaPowerBashBase{ Relocation::AddressLibrary::GetSingleton().GetAddress(374463) };
	}

	namespace hkReferencedObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C6730 (56606), 1.6.318.0: SkyrimSE.exe + 0x9EAF20</summary>
		inline const std::uintptr_t AddReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(57010) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x9C67F0 (56607), 1.6.318.0: SkyrimSE.exe + 0x9EAFE0</summary>
		inline const std::uintptr_t RemoveReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(57011) };
	}

	namespace INISettingCollection
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DEA0E8 (507579), 1.6.318.0: SkyrimSE.exe + 0x1E7E1C8</summary>
		inline const std::uintptr_t NumberActorsAllowedToMorph{ Relocation::AddressLibrary::GetSingleton().GetAddress(378641) };
	}

	namespace InitTESThread
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x164D900 (259694), 1.6.318.0: SkyrimSE.exe + 0x1744760</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(207137) };
	}

	namespace InventoryChanges
	{
		namespace FindBestSoulGemVisitor
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1658668 (260831), 1.6.318.0: SkyrimSE.exe + 0x174E2D0</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(207680) };
		}
	}

	namespace InventoryEntryData
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D66E0 (15757), 1.6.318.0: SkyrimSE.exe + 0x1E1F60</summary>
		inline const std::uintptr_t GetValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(15995) };
	}

	namespace MagicItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x101A30 (11213), 1.6.318.0: SkyrimSE.exe + 0x10BCB0</summary>
		inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(11321) };
	}

	namespace PersistentFormManager
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEAE8 (514172), 1.6.318.0: SkyrimSE.exe + 0x1F592E8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(400320) };
	}

	namespace PlayerCharacter
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1664030 (261920), 1.6.318.0: SkyrimSE.exe + 0x175A500</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(208048) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26EF8 (517014), 1.6.318.0: SkyrimSE.exe + 0x2FC19C8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(403521) };
	}

	namespace ScriptEventSourceHolder
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x186790 (14108), 1.6.318.0: SkyrimSE.exe + 0x1941C0</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(14298) };
	}

	namespace ScrollItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1524FF0 (228867), 1.6.318.0: SkyrimSE.exe + 0x161F150</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(186591) };
	}

	namespace Sky
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x177790 (13789), 1.6.318.0: SkyrimSE.exe + 0x1818D0</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(13878) };
	}

	namespace SpellItem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1525720 (228888), 1.6.318.0: SkyrimSE.exe + 0x161F8A8</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(186619) };
	}

	namespace TES
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F26B20 (516923), 1.6.318.0: SkyrimSE.exe + 0x2FC1658</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(403450) };
	}

	namespace TESBoundObject
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1A1730 (14809), 1.6.318.0: SkyrimSE.exe + 0x1ACFE0</summary>
		inline const std::uintptr_t GetWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(14988) };
	}

	namespace TESCondition
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x4447A0 (29074), 1.6.318.0: SkyrimSE.exe + 0x45D940</summary>
		inline const std::uintptr_t IsTrue{ Relocation::AddressLibrary::GetSingleton().GetAddress(29888) };
	}

	namespace TESDataHandler
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x194230 (14461), 1.6.318.0: SkyrimSE.exe + 0x19F110</summary>
		inline const std::uintptr_t GetForm{ Relocation::AddressLibrary::GetSingleton().GetAddress(14617) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBE428 (514141), 1.6.318.0: SkyrimSE.exe + 0x1F58C28</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(400269) };
	}

	namespace TESForm
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x190D50 (14411), 1.6.318.0: SkyrimSE.exe + 0x19B880</summary>
		inline const std::uintptr_t GetEnchantment{ Relocation::AddressLibrary::GetSingleton().GetAddress(14563) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x196E10 (14548), 1.6.318.0: SkyrimSE.exe + 0x1A1C90</summary>
		inline const std::uintptr_t GetFormName{ Relocation::AddressLibrary::GetSingleton().GetAddress(14720) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x190DC0 (14412), 1.6.318.0: SkyrimSE.exe + 0x19B8F0</summary>
		inline const std::uintptr_t GetMaximumCharge{ Relocation::AddressLibrary::GetSingleton().GetAddress(14564) };
	}

	namespace TESFurniture
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1553E58 (233784), 1.6.318.0: SkyrimSE.exe + 0x164B400</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(189309) };
	}

	namespace TESObjectREFR
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1D8E40 (15802), 1.6.318.0: SkyrimSE.exe + 0x1E4880</summary>
		inline const std::uintptr_t GetInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(16040) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x296460 (19355), 1.6.318.0: SkyrimSE.exe + 0x2A8B00</summary>
		inline const std::uintptr_t GetReferenceName{ Relocation::AddressLibrary::GetSingleton().GetAddress(19782) };
	}

	namespace TESObjectWEAP
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x2EFF868 (514923), 1.6.318.0: SkyrimSE.exe + 0x2F99F50</summary>
		inline const std::uintptr_t UnarmedWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(401061) };
	}

	namespace TESSoulGem
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x237A90 (17753), 1.6.318.0: SkyrimSE.exe + 0x247E20</summary>
		inline const std::uintptr_t GetSoulLevelValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(18166) };
	}

	namespace UI
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8DA3D0 (52050), 1.6.318.0: SkyrimSE.exe + 0x909870</summary>
		inline const std::uintptr_t Notification{ Relocation::AddressLibrary::GetSingleton().GetAddress(52933) };

		/// <summary>1.5.97.0: SkyrimSE.exe + 0x1EBEB20 (514178), 1.6.318.0: SkyrimSE.exe + 0x1F59320</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(400327) };
	}
}
