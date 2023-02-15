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
    int arr2[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    Pyramid pyr1(arr1, sizeof(arr1) / sizeof(arr1[0]));

    std::cout << "Исходный массив: ";
    printArr(arr1, sizeof(arr1) / sizeof(arr1[0])); // Печать исходного массива

    printPyramid(pyr1); // Печать пирамиды
    pyr1.clear(); // Очищение памяти

    return 0;
}