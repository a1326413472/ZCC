// Fill out your copyright notice in the Description page of Project Settings.


#include "Creation/ZCCSpecieDataAsset.h"
#include "ZCCCoreLibraryStatic.h"

bool UZCCSpecieDataAsset::GetPresetCreation(FName PresetIdentifier, FZCCCharacterCreation& CharacterCreation)
{
	return UZCCCoreLibraryStatic::GetDataTableRow(DT_Preset, PresetIdentifier, CharacterCreation);
}

bool UZCCSpecieDataAsset::GetDefaultCreation(FZCCCharacterCreation& CharacterCreation)
{
	return GetPresetCreation("default", CharacterCreation);
}
