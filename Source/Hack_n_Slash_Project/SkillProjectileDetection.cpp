// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillProjectileDetection.h"
#include "SkillBase.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASkillProjectileDetection::ASkillProjectileDetection()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	detectionMesh = CreateDefaultSubobject<UStaticMeshComponent>("DetectionMesh");
	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");


	if (detectionMesh != nullptr && RootComponent != nullptr)
		detectionMesh->SetupAttachment(RootComponent);


	if (detectionMesh != nullptr && RootComponent != nullptr && projectileMovementComponent != nullptr)
	{
		projectileMovementComponent->SetUpdatedComponent(RootComponent);
		projectileMovementComponent->bInitialVelocityInLocalSpace = false;
		projectileMovementComponent->ProjectileGravityScale = 0.0f;
	}
}

// Called when the game starts or when spawned
void ASkillProjectileDetection::BeginPlay()
{
	Super::BeginPlay();
	if (detectionMesh != nullptr)
	{
		detectionMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASkillProjectileDetection::OnTriggerBeginOverlap);
		detectionMesh->OnComponentEndOverlap.AddUniqueDynamic(this, &ASkillProjectileDetection::OnTriggerEndOverlap);
	}
}

// Called every frame
void ASkillProjectileDetection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkillProjectileDetection::Init(USkillBase* _SkillOwner, FVector _direction, float _speed, float _maxRange)
{
	SkillOwner = _SkillOwner;
	distanceTravelled = 0.0f;
	maxRange = _maxRange;
	if (_SkillOwner == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SkillCollisionDetection::Init :: NO SKILL OWNER")));

	if (!_direction.IsNearlyZero())
	{
		_direction.Normalize();
		projectileMovementComponent->Velocity = _direction * _speed;
	}
}

void ASkillProjectileDetection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (SkillOwner != nullptr)
		SkillOwner->DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

}

void ASkillProjectileDetection::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (SkillOwner != nullptr)
		SkillOwner->DetectionMeshEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

