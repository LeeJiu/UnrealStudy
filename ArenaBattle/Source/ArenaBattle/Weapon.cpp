// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SkeletalMeshComponent �� ����
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponBlackKnight"));
	RootComponent = Weapon;

	// ConstructorHelpers
	// -> �ּ¿� ���õ� ������ ������ �� �ִ�.
	// -> �����ڿ����� ��� �����ϴ�.
	// => CDO ���ۿ� ���ȴ�.
	// <-> StaticLoadObject(���� �÷��� ��Ÿ�� �߿� �ּ� �ε��Ϸ���)
	// ClassFinder : �ּ��� �� ����
	// ObjectFinder : �ּ��� ���빰
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BlackKnight(
		TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight'"));
	Weapon->SetSkeletalMesh(SK_BlackKnight.Object);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

