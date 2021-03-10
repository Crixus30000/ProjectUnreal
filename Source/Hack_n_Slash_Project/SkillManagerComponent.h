// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManagerComponent.generated.h"

class USkillBase;
class AHack_n_Slash_ProjectPlayerController;
class AAI_BaseCharacterCpp;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class HACK_N_SLASH_PROJECT_API USkillManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USkillManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, Instanced,BlueprintReadWrite)
		TArray<USkillBase*>Skills;



	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION()
		void UpDateSkillM();
	UFUNCTION()
		void CallTickOfSkills(float _deltaTime);
	UFUNCTION()
		bool ASkillIsExecuting();
	UFUNCTION()
		bool OnSkillRequest( int32 _SkillIndex);

	UFUNCTION(BlueprintCallable)
		AHack_n_Slash_ProjectCharacter* GetOwnerCharacter();
	UFUNCTION(BlueprintCallable)
		AAI_BaseCharacterCpp* GetIAOwnerCharacter();

	UFUNCTION(BlueprintCallable)
		float GetSkillCoolDown(int32 _SkillIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Test", meta = (DisplayName = "PlayAnimation"))
		void PlayAnimationSKM(UAnimMontage* Montage); // Do something C++ when this get called...

	

	
};
