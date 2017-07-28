// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"	//.generated.h 는 무조건 마지막에 선언


class FHouse
{
public:
	TSharedPtr<FHouse> OthersDeed;
	TWeakPtr<FHouse> AccessHouse;
	int32 Size = 10;
};

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
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "WebService")
	class UWebConnection* WebConnection;

	UPROPERTY()
	class UWebConnection* WebConnectionNew;

	UPROPERTY()
	class UWebConnection* WebConnectionNew2;

	UPROPERTY()
	class UWebConnection* WebConnectionNew3;

	class UWebConnection* WebConnectionTest;

	UFUNCTION()
	void RequestTokenComplete(const FString& Token);

	FTimerHandle ObjectCheckTimer;

	UFUNCTION()
	void CheckUObjectAlive();


	void Search();

	void BindDelegate();

	void SerializationAndPackaging();

	void SmartPointer();
};