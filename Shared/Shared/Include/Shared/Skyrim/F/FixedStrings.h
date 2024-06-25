#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"



namespace Skyrim
{
	class FixedStrings
	{
	public:
		// Non-member functions
		static FixedStrings* GetSingleton();

		// Member variables
		BSFixedString npcRoot;                                   // 0, "NPC Root [Root]"
		BSFixedString npc;                                       // 8, "NPC"
		BSFixedString npcHead;                                   // 10, "NPC Head [Head]"
		BSFixedString npcPelvis;                                 // 18, "NPC Pelvis [Pelv]"
		BSFixedString npcSpine0;                                 // 20, "NPC Spine [Spn0]" (Bip01Spine)
		BSFixedString npcSpine1;                                 // 28, "NPC Spine1 [Spn1]"
		BSFixedString npcSpine2;                                 // 30, "NPC Spine2 [Spn2]" (Bip01Spine2)
		BSFixedString npcLeftFoot;                               // 38, "NPC L Foot [Lft ]"
		BSFixedString npcRightFoot;                              // 40, "NPC R Foot [Rft ]"
		BSFixedString npcLeftCalf;                               // 48, "NPC L Calf [LClf]"
		BSFixedString npcRightCalf;                              // 50, "NPC R Calf [RClf]"
		BSFixedString specialIdleCast;                           // 58, "SpecialIdle_Cast"
		BSFixedString specialIdleAreaEffect;                     // 60, "SpecialIdle_AreaEffect" (SpecialIdle_AreaEffect)
		BSFixedString attachSound;                               // 68, "AttachSound" (AttachSound)
		BSFixedString soundMarker;                               // 70, "Sound Marker" (SoundMarker)
		BSFixedString skinnedDecalNode;                          // 78, "Skinned Decal Node" (SkinnedDecalNode)
		BSFixedString decalNode;                                 // 80, "Decal Node" (DecalNode)
		BSFixedString modelSwapNode;                             // 88, "ModelSwapNode" (ModelSwapNode)
		BSFixedString openString;                                // 90, "Open" (OpenString)
		BSFixedString closeString;                               // 98, "Close" (CloseString)
		BSFixedString dvpg;                                      // A0, "DVPG" (DVPG)
		BSFixedString prn;                                       // A8, "Prn" (Prn)
		BSFixedString weapon;                                    // B0, "WEAPON" (Weapon)
		BSFixedString swordBone;                                 // B8, "WeaponSword" (SwordBone)
		BSFixedString daggerBone;                                // C0, "WeaponDagger" (DaggerBone)
		BSFixedString axeBone;                                   // C8, "WeaponAxe" (AxeBone)
		BSFixedString maceBone;                                  // D0, "WeaponMace" (MaceBone)
		BSFixedString shieldBone;                                // D8, "SHIELD" (ShieldBone)
		BSFixedString weaponBackBone;                            // E0, "WeaponBack" (WeapBackBone)
		BSFixedString bowBone;                                   // E8, "WeaponBow" (BowBone)
		BSFixedString quiverBone;                                // F0, "QUIVER" (QuiverBone)
		BSFixedString editorMarker;                              // F8, "EditorMarker" (EditorMarker)
		BSFixedString editorMarker0;                             // 100, "EditorMarker:0"
		BSFixedString editorMarker1;                             // 108, "EditorMarker:1"
		BSFixedString editorMarker2;                             // 110, "EditorMarker:2"
		BSFixedString arrowQuiver;                               // 118, "ArrowQuiver" (ArrowQuiver)
		BSFixedString markerSource;                              // 120, "MarkerSource" (MarkerSource)
		BSFixedString markerTarget;                              // 128, "MarkerTarget" (MarkerTarget)
		BSFixedString attachLight;                               // 130, "AttachLight" (AttachLight)
		BSFixedString skin;                                      // 138, "skin"
		BSFixedString raceEars;                                  // 140, "FaceGenEars"
		BSFixedString unequip;                                   // 148, "Unequip" (Unequip)
		BSFixedString laserSightsName;                           // 150, "LaserSight" (LaserSightsName)
		BSFixedString aimSightsName;                             // 158, "AimSight" (AimSightsName)
		BSFixedString decal;                                     // 160, "Decal" (Decal)
		BSFixedString permanentDecal;                            // 168, "Permanent Decal" (PermanentDecal)
		BSFixedString grabLeft;                                  // 170, "grabLeft"
		BSFixedString grabRight;                                 // 178, "grabRight"
		BSFixedString arrow0;                                    // 180, "Arrow:0" (Arrow0)
		BSFixedString arrowBone;                                 // 188, "ArrowBone"
		BSFixedString raceHeadSkinned;                           // 190, "BSFaceGenNiNodeSkinned" (RaceHeadSkinned)
		BSFixedString entryPoint;                                // 198, "EntryPoint"
		BSFixedString npcLeftUpperArm;                           // 1A0, "NPC L UpperArm [LUar]"
		BSFixedString npcLeftLowerArm;                           // 1A8, "NPC L Forearm [LLar]"
		BSFixedString npcRightUpperArm;                          // 1B0, "NPC R UpperArm [RUar]"
		BSFixedString npcLook;                                   // 1B8, "NPC LookNode [Look]"
		BSFixedString npcTail1;                                  // 1C0, "NPC Tail1"
		BSFixedString npcTailHub;                                // 1C8, "NPC TailHub"
		BSFixedString npcPelvisAlternate;                        // 1D0, "NPC Pelvis"
		BSFixedString talking;                                   // 1D8, "Talking"
		BSFixedString cameraFirst;                               // 1E0, "Camera1st [Cam1]"
		BSFixedString cameraThird;                               // 1E8, "Camera3rd [Cam3]"
		BSFixedString headMeshForExportFaceGenerationAndMorphs0; // 1F0, "HeadMeshForExport_FaceGenAndMorphs:0"
		BSFixedString pinnedLimb;                                // 1F8, "PinnedLimb" (PinnedLimb)
		BSFixedString backpack;                                  // 200, "Backpack" (Backpack)
		BSFixedString projectileNode;                            // 208, "ProjectileNode" (ProjectileNode)
		BSFixedString blastRadiusNode;                           // 210, "BlastRadiusNode" (BlastRadiusNode)
		BSFixedString torchFire;                                 // 218, "TorchFire" (TorchFire)
		BSFixedString lightOn;                                   // 220, "##LightOn" (LightOn)
		BSFixedString npcCOM;                                    // 228, "NPC COM [COM ]"
		BSFixedString skinAttachment;                            // 230, "SkinAttachment"
		BSFixedString npcNeck;                                   // 238, "NPC Neck [Neck]"
		BSFixedString nifRound;                                  // 240, "##NifRound" (NifRound)
		BSFixedString scb;                                       // 248, "Scb" (Scb)
		BSFixedString upperBody;                                 // 250, "UpperBody" (UpperBody)
		BSFixedString lightOff;                                  // 258, "##LightOff" (LightOff)
		BSFixedString headMagicNode;                             // 260, "NPC Head MagicNode [Hmag]" (HeadMagicNode)
		BSFixedString leftMagicNode;                             // 268, "NPC L MagicNode [LMag]" (LeftMagicNode)
		BSFixedString rightMagicNode;                            // 270, "NPC R MagicNode [RMag]" (RightMagicNode)
		BSFixedString magicLeft;                                 // 278, "MagicLeft" (MagicLeft)
		BSFixedString magicRight;                                // 280, "MagicRight" (MagicRight)
		BSFixedString magicOther;                                // 288, "MagicOther" (MagicOther)
		BSFixedString cameraControlNode;                         // 290, "Camera Control" (CameraControlNode)
		BSFixedString npcRootAlternate;                          // 298, "NPC Root [Root]"
		BSFixedString horseSaddleNode;                           // 2A0, "SaddleBone" (HorseSaddleNode)
		BSFixedString perchFireNode;                             // 2A8, "PerchFireNode" (PerchFireNode)
		BSFixedString graphDeleting;                             // 2B0, "GraphDeleting" (GraphDeleting)
		BSFixedString isBlocking;                                // 2B8, "IsBlocking" (AnimationVariableIDNames)
		BSFixedString isShouting;                                // 2C0, "IsShouting" (IsShouting)
		BSFixedString isPlayer;                                  // 2C8, "IsPlayer" (IsPlayer)
		BSFixedString isNPC;                                     // 2D0, "IsNPC" (IsNPC)
		BSFixedString integerIsPlayer;                           // 2D8, "iIsPlayer" (iIsPlayer)
		BSFixedString scale;                                     // 2E0, "fScale" (AnimationVariableScaleName)
		BSFixedString femaleOffset;                              // 2E8, "FemaleOffset" (FemaleOffset)
		BSFixedString isFirstPerson;                             // 2F0, "IsFirstPerson" (IsFirstPerson)
		BSFixedString integerIsFirstPerson;                      // 2F8, "i1stPerson"
		BSFixedString floatIsFirstPerson;                        // 300, "fIsFirstPerson"
		BSFixedString humanoidFootIKEnable;                      // 308, "bHumanoidFootIKEnable" (HumanoidFootIKEnable)
		BSFixedString synchronizeLocomotionState;                // 310, "iSyncIdleLocomotion" (SyncLocomotionState)
		BSFixedString synchronizeTurnState;                      // 318, "iSyncTurnState" (SyncTurnState)
		BSFixedString isAttackReady;                             // 320, "IsAttackReady" (AnimationVariableIDNames)
		BSFixedString isVoiceReady;                              // 328, "bVoiceReady" (IsVoiceReady)
		BSFixedString isLeftCastReady;                           // 330, "bMLh_Ready" (IsLeftCastReady)
		BSFixedString isRightCastReady;                          // 338, "bMRh_Ready" (IsRightCastReady)
		BSFixedString equipOkay;                                 // 340, "bEquipOk" (AnimationVariableIDNames)
		BSFixedString hitFrame;                                  // 348, "HitFrame" (HitFrame)
		BSFixedString isSprinting;                               // 350, "IsSprinting" (AnimationVariableIDNames)
		BSFixedString synchronizeSprintState;                    // 358, "iSyncSprintState" (WantSprint)
		BSFixedString weaponAdjust;                              // 360, "weapAdj" (WeaponAdjust)
		BSFixedString weaponSpeedMultiplier;                     // 368, "weaponSpeedMult" (WeaponSpeed)
		BSFixedString leftWeaponSpeedMultiplier;                 // 370, "leftWeaponSpeedMult" (LeftWeaponSpeed)
		BSFixedString bowZoom;                                   // 378, "BowZoom" (BowZoom)
		BSFixedString isBowZoomed;                               // 380, "bBowZoomed" (IsBowZoomed)
		BSFixedString leftHandType;                              // 388, "iLeftHandType"
		BSFixedString rightHandType;                             // 390, "iRightHandType"
		BSFixedString leftHandEquipped;                          // 398, "iLeftHandEquipped"
		BSFixedString rightHandEquipped;                         // 3A0, "iRightHandEquipped"
		BSFixedString leftGraphName;                             // 3A8, "bLeftHand" (LeftGraphName)
		BSFixedString rightGraphName;                            // 3B0, "bRightHand" (RightGraphName)
		BSFixedString idleTimer;                                 // 3B8, "fIdleTimer"
		BSFixedString injured;                                   // 3C0, "Injured" (Injured)
		BSFixedString land;                                      // 3C8, "Land" (Land)
		BSFixedString crashLand;                                 // 3D0, "bCrashLand" (CrashLand)
		BSFixedString landTypeIndex;                             // 3D8, "LandTypeIndex" (LandTypeIndex)
		BSFixedString actorResponse;                             // 3E0, "ActorResponse" (ActorResponse)
		BSFixedString playerCharacterResponse;                   // 3E8, "PlayerCharacterResponse" (PlayerResponse)
		BSFixedString tailPitchCurrent;                          // 3F0, "TailPitchCurrent"
		BSFixedString tailPitchMaximum;                          // 3F8, "TailPitchMax"
		BSFixedString tailYawCurrent;                            // 400, "TailYawCurrent"
		BSFixedString tailYawMaximum;                            // 408, "TailYawMax"
		BSFixedString maximumHeadTrackAngle;                     // 410, "LookAtHeadingMaxAngle" (MaxHeadTrackAngle)
		BSFixedString english;                                   // 418, "English" (English)
		BSFixedString russian;                                   // 420, "Russian"
		BSFixedString polish;                                    // 428, "Polish"
		BSFixedString leftSpellRelease;                          // 430, "MLh_SpellFire_Event" (LeftSpellRelease)
		BSFixedString rightSpellRelease;                         // 438, "MRh_SpellFire_Event" (RightSpellRelease)
		BSFixedString voiceRelease;                              // 440, "Voice_SpellFire_Event" (VoiceRelease)
		BSFixedString arrowRelease;                              // 448, "arrowRelease" (ArrowRelease)
		BSFixedString endAnimation;                              // 450, "EndAnim" (EndAnim)
		BSFixedString stopEffect;                                // 458, "StopEffect" (StopEffect)
		BSFixedString tweenEntryDirection;                       // 460, "TweenEntryDirection"
		BSFixedString tweenPosition;                             // 468, "TweenPosition" (TweenPosition)
		BSFixedString tweenRotation;                             // 470, "TweenRotation" (TweenRotation)
		BSFixedString hasTweenSpeed;                             // 478, "HasTweenSpeed"
		BSFixedString tweenSpeed;                                // 480, "TweenSpeed"
		BSFixedString tweenUpdate;                               // 488, "bTweenUpdate"
		BSFixedString targetLocation;                            // 490, "TargetLocation"
		BSFixedString movementDirection;                         // 498, "MovementDirection" (MovementDirection)
		BSFixedString wardStrength;                              // 4A0, "fCastStrength" (WardStrength)
		BSFixedString staggerMagnitude;                          // 4A8, "staggerMagnitude" (StaggerMagnitude)
		BSFixedString staggerDirection;                          // 4B0, "staggerDirection" (StaggerDirection)
		BSFixedString isBusy;                                    // 4B8, "IsBusy" (AnimationVariableIDNames)
		BSFixedString imageSpaceModifierStart;                   // 4C0, "Imod" (ImageSpaceModStart)
		BSFixedString imageSpaceModifierStop;                    // 4C8, "Rimod" (ImageSpaceModStop)
		BSFixedString distanceToGoal;                            // 4D0, "DistToGoal"
		BSFixedString previousHitFrame;                          // 4D8, "preHitFrame" (PreHitFrame)
		BSFixedString weaponSwing;                               // 4E0, "weaponSwing" (WeaponSwing)
		BSFixedString weaponLeftSwing;                           // 4E8, "weaponLeftSwing" (WeaponLeftSwing)
		BSFixedString attackWindowStart;                         // 4F0, "AttackWinStart" (AttackWinStart)
		BSFixedString attackWindowEnd;                           // 4F8, "AttackWinEnd" (AttackWinEnd)
		BSFixedString velocityZ;                                 // 500, "VelocityZ" (VelocityZ)
		BSFixedString graphSpeed;                                // 508, "speed" (GraphSpeed)
		BSFixedString graphTurnDelta;                            // 510, "TurnDelta" (GraphTurnDelta)
		BSFixedString graphDirection;                            // 518, "Direction" (GraphDirection)
		BSFixedString speedSampled;                              // 520, "SpeedSampled" (SpeedSampled)
		BSFixedString horseSpeedSampled;                         // 528, "HorseSpeedSampled" (HorseSpeedSampled)
		BSFixedString lookAtOutOfRange;                          // 530, "LookAtOutOfRange" (LookAtOutOfRange)
		BSFixedString aimHeadingMaximum;                         // 538, "AimHeadingMax"
		BSFixedString aimLookingMaximum;                         // 540, "AimPitchMax"
		BSFixedString aimHeadingCurrent;                         // 548, "AimHeadingCurrent" (AimHeadingCurrent)
		BSFixedString aimLookingCurrent;                         // 550, "AimPitchCurrent" (AimLookingCurrent)
		BSFixedString synchronizeForwardState;                   // 558, "iSyncForwardState" (SyncForwardState)
		BSFixedString synchronizeStrafeState;                    // 560, "iSyncStrafeState" (SyncStrafeState)
		BSFixedString animationDriven;                           // 568, "bAnimationDriven" (AnimationDriven)
		BSFixedString allowRotation;                             // 570, "bAllowRotation" (AllowRotation)
		BSFixedString isSynchronized;                            // 578, "bIsSynced" (AnimationVariableIDNames)
		BSFixedString isSpeedSynchronized;                       // 580, "bSpeedSynced" (AnimationVariableIDNames)
		BSFixedString disableInterpolation;                      // 588, "bDisableInterp" (AnimationVariableIDNames)
		BSFixedString getUpType;                                 // 590, "iGetUpType" (GetUpType)
		BSFixedString objectActivated;                           // 598, "ObjectActivated" (ObjectActivated)
		BSFixedString flameProjectileLength;                     // 5A0, "fFlameProjectileLength" (FlameProjectileLength)
		BSFixedString pairedKillTarget;                          // 5A8, "PairedKillTarget" (PairedKillTarget)
		BSFixedString isAimActive;                               // 5B0, "bAimActive" (IsAimActive)
		BSFixedString havokDynamicEvent;                         // 5B8, "TurnDynamic" (HavokDynamicEvent)
		BSFixedString forceIdleStop;                             // 5C0, "bForceIdleStop" (AnimationVariableIDNames)
		BSFixedString constraintOffset;                          // 5C8, "ConstraintOffset" (ConstraintOffset)
		BSFixedString left;                                      // 5D0, "Left" (Left)
		BSFixedString pickup;                                    // 5D8, "PickUp" (Pickup)
		BSFixedString tweenerStartEvent;                         // 5E0, "PathTweenerStart" (TweenerStartEvent)
		BSFixedString tweenerEndEvent;                           // 5E8, "PathTweenerEnd" (TweenerEndEvent)
	};
}
