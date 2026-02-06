#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

class game {
private:
    int num;
    int attemps;
    int maxnumder;
    int secretnumber;

public:
    game(int maxnum = 50) {
        maxnumder = maxnum;
        attemps = 5;

        srand(static_cast<unsigned int>(time(0)));
        secretnumber = rand() % maxnum + 1;

        cout << "привет, я игра!" << endl;
        cout << "я загадываю число, а ты должен его угадать за " << attemps << " попыток" << endl;
        cout << "число от 1 до " << maxnum << endl;
    }

    ~game() {
        cout << "загаданное число было: " << secretnumber << endl;
        cout << "спасибо за игру, ждем тебя снова!" << endl << endl;
    }

    bool guess(int guess) {
        attemps--;

        if (guess == secretnumber) {
            cout << "верно, это число " << secretnumber << endl;
            cout << "ты угадал(а) загаданное число за " << (5 - attemps) << " попыток" << endl;
            return true;
        }

        if (guess < secretnumber) {
            cout << "попробуй больше" << endl;
        }
        else {
            cout << "попробуй меньше" << endl;
        }

        cout << "осталось попыток: " << attemps << endl;
        return false;
    }

    bool haveatemmpts() {
        return attemps > 0;
    }

    void SecretNumber() {
        cout << "загаданное число было: " << secretnumber << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== ИГРА 'УГАДАТЬ ЧИСЛО' ===" << endl;

    char playAgain = 'д';

    while (playAgain == 'д' || playAgain == 'Д') {
        game game;

        bool won = false;

        while (game.haveatemmpts()) {
            int guess;
            cout << "\nВведи число: ";
            cin >> guess;

            if (game.guess(guess)) {
                won = true;
                break;
            }
        }

        if (!won) {
            cout << "\nпопытки закончились!" << endl;
            game.SecretNumber();
        }

        cout << "\nсыграем еще? (д или н): ";
        cin >> playAgain;

    }

    cout << "спасибо за игру!" << endl;
    return 0;
}