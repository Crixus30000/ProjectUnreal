// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillCollisionDetection.h"
#include "SkillBase.h"
// Sets default values
ASkillCollisionDetection::ASkillCollisionDetection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	detectionMesh = CreateDefaultSubobject<UStaticMeshComponent>("DetectionMesh");

	if (detectionMesh != nullptr && RootComponent != nullptr)
		detectionMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASkillCollisionDetection::BeginPlay()
{
	Super::BeginPlay();
	if (detectionMesh != nullptr)
	{
		detectionMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASkillCollisionDetection::OnTriggerBeginOverlap);
		detectionMesh->OnComponentEndOverlap.AddUniqueDynamic(this, &ASkillCollisionDetection::OnTriggerEndOverlap);
	}
}

// Called every frame
void ASkillCollisionDetection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASkillCollisionDetection::Init(USkillBase* _SkillOwner)
{
	SkillOwner = _SkillOwner;
	if (_SkillOwner == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SkillCollisionDetection::Init :: NO SKILL OWNER")));
}

void ASkillCollisionDetection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (SkillOwner != nullptr)
		SkillOwner->DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void ASkillCollisionDetection::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (SkillOwner != nullptr)
		SkillOwner->DetectionMeshEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

