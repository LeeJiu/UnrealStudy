// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"	//.generated.h 는 무조건 마지막에 선언

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	
public:
	UABGameInstance();

	virtual void Init() override;
	
	UPROPERTY()
	class UWebConnection* WebConnection;
};
