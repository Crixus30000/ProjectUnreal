// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "SkillBaseAttack.generated.h"

/**
 *
 */

UCLASS()
class HACK_N_SLASH_PROJECT_API USkillBaseAttack : public USkillBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkillCollisionDetection> detectionMesh;
		UPROPERTY()
	ASkillCollisionDetection* detection ;

	UFUNCTION()
		virtual void Execute() override;
	UFUNCTION()
		virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
