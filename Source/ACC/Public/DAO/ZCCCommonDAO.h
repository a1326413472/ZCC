// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCDAOBase.h"
#include <Creation/ZCCSpecieDataAsset.h>
#include "ZCCCommonDAO.generated.h"


/**
 * 
 */
UCLASS()
class ACC_API UZCCCommonDAO : public UZCCDAOBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "ACC|DAO", meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetSpecieData(FName Identifier, UZCCSpecieDataAsset*& SpecieData);
};
