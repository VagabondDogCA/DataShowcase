// Fill out your copyright notice in the Description page of Project Settings.

#include "RoadSign_CPP.h"


// Sets default values
ARoadSign_CPP::ARoadSign_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = sceneComp;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARoadSign_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoadSign_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

