// Fill out your copyright notice in the Description page of Project Settings.

#include "RoadSign_CPP.h"
#include "Components/CapsuleComponent.h"

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

}



