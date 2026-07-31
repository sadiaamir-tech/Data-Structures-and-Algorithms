#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int arr[10][10];
    int oneD[100];

    // Input 2D array
    cout << "Enter elements of 2D array:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Copy into 1D array using Column Major Order
    int k = 0;
    for(int j = 0; j < cols; j++)
    {
        for(int i = 0; i < rows; i++)
        {
            oneD[k] = arr[i][j];
            k++;
        }
    }

    // Display 1D array
    cout << "\n1D Array (Column Major Order): ";
    for(int i = 0; i < rows * cols; i++)
    {
        cout << oneD[i] << " ";
    }

    return 0;
}
