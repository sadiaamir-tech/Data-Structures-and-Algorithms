#include <iostream>
using namespace std;

int main()
{
    float marks[5][5] =
    {
        {3.66, 3.33, 4.00, 3.00, 2.66}, // Ali
        {3.33, 3.00, 3.66, 3.00, -1},   // Hiba
        {4.00, 3.66, 2.66, -1, -1},     // Asma
        {2.66, 2.33, 4.00, -1, -1},     // Zain
        {3.33, 3.66, 4.00, 3.00, 3.33}  // Faisal
    };

    string names[5] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};

    for(int i = 0; i < 5; i++)
    {
        float sum = 0;
        int count = 0;

        for(int j = 0; j < 5; j++)
        {
            if(marks[i][j] != -1)
            {
                sum += marks[i][j];
                count++;
            }
        }

        cout << names[i] << " GPA = " << sum / count << endl;
    }

    return 0;
}
