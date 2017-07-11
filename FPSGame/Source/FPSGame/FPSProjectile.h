// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSProjectile.generated.h"

UCLASS()
class FPSGAME_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sphere Collision Component
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent * CollisionComponent;
	
	// Movement Component
	UPROPERTY(VisibleAnywhere, Category = Movement)
	class UProjectileMovementComponent * ProjectileMovementComponent;

	// 발사 방향으로 초기화
	void FireInDirection(const FVector& ShootDirection);

	// 충돌 시 호출되는 함수
	UFUNCTION()
		void OnHit(UPrimitiveComponent * HitComponent, AActor* OtherActor,
			UPrimitiveComponent * OtherComponent, FVector NormalImpulse, 
			const FHitResult& Hit);
};
