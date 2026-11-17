#include <iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int arr[1000];

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int size = n;
        int index = 0;

        while (size > 1) {
            index = (index + k - 1) % size;

            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }

            size--;
        }

        return arr[0];
    }
};

int main() {
    Solution s;

    int n = 5;
    int k = 2;

    cout << "Winner: " << s.findTheWinner(n, k);

    return 0;
}
