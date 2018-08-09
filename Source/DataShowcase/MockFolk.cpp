// Fill out your copyright notice in the Description page of Project Settings.

#include "MockFolk.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"


// Sets default values
AMockFolk::AMockFolk()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->GravityScale = 0.f;
	GetCharacterMovement()->bOrientRotationToMovement = 1;
	bUseControllerRotationYaw = 0;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 3500.f;
	SpringArm->bAbsoluteRotation = 1; // Don't want arm to rotate when character does
	SpringArm->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	SpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	ControllerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ControllerCamera"));
	ControllerCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	QuestComponent = CreateDefaultSubobject<UQuestSysComponent_CPP>(TEXT("SysComponent"));
	AddOwnedComponent(QuestComponent);
}


// Called when the game starts or when spawned
void AMockFolk::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMockFolk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMockFolk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

bool AMockFolk::ChangeRoadSign(ARoadSign_CPP* MoveToRoadSign)
{
	if (CurrentAtRoadSign == nullptr) {
		CurrentAtRoadSign = MoveToRoadSign;
		return 0;
	}
	if (CurrentAtRoadSign->CanExplore(MoveToRoadSign)){
		CurrentAtRoadSign = MoveToRoadSign;
		return 1;
	}
	return 0;
}

FString AMockFolk::GetCurrentRoadSignName()
{
	return CurrentAtRoadSign->GetName();
}

