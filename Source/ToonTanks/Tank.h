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
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const {return TankPlayerController;}
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, category="Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, category="Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 600.f;
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 45.f;

	APlayerController* TankPlayerController;
	void Move(float Value);
	void Turn(float Value);
};
