#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
void findMaxAndCount(T* arr, int size, T& maxValue, int& count)
{
    maxValue = arr[0];
    count = 1;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
            count = 1;
        } else if (arr[i] == maxValue)
        {
            ++count;
        }
    }
}
template <>
void findMaxAndCount<char*>(char** arr, int size, char*& maxValue, int& count)
{
    maxValue = arr[0];
    count = 1;
    for (int i = 1; i < size; ++i)
    {
        if (strcmp(arr[i], maxValue) > 0)
        {
            maxValue = arr[i];
            count = 1;
        } else if (strcmp(arr[i], maxValue) == 0)
        {
            ++count;
        }
    }
}
int main()
{
    int a[] = {1, 5, 3, 5, 2};
    int maxInt, countInt;
    findMaxAndCount(a, 5, maxInt, countInt);
    cout << "Max int: " << maxInt << ", Count: " << countInt << endl;
    const char* b[] = {"red", "purple", "blue", "purple", "green"};
    const char* maxStr;
    int countStr;
    findMaxAndCount(const_cast<char**>(b), 5, const_cast<char*&>(maxStr), countStr);
    cout << "Max string: " << maxStr << ", Count: " << countStr << endl;
    return 0;
}