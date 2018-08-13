// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Containers/Queue.h"
#include "QuestSysComponent_CPP.generated.h"

UENUM(BlueprintType)
enum class EQuestCategory : uint8
{
	VE_Main UMETA(DisplayName = "Main Quest"),
	VE_Branch UMETA(DisplayName = "Branch Quest"),
	VE_Generice UMETA(DisplayName = "Generic"),
}; 

UENUM(BlueprintType)
enum class EGoalType : uint8
{
	VE_Hunt UMETA(DisplayName = "Hunt"),
	VE_Find UMETA(DisplayName = "Find"),
	VE_Talk UMETA(DisplayName = "Talk"),
};

UENUM(BlueprintType)
enum class ERegion : uint8
{
	VE_Swamp UMETA(DisplayName = "Swamp"),
	VE_WasteLand UMETA(DisplayName = "WasteLand"),
	VE_Vila UMETA(DisplayName = "Vila"),
};

USTRUCT(BlueprintType)
struct FQuestReward : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 Experience;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 Gold;
};

USTRUCT(BlueprintType)
struct FGoalLocation : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bHasLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FVector GoalLocation;  
};

USTRUCT(BlueprintType)
struct FGoalInfo : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		EGoalType Type;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bCustomGoal = 1;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText GoalText;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText AdditionalName;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 AmountToHunt;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FGoalLocation GoalLocation;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bUpdateQuestDescription;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText UpdatedDescription;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 FollowingSubGoalIndices;
};

USTRUCT(BlueprintType)
struct FQuestInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText Name;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		EQuestCategory Category;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FText Description;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		ERegion Region;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FQuestReward CompletionReward;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int32 SuggestedLevel;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float Difficulty;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<FGoalInfo> SubGoals;



};

USTRUCT(BlueprintType)
struct FQuestNode : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString QuestName;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		EQuestCategory QuestNodeType;

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


