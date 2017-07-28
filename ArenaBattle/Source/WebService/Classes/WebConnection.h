// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WebConnection.generated.h"

//DECLARE_DELEGATE_OneParam(FTokenCompleteSignature, const FString&);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTokenCompleteSignature, const FString&, Token);

/**
 * 
 */
UCLASS()
class WEBSERVICE_API UWebConnection : public UObject
{
	GENERATED_BODY()
	
public:
	UWebConnection();
	
	UPROPERTY()
	FString Host;

	UPROPERTY()
	FString URI;

	UFUNCTION()
	void RequestToken(const FString& UserID);
	
	UPROPERTY(BlueprintAssignable, Category = "WebService")
	FTokenCompleteSignature TokenCompleteDelegate;

	// 일일히 연산자 오버로딩을 하는 방법.
	friend FArchive& operator<<(FArchive& Ar, UWebConnection& WC)
	{
		// IsLoading & IsSaving : 현재 FArchive 의 상태를 알 수 있다.
		if (Ar.IsLoading())
		{
			UE_LOG(LogTemp, Warning, TEXT("Archive is Loading State"));
		}
		else if (Ar.IsSaving())
		{
			UE_LOG(LogTemp, Warning, TEXT("Archive is Saving State"));
		}
		else
		{
			return Ar;
		}

		// 전송할 데이터를 FArchive 에 전달한다. 그리고 FArchive 반환.
		return Ar << WC.Host << WC.URI;
	}

};

DECLARE_LOG_CATEGORY_EXTERN(WebConnection, Log, All);