// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Structures.generated.h"

UENUM(BlueprintType)
enum class EGender : uint8
{
	VE_Male 	UMETA(DisplayName = "Male"),
	VE_Female 	UMETA(DisplayName = "Female"),
	VE_Ann		UMETA(DisplayName = "Ann")
};

USTRUCT(BlueprintType)
struct FPawnStatus : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		FString _ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Age;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		EGender Gender;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Exp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Defence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Wisdom;
};

USTRUCT(BlueprintType)
struct FItemModifier : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		FString _ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Defence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStatus)
		int32 Wisdom;
};

UENUM(BlueprintType)
enum class EModifierType : uint8
{
	VE_AddPwr 		UMETA(DisplayName = "Add # Power"),
	VE_AddDef		UMETA(DisplayName = "Add # Defence"),
	VE_AddSpd		UMETA(DisplayName = "Add # Speed"),
	VE_AddWis		UMETA(DisplayName = "Add # Wisdom"),
	VE_IncPwr		UMETA(DisplayName = "Increased #% Power"),
};