// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerCharacter.h"
#include "DataShowcase_GameInstance.generated.h"


UCLASS()
class DATASHOWCASE_API UDataShowcase_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
			APlayerCharacter* CreateChar();

		UFUNCTION(BlueprintCallable)
			void RandomizeChar(APlayerCharacter* CharToGo);
};