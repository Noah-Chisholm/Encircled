// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Encircled/Utility/Flag.h"
#include "Encircled/Utility/EntityFlags.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ENCIRCLED_API APC_ROTLA : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APC_ROTLA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void JumpROTLA(const FInputActionValue& Value);

	void CrouchHandler(const FInputActionValue& Value);

	void CrouchROTLA();

	void HandleBack(const FInputActionValue& Value);

	void SprintHandler(const FInputActionValue& Value);

	void Sprint();

	void Slide();

	void StopMove();

	void StopSprint();
	
	void StopCrouch();

	void StopSlide();

	void StopJump();

	void StopJumping();

	void HandleStartPrimaryAction();
	
	void HandleFinishPrimaryAction();

	void HandleSecondaryAction();

	void HandleTertiarayAction();

	void HandleInteractionAction();

	void HandleReload();

	void ChangeHeight(float DesiredHeight);

	UFUNCTION(BlueprintImplementableEvent)
	void ExitWidget();

	bool CanJumpInternal_Implementation() const override;

	UFlag* PlayerFlag;
	
	UFUNCTION(BlueprintCallable)
	void SetFlag(EEntityFlags Value) {
		PlayerFlag->_SetFlag(static_cast<int32>(Value));
	}; 
	UFUNCTION(BlueprintCallable)
	void RemoveFlag(EEntityFlags Value) {
		PlayerFlag->_RemoveFlag(static_cast<int32>(Value));
	}; 
	UFUNCTION(BlueprintCallable)
	bool HasFlag(EEntityFlags Value) const {
		return PlayerFlag->_HasFlag(static_cast<int32>(Value));
	};

	virtual void Landed(const FHitResult& Hit) override;

	FTimerHandle MovingTimer;
	float NormalHeight;
	float CrouchHeight;
	float SlideHeight;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float crouchHeightMult = 0.5f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float slideHeightMult = 0.5f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float CrouchSpeed = 300.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float LoudnessMult = 1.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float CrouchNoiseMult = 0.5f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float NoiseRange = 1000.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float WalkSpeed = 600.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SprintSpeed = 900.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SlideBoost = 1250.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SlideDuration = 2.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SlideFriction = 0.1f;
	float NormalFriction;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float JumpHeight = 550.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float HeightChangeSpeed = 1.0f;
	float DesiredHeight;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float AirControl = 0.0f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	int32 MaxJumps = 1;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float MaxJumpTime = 0.5f;
	
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	float SlideTime = 0.0f;
	
	FVector SlideDirection;
	
	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	float InteractionDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* BackAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PrimaryAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SecondaryAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* TertiararyAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InteractableAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* ReloadAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FirstPersonCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapons")
	class USceneComponent* PrimaryGripLocation;

	class ADebugWeapon* EquipedWeapon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
