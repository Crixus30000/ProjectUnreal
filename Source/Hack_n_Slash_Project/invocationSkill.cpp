// Fill out your copyright notice in the Description page of Project Settings.


#include "invocationSkill.h"
#include "SkillManagerComponent.h"
#include "Hack_n_Slash_ProjectCharacter.h"

void UinvocationSkill::Execute()
{

	FTransform CurrentTransform = SkillManagerOwner->GetOwner()->GetTransform();
	CurrentTransform.SetRotation(FQuat::Identity);
	CurrentTransform.SetLocation(CurrentTransform.GetLocation() + (SkillManagerOwner->GetOwner()->GetActorForwardVector() * 200) - FVector(0, 0, 90));

	FXLocation = CurrentTransform.GetLocation();

	FXActor = SkillManagerOwner->GetWorld()->SpawnActorDeferred<AActor>(FX, CurrentTransform);

	FXActor->FinishSpawning(CurrentTransform);

	Super::Execute();
}
