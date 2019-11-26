// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    /*Welcome Message and hidden word
    TODO Randomize the hidden word.
    */
    HiddenWord = TEXT("Rakes");

    // Welcome the player
    PrintLine(TEXT("       Welcome to Bulls and Cows!"));
    PrintLine(TEXT("Press 'Tab', and then 'Enter' to start!"));

    // Set lives
    // Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    /* Basic game loop
        TODO Move this to it's own funtion
    */
    if(Input == HiddenWord) {
        PrintLine(TEXT("Your word was: ") + Input);
        PrintLine(TEXT("You Win!"));
    } else if (Input.IsEmpty()){
        PrintLine(TEXT("Input your guess for a five letter isogram")); // TODO Magic Number removal
    } else {
        PrintLine(TEXT("Your word was: ") + Input);
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