// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Containers/Queue.h"
#include "QuestSysComponent_CPP.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	VE_Carrier UMETA(DisplayName = "Carrier"),
	VE_ClearOut UMETA(DisplayName = "Slayer"),
};

USTRUCT(BlueprintType)
struct FQuestNode : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString QuestName;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		EQuestType QuestNodeType;

	//NOT A TYPE OF UObject, since targets won't generate when task init
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<AActor*> QuestTargets;
	
	//Not a type of UObject, since targets already dead when out of combat map
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<AActor*> QuestCompletedTargets;
	
	//Always a RoadSign type
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		AActor* QuestStartPosition;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bIsQuestCompleted;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString QuestDescription;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATASHOWCASE_API UQuestSysComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestSysComponent_CPP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	TArray<FQuestNode> currentQuests;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void GenerateRandomQuest();

	UFUNCTION(BlueprintCallable)
		void CheckPoint();


	UFUNCTION(BlueprintCallable)
		const FQuestNode& GetFirstQuest();
};


