// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DataShowcase_GameInstance.h"
#include "CoreMinimal.h"
#include "Structures.h"
#include "GameFramework/Character.h"
#include "MockFolk.generated.h"


UCLASS()
class DATASHOWCASE_API AMockFolk : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMockFolk();


	//all player status go there
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPawnStatus CharacterStatus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};


