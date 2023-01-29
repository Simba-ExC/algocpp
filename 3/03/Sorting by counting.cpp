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
    std::cout << "Исходный массив: ";
    printArr(arr, size);
    count_sort(arr, size);
    std::cout << "Отсортированный массив: ";
    printArr(arr, size);
}

int main()
{
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

    sortPrintArr(arr1, sizeof(arr1) / sizeof(arr1[0]));
    sortPrintArr(arr2, sizeof(arr2) / sizeof(arr2[0]));
    sortPrintArr(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}
