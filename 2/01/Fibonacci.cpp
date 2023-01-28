#include <iostream>

unsigned long long fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Числа Фибоначчи: ";

    for (int i = 1; i <= n; i++)
    {
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}