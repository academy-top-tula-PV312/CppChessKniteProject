#include <iostream>
#include <iomanip>

const int size{ 8 };
int desk[size][size]{};

int offset[size][2]{ {-2, 1},
                  {-1, 2},
                  {1, 2},
                  {2, 1},
                  {2, -1},
                  {1, -2},
                  {-1, -2},
                  {-2, -1} };

void DeskPrint();

int WeghtCalculate(int row, int col);
int MinWeightIndex(int weights[]);
bool IsDesk(int row, int col);

void KniteBypass(int rowCurr, int colCurr);

int main()
{

    /*int rowCurr, colCurr;
    std::cout << "Input row: ";
    std::cin >> rowCurr;
    std::cout << "Input column: ";
    std::cin >> colCurr;*/

    int count{};

    for(int row{}; row < size; row++)
        for (int col{}; col < size; col++)
        {
            std::cout << "----" << ++count << "----\n";
            KniteBypass(row, col);

            for (int i{}; i < size; i++)
                for (int j{}; j < size; j++)
                    desk[i][j] = 0;

            std::cout << "\n";
        }
    
}

void DeskPrint()
{
    for (int i{}; i < size; i++)
    {
        for (int j{}; j < size; j++)
            std::cout << std::setw(3) << desk[i][j];
        std::cout << "\n";
    }
}

int WeghtCalculate(int row, int col)
{
    int weight{};

    for (int i{}; i < size; i++)
    {
        int offsetRow = row + offset[i][0];
        int offsetCol = col + offset[i][1];

        if (IsDesk(offsetRow, offsetCol))
        {
            if (!desk[offsetRow][offsetCol])
                weight++;
        }
    }

    return weight;
}

int MinWeightIndex(int weights[])
{
    int index;
    for (index = 0; index < size; index++)
        if (weights[index])
            break;
    
    for (int i{ index + 1 }; i < size; i++)
        if (weights[index] > weights[i] && weights[i] != 0)
            index = i;
    return index;
}

bool IsDesk(int row, int col)
{
    return row >= 0 && row < size && col >= 0 && col < size;
}

void KniteBypass(int rowCurr, int colCurr)
{
    int step{};
    desk[rowCurr][colCurr] = ++step;

    while (step < 63)
    {
        int variantsWeight[size]{};

        for (int i{}; i < size; i++)
        {
            int offsetRow = rowCurr + offset[i][0];
            int offsetCol = colCurr + offset[i][1];

            if (IsDesk(offsetRow, offsetCol))
            {
                if (!desk[offsetRow][offsetCol])
                    variantsWeight[i] = WeghtCalculate(offsetRow, offsetCol);
            }
        }
        int offsetMin = MinWeightIndex(variantsWeight);

        rowCurr += offset[offsetMin][0];
        colCurr += offset[offsetMin][1];
        desk[rowCurr][colCurr] = ++step;
    }

    for (int i{}; i < size; i++)
    {
        int offsetRow = rowCurr + offset[i][0];
        int offsetCol = colCurr + offset[i][1];

        if (IsDesk(offsetRow, offsetCol))
            if (!desk[offsetRow][offsetCol])
            {
                desk[offsetRow][offsetCol] = 64;
                break;
            }
    }

    DeskPrint();
}
