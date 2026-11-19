#include <iostream>
using namespace std;

class Solution {
public:

    int findLHS(int nums[], int n) {

        int maxLength = 0;

        for (int i = 0; i < n; i++) {

            int count1 = 0;
            int count2 = 0;

            for (int j = 0; j < n; j++) {

                if (nums[j] == nums[i]) {
                    count1++;
                }

                if ((long long)nums[j] == (long long)nums[i] + 1) {
                    count2++;
                }
            }

            if (count1 > 0 && count2 > 0) {

                int total = count1 + count2;

                if (total > maxLength) {
                    maxLength = total;
                }
            }
        }

        return maxLength;
    }
};

int main() {

    Solution s;

    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};

    int n = 8;

    cout << "Longest Harmonious Subsequence: "
         << s.findLHS(nums, n);

    return 0;
}
