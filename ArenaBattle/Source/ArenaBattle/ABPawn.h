// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ABPawn.generated.h"

//ini 파일을 읽어오기 위해 / 게임 로직 = DefaultGame / 엔진 = DefaultEngine
UCLASS(config=Game)
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	// 인간형 폰의 충돌과 이동을 관리하는 루트 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	class UCapsuleComponent* Body;

	// 인간형 폰의 외형을 담당하는 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Visual")
	class USkeletalMeshComponent* Mesh;

	// 시선 방향을 가리키는 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Helper")
	class UArrowComponent* Arrow;

	// 카메라 구도를 쉽게 세팅할 수 있게 제공하는 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	// 폰에 빙의한 플레이어의 화면을 렌더링할 카메라 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	// 캐릭터를 움직이기 위한 컴포넌트
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
	class UFloatingPawnMovement* Movement;

	// 폰들이 공통적인 값을 가진다.
	UPROPERTY(config, BlueprintReadWrite, EditDefaultsOnly, Category = "Stat")
	float MaxHP;

	// 인스턴스마다 다른 값을 가질 수 있다.
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Stat")
	float CurrentHP;

	UFUNCTION()
	void CharacterMeshDeferred();
	//FStreamableDelegate StreamableDelegate;

private:
	int32 NewIndex;


	// FStringAssetReference : 에셋 정보 / 소프트 레퍼런싱
	UPROPERTY(config)
	TArray<FStringAssetReference> CharacterAssets;

	float CurrentLeftRightVal;
	float CurrentUpDownVal;

	UFUNCTION()
	void UpDownInput(float NewInputVal);

	UFUNCTION()
	void LeftRightInput(float NewInputVal);

};
