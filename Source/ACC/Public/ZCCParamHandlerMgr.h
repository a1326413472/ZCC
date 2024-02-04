// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "Creation//ZCCParamHandler.h"
#include "ZCCParamHandlerMgr.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCParamHandlerMgr : public UZCCObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TMap<TSubclassOf<UZCCParamHandler>, UZCCParamHandler*> ParamHandlers;

	template <class T>
	T* GetHandlerByClass(TMap<TSubclassOf<T>, T*> InMap, TSubclassOf<T> Class)
	{
		// If already in given TMap
		if (InMap.Contains(Class))
		{
			return InMap.FindChecked(Class);
		}
		// else create one
		T* Object = NewObject<T>(this, Class);
		InMap.Add(Class, Object);

		return Object;
	}

	UFUNCTION(BlueprintCallable, Category = "ZCC|Param")
	UZCCParamHandler* GetParamHandler(TSubclassOf<UZCCParamHandler> Class);
};
