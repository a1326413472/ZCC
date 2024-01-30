// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCObject.h"
#include "ZCCGameSubsystem.h"

UZCCGameSubsystem* UZCCObject::GetZCCSubsystem()
{
	if (GetWorld())
	{
		if (GetWorld()->GetGameInstance())
		{
			return GetWorld()->GetGameInstance()->GetSubsystem<UZCCGameSubsystem>();
		}
	}
	return nullptr;
}

UWorld* UZCCObject::GetWorld() const
{
	// TOSTUDY
	if (!HasAnyFlags(RF_ClassDefaultObject) && ensureMsgf(GetOuter(), TEXT("Actor: %s has a null OuterPrivate in UDUObject::GetWorld()"), *GetFullName())
		&& !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
	{
		return GetOuter()->GetWorld();
	}
	return nullptr;
}
