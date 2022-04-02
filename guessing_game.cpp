// Copyright (c) 2022 St. Mother Teresa HS All rights reserved.
//
// Created by: Andrew Ten-Den
// Created on: April 2022
// This program lets the user try and guess the correct number between 0 and 9


#include <iostream>
#include <random>


int main() {
    // this function lets the user guess a random number between 0 and 9
    int someRandomNumber;
    int guessedNumberAsInteger;
    std::string guessedNumberAsString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);

    // input
    std::cout << "Enter a number between 0 and 9: ";
    std::cin >> guessedNumberAsString;

    // process
    try {
        guessedNumberAsInteger = std::stoi(guessedNumberAsString);
        if (guessedNumberAsInteger == someRandomNumber) {
            // output
            std::cout << "You guessed correct!";
        } else if (guessedNumberAsInteger != someRandomNumber) {
            // output
            std::cout << "You guessed wrong!";
            std::cout << "\nThe correct answer was "
            << someRandomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "That was not a valid integer\n";
    }
    std::cout << "\nDone." << std::endl;
}
