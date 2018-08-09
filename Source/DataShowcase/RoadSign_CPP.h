// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "RoadSign_CPP.generated.h"

UCLASS()
class DATASHOWCASE_API ARoadSign_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadSign_CPP();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshComponent;

	UMaterialInterface *Material_Deadly, *Material_Peaceful;

	bool isExplored;

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ARoadSign_CPP*> WayOut;
	UFUNCTION(BlueprintCallable)
		bool CanExplore(ARoadSign_CPP* TryWayOut);

	void TurnColor();
};


