// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActorObject.h"
#include "highlightable.h"
// Sets default values
ABaseActorObject::ABaseActorObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	MeshObject = CreateDefaultSubobject<UStaticMeshComponent>("DetectionMesh");
	OutlineMesh = CreateDefaultSubobject<UStaticMeshComponent>("OutlineMesh");

	if (MeshObject != nullptr && RootComponent != nullptr)
		MeshObject->SetupAttachment(RootComponent);
	if (OutlineMesh != nullptr && MeshObject != nullptr)
		OutlineMesh->SetupAttachment(MeshObject);
}

// Called when the game starts or when spawned
void ABaseActorObject::BeginPlay()
{
	Super::BeginPlay();
	if (MeshObject != nullptr)
	MeshObject->SetStaticMesh(MeshForObject);
	OutlineMesh->SetVisibility(false);

}

// Called every frame
void ABaseActorObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseActorObject::SetAllMeshObject(UStaticMesh* _MeshObject)
{
	MeshObject->SetStaticMesh(_MeshObject);
	OutlineMesh->SetStaticMesh(_MeshObject);
	UMaterialInstanceDynamic* outlineMaterialMaterial = UMaterialInstanceDynamic::Create(MaterialInterface, nullptr);


	OutlineMesh->SetMaterial(0, outlineMaterialMaterial);
	outlineMaterialMaterial->SetScalarParameterValue("Scale", 6);
	outlineMaterialMaterial->SetVectorParameterValue("Color", FLinearColor::Blue);
}

void ABaseActorObject::SeeHighlight_Implementation()
{
	OutlineMesh->SetVisibility(true);

}

void ABaseActorObject::UnSeeHighlight_Implementation()
{
	OutlineMesh->SetVisibility(false);
}

