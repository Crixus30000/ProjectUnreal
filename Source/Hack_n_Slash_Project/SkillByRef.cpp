// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillByRef.h"
#include "Damagable.h"
#include "SkillManagerComponent.h"
#include "Hack_n_Slash_ProjectCharacter.h"


void USkillByRef::Execute()
{
	damagableRef = Cast<IDamagable>(SkillManagerOwner->GetOwnerCharacter()->Target);

	if (damagableRef != nullptr)
	{
		damagableRef->Execute_TakeDamage(Cast<UObject>(damagableRef), 20);
	}
	Super::Execute();
}