// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "ProjectileSkillBase.generated.h"

/**
 * 
 */
UCLASS()
class HACK_N_SLASH_PROJECT_API UProjectileSkillBase : public USkillBase
{
	GENERATED_BODY()

protected:
	virtual void Execute() override;

public:
	virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float projectileSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkillProjectileDetection> projectileBP;
	
};
