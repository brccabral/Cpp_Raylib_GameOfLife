#include "simulation.h"

Simulation::Simulation(const int width, const int height, const int cellSize) : grid(width, height, cellSize)
{}

void Simulation::Draw() const
{
    grid.Draw();
}

void Simulation::SetCellValue(const int row, const int column, const int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) const
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffset = {
            {-1, 0}, //
            {1, 0}, //
            {0, -1}, //
            {0, 1}, //
            {-1, -1}, //
            {-1, 1}, //
            {1, -1}, //
            {1, 1}, //
    };

    for (const auto &[first, second]: neighborOffset)
    {
        const int neighborRow = (row + first + grid.GetRows()) % grid.GetRows();
        const int neighborColumn = (column + second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }
    return liveNeighbors;
}
