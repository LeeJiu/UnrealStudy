// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (CrosshairTexture)
	{
		// 캔버스의 중심 구한다.
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		// 텍스처의 중심이 캔버스의 중심에 맞도록 텍스처 크기 절반만큼 오프셋을 준다.
		FVector2D CrossHairDrawPosition(
			Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), 
			Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));

		// 중심점에 조준선 그린다.
		FCanvasTileItem TileItem(
			CrossHairDrawPosition, CrosshairTexture->Resource, 
			FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}
