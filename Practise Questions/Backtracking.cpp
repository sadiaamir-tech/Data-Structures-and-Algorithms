#include <iostream>
using namespace std;

bool isValid(int maze[4][4], int r, int c)
{
    if (r < 0 || r >= 4 || c < 0 || c >= 4)
        return false;

    if (maze[r][c] == 0)
        return false;

    return true;
}

bool solveMaze(int maze[4][4], int path[4][4], int r, int c)
{
    // Destination
    if (r == 3 && c == 3)
    {
        path[r][c] = 1;
        return true;
    }

    // Invalid cell
    if (!isValid(maze, r, c))
        return false;

    // Choose
    path[r][c] = 1;

    // Down
    if (solveMaze(maze, path, r + 1, c))
        return true;

    // Right
    if (solveMaze(maze, path, r, c + 1))
        return true;

    // Up
    if (solveMaze(maze, path, r - 1, c))
        return true;

    // Left
    if (solveMaze(maze, path, r, c - 1))
        return true;

    // Backtrack
    path[r][c] = 0;

    return false;
}

int main()
{
    int maze[4][4] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int path[4][4] = {0};

    if (solveMaze(maze, path, 0, 0))
    {
        cout << "Path found:\n";

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << path[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
        cout << "No path found";
    }

    return 0;
}
