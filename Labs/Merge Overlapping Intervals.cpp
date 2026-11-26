#include <iostream>
using namespace std;

class Solution {
public:

    void merge(int arr[][2], int n) {

        // Sorting intervals
        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (arr[j][0] > arr[j + 1][0]) {

                    int temp = arr[j][0];
                    arr[j][0] = arr[j + 1][0];
                    arr[j + 1][0] = temp;

                    temp = arr[j][1];
                    arr[j][1] = arr[j + 1][1];
                    arr[j + 1][1] = temp;
                }
            }
        }

        int start = arr[0][0];
        int end = arr[0][1];

        cout << "Merged Intervals: ";

        for (int i = 1; i < n; i++) {

            if (arr[i][0] <= end) {

                if (arr[i][1] > end) {
                    end = arr[i][1];
                }
            }
            else {

                cout << "[" << start << "," << end << "] ";

                start = arr[i][0];
                end = arr[i][1];
            }
        }

        cout << "[" << start << "," << end << "]";
    }
};

int main() {

    Solution s;

    int arr[4][2] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    s.merge(arr, 4);

    return 0;
}
