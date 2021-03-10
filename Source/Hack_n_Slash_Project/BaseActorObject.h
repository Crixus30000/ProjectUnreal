// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "highlightable.h"
#include "BaseActorObject.generated.h"

UCLASS()
class HACK_N_SLASH_PROJECT_API ABaseActorObject : public AActor , public Ihighlightable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActorObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MeshObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* OutlineMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool IsOutline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInterface* MaterialInterface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMesh* MeshForObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D* Icon;

	UPROPERTY(VisibleAnywhere, Instanced, BlueprintReadWrite)
	class UObjectStat * StatObject;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	 void SetAllMeshObject(UStaticMesh* _MeshObject);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SeeHighlight")
		void SeeHighlight();
		void SeeHighlight_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UnSeeHighlight")
		void UnSeeHighlight();
		void UnSeeHighlight_Implementation();
	//void InitData(UObjectStat * StatObject);
};
