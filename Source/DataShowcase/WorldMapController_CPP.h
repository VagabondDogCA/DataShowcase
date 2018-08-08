// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RoadSign_CPP.h"
#include "WorldMapController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class DATASHOWCASE_API AWorldMapController_CPP : public APlayerController
{
	GENERATED_BODY()


		AWorldMapController_CPP();
	
		

public:
	
	ARoadSign_CPP * TargetRoad;


	UFUNCTION(BlueprintCallable)
		virtual void Possess(APawn* aPawn) override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
