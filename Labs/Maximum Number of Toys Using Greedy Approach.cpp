#include <iostream>
using namespace std;

int maxToys(int arr[], int n, int k) {

    // Sort array using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int count = 0;

    // Buy cheapest toys first
    for (int i = 0; i < n; i++) {

        if (arr[i] <= k) {
            k = k - arr[i];
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

int main() {

    int arr[] = {1, 12, 5, 111, 200, 1000, 10};

    int N = 7;
    int K = 50;

    cout << "Maximum toys: " << maxToys(arr, N, K);

    return 0;
}
