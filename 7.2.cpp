#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
void shellSort(T* arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
template <>
void shellSort<char*>(char** arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            char* temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
int main()
{
    int numbers[] = {9, 3, 7, 1, 5};
    shellSort(numbers, 5);
    cout << "Ordered array:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << "\n";
    char* words[] = {"red", "blue", "green", "purple"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    shellSort(words, wordsSize);
    cout << "Ordered string array:\n";
    for (int i = 0; i < wordsSize; ++i)
    {
        cout << words[i] << " ";
    }
    cout << "\n";
    return 0;
}