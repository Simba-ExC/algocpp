#include <iostream>

int rand_between(const int from, const int to) // Случайное число в диапазоне
{
    if (to == from)
        return to;
    if (to < from)
        return rand_between(to, from);
    return from + rand() % (to - from + 1);
}

int pivoting(int* arr, int pi, int size) // Пивотирование
{
    int left = 0;
    int right = size - 1;
    int pivot = arr[pi];
    while (true)
    {
        while (arr[left] < pivot)
        {
            left += 1;
        }
        while (arr[right] > pivot)
        {
            right -= 1;
        }
        if (left >= right)
        {
            return left;
        }
        else
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }
    }
}

void funcQuickSort(int* arr, int left, int right, int size)
{
    if (size == 1 || left >= right) // Если массив из одного элемента или левая граница больше правой
    {
        return;
    }

    // Выбор опоры
    int pi = rand_between(left, right);
    int border = pivoting(arr, pi, size);

    // Рекурсивный вызов
    funcQuickSort(arr, left, border, border + 1);
    funcQuickSort(arr, border + 1, right, right + 1);
}

void quick_sort(int* arr, int size) // Функция сортировки. Так как по условиям задачи в полях функции может быть только массив и его размер, то завел дополнительную функцию, в которую входят еще левая и правая границы, чтобы передавать части массива в рекурсивные вызовы, не создавая новые массивы для частей.
{
    funcQuickSort(arr, 0, size - 1, size);
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
    quick_sort(arr, size);
    std::cout << "Отсортированный массив: ";
    printArr(arr, size);
}

int main()
{
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    sortPrintArr(arr1, sizeof(arr1) / sizeof(arr1[0]));
    sortPrintArr(arr2, sizeof(arr2) / sizeof(arr2[0]));
    sortPrintArr(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}