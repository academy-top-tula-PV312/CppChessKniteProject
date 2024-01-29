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
int MinWeightIndex(int weights[], int size);

int main()
{
    int step{};
    int rowCurr, colCurr;
    std::cout << "Input row: ";
    std::cin >> rowCurr;
    std::cout << "Input column: ";
    std::cin >> colCurr;

    desk[rowCurr][colCurr] = ++step;

    while (step <= 63)
    {
        int variants[size][2]{};
        int variantsWeight[size]{};
        int variantsSize{};
        
        for (int i{}; i < size; i++)
        {
            int offsetRow = rowCurr + offset[i][0];
            int offsetCol = colCurr + offset[i][1];

            if (offsetRow >= 0 && offsetRow < size
                && offsetCol >= 0 && offsetCol < size)
            {
                if (!desk[offsetRow][offsetCol])
                {
                    variantsWeight[i] = WeghtCalculate(offsetRow, offsetCol);
                    variantsSize++;
                }
            }
        }
        int offsetMin = MinWeightIndex(variantsWeight, variantsSize);
        
        rowCurr += offset[offsetMin][0];
        colCurr += offset[offsetMin][1];
        desk[rowCurr][colCurr] = ++step;
    }

    DeskPrint();
    
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
    return 0;
}

int MinWeightIndex(int weights[], int size)
{
    int index{};
    for (int i{ 1 }; i < size; i++)
        if (weights[index] > weights[i])
            index = i;
    return index;
}
