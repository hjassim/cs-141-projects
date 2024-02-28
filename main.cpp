// Haneen Jassim
// 1/14/24
// Program creates a game of Bulls and Cows. Player 1 creates a 4 digit solution code, which must abide by a set of rules. Game not not preceed until the solution code follows the rules.
// Player 2 then has 10 attempts to guess the code. If they guess a number that is in the code but is not in the correct position, that is considered a cow. If they guess a number that is in the solution code and in the right position, that is considered a bull.
// Valid guess attempts add 1 to turn count, while invalid attempts do not. The game ends when the code is guessed or if 10 turns have passed.


#include <iostream>

int trueCode1;
int trueCode2;
int trueCode3;
int trueCode4;


// checks for cows in the guessed code
// a cow is a number in the true code but not in the correct position
// parameters are 4 integers
int numCows(int num1, int num2, int num3, int num4) {

    int numberCows = 0;

    if (num1 == trueCode2 || num1 == trueCode3 || num1 == trueCode4) {
        numberCows = numberCows + 1;
    }

    if (num2 == trueCode1 || num2 == trueCode3 || num2 == trueCode4) {
        numberCows = numberCows + 1;
    }

    if (num3 == trueCode1 || num3 == trueCode2 || num3 == trueCode4) {
        numberCows = numberCows + 1;
    }

    if (num4 == trueCode1 || num4 == trueCode2 || num4 == trueCode3) {
        numberCows = numberCows + 1;
    }

    return numberCows;

}

// checks for bulls in the guessed code
// a bull is a number in the true code and in the correct position
// parameters are 4 integers
int numBulls(int num1, int num2, int num3, int num4) {

    int numberBulls = 0;

    if (num1 == trueCode1) {
        numberBulls = numberBulls + 1;
    }

    if (num2 == trueCode2) {
        numberBulls = numberBulls + 1;
    }

    if (num3 == trueCode3) {
        numberBulls = numberBulls + 1;
    }

    if (num4 == trueCode4) {
        numberBulls = numberBulls + 1;
    }

    return numberBulls;
}

// compares 4 integer parameters to the code solution
bool correctGuess (int num1, int num2, int num3, int num4) {

    if (num1 == trueCode1 && num2 == trueCode2 && num3 == trueCode3 && num4 == trueCode4) {
        return true;
    }

    else {
        return false;
    }
}

// checks if the 4 integer parameters follow the game rules
// 1 checks for duplicates, which are not allowed
// 2 must be between 1-9 (single digits, no negatives)
bool guessRules (int num1, int num2, int num3, int num4) {

    if (num1 == num2 || num1 == num3 || num1 == num4 || num2 == num3 || num2 == num4 || num3 == num4) {
        return false;
    }

    else if (num1<0 || num1>9) {
        return false;
    }

    else if (num2<0 || num2>9) {
        return false;
    }

    else if (num3<0 || num3>9) {
        return false;
    }

    else if (num4<0 || num4>9) {
        return false;
    }

    return true;
}

// function that runs the game, using previously defined functions
void codeGuess() {

    std::cout << "Enter the solution to use: ";

    while (1==1) {
        std::cin >> trueCode1;
        std::cin >> trueCode2;
        std::cin >> trueCode3;
        std::cin >> trueCode4;

        if (guessRules(trueCode1, trueCode2, trueCode3, trueCode4) == true) {
            break;
        }

        else {
            std::cout << std::endl << "Invalid code. Try again.";
            std::cout << std::endl << "Enter the solution to use: ";
        }

    }


    int i = 1;

        while (i <= 11) {
            
            if (i==11) {
                std::cout << std::endl<<  "You lose. The correct answer is: ";
                std::cout << trueCode1 << " " << trueCode2 << " " << trueCode3 << " " << trueCode4;
                break;
            }

            std::cout << std::endl << "Turn " << i << ". Enter a guess: ";

            int codeGuess1;
            int codeGuess2;
            int codeGuess3;
            int codeGuess4;

            std::cin >> codeGuess1;
            std::cin >> codeGuess2;
            std::cin >> codeGuess3;
            std::cin >> codeGuess4;

            if (correctGuess(codeGuess1, codeGuess2, codeGuess3, codeGuess4) == true) {
                std::cout << "Congratulations! You win!";
                break;
            }

            if (guessRules(codeGuess1, codeGuess2, codeGuess3, codeGuess4) == false) {
                std::cout << std::endl << "Invalid code. Try again.";
            }

            else {
                std::cout << std::endl << "There are " << (numBulls(codeGuess1, codeGuess2, codeGuess3, codeGuess4)) << " bulls";
                std::cout << " and " << (numCows(codeGuess1, codeGuess2, codeGuess3, codeGuess4)) << " cows." << std::endl;
                i+=1;
            }
        }

}


int main() {
    codeGuess();
    return 0;
}