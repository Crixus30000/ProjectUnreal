// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Hack_n_Slash_ProjectPlayerController.generated.h"
class UObjectStat;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCallSkill, int32,_Index );

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCatchLoot,class UObjectStat*,_ObjectStat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryVisible, bool, _Visible);

UCLASS()
class AHack_n_Slash_ProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AHack_n_Slash_ProjectPlayerController();


	virtual void BeginPlay()override;
	UPROPERTY()
		FCallSkill OnCallSkillDeleguate;

	UPROPERTY()
		FCatchLoot OnCallCatchLoot;

	UPROPERTY(BlueprintAssignable)
		FUpdateInventoryVisible OnInventoryVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AActor* Target;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool HasTarget = false;
	

	bool MoveToTarget = false;


	class Ihighlightable *TargetHighlight;
	bool IsHighLightSomthing;
	bool IsAlreadyHighLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool InventoryVisible;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsOnUIblockRay;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		class AHack_n_Slash_ProjectCharacter* CharacterRef;

	
protected:
	
	UPROPERTY()
		FHitResult Hit;

	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;


	bool IsRightClick = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	void DoRayCastToRightClic();
	void DoRayCastToLeftClic();
	void SetTarget(AActor * _Target);
	void SetTarget(int32 _LR);


	void AskRequestForSkillClickRight();
	void AskRequestForSkillClickLeft();

	void AskRequestForSkill1();
	void AskRequestForSkill2();
	void AskRequestForSkill3();


	void SetInventoryVisibility();
	

};


