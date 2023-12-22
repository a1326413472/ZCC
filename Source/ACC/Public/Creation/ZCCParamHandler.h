// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "ZCCParamHandler.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCParamHandler : public UZCCObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZCC|ParamHandler")
	FName Key;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ZCC|ParamHandler")
	bool OnReceiveInt();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ZCC|ParamHandler")
	bool OnReceiveFloat();
};
