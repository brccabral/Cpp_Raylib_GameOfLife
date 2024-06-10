#pragma once
#include <vector>


class Grid
{
public:

    Grid(int width, int height, int cellSize);
    void Draw() const;
    void SetValue(int row, int column, int value);
    [[nodiscard]] int GetValue(int row, int column) const;
    [[nodiscard]] int GetRows() const
    {
        return rows;
    }
    [[nodiscard]] int GetColumns() const
    {
        return columns;
    }

private:

    [[nodiscard]] bool IsWithinBounds(int row, int column) const;

    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};
