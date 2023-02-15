#include <iostream>

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

int main() {
  int actualSize = 0;
  int logicalSize = 0;

  std::cout << "Введите фактический размер массива: ";
  std::cin >> actualSize;
  std::cout << "Введите логический размер массива: ";
  std::cin >> logicalSize;

  if (actualSize < logicalSize) {
    std::cout
        << "Ошибка! Логический размер массива не может превышать фактический!"
        << std::endl;
  } else {
    int *dynamicArr = new int[actualSize]();

    for (int i = 0; i < logicalSize; ++i) {
      std::cout << "Введите arr[" << i << "]: ";
      std::cin >> dynamicArr[i];
    }
    print_dynamic_array(dynamicArr, logicalSize, actualSize);

    delete[] dynamicArr;
    dynamicArr = nullptr;
  }
}s