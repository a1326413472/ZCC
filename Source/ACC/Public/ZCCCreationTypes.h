// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCCoreTypes.h"
#include "Engine/DataTable.h"
#include "ZCCCreationTypes.generated.h"

/// <summary>
/// Declare delegate
/// ����ί��
/// </summary>
/// TODO
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FACCIntParamChangeSignature, class UZCCCreationComponent*, CreationComponent, FName, GroupKey, FZCCIntParam, Param);


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
struct ACC_API FZCCCreation : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	FName Specie;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	EZCCMaturity Maturity = EZCCMaturity::Adult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	EZCCGender Gender = EZCCGender::Male;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	TArray<FZCCGroupParam> GroupParams;

	FZCCGroupParam* GetGroupParamRef(FName Key)
	{
		auto Entry = GroupParams.FindByPredicate([Key](const FZCCGroupParam& InItem) {
			return InItem.Key == Key;
		});

		return Entry;
	}

	bool IsValid() const
	{
		return (!Specie.IsNone());
	}
};


/// <summary>
/// Struct : Creation
/// </summary>
USTRUCT(BlueprintType)
struct ACC_API FZCCCharacterCreation : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	FZCCCreation CreationBase;





	bool IsValid() const
	{
		return (!CreationBase.IsValid());
	}
};