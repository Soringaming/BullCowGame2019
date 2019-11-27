// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //Initialize the game
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if(bGameOver) 
    {
        ClearScreen();
        SetupGame();
    } 
    else // checking PlayerGuess
    {
        ProcessGuess(Input);
    }
    /*
    Check Isogram
        If not, promt for guess.
    Remove lives
        Are lives greater than 0?
        If yes GuessAgain
            Show lives left
        If no show GameOver and HiddenWord?
    check user input
    PlayAgain or Quit
*/
}

void UBullCowCartridge::SetupGame()
{
    // Set lives
    // Prompt Player for guess
    HiddenWord = TEXT("Bake");
    // TODO Randomize hidden word
    Lives = HiddenWord.Len();
    bGameOver = false;
    WelcomePlayer();
}

void UBullCowCartridge::WelcomePlayer()
{
    // Welcome the player
    PrintLine(TEXT("DEBUG: The hidden word is: %s"), *HiddenWord);
    PrintLine(TEXT("Welcome to Bulls and Cows!"));
    PrintLine(TEXT("Can you guess the %i letter isogram?"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Press 'Tab' to start typing your guess!"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord) // Win
    {
        PrintLine(TEXT("You Win!"));
        EndGame(); // play again
    } 
    else
    {
        PrintLine(TEXT("You have lost a life and \nhave %i lives left."), --Lives);
        if(Lives > 0) 
        {
            if (Guess.Len() != HiddenWord.Len()) // Check Length
            {
                PrintLine(TEXT("The hidden isogram is %i characters long. \nAn isogram is a word without \nrepeating characters."), HiddenWord.Len());
            }
        } 
        else 
        {
            PrintLine(TEXT("You have no lives left!"));
            EndGame();
        }
    }   
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}