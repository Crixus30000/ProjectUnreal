// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_BaseController.h"
#include "BehaviorTree/BlackboardComponent.h"



void AAI_BaseController::BeginPlay()
{
	Super::BeginPlay();

	if (BTRef != nullptr)
		RunBehaviorTree(BTRef);
	BBRef = GetBlackboardComponent();
}

//Init  BlackBoardIA base Value of self
void AAI_BaseController::InitBB()
{
	if (BBData != nullptr)
		UseBlackboard(BBData, BBRef);

	BBRef->SetValueAsVector("HomeLocation",GetPawn()->GetActorLocation());
	BBRef->SetValueAsObject("SelfActor",GetPawn());
	BBRef->SetValueAsObject("SelfRef",this);

}
