// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MockFolk.h"
#include "Structures.h"
#include "DataShowcase_GameInstance.generated.h"


UCLASS()
class DATASHOWCASE_API UDataShowcase_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
			AMockFolk* CreateChar();

		UFUNCTION(BlueprintCallable)
			void SaveChar();

		UFUNCTION(BlueprintCallable)
			AMockFolk* LoadChar();

		UFUNCTION(BlueprintCallable)
			void RandomizeChar(AMockFolk* CharToGo);
};