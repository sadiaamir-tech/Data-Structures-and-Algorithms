#include <iostream>
using namespace std;

class Solution {
public:

    bool carPooling(int trips[][3], int n, int capacity) {

        int arr[1001] = {0};

        for (int i = 0; i < n; i++) {

            int passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            arr[from] += passengers;
            arr[to] -= passengers;
        }

        int total = 0;

        for (int i = 0; i <= 1000; i++) {

            total += arr[i];

            if (total > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution s;

    int trips[2][3] = {
        {2, 1, 5},
        {3, 3, 7}
    };

    int capacity = 4;

    if (s.carPooling(trips, 2, capacity)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
