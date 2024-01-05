// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ZCCGPHDataAsset.h"
#include "ZCCSpecieDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCSpecieDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ACC|Config")
	FName Identifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ACC|ParamHandler")
	UZCCGroupParamHandlerDataAsset* GroupParamHandler;

};


/**
 *	Struct : Specie Row Data
 */
USTRUCT(BlueprintType)
struct FZCCSpecieRowTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZCC")
	TSoftObjectPtr<UZCCSpecieDataAsset> Data;

};