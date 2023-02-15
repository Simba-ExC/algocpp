#include <iostream>
#include <cmath>

struct Pyramid // Структура Пирамида
{
private:
    int size; // Размер пирамиды
    int* pyramid; // Массив пирамиды
public:
    Pyramid(int* arr, int size) // Конструктор пирамиды
    {
        this->size = size;
        pyramid = new int[size];
        for (int i = 0; i < size; ++i)
        {
            pyramid[i] = arr[i];
        }
    }

    // Геттеры
    std::string getName(int index) // Получение имени элемента
    {
        if (index == 0)
        {
            return "root";
        }
        else if (index % 2 != 0)
        {
            return "left";
        }
        else if (index % 2 == 0)
        {
            return "right";
        }
    }
    int getElement(int index) // Получение элемента
    {
        return pyramid[index];
    }
    int getLeftChild(int parentIndex) // Получение индекса левого ребенка
    {
        return 2 * parentIndex + 1;
    }
    int getRightChild(int parentIndex) // Получение индекса правого ребенка
    {
        return 2 * parentIndex + 2;
    }
    int getParent(int childIndex) // Получение индекса родителя
    {
        return (childIndex - 1) / 2;
    }
    int getSize() // Получение размера пирамиды
    {
        return size;
    }
    int getLevel(int index) // Получение уровня элемента
    {
        return static_cast<int>(log2(index));
    }

    void clear() // Очищение памяти
    {
        delete[] pyramid;
        pyramid = nullptr;
    }
};

void printPyramid(Pyramid pyr) // Печать пирамиды
{
    std::cout << "Пирамида:" << std::endl;
    for (int i = 0; i < pyr.getSize(); ++i)
    {
        if (i == 0)
        {
            std::cout << 0 << " "
                << pyr.getName(i) << " "
                << pyr.getElement(i) << std::endl;
        }
        else
        {
            std::cout << pyr.getLevel(i) << " "
                << pyr.getName(i) << " ("
                << pyr.getElement(pyr.getParent(i)) << ") "
                << pyr.getElement(i) << std::endl;
        }
    }
}

void printPyramidElement(Pyramid pyr, int index) // Печать Элемента пирамиды
{
    std::cout << "Вы находитесь здесь: ";
    if (index == 0)
    {
        std::cout << 0 << " "
            << pyr.getName(index) << " "
            << pyr.getElement(index) << std::endl;
    }
    else
    {
        std::cout << pyr.getLevel(index) << " "
            << pyr.getName(index) << " ("
            << pyr.getElement(pyr.getParent(index)) << ") "
            << pyr.getElement(index) << std::endl;
    }
    std::cout << "Введите команду: ";
}

void printArr(int* arr, int size) // Печать массива
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[] = { 1, 3, 6, 5, 9, 8 };

    Pyramid pyr1(arr1, sizeof(arr1) / sizeof(arr1[0]));

    std::cout << "Исходный массив: ";
    printArr(arr1, sizeof(arr1) / sizeof(arr1[0])); // Печать исходного массива

    printPyramid(pyr1); // Печать пирамиды

    std::string inputWord = "_"; // Вводимая команда
    int index = 0; // Текущий текущего элемента пирамиды

    while (inputWord != "exit") // Пока не ввели exit
    {
        printPyramidElement(pyr1, index); // Печать элемента массива
        std::cin >> inputWord;

        if (inputWord == "up") // Если ввели up
        {
            if (index == 0) // Если нет родителя
            {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
            else // Если родитель есть
            {
                std::cout << "Ок" << std::endl;
                index = pyr1.getParent(index); // Получаем индекс родителя
            }
        }
        else if (inputWord == "right") // Если хотим получить правого потомка
        {
            if (pyr1.getRightChild(index) >= pyr1.getSize()) // Если индекс правого потомка больше размера пирамиды
            {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
            else
            {
                std::cout << "Ок" << std::endl;
                index = pyr1.getRightChild(index); // Получаем индекс правого потомка
            }
        }
        else if (inputWord == "left")// Если хотим получить левого потомка
        {
            if (pyr1.getLeftChild(index) >= pyr1.getSize())// Если индекс левого потомка больше размера пирамиды
            {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
            else
            {
                std::cout << "Ок" << std::endl;
                index = pyr1.getLeftChild(index);// Получаем индекс левого потомка
            }
        }
        else if (inputWord == "exit") // Выходим.ю если ввели exit
        {
            break;
        }
        else if (inputWord != "up" && inputWord != "right" && inputWord != "left" && inputWord != "exit") // Если ошибка ввода
        {
            std::cout << "Вы ввели неверную команду" << std::endl;
        }
    }

    pyr1.clear(); // Очищение памяти

    return 0;
}