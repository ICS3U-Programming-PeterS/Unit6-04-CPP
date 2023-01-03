// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: January 2, 2023
// This program uses 2 loops (a loop inside a loop) to generate
// random numbers between 1 and 50 and display them to the user.
// It then places the numbers into the 2D array
#include <array>
#include <iostream>
#include <random>

// Constants for minimum and maximum values of random numbers
const int MIN_NUM = 1;
const int MAX_NUM = 50;

// Function to calculate the average of all values in the array
float calcAverage(std::array<std::array<int, 3>, 5> array) {
    // Initialize sum and number of numbers to zero
    float sum = 0;
    float numNumbers = 0;
    // Loop through all elements in the array and add their values to the sum
    // Increment the number of numbers by 1 for each element
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            sum += array[i][j];
            numNumbers++;
        }
    }

    // Calculate the average by dividing the sum by the number of numbers
    float average = sum / numNumbers;
    return average;
}

int main() {
    std::array<std::array<int, 3>, 5> array;
    // Generates a random number from 1 to 50
    int randomNumber;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(MIN_NUM, MAX_NUM);
            randomNumber = idist(rgen);
            array[i][j] = randomNumber;
            std::cout << randomNumber << " ";
        }
        std::cout << std::endl;
    }

    float average = calcAverage(array);
    std::cout << "The average is: " << average << std::endl;
}
