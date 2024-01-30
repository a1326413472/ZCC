// Fill out your copyright notice in the Description page of Project Settings.


#include "DAO/ZCCDAOMgr.h"

UObject* UZCCDAOMgr::AddObjectByClass_Implementation(TSubclassOf<UObject> ObjectClass)
{
	UObject* Object = Super::AddObjectByClass_Implementation(ObjectClass);

	// force set some value as DAO Base
	// 强制设置一些值作为DAO Base
	if (Object->IsA(UZCCDAOBase::StaticClass()))
	{
		UZCCDAOBase* DAOObject = Cast<UZCCDAOBase>(Object);
		DAOObject->DAOMgr = this;
	}

	return Object;
}

UZCCDAOBase* UZCCDAOMgr::GetDAOByClass(TSubclassOf<UZCCDAOBase> DAOClass)
{
	UObject* Object = FindObjectByClass(DAOClass);
	if (!IsValid(Object))
	{
		return Cast<UZCCDAOBase>(AddObjectByClass(DAOClass));
	}
	return Cast<UZCCDAOBase>(Object);
}
