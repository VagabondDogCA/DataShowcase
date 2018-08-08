// Fill out your copyright notice in the Description page of Project Settings.

#include "DataShowcase_GM.h"
#include "UObject/ConstructorHelpers.h"
#include "WorldMapController_CPP.h"


ADataShowcase_GM::ADataShowcase_GM()
{
	ConstructorHelpers::FClassFinder<APawn> _DefaultPawn(TEXT("/Game/Pawns/MockFolk_BP"));
	if(_DefaultPawn.Succeeded())
		DefaultPawnClass = _DefaultPawn.Class;

	ConstructorHelpers::FClassFinder<AController> _DefaultController(TEXT("/Game/AllLevels/WorldMapController_BP"));
	if(_DefaultController.Succeeded())
		PlayerControllerClass = _DefaultController.Class;
}
