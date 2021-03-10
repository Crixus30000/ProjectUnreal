// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillEnemyByRef.h"
#include "Damagable.h"
#include "SkillManagerComponent.h"
#include "AI_BaseCharacterCpp.h"

void USkillEnemyByRef::Execute()
{
	damagableRef = Cast<IDamagable>(SkillManagerOwner->GetIAOwnerCharacter()->Target);

	if (damagableRef != nullptr)
	{
		damagableRef->Execute_TakeDamage(Cast<UObject>(damagableRef), 20);
	}
	Super::Execute();
}