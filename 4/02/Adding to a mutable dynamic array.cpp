#include <iostream>

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int element)
{
    if (actual_size > logical_size) // Если фактический размер больше логического, то просто доавляю элемент в запас
    {
        logical_size += 1;
        arr[logical_size - 1] = element;
        return arr;
    }
    else // Иначе создаю новый массив в два раза больше фактического и возвращаю его
    {
        actual_size *= 2;
        logical_size += 1;

        int* tempArr = new int[actual_size]();

        for (int i = 0; i < logical_size - 1; ++i)
        {
            tempArr[i] = arr[i];
        }
        tempArr[logical_size - 1] = element;

        delete[] arr;
        arr = nullptr;

        return tempArr;
    }
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    if (logical_size > 0) // Если логический массив больше нуля, то печатаем сначала элементы, затем запас
    {
        for (int i = 0; i < actual_size; ++i)
        {
            if (logical_size > i)
            {
                std::cout << arr[i] << " ";
            }
            else
            {
                std::cout << "_ ";
            }
        }
    }
    else // Иначе нижнее подчеркивание
    {
        std::cout << "_ ";
    }
    std::cout << std::endl;
}

int main()
{
    // Переменные для ввода фактического и логического размера
    int actualSize = 0;
    int logicalSize = 0;

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actualSize;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logicalSize;

    if (actualSize < logicalSize) // Если логический размер больше фактического
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
    }
    else
    {
        int* dynamicArr = new int[actualSize]();

        for (int i = 0; i < logicalSize; ++i) // Ввод значений в массив
        {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> dynamicArr[i];
        }

        while (true)
        {
            int inputElement = 0; // Элемент для добавления

            // Печать массива
            std::cout << "Динамический массив: ";
            print_dynamic_array(dynamicArr, logicalSize, actualSize);
            std::cout << "Введите элемент для добавления: ";

            std::cin >> inputElement;
            if (inputElement != 0) // Если вводимоее число не ноль, то добавляем элемент
            {
                dynamicArr = append_to_dynamic_array(dynamicArr, logicalSize, actualSize, inputElement);
            }
            else // Если вводимоее число ноль, то заканчиваем принимать значения
            {
                std::cout << "Спасибо! Ваш массив: ";
                print_dynamic_array(dynamicArr, logicalSize, actualSize);
                break;
            }
        }

        delete[] dynamicArr;
        dynamicArr = nullptr;
    }
}