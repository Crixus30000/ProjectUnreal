// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillBase.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType, EditInLineNew)
class HACK_N_SLASH_PROJECT_API USkillBase : public UObject
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, Category = "Skill_Data")
		class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere , Category = "Skill_Data")
		class USkillManagerComponent* SkillManagerOwner;

	UPROPERTY(EditAnywhere, Category = "Skill_Data")
		bool IsExecuting = false;

	UPROPERTY(EditAnywhere, Category = "Skill_Data")
		float CooldownLimit;

	UPROPERTY(EditAnywhere, Category = "Skill_Data")
		float CooldownTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 range = 0;

	UPROPERTY(EditAnywhere, Category = "Skill_Data")
		float Damage;


	UFUNCTION()
		bool RequestExecution();

	UFUNCTION()
		void TickSkill(float _deltaTime);


		//Trigger Event
	virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void DetectionMeshEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



	//EVENT FOR BLEUPRINT CAN BE USE FOR FX AND SOUND OR OTHER...
	UFUNCTION(BlueprintImplementableEvent)
		void Event_OnExecuteBP();

	UFUNCTION(BlueprintImplementableEvent)
		void Event_OnEndExecutionBP();

	UFUNCTION(BlueprintImplementableEvent)
		void Event_DetectionMeshBeginOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
		void Event_DetectionMeshEndOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		float GetCooldown();

	virtual void  Execute();

	virtual void EndExecution();
	
	
protected:
	

	
};
