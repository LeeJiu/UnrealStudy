// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPawn.h"
#include "ABGameInstance.h"
#include "ArenaBattle.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/AssetManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AABPawn::AABPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ===== 컴포넌트 생성 =====

	Body = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Body"));
	RootComponent = Body;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Body);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Body);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Body);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));


	Body->SetCapsuleSize(34.0f, 88.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	//하드 레퍼런싱
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		SK_Warrior(TEXT("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Barbarous.SK_CharM_Barbarous'"));
	Mesh->SetSkeletalMesh(SK_Warrior.Object);
	
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 650.0f;	
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;

	MaxHP = 100.0f;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AABPawn::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = MaxHP;

	NewIndex = FMath::RandRange(0, CharacterAssets.Num() - 1);

	// 동기 로딩
	//TAssetPtr<USkeletalMesh> NewCharacter =
	//	UAssetManager::GetStreamableManager().SynchronousLoad(CharacterAssets[NewIndex]);
	//if (NewCharacter)
	//{
	//	Mesh->SetSkeletalMesh(NewCharacter.Get());
	//}

	// ======================================================================================

	// 비동기 로딩
	//StreamableDelegate.BindUObject(this, &AABPawn::CharacterMeshDeferred);
	//ABGameInstance->AssetLoader.RequestAsyncLoad(CharacterAssets[NewIndex], StreamableDelegate);

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterAssets[NewIndex],
		FStreamableDelegate::CreateUObject(this, &AABPawn::CharacterMeshDeferred));

	
}

// Called every frame
void AABPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector InputVector = FVector(CurrentUpDownVal, CurrentLeftRightVal, 0.0f);
	if (InputVector.SizeSquared() > 0.0f)
	{
		FRotator TargetRotation = UKismetMathLibrary::MakeRotFromX(InputVector);
		SetActorRotation(TargetRotation);
		AddMovementInput(GetActorForwardVector());
	}
}

// Called to bind functionality to input
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LeftRight", this, &AABPawn::LeftRightInput);
	PlayerInputComponent->BindAxis("UpDown", this, &AABPawn::UpDownInput);
}

void AABPawn::CharacterMeshDeferred()
{
	AB_LOG_CALLONLY(Warning);

	TAssetPtr<USkeletalMesh> NewCharacter(CharacterAssets[NewIndex]);
	if (NewCharacter)
	{
		Mesh->SetSkeletalMesh(NewCharacter.Get());
	}
}

void AABPawn::UpDownInput(float NewInputVal)
{
	CurrentUpDownVal = NewInputVal;
}

void AABPawn::LeftRightInput(float NewInputVal)
{
	CurrentLeftRightVal = NewInputVal;
}

