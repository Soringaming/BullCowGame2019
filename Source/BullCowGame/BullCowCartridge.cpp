// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if(bGameOver) 
    {
        ClearScreen();
        SetupGame();
    } 
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    // TODO Randomize hidden word
    HiddenWord = TEXT("Bake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    WelcomePlayer();
    // const TCHAR HW[] = TEXT("plum");
    // PrintLine(TEXT("Letter 1 of the hidden word is: %c"), HiddenWord[0]);
    // PrintLine(TEXT("Letter 1 of the fake hidden word is: %c"), HW[0]);
}

void UBullCowCartridge::WelcomePlayer() const
{
    // Welcome the player
    PrintLine(TEXT("Welcome to Bulls and Cows!"));
    PrintLine(TEXT("Can you guess the %i letter isogram?"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Press 'Tab' to start typing your guess!"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    // Win
    if (Guess == HiddenWord)
    {
        ClearScreen();
        PrintLine(TEXT("You Win!"));
        EndGame(); // PlayAgain or Quit
        return;
    } 
    
    // Check Length
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden isogram is %i characters long."), HiddenWord.Len());
        return;
    }
    
    //Check Isogram
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("An isogram is a word without \nrepeating characters.\nTry again."));
        return;
    }

    // At this point the player didn't guess right
    // Remove life and return for player input
    --Lives;
    PrintLine(TEXT("You have lost a life."));
    if(Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    } 

    // Show the player bulls and cows
    PrintLine(TEXT("Guess again, you have %i lives left."), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    // Loop through index and compare
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for(int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if(Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }
    return true;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again."));
}