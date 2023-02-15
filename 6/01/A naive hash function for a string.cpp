#include <iostream>

int simpleStringHash(std::string &word)
{
    int hash = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        hash += static_cast<int>(word[i]);
    }

    return hash;
}

int main()
{
    std::string input = "_";

    while (input != "exit")
    {
        std::cout << "Введите строку: ";
        std::cin >> input;

        std::cout << "Наивный хэш строки " << input << " = " << simpleStringHash(input) << std::endl;
    }

    return 0;
}