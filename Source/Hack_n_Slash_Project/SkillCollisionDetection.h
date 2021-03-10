// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillCollisionDetection.generated.h"

UCLASS()
class HACK_N_SLASH_PROJECT_API ASkillCollisionDetection : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASkillCollisionDetection();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* detectionMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USkillBase* SkillOwner;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void Init(USkillBase * _SkillOwner);

	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
