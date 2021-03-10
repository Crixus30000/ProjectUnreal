// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBaseAttack.h"
#include "SkillCollisionDetection.h"
#include "SkillManagerComponent.h"
#include "Damagable.h"
#include "Hack_n_Slash_ProjectCharacter.h"

void USkillBaseAttack::Execute()
{
	
	
	detection = SkillManagerOwner->GetWorld()->SpawnActorDeferred<ASkillCollisionDetection>(detectionMesh, SkillManagerOwner->GetOwner()->GetTransform());

	if (detection != nullptr)
	{
		detection->Init(this);
		detection->FinishSpawning(SkillManagerOwner->GetOwner()->GetTransform());
	}
	Super::Execute();
}

void USkillBaseAttack::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp,  OtherBodyIndex,  bFromSweep, SweepResult);
	IDamagable* damage = Cast<IDamagable>(OtherActor);
	if (damage != nullptr)
	{
		OtherActor->SetActorLocation(OtherActor->GetActorLocation() + detection->GetActorForwardVector() * 100);
		damage->Execute_TakeDamage(Cast<UObject>(damage),20);
	}

	
	//GetWorld()->DestroyActor(detection);
}