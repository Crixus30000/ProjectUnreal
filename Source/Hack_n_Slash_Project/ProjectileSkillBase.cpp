// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSkillBase.h"
#include "SkillProjectileDetection.h"
#include "SkillManagerComponent.h"
#include "Damagable.h"
#include "Kismet/KismetMathLibrary.h"


void UProjectileSkillBase::Execute()
{

	if (SkillManagerOwner != nullptr)
	{
		ASkillProjectileDetection* projectile = nullptr;
		projectile = SkillManagerOwner->GetWorld()->SpawnActorDeferred<ASkillProjectileDetection>(projectileBP, SkillManagerOwner->GetOwner()->GetActorTransform());

		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(SkillManagerOwner->GetOwnerCharacter()->GetActorLocation(), SkillManagerOwner->GetOwnerCharacter()->LastMousePos);

		FVector newVec = Rot.Vector();
		newVec.X = 0;
		newVec.Z = 0;
		FRotator newrot = FRotator::MakeFromEuler(newVec);
		SkillManagerOwner->GetOwnerCharacter()->SetActorRotation(Rot);


		if (projectile != nullptr)
		{
			projectile->Init(this, SkillManagerOwner->GetOwnerCharacter()->LastMousePos- SkillManagerOwner->GetOwner()->GetActorLocation(), projectileSpeed, range);
			projectile->FinishSpawning(SkillManagerOwner->GetOwner()->GetActorTransform());
		}
	}

	Super::Execute();
}

void UProjectileSkillBase::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	IDamagable* damage = Cast<IDamagable>(OtherActor);
	if (damage != nullptr)
	{
		damage->Execute_TakeDamage(Cast<UObject>(damage), 20);
	}
	//TODO damage logic here
}