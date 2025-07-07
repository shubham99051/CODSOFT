#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // seed random generator once at start
    char playAgain;

    do {
        int secretNumber, guess, attempt = 0, maxAttempts, upperLimit;
        int choice;

        // Show intro and difficulty selection
        cout << "==============================\n";
        cout << "     NUMBER GUESSING GAME     \n";
        cout << "==============================\n\n";
        cout << "Choose your difficulty level:\n";
        cout << "1. Easy   (1-50)   - 10 tries\n";
        cout << "2. Medium (1-100)  - 7 tries\n";
        cout << "3. Hard   (1-200)  - 5 tries\n";
        cout << "Enter 1, 2 or 3: ";
        cin >> choice;

        // Configure game based on selected difficulty
        if (choice == 1) {
            upperLimit = 50;
            maxAttempts = 10;
        } else if (choice == 2) {
            upperLimit = 100;
            maxAttempts = 7;
        } else {
            upperLimit = 200;
            maxAttempts = 5;
        }

        // Generate the secret number
        secretNumber = rand() % upperLimit + 1;
        cout << "\nAlright! I've picked a number between 1 and " << upperLimit << ". Let's see if you can guess it.\n";

        // Begin guessing loop
        while (attempt < maxAttempts) {
            cout << "\nEnter your guess: ";
            cin >> guess;
            attempt++;

            if (guess == secretNumber) {
                cout << " Nice! You nailed it in " << attempt << " attempt(s).\n";
                break;
            } else if (guess < secretNumber) {
                cout << "Too low!";
            } else {
                cout << "Too high!";
            }

            cout << " (" << maxAttempts - attempt << " attempts left)";
        }

        // Reveal the number if the player used all attempts
        if (guess != secretNumber) {
            cout << "\n\n Out of tries! The correct number was: " << secretNumber << "\n";
        }

        // Ask if they want to play again
        cout << "\nPlay again? (Y/N): ";
        cin >> playAgain;
        cout << "\n";

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing! \n";
    return 0;
}