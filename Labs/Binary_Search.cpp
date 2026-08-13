#include <iostream>
using namespace std;

int binarySearch(int nums[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = binarySearch(nums, size, target);

    if (result == -1)
        cout << "Target not found";
    else
        cout << "Target found at index " << result;

    return 0;
}
