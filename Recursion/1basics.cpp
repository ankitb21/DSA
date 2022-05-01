#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

// typical stack size is 1MB in windows, 8MB in Linux
void func(int num)
{
    cout << num << endl;
    func(num + 1);
}

void reverseArray(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Recursive case
    swap(arr[0], arr[n - 1]);
    reverseArray(arr + 1, n - 2);
}

bool isPalindrome(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return true;

    if (arr[0] != arr[n - 1])
        return false;

    // Recursive case
    return isPalindrome(arr + 1, n - 2);
}

int main()
{
    // func(0);
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {10, 20, 30, 20, 10};
    int n = sizeof(arr1) / sizeof(int);
    // printArray(arr1, n);
    // reverseArray(arr1, n);
    // printArray(arr1, n);

    printArray(arr2, n);
    cout << isPalindrome(arr2, n) << " " << isPalindrome(arr1, n) << endl;
    printArray(arr2, n);

    return 0;
}