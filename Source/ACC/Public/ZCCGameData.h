// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "ZCCGameData.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCGameData : public UZCCObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ACC|Data", meta=(RequiredAssetDataTags="RowStructure=ZCCSpecieRowTable"))
	UDataTable* DT_Specie;
};
