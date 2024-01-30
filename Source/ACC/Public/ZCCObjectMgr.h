// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "ZCCObjectMgr.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCObjectMgr : public UZCCObject
{
	GENERATED_BODY()
	
protected:

	UPROPERTY()
	TSet<UObject*> OwnedObjects;

public:

	UObject* FindObjectByClass(const TSubclassOf<UObject> ObjectClass) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZCC|Object", meta = (DeterminesOutputType = "ObjectClass"))
	UObject* AddObjectByClass(TSubclassOf<UObject> ObjectClass);
	virtual UObject* AddObjectByClass_Implementation(TSubclassOf<UObject> ObjectClass);

};
