// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestSysComponent_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "RoadSign_CPP.h"
#include "MockFolk.h"


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
	static const int RoadSignNum = RoadSigns.Num();

	FQuestNode newQuestNode;
	newQuestNode.QuestName = "Some What Regular Newbie Letter Carrier Quest";
	newQuestNode.QuestNodeType = EQuestType::VE_Carrier;
	
	
	TArray<uint8> ExceptionPoints;
	ExceptionPoints.AddUnique(FMath::RandRange(0, RoadSignNum));
	newQuestNode.QuestStartPosition = RoadSigns[ExceptionPoints[0]];
	uint8 newPoint;
	do {
		newPoint = FMath::RandRange(0, RoadSignNum);
	} while (ExceptionPoints[0] != newPoint);

	newQuestNode.QuestTargets.Add(RoadSigns[newPoint]->GetName());
	
	currentQuests.Add(newQuestNode);
}

void UQuestSysComponent_CPP::CheckPoint()
{
	AMockFolk *parentInstance = Cast<AMockFolk>(GetOwner());
	if (!parentInstance)
		return;
	for (FQuestNode& questNode : currentQuests)
	{
		FString currentPoint;
		if (questNode.QuestTargets.Num() == 0) {
			questNode.bIsQuestCompleted = 1;

			//TODO pop this quest node from collection

		} else {
			currentPoint = questNode.QuestTargets.Last();
			if (parentInstance->GetCurrentRoadSignName() == currentPoint) {
				FString DequedString = questNode.QuestTargets.Pop();
				questNode.QuestCompletedTargets.Add(DequedString);
			}
		}
	}
}

const FQuestNode& UQuestSysComponent_CPP::GetFirstQuest()
{
	return currentQuests.Last();
}

