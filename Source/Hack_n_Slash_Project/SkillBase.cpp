// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"

//SYSTEM Skill EXPLAIN
//1-player controller call input and send to character by event
//2-character receive the call with parameter and ask to skill manager if skill a skill is executing
//3-if no skill executing call request execute and look  current cooldown
//4-if skill cooldown = 0 then he call animation and pass Is executing true and play animation
//5-in animation wait event to spawn actor collider to do action in consequence
// at end of animation call event end execution and reset cooldown to cooldown max



bool USkillBase::RequestExecution()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("IS Request"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(CooldownTimer));

	if (CooldownTimer >= CooldownLimit)
	{
		IsExecuting = true;

		return true;
	}
	else
		return false;
}

void USkillBase::TickSkill(float _deltaTime)//Update CoolDown
{
	if (CooldownTimer < CooldownLimit)
	{
	CooldownTimer +=_deltaTime;
	}
	else if(CooldownTimer > CooldownLimit)
	{
		CooldownTimer = CooldownLimit;
	}
}

//overlap detection of skill
void USkillBase::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Event_DetectionMeshBeginOverlapBP( OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex,  bFromSweep, SweepResult);
}

void USkillBase::DetectionMeshEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Event_DetectionMeshEndOverlapBP( OverlappedComponent,  OtherActor,  OtherComp,  OtherBodyIndex);
}



float USkillBase::GetCooldown()
{
	return ((float)CooldownTimer/(float)CooldownLimit);
}

void USkillBase::Execute()//ask execution can be Override in child class
{
	//EndExecution();
}

void USkillBase::EndExecution()//ask end execution can be Override in child class
{
	IsExecuting = false;
	CooldownTimer = 0.0f;

}
