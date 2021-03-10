// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill1CooldowCheckService.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "Containers/EnumAsByte.h"
#include "Engine/World.h"
#include "AI_BaseController.h"
#include "SkillManagerComponent.h"
USkill1CooldowCheckService::USkill1CooldowCheckService(const FObjectInitializer& ObjectIn) : Super(ObjectIn)
{
	NodeName = "AggroService";
	bNotifyCeaseRelevant = true;
	bNotifyBecomeRelevant = true;
	Interval = 0.1f;
	RandomDeviation = 0.0f;
}

void USkill1CooldowCheckService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	//InitAtt Start
	if (OwnerComp.GetBlackboardComponent() != nullptr)
	{
		CurrentBlackBoard = OwnerComp.GetBlackboardComponent();
		SelfController = Cast<AAIController>(OwnerComp.GetAIOwner());
		SkillManager = Cast<USkillManagerComponent>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("SkillManager"));
		if (SkillManager != nullptr && SkillManager->Skills.Num()>0)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsFloat("CoodownAttack", SkillManager->GetSkillCoolDown(0));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NoSkillManager")));
		}
	}
}

void USkill1CooldowCheckService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	//Do RayCast Between IA And PlayerCharacter And check if Ray Collide With None 
	// and Set Target ref And Target Location 
	if (SkillManager != nullptr && SkillManager->Skills.Num() > 0)
	{
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat("CoodownAttack", SkillManager->GetSkillCoolDown(0));
	}
	else
	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NoSkillManager")));

	}
}