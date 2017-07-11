// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"
#include "Engine.h"
#include "Camera/CameraComponent.h"
//#include "Components/SkeletalMeshComponent.h"
//#include "Components/CapsuleComponent.h"
#include "FPSProjectile.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 1인칭 카메라 컴포넌트를 가져온다.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// 카메라 컴포넌트를 캡슐 컴포넌트에 붙인다.
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
	// 카메라 위치 설정 / 눈보다 윗 쪽에
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// 폰이 카메라 회전을 제어가능 하게 한다.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// 메시 컴포넌트를 가져온다.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// 오너 컴포넌트만 메시를 볼 수 있다.
	FPSMesh->SetOnlyOwnerSee(true);
	// 메시에 카메라를 붙인다.
	FPSMesh->SetupAttachment(FPSCameraComponent);
	// 일부 환경 섀도우를 꺼서 하나의 메시만 보여준다.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// 본인 외에는 3인칭 메시를 볼 수 있다.
	GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Fire()
{
	// 발사 시도
	if (ProjectileClass)
	{
		// Camera Transform
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);	//액터의 눈 위치와 방향 받아온다.

		// Camera Space To World Space / 액터의 위치와 방향으로 총구 위치와 방향 설정
		FVector MuzzleLocation = 
			CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		// 조준을 약간 위쪽으로
		MuzzleRotation.Pitch += 10.0f;
		UWorld * World = GetWorld();
		// UWorld
		// 랜더되거나 존재하는 액터와 컴포넌트가 있는
		// 샌드 박스나 맵을 나타내는 최상위 객체

		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// 총구 위치에 발사체 스폰 시킨다.
			AFPSProjectile * Projectile = 
				World->SpawnActor<AFPSProjectile>(
					ProjectileClass, MuzzleLocation, 
					MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// 발사 방향 구한다.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}