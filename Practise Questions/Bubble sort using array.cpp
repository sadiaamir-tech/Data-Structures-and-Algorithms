#include <iostream>
using namespace std;

class BubbleSort
{
public:

    void sort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    BubbleSort b;

    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    cout << "Before Sorting: ";
    b.display(arr, n);

    b.sort(arr, n);

    cout << "\nAfter Sorting: ";
    b.display(arr, n);

    return 0;
}
