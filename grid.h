#pragma once
#include <vector>


class Grid
{
public:

    Grid(int width, int height, int cellSize);
    void Draw() const;
    void SetValue(int row, int column, int value);

private:

    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};
