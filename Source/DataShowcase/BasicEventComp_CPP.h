// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "BasicEventComp_CPP.generated.h"

UENUM(BlueprintType)
enum class EGameEventType : uint8
{
	VE_ClearOut UMETA(DisplayName = "ClearOut"),
	VE_Assasin UMETA(DisplayName = "Assasin"),
	VE_Defence UMETA(DisplayName = "Explore"),
};


USTRUCT(BlueprintType)
struct FBasicGameEvent : public FTableRowBase 
{
	GENERATED_USTRUCT_BODY()
public:
	FName EventDisplayName;
	int32 EventLevel;
	EGameEventType EventType;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATASHOWCASE_API UBasicEventComp_CPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBasicEventComp_CPP();

	UFUNCTION(BlueprintCallable)
		void GenerateEventsOnStart();

	UFUNCTION(BlueprintCallable)
		FBasicGameEvent GetEventAtIndex(int32 _index);

	UFUNCTION(BlueprintCallable)
		void AddGenericEvent(FName _EventName, int32 EventLevel, EGameEventType _EventType);

	UFUNCTION(BlueprintCallable)
		void AddRandomEvent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FBasicGameEvent> PropertyEvents;

	uint8 MAX_EVENTS_LENGTH = 3;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
