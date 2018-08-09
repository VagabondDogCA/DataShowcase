// Fill out your copyright notice in the Description page of Project Settings.

#include "RoadSign_CPP.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
// Sets default values
ARoadSign_CPP::ARoadSign_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = sceneComp;

	UCapsuleComponent* CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComp->SetupAttachment(RootComponent);


	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	//MeshComponent->SetRelativeRotation(FRotator(0, 90.f, 0));
	
	ConstructorHelpers::FObjectFinder<UMaterial> MPeaceful(TEXT("/Game/Materials/PeacefulBlue"));
	Material_Peaceful = MPeaceful.Object;
	ConstructorHelpers::FObjectFinder<UMaterial> MDeadly(TEXT("Material'/Game/Materials/DeadlyRed.DeadlyRed'"));
	Material_Deadly = MDeadly.Object;
}

void ARoadSign_CPP::BeginPlay()
{
	Super::BeginPlay();
	
	
	/*Material_Deadly = UMaterialInstanceDynamic::Create(DeadlyMaterial.Object, DeadlyMaterial.Object);
	Material_Peaceful = UMaterialInstanceDynamic::Create(PeacefulMaterial.Object, PeacefulMaterial.Object);
	*/
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Material_Peaceful->GetPathName());
	if (isExplored) {
			MeshComponent->SetMaterial(0, Material_Peaceful);
	} else {
			MeshComponent->SetMaterial(0, Material_Deadly);
	}
}

bool ARoadSign_CPP::CanExplore(ARoadSign_CPP* TryWayOut)
{
	if (WayOut.Contains(TryWayOut)) {
		TryWayOut->TurnColor();
		return 1;
	}
	return 0;
}

void ARoadSign_CPP::TurnColor()
{
	isExplored = 1;
	MeshComponent->SetMaterial(0, Material_Peaceful);
}

void ARoadSign_CPP::MutualConntect(ARoadSign_CPP* ConnectedSign)
{
	WayOut.Add(ConnectedSign);
	ConnectedSign->WayOut.Add(this);
}

