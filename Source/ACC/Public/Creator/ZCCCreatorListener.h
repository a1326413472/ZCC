// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "ZCCCreationTypes.h"
#include "ZCCCreatorListener.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCCreatorListener : public UZCCObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "ZCC|EventDispatchers")
	FACCIntParamChangeSignature OnIntParamChange;

};
