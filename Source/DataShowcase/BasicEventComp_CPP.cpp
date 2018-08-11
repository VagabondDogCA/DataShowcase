// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicEventComp_CPP.h"


// Sets default values for this component's properties
UBasicEventComp_CPP::UBasicEventComp_CPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UBasicEventComp_CPP::BeginPlay()
{
	Super::BeginPlay();

	GenerateEventsOnStart();

}


// Called every frame
void UBasicEventComp_CPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBasicEventComp_CPP::GenerateEventsOnStart()
{
	uint8 currEventSize = PropertyEvents.Num();

	for (int i = currEventSize - 1; i < MAX_EVENTS_LENGTH; i++) {

		FBasicGameEvent newEvent;
		//Name
		FString nameString = (TEXT("Task%s"), FString::FromInt(i));
		newEvent.EventDisplayName = FName(*nameString);
		//
		newEvent.EventLevel = 1;
		newEvent.EventType = EGameEventType(i);

		PropertyEvents.Add(newEvent);
	}

}

FBasicGameEvent UBasicEventComp_CPP::GetEventAtIndex(int32 _index)
{
	if (_index > MAX_EVENTS_LENGTH)
		return PropertyEvents[0];
	return PropertyEvents[_index];
}

void UBasicEventComp_CPP::AddGenericEvent(FName _EventName, int32 _EventLevel, EGameEventType _EventType)
{
	FBasicGameEvent newEvent;
	newEvent.EventDisplayName = _EventName;
	newEvent.EventLevel = _EventLevel;
	newEvent.EventType = _EventType;
	PropertyEvents.Add(newEvent);
}

void UBasicEventComp_CPP::AddRandomEvent()
{
	//TODO
}