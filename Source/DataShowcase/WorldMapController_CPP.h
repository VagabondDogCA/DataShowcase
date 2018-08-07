// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WorldMapController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class DATASHOWCASE_API AWorldMapController_CPP : public APlayerController
{
	GENERATED_BODY()


		AWorldMapController_CPP();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
