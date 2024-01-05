// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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



};