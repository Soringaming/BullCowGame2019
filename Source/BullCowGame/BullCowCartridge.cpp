// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //Initialize the game
    SetupGame();
    PrintLine(TEXT("DEBUG: The hidden word is: %s"), *HiddenWord);

    // Welcome the player
    PrintLine(TEXT("Welcome to Bulls and Cows!"));
    PrintLine(TEXT("Can you guess the %i letter isogram?"), HiddenWord.Len());
    PrintLine(TEXT("Press 'Tab' to start typing your guess!"));

    // Set lives
    // Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    /* Basic game loop
        TODO Move this to it's own funtion
    */
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Your word was: %s"), *Input);
        PrintLine(TEXT("You Win!"));
    } 
    else
    {
        if (Input.IsEmpty())
        {
            PrintLine(TEXT("Input your guess for a %i letter isogram"), HiddenWord.Len()); // TODO Magic Number removal
        } 
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("Please input a %i letter isogram!"), HiddenWord.Len()); // TODO Magic Number removal
        }

        PrintLine(TEXT("Your word was: %s"), *Input);
        PrintLine(TEXT("You lose!"));
    }
    /*
    Check Isogram
        If not, promt for guess.
    Check Length
        If not, promt for guess.
    Is it correct?
        If yes Win
    Remove lives
        Are lives greater than 0?
        If yes GuessAgain
            Show lives left
        If no show GameOver and HiddenWord?
    promt to play again
    check user input
    PlayAgain or Quit
*/
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("Bake");
    // TODO Randomize hidden word
    Lives = 5;
}