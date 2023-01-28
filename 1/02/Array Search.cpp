#include <iostream>

int calcOfGreaterElements(int* arr, int size, int referencePoint)
{
    int left = 0;
    int right = size - 1;
    int middle = 0;
    middle = (left + right) / 2;

    while (left <= right)
    {
        if (arr[middle] == referencePoint) // Если сразу нашли точку отсчета в массиве
        {
            if (left == middle) // Если на данный момент левая граница равна середине
            {
                break;
            }
            while (arr[middle] != referencePoint || left != middle) // Пока средний элемент массива не равен точке отсчета или левая граница неравна середине
            {
                left = middle;
                middle = (left + right) / 2;

                if (arr[middle] > referencePoint)
                {
                    right = middle - 1;
                }
                else if (arr[middle] < referencePoint)
                {
                    left = middle + 1;
                }
            }
        }
        if (arr[middle] > referencePoint)
        {
            right = middle - 1;
        }
        else if (arr[middle] < referencePoint)
        {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }

    if (referencePoint >= arr[size - 1]) // Если ввели число, заведомо большее, чем любой из элементов массива
    {
        return 0;
    }
    else if (referencePoint < arr[0]) // Если ввели число, заведомо меньше, чем любой из элементов массива
    {
        return size;
    }
    else // Возвращаем значение количества найденных чисел
    {
        return (size - 1) - middle;
    }
}

int main()
{
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int referencePoint = 0;

    std::cout << "Введите точку отсчета: ";
    std::cin >> referencePoint;
    int numberOfGreaterElements = 0;

    numberOfGreaterElements = calcOfGreaterElements(arr, sizeof(arr) / sizeof(arr[0]), referencePoint);

    std::cout << "Количество элементов в массиве больших, чем " << referencePoint << ": " << numberOfGreaterElements;

    return 0;
}