#include <bits/stdc++.h>
using namespace std;

// typical stack size is 1MB in windows, 8MB in Linux
// Recursion = 1. Expectation-Faith Method (Easy questions)
// 2. Level & Options methods (Medium and Hard questions)

// Expectation Faith Method
// a) High Level thinking -> Expectation + Faith + Relation b/w them
// b) Low level thinking -> DRY RUN / think of smallest input where recursion should stop

// Helper Function
void printArray(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

// 1.
void printDecreasing(int n)
{
    if (n <= 0)
        return;

    cout << n << " ";
    printDecreasing(n - 1);
}

// 2.
void printIncreasing(int n)
{
    if (n <= 0)
        return;

    printIncreasing(n - 1);
    cout << n << " ";
}

// 3.
int factorial(int n)
{
    // Base cases

    // Factorial not available
    if (n < 0)
        return -1;

    // n == 0 and n == 1
    if (n <= 1)
        return 1;

    // Recursive case
    return n * factorial(n - 1);
}

// 4. Time - O(n)
int powerLinear(int x, int n)
{
    if (n == 0)
        return 1;
    return x * powerLinear(x, n - 1);
}

// 5. Time - O(logn)
int powerLogarithmic(int x, int n)
{

    if (n == 0)
        return 1;

    // Recursive case
    int powerHalf = powerLogarithmic(x, n / 2);

    if (n & 1)
        return powerHalf * powerHalf * x;
    return powerHalf * powerHalf;
}

// 6.
void reverseArray(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Recursive case
    swap(arr[0], arr[n - 1]);
    reverseArray(arr + 1, n - 2);
}

// 7.
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
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {10, 20, 30, 20, 10};
    int n = sizeof(arr1) / sizeof(int);
    // printArray(arr1, n);
    // reverseArray(arr1, n);
    // printArray(arr1, n);

    // printArray(arr2, n);
    // cout << isPalindrome(arr2, n) << " " << isPalindrome(arr1, n) << endl;
    // printArray(arr2, n);

    // printDecreasing(6);
    // cout << endl;
    // printIncreasing(4);
    // cout << endl;

    // cout << powerLogarithmic(2, 1) << endl;
    // cout << powerLogarithmic(2, 5) << endl;
    return 0;
}