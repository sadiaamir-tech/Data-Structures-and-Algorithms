#include <iostream>
using namespace std;

class MergeSort {
public:

    void merge(int arr[], int temp[], int left, int mid, int right) {

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {

            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            }
            else {
                temp[k] = arr[j];
                j++;
            }

            k++;
        }

        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }

        while (j <= right) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        for (int i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
    }

    void sort(int arr[], int n) {

        int temp[100];

        for (int size = 1; size < n; size = size * 2) {

            for (int left = 0; left < n; left = left + 2 * size) {

                int mid = left + size - 1;
                int right = left + 2 * size - 1;

                if (mid >= n)
                    mid = n - 1;

                if (right >= n)
                    right = n - 1;

                if (mid < right) {
                    merge(arr, temp, left, mid, right);
                }
            }
        }
    }
};

int main() {

    MergeSort m;

    int arr[] = {8, 3, 6, 2, 7, 1, 5, 4};

    int n = 8;

    m.sort(arr, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
