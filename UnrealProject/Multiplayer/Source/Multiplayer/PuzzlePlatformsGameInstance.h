// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);
	
	virtual void Init();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void LoadMenuWidget();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void InGameLoadMenu();

	UFUNCTION(Exec)
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& Address) override;

	UFUNCTION(Exec)
	virtual void LoadMainMenu() override;


private:
	TSubclassOf<class UUserWidget> MenuClass;

	class UMainMenu* Menu;

	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UInGameMenu* InGameMenu;
	
};
