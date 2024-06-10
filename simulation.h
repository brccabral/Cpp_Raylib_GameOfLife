#pragma once
#include "grid.h"

class Simulation
{
public:

    Simulation(int width, int height, int cellSize);
    void Draw() const;
    void SetCellValue(int row, int column, int value);
    [[nodiscard]] int CountLiveNeighbors(int row, int column) const;
    void Update();
    [[nodiscard]] bool IsRunning() const
    {
        return isRunning;
    }
    void Start()
    {
        isRunning = true;
    }
    void Stop()
    {
        isRunning = false;
    }
    void ClearGrid();
    void CreateRandomState();

private:

    Grid grid;
    Grid tempGrid;
    bool isRunning;
};
