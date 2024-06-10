#include <raylib.h>
#include "simulation.h"

int main()
{
    constexpr int WINDOW_WIDTH = 750;
    constexpr int WINDOW_HEIGHT = 750;
    constexpr int CELL_SIZE = 25;

    constexpr Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
    SetTargetFPS(60);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    simulation.SetCellValue(3, 4, 1);
    simulation.SetCellValue(3, 5, 1);
    simulation.SetCellValue(4, 5, 1);
    simulation.SetCellValue(2, 5, 1);

    const int liveNbr = simulation.CountLiveNeighbors(3, 4);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREY);

        simulation.Draw();
        DrawText(TextFormat("%i", liveNbr), 10, 10, 20, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
