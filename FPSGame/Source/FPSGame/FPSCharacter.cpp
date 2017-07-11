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

	// 1��Ī ī�޶� ������Ʈ�� �����´�.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// ī�޶� ������Ʈ�� ĸ�� ������Ʈ�� ���δ�.
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());
	// ī�޶� ��ġ ���� / ������ �� �ʿ�
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// ���� ī�޶� ȸ���� ����� �ϰ� �Ѵ�.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// �޽� ������Ʈ�� �����´�.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// ���� ������Ʈ�� �޽ø� �� �� �ִ�.
	FPSMesh->SetOnlyOwnerSee(true);
	// �޽ÿ� ī�޶� ���δ�.
	FPSMesh->SetupAttachment(FPSCameraComponent);
	// �Ϻ� ȯ�� �����츦 ���� �ϳ��� �޽ø� �����ش�.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// ���� �ܿ��� 3��Ī �޽ø� �� �� �ִ�.
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
	// �߻� �õ�
	if (ProjectileClass)
	{
		// Camera Transform
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);	//������ �� ��ġ�� ���� �޾ƿ´�.

		// Camera Space To World Space / ������ ��ġ�� �������� �ѱ� ��ġ�� ���� ����
		FVector MuzzleLocation = 
			CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		// ������ �ణ ��������
		MuzzleRotation.Pitch += 10.0f;
		UWorld * World = GetWorld();
		// UWorld
		// �����ǰų� �����ϴ� ���Ϳ� ������Ʈ�� �ִ�
		// ���� �ڽ��� ���� ��Ÿ���� �ֻ��� ��ü

		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// �ѱ� ��ġ�� �߻�ü ���� ��Ų��.
			AFPSProjectile * Projectile = 
				World->SpawnActor<AFPSProjectile>(
					ProjectileClass, MuzzleLocation, 
					MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// �߻� ���� ���Ѵ�.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}