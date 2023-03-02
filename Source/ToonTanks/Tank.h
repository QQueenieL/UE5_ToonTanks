// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, category="Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, category="Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 200.f;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 45.f;

	void Move(float Value);
	void Turn(float Value);
};