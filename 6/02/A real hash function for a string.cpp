#include <iostream>
#include <tgmath.h>

int realStringHash(std::string& word, int primeNumber, int module)
{
    int hash = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        hash += static_cast<int>(word[i]) * static_cast<int>(pow(primeNumber, i));
    }

    return hash % module;
}

int main()
{
    int primeNumber = 1;
    int module = 1;
    std::string input = "_";

    std::cout << "Введите p: ";
    std::cin >> primeNumber;
    std::cout << "Введите n: ";
    std::cin >> module;

    while (input != "exit")
    {
        std::cout << "Введите строку: ";
        std::cin >> input;

        std::cout << "Хэш строки " << input << " = " << realStringHash(input, primeNumber, module) << std::endl;
    }

    return 0;
}