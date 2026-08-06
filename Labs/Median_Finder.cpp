#include <iostream>
#include <algorithm>
using namespace std;

class MedianFinder
{
    int arr[50000];
    int size;

public:
    MedianFinder()
    {
        size = 0;
    }

    void addNum(int num)
    {
        arr[size] = num;
        size++;

        // Sort the array
        sort(arr, arr + size);
    }

    double findMedian()
    {
        if (size % 2 == 1)
        {
            return arr[size / 2];
        }
        else
        {
            return (arr[size / 2] + arr[(size / 2) - 1]) / 2.0;
        }
    }
};

int main()
{
    MedianFinder medianFinder;

    medianFinder.addNum(1);
    medianFinder.addNum(2);

    cout << "Median = " << medianFinder.findMedian() << endl;

    medianFinder.addNum(3);

    cout << "Median = " << medianFinder.findMedian() << endl;

    return 0;
}
