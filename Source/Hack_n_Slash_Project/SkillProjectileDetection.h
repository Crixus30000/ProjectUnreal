// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillProjectileDetection.generated.h"

UCLASS()
class HACK_N_SLASH_PROJECT_API ASkillProjectileDetection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillProjectileDetection();

protected:
	// Called when the game starts or when spawned

public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* detectionMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USkillBase* SkillOwner;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float distanceTravelled = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxRange = 0.0f;

	UPROPERTY(VisibleAnywhere)
		class UProjectileMovementComponent* projectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void Init(USkillBase* _SkillOwner, FVector _direction, float _speed, float _maxRange);



	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
