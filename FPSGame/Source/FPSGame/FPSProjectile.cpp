// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = 
		CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	// New Collision Channel Use
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);

	// Sphere�� �ݰ� ����
	CollisionComponent->InitSphereRadius(15.0f);

	// �ùķ��̼����� ���������� ���̹Ƿ� CollisionComponent�� RootComponent�� �����.
	RootComponent = CollisionComponent;
	
	// �߻�ü Movement management
	ProjectileMovementComponent = 
		CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// �߻�ü ���� ����
	InitialLifeSpan = 3.0f;

	
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// �ӵ��� �߻� �������� �ʱ�ȭ
void AFPSProjectile::FireInDirection(const FVector & ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void AFPSProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(
			ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
}
