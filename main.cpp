#include <raylib.h>
#include "simulation.h"

int main()
{
    constexpr int WINDOW_WIDTH = 1200;
    constexpr int WINDOW_HEIGHT = 800;
    constexpr int CELL_SIZE = 4;

    constexpr Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
    SetTargetFPS(60);
    SetRandomSeed(GetTime());

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER) && !simulation.IsRunning())
        {
            simulation.Start();
            SetWindowTitle("Game Of Life - Running");
        }
        else if (IsKeyPressed(KEY_ENTER) && simulation.IsRunning())
        {
            simulation.Stop();
            SetWindowTitle("Game Of Life - Stopped");
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(GREY);

        simulation.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
