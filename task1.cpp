#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    char playAgain;
    do {
        int secretNumber = rand() % 100 + 1;
        int guess = 0;
        int attempts = 0;
        const int maxAttempts = 7;

        cout << "\n=========================================\n";
        cout << "      WELCOME TO THE NUMBER GUESSING     \n";
        cout << "=========================================\n";
        cout << "I have chosen a number between 1 and 100.\n";
        cout << "You have " << maxAttempts << " attempts to guess it!\n\n";

        while (attempts < maxAttempts) {
            cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ". Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > secretNumber) {
                cout << "Too high! Try again.\n";
            } else if (guess < secretNumber) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!\n";
                break;
            }
        }

        if (guess != secretNumber) {
            cout << "\nGame Over! The correct number was: " << secretNumber << "\n";
        }

        cout << "\nWould you like to play another round? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}