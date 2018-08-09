// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/DataTable.h"
#include "RoadSign_CPP.h"
#include "DataShowcase_GM.generated.h"



USTRUCT(BlueprintType)
struct FMapNode : public FTableRowBase{
	GENERATED_BODY()
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString NodeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector NodeLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> ConnectedNodes;
};


/**
 * 
 */
UCLASS()
class DATASHOWCASE_API ADataShowcase_GM : public AGameModeBase
{
	GENERATED_BODY()

public:
		ADataShowcase_GM();
	
		UDataTable* MapNodeDT;
		TSubclassOf<AActor> PathMesh;
		TSubclassOf<ARoadSign_CPP> RoadSignBpClass;

		void SpawnWorldMap();

		TArray<ARoadSign_CPP*> ExistedNodes;


		virtual void BeginPlay() override;
};