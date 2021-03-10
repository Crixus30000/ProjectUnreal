// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillAutodestruction.h"
#include "SkillManagerComponent.h"
#include "Hack_n_Slash_ProjectCharacter.h"

void USkillAutodestruction::Execute()
{
	FTransform CurrentTransform = SkillManagerOwner->GetOwner()->GetTransform();
	CurrentTransform.SetLocation(CurrentTransform.GetLocation() );

	FXLocation = CurrentTransform.GetLocation();

	FXActor = SkillManagerOwner->GetWorld()->SpawnActorDeferred<AActor>(FX, CurrentTransform);

	FXActor->FinishSpawning(CurrentTransform);

	Super::Execute();
}