// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestSysComponent_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "RoadSign_CPP.h"
#include "PlayerCharacter.h"


// Sets default values for this component's properties
UQuestSysComponent_CPP::UQuestSysComponent_CPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestSysComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
	
	if (ensure(GetOwner() != nullptr)) {
		UE_LOG(LogTemp, Warning, TEXT("UQuestSysCompo has owner: %s"), *GetOwner()->GetName());
	}
	
}


// Called every frame
void UQuestSysComponent_CPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQuestSysComponent_CPP::GenerateRandomQuest()
{
	if (currentQuests.Num() >= 3) {
		return;
	}

	static TArray<AActor*> RoadSigns;

	UGameplayStatics::GetAllActorsOfClass(this, ARoadSign_CPP::StaticClass(), RoadSigns);
	
	/*
	* DEBUG	message
	for (AActor* _roadsign : RoadSigns) {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, *_roadsign->GetName());
	}
	*/
	static const int RoadSignNum = RoadSigns.Num();

	FQuestNode newQuestNode;
	//quest name
	newQuestNode.QuestName = "Some What Regular Newbie Letter Carrier Quest";
	//quest type
	newQuestNode.QuestNodeType = EQuestCategory::VE_Generice;
	
	TArray<uint8> ExceptionPoints;
	//random map node num
	ExceptionPoints.AddUnique(FMath::RandRange(0, RoadSignNum));
	//start map node
	newQuestNode.QuestStartPosition = RoadSigns[ExceptionPoints[0]];
	uint8 newPoint;
	do {
		newPoint = FMath::RandRange(0, RoadSignNum);
		
	} while (ExceptionPoints[0] == newPoint);
	ExceptionPoints.Add(newPoint);
	newQuestNode.QuestTargets.Add(RoadSigns[newPoint]);
	currentQuests.Add(newQuestNode);
}

void UQuestSysComponent_CPP::CheckPoint()
{
	APlayerCharacter *parentInstance = Cast<APlayerCharacter>(GetOwner());
	if (!parentInstance)
		return;
	for (FQuestNode& questNode : currentQuests)
	{
		AActor* currentPoint;
		if (questNode.QuestTargets.Num() == 0) {
			questNode.bIsQuestCompleted = 1;

		} else {
			currentPoint = questNode.QuestTargets.Last();
			if (parentInstance->GetCurrentRoadSignRef() == currentPoint) {
				AActor* DequedString = questNode.QuestTargets.Pop();
				questNode.QuestCompletedTargets.Add(DequedString);
			}
		}
	}
}

const FQuestNode& UQuestSysComponent_CPP::GetFirstQuest()
{
	return currentQuests.Last();
}

