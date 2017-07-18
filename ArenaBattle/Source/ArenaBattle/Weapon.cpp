// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SkeletalMeshComponent 를 생성
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponBlackKnight"));
	RootComponent = Weapon;

	// ConstructorHelpers
	// -> 애셋에 관련된 정보를 가져올 수 있다.
	// -> 생성자에서만 사용 가능하다.
	// => CDO 제작에 사용된다.
	// <-> StaticLoadObject(게임 플레이 런타임 중에 애셋 로딩하려면)
	// ClassFinder : 애셋의 형 정보
	// ObjectFinder : 애셋의 내용물
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

