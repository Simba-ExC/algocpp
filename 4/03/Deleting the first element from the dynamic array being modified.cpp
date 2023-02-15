#include <iostream>

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    if (logical_size - 1 > actual_size / 3) // Если логический массив -1 больше трети фактического
    {
        logical_size -= 1;

        for (int i = 0; i < logical_size; ++i)
        {
            arr[i] = arr[i + 1];
        }

        return arr;
    }
    else if (logical_size - 1 <= actual_size / 3) //Если логический массив -1 меньше или равен трети фактического
    {
        actual_size /= 3;
        logical_size -= 1;

        int* tempArr = new int[actual_size]();

        for (int i = 0; i < logical_size; ++i)
        {
            tempArr[i] = arr[i + 1];
        }

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
            std::string inputWord; // Вводимый ответ
            // Печать массива
            std::cout << "Динамический массив: ";
            print_dynamic_array(dynamicArr, logicalSize, actualSize);
            std::cout << "Удалить первый элемент? ";

            std::cin >> inputWord;

            if (inputWord == "да" && logicalSize != 0) //Если ввели да и логический массив не ноль, то удаляем элемент
            {
                dynamicArr = remove_dynamic_array_head(dynamicArr, logicalSize, actualSize);
            }
            else if (inputWord == "да" && logicalSize == 0)//Если лгический массив пуст
            {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
                break;
            }
            else if (inputWord == "нет")//Если заканчиваем программу
            {
                std::cout << "Спасибо! Ваш динамический массив: ";
                print_dynamic_array(dynamicArr, logicalSize, actualSize);
                break;
            }
        }

        delete[] dynamicArr;
        dynamicArr = nullptr;
    }
}