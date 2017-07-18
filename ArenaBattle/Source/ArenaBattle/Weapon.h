// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class ARENABATTLE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 블루 프린트에서 읽기만 가능
	// 메시를 저장 / 메시를 변경 가능하게 하면 크래시 발생
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class USkeletalMeshComponent* Weapon;
	
	// 블루 프린트에서 읽기/쓰기 가능 / 인스턴스마다 다르게 편집 가능 / 카테고리 설정
	//UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Stat")
	//float BaseDamage;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Stat")
	float GetDamage() { return BaseDamage; }

private:
	// AllowPrivateAccess : private 멤버 변수도 블루프린트 스크립트에서 사용 가능
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	float BaseDamage;
};
