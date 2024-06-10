#include "simulation.h"

Simulation::Simulation(const int width, const int height, const int cellSize)
    : grid(width, height, cellSize), tempGrid(width, height, cellSize), isRunning(false)
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

void Simulation::Update()
{
    if (!isRunning)
    {
        return;
    }
    for (int row = 0; row < grid.GetRows(); ++row)
    {
        for (int column = 0; column < grid.GetColumns(); ++column)
        {
            const int liveNbr = CountLiveNeighbors(row, column);

            if (grid.GetValue(row, column))
            {
                if (liveNbr > 3 || liveNbr < 2)
                {
                    tempGrid.SetValue(row, column, 0);
                }
                else
                {
                    tempGrid.SetValue(row, column, 1);
                }
            }
            else
            {
                if (liveNbr == 3)
                {
                    tempGrid.SetValue(row, column, 1);
                }
                else
                {
                    tempGrid.SetValue(row, column, 0);
                }
            }
        }
    }

    grid = tempGrid;
}

void Simulation::ClearGrid()
{
    if (!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if (!IsRunning())
    {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(const int row, const int column)
{
    if (!IsRunning())
    {
        grid.ToggleCell(row, column);
    }
}
