// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapController_CPP.h"
#include "Engine/Engine.h"
#include "RoadSign_CPP.h"
#include "AI/Navigation/NavigationSystem.h"




AWorldMapController_CPP::AWorldMapController_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWorldMapController_CPP::BeginPlay()
{
	Super::BeginPlay();

	InputComponent->BindAction("LMB", IE_Released, this, &AWorldMapController_CPP::MoveToRoadSign);
	bShowMouseCursor = 1;
}

void AWorldMapController_CPP::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
	UE_LOG(LogTemp, Warning, TEXT("Pawn name is : %s"), *aPawn->GetName());
}

void AWorldMapController_CPP::MoveToRoadSign()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Heihei"));
	FHitResult TraceHitResult;
	GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
	if (TraceHitResult.bBlockingHit) {
		
		ARoadSign_CPP* hitRoad = Cast<ARoadSign_CPP>(TraceHitResult.Actor);
		if (hitRoad) {
			SimpleMoveToRoadSign(hitRoad->GetActorLocation());
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TraceHitResult.GetActor()->GetName());
		}
	}
}

void AWorldMapController_CPP::SimpleMoveToRoadSign(FVector destination)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(destination, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, destination);
		}
	}
}

void AWorldMapController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


