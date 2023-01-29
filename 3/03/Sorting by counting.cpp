#include <iostream>

void count_sort(int* arr, int size) // Сортировка подсчетом
{
    int bottom = 10;
    int* counts = new int[size]();

    for (int i = 0; i < size; ++i)
    {
        counts[arr[i] - bottom] += 1; // Так как массив состоит из чисел не меньше 10, то вычитаем 10
    }

    int c = 0;
    for (int i = 0; i < size; ++i)
    {
        while (counts[c] == 0)
        {
            c += 1;
        }
        arr[i] = c + bottom; // Прибавляем 10, так как нижний порог 10
        counts[c] -= 1;
    }

    delete[] counts;
    counts = nullptr;
}

void printArr(int* arr, int size) // Печать массива
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sortPrintArr(int* arr, int size) // Печать исходного и отсортированного массива
{