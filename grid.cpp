#include "grid.h"

#include <raylib.h>

Grid::Grid(const int width, const int height, const int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0))
{}

void Grid::Draw() const
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            const Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(const int row, const int column, const int value)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column] = value;
    }
}

int Grid::GetValue(const int row, const int column) const
{
    if (IsWithinBounds(row, column))
    {
        return cells[row][column];
    }
    return 0;
}

void Grid::FillRandom()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            // set value 25% of the time
            cells[row][column] = GetRandomValue(0, 4) == 4 ? 1 : 0;
        }
    }
}

void Grid::Clear()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            cells[row][column] = 0;
        }
    }
}

void Grid::ToggleCell(const int row, const int column)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column] = !cells[row][column];
    }
}

bool Grid::IsWithinBounds(const int row, const int column) const
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        return true;
    }
    return false;
}
