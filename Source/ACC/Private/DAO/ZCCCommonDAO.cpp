// Fill out your copyright notice in the Description page of Project Settings.


#include "DAO/ZCCCommonDAO.h"

#include "ZCCCoreLibraryStatic.h"
#include "ZCCGameSubsystem.h"

bool UZCCCommonDAO::GetSpecieData(FName Identifier, UZCCSpecieDataAsset*& SpecieData)
{
	if (UZCCGameSubsystem* ZCCGameSubsystem = GetZCCSubsystem())
	{
		FZCCSpecieRowTable MySpecieRowTable;
		UDataTable* MyInDataTable = ZCCGameSubsystem->GetGameData()->DT_Specie;
		FName MyIdentifier = Identifier;

		bool MyGetDataTableRow = UZCCCoreLibraryStatic::GetDataTableRow(MyInDataTable, MyIdentifier, MySpecieRowTable);

		if (MyGetDataTableRow)
		{
			SpecieData = MySpecieRowTable.Data.LoadSynchronous();

			return true;
		}
	}
	return false;
}
