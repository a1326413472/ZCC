// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ZCCGPHDataAsset.h"
#include <ZCCCreationTypes.h>
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZCC|Specie", meta=(RequiredAssetDataTags="RowStructure=ZCCCharacterCreation"))
	UDataTable* DT_Preset;


	UFUNCTION(BlueprintCallable, Category = "ZCC|Specie", meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetPresetCreation(FName PresetIdentifier, FZCCCharacterCreation& CharacterCreation);

	UFUNCTION(BlueprintCallable, Category="ZCC|Specie", meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetDefaultCreation(FZCCCharacterCreation& CharacterCreation);

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