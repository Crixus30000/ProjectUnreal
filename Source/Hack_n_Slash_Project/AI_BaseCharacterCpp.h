// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damagable.h"
#include "highlightable.h"
#include "GenericTeamAgentInterface.h"
#include "AI_BaseCharacterCpp.generated.h"

UCLASS()
class HACK_N_SLASH_PROJECT_API AAI_BaseCharacterCpp : public ACharacter, public IDamagable , public IGenericTeamAgentInterface , public Ihighlightable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_BaseCharacterCpp();


	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	FGenericTeamId TeamId;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FGenericTeamId GetGenericTeamId() const  override { return TeamId; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDeadCaracter;
	int currentSkill = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkillManager")
		class USkillManagerComponent* SkillManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AActor* Target;

	UFUNCTION(BlueprintCallable, Category = "SkillNotify", meta = (DisplayName = "SkillNotify"))
		void SkillNotify(); // Do something C++ when this get called...
	UFUNCTION(BlueprintCallable, Category = "EndSkillnotify", meta = (DisplayName = "EndSkillnotify"))
		void EndSkillnotify(); // Do something C++ when this get called...


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Damagable")
		void TakeDamage(int32 _Damage);
		void TakeDamage_Implementation(int32 _Damage);

		UFUNCTION()
			void CallRequestSkill(int32 _index);

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SeeHighlight")
			void SeeHighlight();
		void SeeHighlight_Implementation();
		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UnSeeHighlight")
			void UnSeeHighlight();
		void UnSeeHighlight_Implementation();
};
