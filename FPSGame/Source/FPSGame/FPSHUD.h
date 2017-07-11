// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	// 화면 중앙에 그린다.
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;

public:
	// HUD에 대한 주요 DrawCall
	virtual void DrawHUD() override;
	
};
