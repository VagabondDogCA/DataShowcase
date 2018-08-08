// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapController_CPP.h"
#include "Engine/Engine.h"




AWorldMapController_CPP::AWorldMapController_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWorldMapController_CPP::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
	UE_LOG(LogTemp, Warning, TEXT("Pawn name is : %s"), *aPawn->GetName());
}

void AWorldMapController_CPP::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = 1;
}

void AWorldMapController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult TraceHitResult;
	GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
	if(TraceHitResult.bBlockingHit)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TraceHitResult.GetActor()->GetName());
}


