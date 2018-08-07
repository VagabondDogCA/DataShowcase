// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapController_CPP.h"




AWorldMapController_CPP::AWorldMapController_CPP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWorldMapController_CPP::Tick(float DeltaTime)
{
	/*
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	GetWorld()->LineTraceSingle(
		RV_Hit,        //result
		Start,    //start
		End, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);*/
}


