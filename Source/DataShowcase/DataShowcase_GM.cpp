// Fill out your copyright notice in the Description page of Project Settings.

#include "DataShowcase_GM.h"
#include "UObject/ConstructorHelpers.h"
#include "WorldMapController_CPP.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/TransformCalculus3D.h"
#include "Kismet/KismetMathLibrary.h"

ADataShowcase_GM::ADataShowcase_GM()
{
	ConstructorHelpers::FClassFinder<APawn> _DefaultPawn(TEXT("/Game/Pawns/PlayerCharacter_BP"));
	if(_DefaultPawn.Succeeded())
		DefaultPawnClass = _DefaultPawn.Class;

	ConstructorHelpers::FClassFinder<AController> _DefaultController(TEXT("/Game/AllLevels/WorldMapController_BP"));
	if(_DefaultController.Succeeded())
		PlayerControllerClass = _DefaultController.Class;

	ConstructorHelpers::FObjectFinder<UDataTable> _DefaultDT(TEXT("DataTable'/Game/AllLevels/StaticWorldMap.StaticWorldMap'"));
	if (_DefaultDT.Succeeded())
		MapNodeDT = _DefaultDT.Object;

	ConstructorHelpers::FClassFinder<AActor> _DefaultPathMesh(TEXT("/Game/Pawns/PathActor"));
	if (_DefaultPathMesh.Succeeded())
		PathMesh = _DefaultPathMesh.Class;

	ConstructorHelpers::FClassFinder<ARoadSign_CPP> _DefaultRoadSign(TEXT("/Game/Pawns/RoadSign_BP"));
	if (_DefaultRoadSign.Succeeded())
		RoadSignBpClass = _DefaultRoadSign.Class;
}

void ADataShowcase_GM::SpawnWorldMap()
{
	TArray<FMapNode*> DataRows_MapNodes;
	FString Context; // Used in error reporting.
	MapNodeDT->GetAllRows<FMapNode>(Context, DataRows_MapNodes);

	while (DataRows_MapNodes.Num() > 0) {
		//Get the last RoadSign
		FMapNode* popedNode = DataRows_MapNodes.Pop();
		
		//Spawn Node
		AActor* tempActor = (GetWorld()->SpawnActor(RoadSignBpClass, &popedNode->NodeLocation, &FRotator::ZeroRotator));
		ARoadSign_CPP* currentNode = Cast<ARoadSign_CPP>(tempActor);
		currentNode->RoadName = popedNode->NodeName;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *currentNode->GetName());
		if(currentNode)
			ExistedNodes.Add(currentNode);

		for (ARoadSign_CPP* RoadSignToCheck : ExistedNodes) {
			for (FString _connectedNode : popedNode->ConnectedNodes) {
				if (RoadSignToCheck->RoadName == _connectedNode) {
					currentNode->MutualConntect(RoadSignToCheck);
					//TODO create bridge
					FVector BridgeLocation = currentNode->GetActorLocation() + (RoadSignToCheck->GetActorLocation() - currentNode->GetActorLocation()) / 2;
					FRotator BridgeLookDirection = UKismetMathLibrary::FindLookAtRotation(currentNode->GetActorLocation(), RoadSignToCheck->GetActorLocation());
					FScale BridgeScale(const FVector(1, BridgeLocation.Size() , 1));
					BridgeLocation += FVector(0, 0, 2);
					AActor* Bridge = GetWorld()->SpawnActor(PathMesh, &BridgeLocation, &BridgeLookDirection);
					Bridge->SetActorScale3D(FVector((RoadSignToCheck->GetActorLocation() - currentNode->GetActorLocation()).Size()/100 - 4,1,1));
					if(Bridge)
						UE_LOG(LogTemp, Warning, TEXT("Bridge spawned : %s"), *Bridge->GetName());
				}
			}
		}		
	}
}

void ADataShowcase_GM::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnWorldMap();

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "ADataShowcase_GM init");
}
