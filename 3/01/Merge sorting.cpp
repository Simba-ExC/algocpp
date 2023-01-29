#include <iostream>

void merge_sort(int* arr, int size)
{
    if (size == 1) // Если массив из одного элемента
    {
        return;
    }

    int middle = size / 2; // Находим середину массива

    int* arrLeft = new int[middle](); // Первый подмассив
    for (int i = 0; i < middle; ++i)
    {
        arrLeft[i] = arr[i];
    }
    int* arrRight = new int[size - middle](); // Второй подмассив
    for (int i = 0; i < (size - middle); ++i)
    {
        arrRight[i] = arr[middle + i];
    }

    // Рекурсивно запускаем сортировку для подмассивов
    merge_sort(arrLeft, middle); 
    merge_sort(arrRight, size - middle);

    int* arrSorted = new int[size](); // Массив для слияния

    // Счетчики для массивов
    int iLeft = 0;
    int iRight = 0;
    int iSorted = 0;
    
    while (iLeft < middle || iRight < (size - middle)) // Пока хотя бы один из счётчиков для исходных массивов не прошёл массив до конца
    {
        if (iLeft == middle) //Если счётчик уже пробежал все элементы в arrLeft, то берём  следующий из arrRight в качестве следующего элемента для arrSorted
        {
            arrSorted[iSorted] = arrRight[iRight];
            iRight += 1;
        }
        else if (iRight == (size - middle)) //Если счётчик уже пробежал все элементы в arrRight, то берём  следующий из arrLeft в качестве следующего элемента для arrSorted
        {
            arrSorted[iSorted] = arrLeft[iLeft];
            iLeft += 1;
        }
        else // Иначе, берём минимальный из тех, на которые указывают счётчики в качестве следующего элемента для arrSorted
        {
            if (arrLeft[iLeft] <= arrRight[iRight])
            {
                arrSorted[iSorted] = arrLeft[iLeft];
                iLeft += 1;
            }
            else
            {
                arrSorted[iSorted] = arrRight[iRight];
                iRight += 1;
            }
        }
        iSorted += 1;
    }

    for (int i = 0; i < size; ++i) // Записываем результат в результирующий массив
    {
        arr[i] = arrSorted[i];
    }
    delete[] arrLeft;
    arrLeft = nullptr;
    delete[] arrRight;
    arrRight = nullptr;
    delete[] arrSorted;
    arrSorted = nullptr;
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
    merge_sort(arr, size);
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