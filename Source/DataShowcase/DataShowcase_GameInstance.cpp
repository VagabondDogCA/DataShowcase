// Fill out your copyright notice in the Description page of Project Settings.

#include "DataShowcase_GameInstance.h"
#include "Engine/World.h"
#include "UObject/UObjectGlobals.h"



AMockFolk* UDataShowcase_GameInstance::CreateChar()
{
	
	AMockFolk* newPlayer;
	//newPlayer = CreateDefaultSubobject<AMockFolk>(TEXT("Player"));
	newPlayer = GetWorld()->SpawnActor<AMockFolk>(AMockFolk::StaticClass());
	RandomizeChar(newPlayer);
	return newPlayer;
	

	return nullptr;
}

void UDataShowcase_GameInstance::SaveChar()
{
	return;
}

AMockFolk* UDataShowcase_GameInstance::LoadChar()
{
	return nullptr;
}

void UDataShowcase_GameInstance::RandomizeChar(AMockFolk* CharToGo)
{
	FPawnStatus& tempStatus = CharToGo->CharacterStatus;

	tempStatus.Name = "For Now Fixed";
	tempStatus.Age = FMath::RandRange(19, 71);
	
	//Gender
	int genderRandomize = FMath::RandRange(0, 101);
	if (genderRandomize <= 49) {
		tempStatus.Gender = EGender::VE_Male;
	} else if (genderRandomize <= 98) {
		tempStatus.Gender = EGender::VE_Female;
	} else {
		tempStatus.Gender = EGender::VE_Ann;
	}
	tempStatus.Exp = 0;
	tempStatus.Power = FMath::RandRange(1, 6);
	tempStatus.Defence = FMath::RandRange(1, 6);
	tempStatus.Speed = FMath::RandRange(1, 6);
	tempStatus.Wisdom = FMath::RandRange(1, 6);
	

}
