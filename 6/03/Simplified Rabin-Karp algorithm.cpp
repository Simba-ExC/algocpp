#include <iostream>

int findSubstringLightRabinKarp(std::string& line, std::string& searchString)
{
    int hashCurrent = 0; // Текущий хэш
    int hashSearch = 0; // Хэш строки, которую нужно найти
    bool match = false; // Переменная для определения, нашлось ли совпадение

    // Вычисляем хэш строки, которую нужно найти
    for (int i = 0; i < searchString.length(); ++i)
    {
        hashSearch += static_cast<int>(searchString[i]);
    }

    // Пробегаем циклом по индексам, которые будем проверять на начало потенциального совпадения с searchString
    for (int i = 0; i < line.length() - searchString.length(); ++i)
    {
        if (i == 0) // Если это первая итерация, то считаем хэш от первых searchString.length() символов
        {
            for (int j = 0; j < searchString.length(); ++j)
            {
                hashCurrent += static_cast<int>(line[j]);
            }
        }
        else // Иначе быстро сгенерируем хэш для следующих searchString.length() символов, используя предыдущее значение такого хэша
        {
            hashCurrent -= line[i - 1];
            hashCurrent += line[i + searchString.length() - 1];
        }

        if (hashCurrent == hashSearch) // Если хэши совпали, то совпадение следующих searchString.length() символов возможно. Проверяем это.
        {
            for (int j = 0; j < searchString.length(); ++j)
            {
                if (line[i + j] == searchString[j])
                {
                    match = true;
                }
                else
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    std::string line = "_"; // Строка, в которй будет осуществляться поиск
    std::string searchString = "_"; // Подстрока, которую нужно найти

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> line;

    while (searchString != "exit")
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> searchString;

        int index = findSubstringLightRabinKarp(line, searchString); // Индекс искомой подстроки
        if (index == -1) // Если -1, то подстрока не найдена
        {
            std::cout << "Подстрока " << searchString << " не найдена" << std::endl;
        }
        else // Иначе печатаем индекс начала подстроки
        {
            std::cout << "Подстрока " << searchString << " найдена по индексу " << index << std::endl;
        }
    }

    return 0;
}