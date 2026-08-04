#include <iostream>
using namespace std;

class ColumnMajor
{
private:
    int rows, cols;
    int arr[10][10];
    int oneD[100];

public:
    void input()
    {
        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter elements of 2D array:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void copyColumnMajor()
    {
        int k = 0;

        // Column Major Order
        for (int j = 0; j < cols; j++)
        {
            for (int i = 0; i < rows; i++)
            {
                oneD[k] = arr[i][j];
                k++;
            }
        }
    }

    void display()
    {
        cout << "\n2D Array:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\n1D Array (Column Major Order):\n";
        for (int i = 0; i < rows * cols; i++)
        {
            cout << oneD[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ColumnMajor obj;

    obj.input();
    obj.copyColumnMajor();
    obj.display();

    return 0;
}
