// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObject.h"
#include "ZCCDAOBase.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCDAOBase : public UZCCObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category="ZCC|DAO")
	class UZCCDAOMgr* DAOMgr;
};
