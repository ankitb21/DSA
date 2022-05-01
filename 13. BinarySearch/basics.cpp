#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target)
{
    // Base Case
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    // Recursive Case
    if (arr[mid] > target)
        return binarySearchRecursive(arr, low, high - 1, target);

    return binarySearchRecursive(arr, low + 1, high, target);
}

int main()
{
    int arr1[] = {1, 9, -11};
    return 0;
}