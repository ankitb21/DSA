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

// 8. Tower of Hanoi --> Very Important
long long toh(int N, int from, int to, int aux)
{
    // Base case

    // No disk to move as there is no disk
    if (N == 0)
        return 0;

    // Recursive case

    // print the instructions to move n - 1 disks from "from" to "aux" using "to"
    long long steps1 = toh(N - 1, from, aux, to);

    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;

    // print the instructions to move n - 1 disks from "aux" to "to" using "from"
    long long steps2 = toh(N - 1, aux, to, from);

    return steps1 + steps2 + 1;
}

// 9.
void displayArray(int arr[], int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }

    cout << arr[0] << " ";
    displayArray(arr + 1, n - 1);
}

// 10.
void displayArrayReverse(int arr[], int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }

    cout << arr[n - 1] << " ";
    displayArrayReverse(arr, n - 1);
}

// 11.
int findMaximum(int arr[], int n)
{
    if (n == 0)
        return INT_MIN;

    int maxElement = findMaximum(arr + 1, n - 1);

    if (maxElement > arr[0])
        return maxElement;

    return arr[0];
}

// 12.
int firstIndexOfOccurence(int arr[], int n, int target)
{
    if (n == 0)
        return -1;

    if (arr[0] == target)
        return 0;

    int ans = firstIndexOfOccurence(arr + 1, n - 1, target);

    if (ans == -1)
        return -1;

    return ans + 1;
}

// 13.
int lastIndexOfOccurence(int arr[], int n, int target)
{
    if (n == 0)
        return -1;

    int ans = lastIndexOfOccurence(arr + 1, n - 1, target);

    if (ans != -1)
        return ans + 1;

    if (arr[0] == target)
        return 0;

    return -1;
}

// 14.
auto allIndicesInArray(int arr[], int idx, int n, int target, int frequency)
{
    if (idx == n)
    {
        return new int[frequency];
    }
    if (arr[idx] == target)
    {
        int *arr = allIndicesInArray(arr, idx + 1, n, target, frequency + 1);
        arr[frequency] = idx;
        return arr;
    }
    else
    {
        int *arr = allIndicesInArray(arr, idx + 1, n, target, frequency);
        return arr;
    }
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

    // displayArray(arr1, n);
    // displayArrayReverse(arr1, n);

    // cout << findMaximum(arr1, n) << endl;
    // cout << findMaximum(arr2, n) << endl;

    // cout << firstIndexOfOccurence(arr1, n, 30) << endl;
    // cout << firstIndexOfOccurence(arr2, n, 20) << endl;
    // cout << firstIndexOfOccurence(arr1, n, 50) << endl;
    // cout << firstIndexOfOccurence(arr1, n, 9) << endl;

    // cout << lastIndexOfOccurence(arr1, n, 5) << endl;

    return 0;
}