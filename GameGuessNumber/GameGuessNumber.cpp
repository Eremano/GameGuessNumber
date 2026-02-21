#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

class Language {
private:
    string lang;

public:
    void chooseLanguage() {
        cout << "Choose language / Выбери язык:\n";
        cout << "1. Русский" << endl;
        cout << "2. English" << endl;
        cout << "Your choice: " << endl;

        int choice;
        cin >> choice;

        if (choice == 2) {
            lang = "en";
        }
        else {
            lang = "ru";
        }
    }

    string get(string ruText, string enText) {
        if (lang == "en") {
            return enText;
        }
        else {
            return ruText;
        }
    }
};

class game {
private:
    int num;
    int attemps;
    int maxnumder;
    int secretnumber;
    Language* lang;

public:
    game(int maxnum = 50, Language* langPtr = nullptr) {
        maxnumder = maxnum;
        attemps = 10;
        lang = langPtr;

        srand(static_cast<unsigned int>(time(0)));
        secretnumber = rand() % maxnum + 1;

        cout << lang->get("привет, я игра!", "hello, i'm game!") << endl;
        cout << lang->get("я загадываю число, а ты должен его угадать за ",
            "i'm thinking of a number, you have ")
            << attemps << " "
            << lang->get("попыток", "attempts") << endl;
        cout << lang->get("число от 1 до ", "number from 1 to ") << maxnum << endl;
    }

    ~game() {
        cout << lang->get("загаданное число было: ", "the secret number was: ")
            << secretnumber << endl;
        cout << lang->get("спасибо за игру!", "thanks for playing!") << endl << endl;
    }

    bool guess(int guess) {
        attemps--;

        if (guess == secretnumber) {
            cout << lang->get("верно, это число ", "correct, it's ")
                << secretnumber << endl;
            cout << lang->get("ты угадал за ", "you guessed in ")
                << (5 - attemps) << " "
                << lang->get("попыток", "attempts") << endl;
            return true;
        }

        if (guess < secretnumber) {
            cout << lang->get("попробуй больше", "try higher") << endl;
        }
        else {
            cout << lang->get("попробуй меньше", "try lower") << endl;
        }

        cout << lang->get("осталось попыток: ", "attempts left: ")
            << attemps << endl;
        return false;
    }

    bool haveatemmpts() {
        return attemps > 0;
    }

    void SecretNumber() {
        cout << lang->get("загаданное число было: ", "the secret number was: ")
            << secretnumber << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Language lang;
    lang.chooseLanguage();

    cout << lang.get("=== ИГРА 'УГАДАТЬ ЧИСЛО' ===",
        "=== GUESS THE NUMBER GAME ===") << endl;

    char playAgain = 'д';

    while (playAgain == 'д' || playAgain == 'Д' || playAgain == 'y' || playAgain == 'Y') {
        game game(50, &lang);

        bool won = false;

        while (game.haveatemmpts()) {
            int guess;
            cout << lang.get("Введи число: ", "Enter number: ");
            cin >> guess;

            if (game.guess(guess)) {
                won = true;
                break;
            }
        }

        if (!won) {
            cout << lang.get("попытки закончились!", "out of attempts!") << endl;
            game.SecretNumber();
        }

        cout << lang.get("сыграем еще? (д или н / y or n): ",
            "play again? (y or n): ");
        cin >> playAgain;
    }

    cout << lang.get("спасибо за игру!", "thanks for playing!") << endl;
    return 0;
}
