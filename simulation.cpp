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
