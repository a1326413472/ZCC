// Fill out your copyright notice in the Description page of Project Settings.


#include "Creation/ZCCParamHandler.h"

bool UZCCParamHandler::OnReceiveInt_Implementation(UZCCCreationComponent* CreationComponent, FZCCIntParam IntParam)
{
	return true;
}

bool UZCCParamHandler::OnReceiveFloat_Implementation(UZCCCreationComponent* CreationComponent, FName FloatParam)
{
	return true;
}