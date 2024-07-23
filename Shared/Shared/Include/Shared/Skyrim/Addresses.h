#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	namespace Addresses
	{
		namespace AbsorbEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace AccumulatingValueModifierEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ActiveEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ActiveEffectFactory
		{
			std::uintptr_t CheckTargetFunctions();
			std::uintptr_t InstantiateFunctions();
		}

		namespace Actor
		{
			namespace MagicTarget
			{
				std::uintptr_t VirtualFunctionTable();
			}

			std::uintptr_t AddSpellItem();
			std::uintptr_t AdjustHealthDamageToDifficulty();
			std::uintptr_t CanBeKilledBy();
			std::uintptr_t GetActorValueModifier();
			std::uintptr_t GetArmorRating();
			std::uintptr_t GetControllingActor();
			std::uintptr_t GetLineOfSightLocation();
			std::uintptr_t GetSoulLevel();
			std::uintptr_t GetWeaponDamage();
			std::uintptr_t HandleActorValueModified();
			std::uintptr_t IsActorInLineOfSight();
			std::uintptr_t IsPositionInLineOfSight();
			std::uintptr_t IsReferenceInLineOfSight();
			std::uintptr_t ModifyActorValue();
			std::uintptr_t RemoveActorValueModifiers();
			std::uintptr_t RemoveBasePerks();
			std::uintptr_t SetSelectedMagicItem();
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ActorEquipManager
		{
			std::uintptr_t EquipBoundObject();
			std::uintptr_t Singleton();
			std::uintptr_t UnequipBoundObject();
		}

		namespace ActorValueInfo
		{
			std::uintptr_t GetSingleton();
		}

		namespace ActorValueOwner
		{
			std::uintptr_t GetDualCastingEffectiveness();
		}

		namespace AITimer
		{
			std::uintptr_t Timer();
		}

		namespace BanishEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace BGSCreatedObjectManager
		{
			std::uintptr_t Singleton();
			std::uintptr_t DecrementReference();
		}

		namespace BGSDecalManager
		{
			std::uintptr_t Singleton();
		}

		namespace BGSDefaultObjectManager
		{
			std::uintptr_t GetSingleton();
		}

		namespace BGSEntryPoint
		{
			std::uintptr_t EntryPoints();
			std::uintptr_t HandleEntryPoint();
		}

		namespace BGSEntryPointFunction
		{
			std::uintptr_t EntryPointFunctionArgumentCount();
			std::uintptr_t ExecuteFunction();
		}

		namespace BGSEntryPointPerkEntry
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace BGSFootstepManager
		{
			std::uintptr_t Singleton();
		}

		namespace BGSImpactDataSet
		{
			std::uintptr_t GetImpactData();
		}

		namespace BGSImpactManager
		{
			std::uintptr_t PlaySound();
			std::uintptr_t Singleton();
		}

		namespace BGSMaterialType
		{
			std::uintptr_t GetMaterialTypeFromMaterialID();
		}

		namespace BGSPerk
		{
			std::uintptr_t ApplyPerk();
		}

		namespace BGSSaveGameBuffer
		{
			std::uintptr_t SaveData();
			std::uintptr_t SaveFormID();
		}

		namespace bhkNiCollisionObject
		{
			std::uintptr_t GetRigidBody();
		}

		namespace bhkWorld
		{
			std::uintptr_t Scale();
			std::uintptr_t ScaleInverse();
		}

		namespace BoundItemEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace BSAudioManager
		{
			std::uintptr_t GetSingleton();
			std::uintptr_t GetSoundHandleFromName();
		}

		namespace BSFixedString
		{
			std::uintptr_t Initialize();
		}

		namespace BSInputDeviceManager
		{
			std::uintptr_t Singleton();
		}

		namespace BSPointerHandleManagerInterface
		{
			std::uintptr_t GetHandle();
			std::uintptr_t GetSmartPointer();
		}

		namespace BSReadWriteLock
		{
			std::uintptr_t ReadLock();
			std::uintptr_t ReadUnlock();
			std::uintptr_t WriteLock();
			std::uintptr_t WriteUnlock();
		}

		namespace BSSoundHandle
		{
			std::uintptr_t Play();
		}

		namespace BSStringPool
		{
			namespace Entry
			{
				std::uintptr_t Release();
			}
		}

		namespace CalmEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace Character
		{
			namespace MagicTarget
			{
				std::uintptr_t VirtualFunctionTable();
			}

			std::uintptr_t VirtualFunctionTable();
		}

		namespace CloakEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace CommandEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace CommandSummonedEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ConcussionEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace Console
		{
			std::uintptr_t SelectedReferenceHandle();
		}

		namespace ConsoleLog
		{
			std::uintptr_t PrintLine();
			std::uintptr_t Singleton();
		}

		namespace ContainerMenu
		{
			std::uintptr_t TargetReferenceHandle();
		}

		namespace CraftingSubMenus
		{
			namespace EnchantConstructMenu
			{
				namespace CreateEffectFunctor
				{
					std::uintptr_t VirtualFunctionTable();
				}
			}
		}

		namespace CureEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DarknessEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DemoralizeEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DetectLifeEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DisarmEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DisguiseEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DispelEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace DualValueModifierEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace EffectArchetypes
		{
			std::uintptr_t Archetypes();
		}

		namespace EffectItem
		{
			std::uintptr_t GetCost();
			std::uintptr_t ResetCost();
			std::uintptr_t SetConditions();
		}

		namespace EffectSetting
		{
			std::uintptr_t GetCost();
		}

		namespace EnchantmentItem
		{
			std::uintptr_t ModifyPower();
			std::uintptr_t VirtualFunctionTable();
		}

		namespace EnhanceWeaponEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace EtherealizationEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ExtraDataList
		{
			std::uintptr_t IsQuestBoundObject();
			std::uintptr_t SetLockList();
		}

		namespace FindAppropriateDisplaceEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace FindMaxMagnitudeVisitor
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace FixedStrings
		{
			std::uintptr_t GetSingleton();
		}

		namespace FrenzyEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace GameSettingCollection
		{
			std::uintptr_t GetSetting();
			std::uintptr_t InitializeCollection();
			std::uintptr_t Singleton();
		}

		namespace GetMagicItemDescriptionFunctor
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				std::uintptr_t AttachMovie();
				std::uintptr_t DeleteMember();
				std::uintptr_t GetArraySize();
				std::uintptr_t GetDisplayInformation();
				std::uintptr_t GetElement();
				std::uintptr_t GetMember();
				std::uintptr_t GotoAndPlay();
				std::uintptr_t HasMember();
				std::uintptr_t Invoke();
				std::uintptr_t ObjectAddReference();
				std::uintptr_t ObjectRelease();
				std::uintptr_t PushBack();
				std::uintptr_t RemoveElements();
				std::uintptr_t SetArraySize();
				std::uintptr_t SetDisplayInformation();
				std::uintptr_t SetElement();
				std::uintptr_t SetMember();
				std::uintptr_t SetText();
			}
		}

		namespace GMemory
		{
			std::uintptr_t GlobalHeap();
		}

		namespace GrabActorEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace GString
		{
			std::uintptr_t Constructor();
		}

		namespace GuideEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace HandleEntryPointVisitor
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace hkReferencedObject
		{
			std::uintptr_t AddReference();
			std::uintptr_t RemoveReference();
		}

		namespace IFormFactory
		{
			std::uintptr_t GetFormFactory();
		}

		namespace INIPrefSettingCollection
		{
			std::uintptr_t InitializeCollection();
			std::uintptr_t Singleton();
		}

		namespace INISettingCollection
		{
			std::uintptr_t GetSetting();
			std::uintptr_t InitializeCollection();
			std::uintptr_t Singleton();
		}

		namespace InitTESThread
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace InterfaceStrings
		{
			std::uintptr_t Singleton();
		}

		namespace Inventory3DManager
		{
			std::uintptr_t Singleton();
		}

		namespace InventoryChanges
		{
			namespace FindBestSoulGemVisitor
			{
				std::uintptr_t VirtualFunctionTable();
			}
		}

		namespace InventoryEntryData
		{
			std::uintptr_t GetName();
			std::uintptr_t GetValue();
			std::uintptr_t IsOwnedBy();
		}

		namespace InvisibilityEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ItemList
		{
			std::uintptr_t GetSelectedItem();
			std::uintptr_t Update();
		}

		namespace LightEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace LockEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace MagicItem
		{
			std::uintptr_t GetCost();
			std::uintptr_t GetCostliestEffectItem();
		}

		namespace Main
		{
			std::uintptr_t FrameCount();
			std::uintptr_t Singleton();
		}

		namespace MemoryManager
		{
			std::uintptr_t Allocate();
			std::uintptr_t Deallocate();
			std::uintptr_t GetSingleton();
			std::uintptr_t GetThreadScrapHeap();
			std::uintptr_t Reallocate();
		}

		namespace ModelReferenceEffect
		{
			std::uintptr_t SwitchFirstThirdPerson();
			std::uintptr_t VirtualFunctionTable();
		}

		namespace NiAVObject
		{
			std::uintptr_t GetBoneFromName();
			std::uintptr_t GetCollisionObject();
		}

		namespace NiBooleanExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiFloatExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiFloatsExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NightEyeEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace NiIntegerExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiIntegersExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiMatrix33
		{
			std::uintptr_t EulerAnglesToRotationMatrixXYZ();
			std::uintptr_t EulerAnglesToRotationMatrixZXY();
			std::uintptr_t RotationMatrixToEulerAnglesXYZ();
			std::uintptr_t RotationMatrixToEulerAnglesZXY();
		}

		namespace NiNode
		{
			std::uintptr_t AddDecal();
			std::uintptr_t CreateObject();
		}

		namespace NiObjectNET
		{
			std::uintptr_t AddExtraData();
			std::uintptr_t AddNamedExtraData();
			std::uintptr_t DeleteExtraDataAt();
			std::uintptr_t GetExtraData();
			std::uintptr_t InsertExtraData();
			std::uintptr_t RemoveAllExtraData();
			std::uintptr_t RemoveExtraData();
			std::uintptr_t RemoveExtraDataAt();
		}

		namespace NiStringExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace NiStringsExtraData
		{
			std::uintptr_t CreateObject();
		}

		namespace OpenEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ParalysisEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace PeakValueModifierEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace PlayerCharacter
		{
			namespace MagicTarget
			{
				std::uintptr_t VirtualFunctionTable();
			}

			std::uintptr_t GetDifficultyMultiplier();
			std::uintptr_t Singleton();
			std::uintptr_t VirtualFunctionTable();
		}

		namespace PoisonedWeapon
		{
			std::uintptr_t GetEventSource();
		}

		namespace Precipitation
		{
			std::uintptr_t RainDirection();
		}

		namespace RallyEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ReanimateEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ScrapHeap
		{
			std::uintptr_t Allocate();
			std::uintptr_t Deallocate();
		}

		namespace Script
		{
			std::uintptr_t ClearCachedValues();
			std::uintptr_t CompileAndRun();
			std::uintptr_t ParseParameters();
			std::uintptr_t SetCommand();
		}

		namespace ScriptCompiler
		{
			std::uintptr_t GetFunctionDefinition();
		}

		namespace ScriptedRefEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ScriptEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ScriptEventSourceHolder
		{
			std::uintptr_t GetSingleton();
		}

		namespace ScrollItem
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace Sky
		{
			std::uintptr_t GetSingleton();
		}

		namespace SlowTimeEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace SoulTrapEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace SpawnHazardEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace SpellItem
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace StaggerEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace SummonCreatureEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace TargetValueModifierEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace TaskQueueInterface
		{
			std::uintptr_t QueueScriptFunctionCall();
			std::uintptr_t ShouldQueueTask();
			std::uintptr_t Singleton();
		}

		namespace TelekinesisEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace TES
		{
			std::uintptr_t GetCell();
			std::uintptr_t GetLandColor();
			std::uintptr_t GetMaterialID();
			std::uintptr_t Singleton();
		}

		namespace TESBoundObject
		{
			std::uintptr_t GetWeight();
		}

		namespace TESCondition
		{
			std::uintptr_t Clear();
			std::uintptr_t IsTrue();
		}

		namespace TESDataHandler
		{
			std::uintptr_t EnumerateReferencesCloseToPoint();
			std::uintptr_t EnumerateReferencesCloseToReference();
			std::uintptr_t GetForm();
			std::uintptr_t Singleton();
		}

		namespace TESForm
		{
			std::uintptr_t GetEnchantmentItem();
			std::uintptr_t GetFormFromEditorID();
			std::uintptr_t GetFormName();
			std::uintptr_t GetMaximumCharge();
			std::uintptr_t SetTemporary();
		}

		namespace TESFurniture
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace TESObjectCELL
		{
			std::uintptr_t CreateTemporaryEffectParticle();
			std::uintptr_t GetHavokWorld();
		}

		namespace TESObjectREFR
		{
			std::uintptr_t Activate();
			std::uintptr_t GetInventoryChanges();
			std::uintptr_t GetReferenceFrom3D();
			std::uintptr_t GetReferenceName();
			std::uintptr_t IsCrimeToActivate();
		}

		namespace TESObjectWEAP
		{
			std::uintptr_t UnarmedWeapon();
		}

		namespace TESSoulGem
		{
			std::uintptr_t GetSoulLevelValue();
		}

		namespace TurnUndeadEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace UI
		{
			std::uintptr_t IsMenuOpen();
			std::uintptr_t PlaySound();
			std::uintptr_t ShowMessageBox();
			std::uintptr_t ShowNotification();
			std::uintptr_t Singleton();
		}

		namespace UIMessageQueue
		{
			std::uintptr_t AddInventoryUpdateMessage();
			std::uintptr_t AddMessage();
			std::uintptr_t Singleton();
		}

		namespace UserEvents
		{
			std::uintptr_t Singleton();
		}

		namespace ValueAndConditionsEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace ValueModifierEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace VampireLordEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace VATS
		{
			std::uintptr_t Singleton();
			std::uintptr_t GetPlayerUpdateMultiplier();
			std::uintptr_t SetMagicTimeSlowdown();
		}

		namespace WerewolfEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		namespace WerewolfFeedEffect
		{
			std::uintptr_t VirtualFunctionTable();
		}

		std::uintptr_t ThreadLocalStorageIndex();
	}
}
