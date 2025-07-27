#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class DiceGame {
private:
    int rollCount;

    // Generates a random number between 1 and 6
    int rollDie() {
        return (rand() % 6) + 1;
    }

public:
    DiceGame() {
        rollCount = 0;
        srand(static_cast<unsigned int>(time(0)));  // Seed the random generator
    }

    void start() {
        char choice = 'y';
        while (choice == 'y' || choice == 'Y') {
            int numDice;
            cout << "\nEnter the number of dice to roll: ";
            cin >> numDice;

            if (numDice <= 0) {
                cout << "Please enter a positive number of dice.\n";
                continue;
            }

            vector<int> results;
            for (int i = 0; i < numDice; ++i) {
                results.push_back(rollDie());
            }

            cout << "You rolled: ";
            for (int value : results) {
                cout << value << " ";
            }
            cout << endl;

            rollCount++;

            cout << "Do you want to roll again? (y/n): ";
            cin >> choice;
        }

        cout << "\nTotal rolls this session: " << rollCount << endl;
        cout << "Thank you for playing!\n";
    }
};

int main() {
    cout << "===== Welcome to the Dice Rolling Simulator =====\n";

    DiceGame game;
    game.start();

    return 0;
}