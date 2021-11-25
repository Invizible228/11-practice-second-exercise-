// SecEx.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <windows.h>

using namespace std; // Глобальные переменные
int const N = 4;
int mas[N][N];
unsigned int Count;

void FirstStroke()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        mas[0][i] = rand() % 1000; // рандомизирование до 999
        cout << mas[0][i] << " "; // Выводим
        if ((mas[0][i] / 10) > 0 && (mas[0][i] / 10) <= 10)
        {
            Count++; // Прибавляем к Count +1 за каждое двухзначное число
        }
    }
    cout << endl;
}

void SecondStroke()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        mas[1][i] = rand() % 1000; 
        cout << mas[1][i] << " ";
        if ((mas[1][i] / 10) > 0 && (mas[1][i] / 10) <= 10)
        {
            Count++; 
        }
    }
    cout << endl;
}

void ThirdStroke()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        mas[2][i] = rand() % 1000; 
        cout << mas[2][i] << " ";
        if ((mas[2][i] / 10) > 0 && (mas[2][i] / 10) <= 10)
        {
            Count++;
        }
    }
    cout << endl;
}

void FourthStroke()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        mas[3][i] = rand() % 1000; 
        cout << mas[3][i] << " ";
        if ((mas[3][i] / 10) > 0 && (mas[3][i] / 10) <= 10)
        {
            Count++;
        }
    }
    cout << endl;
}

    int main()
    {
        setlocale(LC_ALL, "Russian");
        int max = 0;
        int min = 1000;
        cout << "Матрица 4 X 4" << endl;
        Sleep(250); //Немного замедляем вывод матрицы
        thread th1(FirstStroke); // Выводим через потоки
        th1.join(); // Блокируем поток
        Sleep(250);
        thread th2(SecondStroke);
        th2.join();
        Sleep(250);
        thread th3(ThirdStroke);
        th3.join();
        Sleep(250);
        thread th4(FourthStroke);
        th4.join();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mas[i][j] > max)
                {
                    max = mas[i][j]; //Находим максимальное
                }

                if (mas[i][j] < min)
                {
                    min = mas[i][j]; //Находим минимальное
                }
            }
        }
        if (Count == 0) { cout << "Двухзначных чисел в данной матрице нет" << endl; }
        else { cout << "Количество двухзначных чисел:" << Count << endl; }
        cout << "Минимальное число:" << max << endl;
        cout << "Максимальное число:" << min << endl;
        return 0;
    }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
