#include <iostream>

int* apply_all(int* arr1, size_t sizeArr1, int* arr2, size_t sizeArr2);
void print(int const arr[], size_t sizeArr);

int main()
{
    // Array size
    const size_t array1_size{ 5 };
    const size_t array2_size{ 3 };
    // Arrays
    int array1[]{1,2,3,4,5};
    int array2[]{ 10,20,30 };

    // Printing Array 1
    std::cout << "Array 1: ";
    print(array1, array1_size);

    // Printing Array 2
    std::cout << "Array 2: ";
    print(array2, array2_size);

    // Calculate new array (combined)
    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{ array1_size * array2_size };

    // Printing final result
    std::cout << "Result: ";
    print(results, results_size);

    delete[] results;


}

int* apply_all(int *arr1, size_t sizeArr1, int *arr2, size_t sizeArr2)
{
    int* result{ nullptr };
    result = new int[sizeArr1 * sizeArr2];
    size_t runVariable{};
    for (size_t numArr2{}; numArr2 < sizeArr2; ++numArr2)
    {
        for (size_t numArr1{}; numArr1 < sizeArr1; ++numArr1)
        {
            result[runVariable] = arr2[numArr2] * arr1[numArr1];
            runVariable++;
        }
    }

    return result;
}

void print(int const arr[], size_t sizeArr)
{
    for (size_t numElem{}; numElem < sizeArr; ++numElem)
    {
        std::cout << arr[numElem] << " ";
    }
    std::cout << "\n";
}