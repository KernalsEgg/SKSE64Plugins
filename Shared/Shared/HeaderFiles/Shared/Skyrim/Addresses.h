#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace Skyrim::Addresses
{
	namespace AccumulatingValueModifierEffect
	{
		/// <summary>SkyrimSE.exe + 0x1636880</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(257549) };
	}

	namespace Actor
	{
		/// <summary>SkyrimSE.exe + 0x62F560</summary>
		inline const std::uintptr_t AddSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37771) };

		/// <summary>SkyrimSE.exe + 0x621350</summary>
		inline const std::uintptr_t GetActorValueModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(37524) };

		/// <summary>SkyrimSE.exe + 0x62EBC0</summary>
		inline const std::uintptr_t GetMount{ Relocation::AddressLibrary::GetSingleton().GetAddress(37757) };

		/// <summary>SkyrimSE.exe + 0x62F170</summary>
		inline const std::uintptr_t GetMovementActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(37762) };

		/// <summary>SkyrimSE.exe + 0x6348A0</summary>
		inline const std::uintptr_t GetSoulLevel{ Relocation::AddressLibrary::GetSingleton().GetAddress(37862) };

		/// <summary>SkyrimSE.exe + 0x1656058</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(260542) };

		/// <summary>SkyrimSE.exe + 0x6213D0</summary>
		inline const std::uintptr_t ModifyActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(37525) };

		/// <summary>SkyrimSE.exe + 0x621590</summary>
		inline const std::uintptr_t RemoveActorValueModifiers{ Relocation::AddressLibrary::GetSingleton().GetAddress(37527) };

		/// <summary>SkyrimSE.exe + 0x632270</summary>
		inline const std::uintptr_t RevertSelectedSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37819) };
	}

	namespace BGSEntryPointPerkEntry
	{
		/// <summary>SkyrimSE.exe + 0x32ECE0</summary>
		inline const std::uintptr_t HandleEntryPoint{ Relocation::AddressLibrary::GetSingleton().GetAddress(23073) };

		/// <summary>SkyrimSE.exe + 0x1598610</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(241053) };
	}

	namespace BSFixedString
	{
		/// <summary>SkyrimSE.exe + 0xC28BF0</summary>
		inline const std::uintptr_t Initialize{ Relocation::AddressLibrary::GetSingleton().GetAddress(67819) };
	}

	namespace BSPointerHandleManagerInterface
	{
		/// <summary>SkyrimSE.exe + 0x1EE670</summary>
		inline const std::uintptr_t GetHandle{ Relocation::AddressLibrary::GetSingleton().GetAddress(15967) };

		/// <summary>SkyrimSE.exe + 0x1329D0</summary>
		inline const std::uintptr_t GetSmartPointer{ Relocation::AddressLibrary::GetSingleton().GetAddress(12204) };
	}

	namespace BSReadWriteLock
	{
		/// <summary>SkyrimSE.exe + 0xC072D0</summary>
		inline const std::uintptr_t ReadLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66976) };

		/// <summary>SkyrimSE.exe + 0xC07590</summary>
		inline const std::uintptr_t ReadUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66982) };

		/// <summary>SkyrimSE.exe + 0xC07350</summary>
		inline const std::uintptr_t WriteLock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66977) };

		/// <summary>SkyrimSE.exe + 0xC075A0</summary>
		inline const std::uintptr_t WriteUnlock{ Relocation::AddressLibrary::GetSingleton().GetAddress(66983) };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			/// <summary>SkyrimSE.exe + 0xC29E80</summary>
			inline const std::uintptr_t Release{ Relocation::AddressLibrary::GetSingleton().GetAddress(67847) };
		}
	}

	namespace BSTArray
	{
		/// <summary>SkyrimSE.exe + 0x8634C0</summary>
		inline const std::uintptr_t AddEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(50282) };
	}

	namespace BSTEventSource
	{
		/// <summary>SkyrimSE.exe + 0x19D600</summary>
		inline const std::uintptr_t AddEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(14705) };

		/// <summary>SkyrimSE.exe + 0x19D7C0</summary>
		inline const std::uintptr_t RemoveEventSink{ Relocation::AddressLibrary::GetSingleton().GetAddress(14707) };

		/// <summary>SkyrimSE.exe + 0x19D270</summary>
		inline const std::uintptr_t SendEvent{ Relocation::AddressLibrary::GetSingleton().GetAddress(14703) };
	}

	namespace Character
	{
		/// <summary>SkyrimSE.exe + 0x165E468</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(261401) };
	}

	namespace CraftingSubMenus
	{
		namespace EnchantConstructMenu
		{
			namespace CreateEffectFunctor
			{
				/// <summary>SkyrimSE.exe + 0x16AFEB8</summary>
				inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(268497) };
			}
		}
	}

	namespace Effect
	{
		/// <summary>SkyrimSE.exe + 0xF8550</summary>
		inline const std::uintptr_t SetDuration{ Relocation::AddressLibrary::GetSingleton().GetAddress(10924) };

		/// <summary>SkyrimSE.exe + 0xF8490</summary>
		inline const std::uintptr_t SetMagnitude{ Relocation::AddressLibrary::GetSingleton().GetAddress(10920) };
	}

	namespace EnchantmentItem
	{
		/// <summary>SkyrimSE.exe + 0x3C0DE0</summary>
		inline const std::uintptr_t ModifyPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(25910) };

		/// <summary>SkyrimSE.exe + 0x15217E0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228570) };
	}

	namespace ExtraDataList
	{
		/// <summary>SkyrimSE.exe + 0x126650</summary>
		inline const std::uintptr_t IsQuestItem{ Relocation::AddressLibrary::GetSingleton().GetAddress(11913) };
	}

	namespace FindMaxMagnitudeVisitor
	{
		/// <summary>SkyrimSE.exe + 0x1636990</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(257550) };
	}

	namespace GameSettingCollection
	{
		/// <summary>SkyrimSE.exe + 0x1DE5258</summary>
		inline const std::uintptr_t ActiveEffectConditionUpdateInterval{ Relocation::AddressLibrary::GetSingleton().GetAddress(506258) };

		/// <summary>SkyrimSE.exe + 0x1DE0D88</summary>
		inline const std::uintptr_t ArrowBowMinimumTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(505061) };

		/// <summary>SkyrimSE.exe + 0x1DE0DE8</summary>
		inline const std::uintptr_t ArrowMinimumPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(505069) };

		/// <summary>SkyrimSE.exe + 0x1DE0DD0</summary>
		inline const std::uintptr_t BowDrawTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(505067) };

		/// <summary>SkyrimSE.exe + 0x1DE40B8</summary>
		inline const std::uintptr_t DifficultyMultiplierHealthByPlayer{ Relocation::AddressLibrary::GetSingleton().GetAddress(505952) };

		/// <summary>SkyrimSE.exe + 0x1DE4088</summary>
		inline const std::uintptr_t DifficultyMultiplierHealthToPlayer{ Relocation::AddressLibrary::GetSingleton().GetAddress(505951) };

		/// <summary>SkyrimSE.exe + 0x1DE34A0</summary>
		inline const std::uintptr_t PlayerMaximumResistance{ Relocation::AddressLibrary::GetSingleton().GetAddress(505721) };
	}

	namespace hkReferencedObject
	{
		/// <summary>SkyrimSE.exe + 0x9C6730</summary>
		inline const std::uintptr_t AddReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(56606) };

		/// <summary>SkyrimSE.exe + 0x9C67F0</summary>
		inline const std::uintptr_t RemoveReference{ Relocation::AddressLibrary::GetSingleton().GetAddress(56607) };
	}

	namespace INISettingCollection
	{
		/// <summary>SkyrimSE.exe + 0x1DEA0E8</summary>
		inline const std::uintptr_t NumberActorsAllowedToMorph{ Relocation::AddressLibrary::GetSingleton().GetAddress(507579) };
	}

	namespace InitTESThread
	{
		/// <summary>SkyrimSE.exe + 0x164D900</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(259694) };
	}

	namespace InventoryChanges
	{
		namespace FindBestSoulGemVisitor
		{
			/// <summary>SkyrimSE.exe + 0x1658668</summary>
			inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(260831) };
		}
	}

	namespace InventoryEntryData
	{
		/// <summary>SkyrimSE.exe + 0x1D66E0</summary>
		inline const std::uintptr_t GetValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(15757) };
	}

	namespace MagicItem
	{
		/// <summary>SkyrimSE.exe + 0x101A30</summary>
		inline const std::uintptr_t GetCost{ Relocation::AddressLibrary::GetSingleton().GetAddress(11213) };
	}

	namespace PersistentFormManager
	{
		/// <summary>SkyrimSE.exe + 0x1EBEAE8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514172) };
	}

	namespace PlayerCharacter
	{
		/// <summary>SkyrimSE.exe + 0x1664030</summary>
		inline const std::uintptr_t MagicTargetVirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(261920) };

		/// <summary>SkyrimSE.exe + 0x2F26EF8</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(517014) };
	}

	namespace ScriptEventSourceHolder
	{
		/// <summary>SkyrimSE.exe + 0x186790</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(14108) };
	}

	namespace ScrollItem
	{
		/// <summary>SkyrimSE.exe + 0x1524FF0</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228867) };
	}

	namespace Sky
	{
		/// <summary>SkyrimSE.exe + 0x177790</summary>
		inline const std::uintptr_t GetSingleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(13789) };
	}

	namespace SpellItem
	{
		/// <summary>SkyrimSE.exe + 0x1525720</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(228888) };
	}

	namespace TES
	{
		/// <summary>SkyrimSE.exe + 0x2F26B20</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(516923) };
	}

	namespace TESBoundObject
	{
		/// <summary>SkyrimSE.exe + 0x1A1730</summary>
		inline const std::uintptr_t GetWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(14809) };
	}

	namespace TESCondition
	{
		/// <summary>SkyrimSE.exe + 0x4447A0</summary>
		inline const std::uintptr_t IsTrue{ Relocation::AddressLibrary::GetSingleton().GetAddress(29074) };
	}

	namespace TESDataHandler
	{
		/// <summary>SkyrimSE.exe + 0x194230</summary>
		inline const std::uintptr_t GetForm{ Relocation::AddressLibrary::GetSingleton().GetAddress(14461) };

		/// <summary>SkyrimSE.exe + 0x1EBE428</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514141) };
	}

	namespace TESForm
	{
		/// <summary>SkyrimSE.exe + 0x190D50</summary>
		inline const std::uintptr_t GetEnchantment{ Relocation::AddressLibrary::GetSingleton().GetAddress(14411) };

		/// <summary>SkyrimSE.exe + 0x196E10</summary>
		inline const std::uintptr_t GetFormName{ Relocation::AddressLibrary::GetSingleton().GetAddress(14548) };

		/// <summary>SkyrimSE.exe + 0x190DC0</summary>
		inline const std::uintptr_t GetMaximumCharge{ Relocation::AddressLibrary::GetSingleton().GetAddress(14412) };
	}

	namespace TESFurniture
	{
		/// <summary>SkyrimSE.exe + 0x1553E58</summary>
		inline const std::uintptr_t VirtualFunctionTable{ Relocation::AddressLibrary::GetSingleton().GetAddress(233784) };
	}

	namespace TESObjectREFR
	{
		/// <summary>SkyrimSE.exe + 0x1D8E40</summary>
		inline const std::uintptr_t GetInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(15802) };

		/// <summary>SkyrimSE.exe + 0x296460</summary>
		inline const std::uintptr_t GetReferenceName{ Relocation::AddressLibrary::GetSingleton().GetAddress(19355) };
	}

	namespace TESSoulGem
	{
		/// <summary>SkyrimSE.exe + 0x237A90</summary>
		inline const std::uintptr_t GetSoulLevelValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(17753) };
	}

	namespace UI
	{
		/// <summary>SkyrimSE.exe + 0x8DA3D0</summary>
		inline const std::uintptr_t Notification{ Relocation::AddressLibrary::GetSingleton().GetAddress(52050) };

		/// <summary>SkyrimSE.exe + 0x1EBEB20</summary>
		inline const std::uintptr_t Singleton{ Relocation::AddressLibrary::GetSingleton().GetAddress(514178) };
	}
}
