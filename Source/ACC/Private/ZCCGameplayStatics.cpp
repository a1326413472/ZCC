// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCGameplayStatics.h"

#include "ZCCGameSubsystem.h"
#include "DAO/ZCCDAOMgr.h"
#include "Kismet/GameplayStatics.h"

UZCCDAOBase* UZCCGameplayStatics::GetDAOByClass(const UObject* WorldContextObject, TSubclassOf<UZCCDAOBase> DAOClass)
{
	if (UZCCGameSubsystem* ZCCGameSubsystem = UGameplayStatics::GetGameInstance(WorldContextObject)->GetSubsystem<UZCCGameSubsystem>())
	{
		if (UZCCDAOMgr* DAOMgr = ZCCGameSubsystem->GetManagerByClass<UZCCDAOMgr>())
		{
			return DAOMgr->GetDAOByClass(DAOClass);
		}
	}
	return nullptr;
}
