#include <iostream>
#include <Windows.h>
#include <cstdlib>
using namespace std;

bool visg(int year)
{
    bool res = false;
    if (year % 4 == 0)
        res = true;
    if (year % 100 == 0)
        res = false;
    if (year % 400 == 0)
        res = true;
    return res;
}
int date(int d, int m, int y)
{
    int k = d;
    if (visg(y) && (m > 2))
        k += y * 366;
    else k += y * 365;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: k += 28;
    case  1: k += 31;
    }
    return k;
}
int difference(int day1, int day2, int month1, int month2, int year1, int year2)
{
    int k = date(day2, month2, year2) - date(day1, month1, year1);
    return k;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int day1, day2, month1, month2, year1, year2;
    std::cout << "введите день 1 даты: ";
    std::cin >> day1;
    std::cout << "введите месяц первой даты: ";
    std::cin >> month1;
    std::cout << "введите год первой даты: ";
    std::cin >> year1;
    std::cout << "введите день 2 даты: ";
    std::cin >> day2;
    std::cout << "введите месяц 2 даты: ";
    std::cin >> month2;
    std::cout << "введите год 2 даты:: ";
    std::cin >> year2;
    std::cout << "разница в " << difference(day1, day2, month1, month2, year1, year2) << " дней\n";
}

double average(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    double avg = average(arr, n);

    std::cout << "среднее арифметическое массива: " << avg;

    return 0;
}

//еще 2 задачи (хз как делать)

int NOD(int a, int b)
{
    if (b == 0)
        return a;
    if (a > b)
        return NOD(b, a % b);
    else
        return NOD(a, b % a);
}

int main()
{
    int a, b;
    std::cout << "введите 2 числа: ";
    std::cin >> a >> b;
    std::cout << "наибольльший общий делитель равен: " << NOD(b, a % b);
}

int checkGuess(int guess, int secretNumber)
{
    int bulls = 0;
    int cows = 0;

    string guessStr = to_string(guess);
    string secretNumberStr = to_string(secretNumber);
    for (int i = 0; i < 4; i++)
    {
        if (guessStr[i] == secretNumberStr[i])
        {
            cows++;
        }
        else if (secretNumberStr.find(guessStr[i]) != string::npos)
        {
            bulls++;
        }
    }
    cout << "быки: " << bulls << endl;
    cout << "коровы: " << cows << endl;
    return cows;
}
void playGame(int secretNumber, int attempts = 0)
{
    int guess;
    cout << "введите четырехзначное число: ";
    cin >> guess;
    attempts++;
    if (checkGuess(guess, secretNumber) == 4)
    {
        cout << "вы победили!" << endl;
        cout << "количество попыток: " << attempts << endl;
    }
    else
    {
        playGame(secretNumber, attempts);
    }
}
int main()
{
    srand(time(0));
    int secretNumber = rand() % 9000 + 1000;
    playGame(secretNumber);
    return 0;
}
