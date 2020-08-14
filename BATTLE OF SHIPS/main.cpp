#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int rows = 4;
const int columns = 4;
int MaxShipsRand = 6;
int ValueShips = 6;
int x;
int y;

int matrix[rows][columns];
int matrixUserInput[rows][columns];

void start()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void ShipSank()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrixUserInput[i][j] != 2)
            {
                matrixUserInput[i][j] = 0;
            }
            matrixUserInput[y][x] = 2;
            cout << matrixUserInput[i][j] << " ";
        }
        cout << endl;
    }
}
void MapShips()
{
    for (int i = 0; i < MaxShipsRand; i++)
    {
        int x = rand() % 4;
        int y = rand() % 4;
        if (matrix[y][x] == 0)
        {

            matrix[y][x] = 1;
        }
        else
        {
            MaxShipsRand = MaxShipsRand + 1;
        }
    }
}

void show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void UserInput()
{

    if (matrix[y][x] == 1)
    {
        cout << "you got me!!" << endl;
        matrix[y][x] = 2;
        ValueShips = ValueShips - 1;
        cout << "Ships remaining: " << ValueShips << endl;
        ShipSank();
    }
    else
    {
        cout << "nothing on the radar, sir!" << endl;
    }
}

int main()
{
    srand(time(NULL));
    start();
    MapShips();
    while (ValueShips != 0)
    {
        cout << "Hello nice human! chose a position, there is a war to win! x: ";
        cin >> x;
        cout << " y: ";
        cin >> y;
        UserInput();
    }
    cout << "Congrats. Thanks for playing my game!" << endl;
    system("pause");
    return 0;
}
