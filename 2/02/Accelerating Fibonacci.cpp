#include <iostream>

unsigned long long fibonacci(int n, unsigned long long* arrFibonacci)
{
    if (arrFibonacci[n - 1] > 0 && n != 1 && n != 2)
    {
        return arrFibonacci[n - 1];
    }
    else if (n == 1)
    {
        return arrFibonacci[n - 1] = 0;
    }
    else if (n == 2)
    {
        return arrFibonacci[n - 1] = 1;
    }
    else
    {
        return arrFibonacci[n - 1] = fibonacci(n - 1, arrFibonacci) + fibonacci(n - 2, arrFibonacci);
    }
}

int main()
{
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Числа Фибоначчи: ";

    unsigned long long* arrFibonacci = new unsigned long long[n]();

    for (int i = 1; i <= n; i++)
    {
        std::cout << fibonacci(i, arrFibonacci) << " ";
    }

    delete[] arrFibonacci;
    arrFibonacci = nullptr;

    return 0;
}
