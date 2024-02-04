// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCParamHandlerMgr.h"

UZCCParamHandler* UZCCParamHandlerMgr::GetParamHandler(TSubclassOf<UZCCParamHandler> Class)
{
	return GetHandlerByClass(ParamHandlers, Class);
}
