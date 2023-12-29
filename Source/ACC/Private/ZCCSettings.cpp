// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCSettings.h"

#define LOCTEXT_NAMESPACE "FZCCModule"

UZCCSettings::UZCCSettings(const FObjectInitializer& Initializer)
{
	SectionName = TEXT("Anime Character Creator");
}

#if WITH_EDITOR
FText UZCCSettings::GetSectionText() const
{
	return LOCTEXT("SettingsDisplayName", "Anime Character Creator");
}
#endif

#undef LOCTEXT_NAMESPACE