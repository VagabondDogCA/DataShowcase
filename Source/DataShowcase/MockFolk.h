// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structures.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "RoadSign_CPP.h"
#include "MockFolk.generated.h"


UCLASS()
class DATASHOWCASE_API AMockFolk : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMockFolk();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPawnStatus CharacterStatus;

	//all player status go there
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ARoadSign_CPP* CurrentAtRoadSign;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* ControllerCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool ChangeRoadSign(ARoadSign_CPP* MoveToRoadSign);
};