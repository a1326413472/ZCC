// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCCoreTypes.h"
#include "Engine/DataTable.h"
#include "ZCCCreationTypes.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCCreationTypes : public UDataTable
{
	GENERATED_BODY()
	
};


/// <summary>
/// Struct : Creation
/// </summary>
USTRUCT(BlueprintType)
struct ACC_API FZCCCharacterCreation : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	FName Specie;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	EZCCMaturity Maturity = EZCCMaturity::Adult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	EZCCGender Gender = EZCCGender::Male;


	bool IsValid() const
	{
		return (!Specie.IsNone());
	}
};