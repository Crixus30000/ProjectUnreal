// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damagable.h"
#include "GenericTeamAgentInterface.h"
#include "Hack_n_Slash_ProjectCharacter.generated.h"
class UObjectStat;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCatchLootToUI,  UObjectStat*, _ObjectStat);


UCLASS(Blueprintable)
class AHack_n_Slash_ProjectCharacter : public ACharacter,public IDamagable ,public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:


	AHack_n_Slash_ProjectCharacter();

	virtual void BeginPlay()override;

	UPROPERTY(BlueprintAssignable)
		FCatchLootToUI OnCallCatchlootToUI;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	int currentSkill = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkillManager")
		class USkillManagerComponent* SkillManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatManager")
		class UStatManager* StatManager;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AActor* Target;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector LastMousePos;
	UPROPERTY(EditAnywhere)
		float MinDistanceTarget = 100.0;
	UFUNCTION()
		bool CloseEnoughTarget();


	UFUNCTION(BlueprintCallable, Category = "SkillNotify", meta = (DisplayName = "SkillNotify"))
		void SkillNotify(); // Do something C++ when this get called...
	UFUNCTION(BlueprintCallable, Category = "EndSkillnotify", meta = (DisplayName = "EndSkillnotify"))
		void EndSkillnotify(); // Do something C++ when this get called...

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Damagable")
		void TakeDamage(int32 _Damage);
		void TakeDamage_Implementation(int32 _Damage);



		//StuffList
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Head;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Shoulder;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* jewels;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Torso;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Legs;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Feet;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* RightHand;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* LeftHand;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Hands;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* Cuffs;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stuff")
			class UObjectStat* EmptyPart;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bag")
			class UBagComponent* BagRef;

	virtual FGenericTeamId GetGenericTeamId() const  override { return TeamId; }



private:
	FGenericTeamId TeamId;
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	UFUNCTION()
		void CallRequestSkill(int32 _index);

	UFUNCTION()
		void CallCatchLoot(UObjectStat* _Statobject);

		
};

