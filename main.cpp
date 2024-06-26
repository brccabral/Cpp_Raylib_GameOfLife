#include <raylib.h>
#include "simulation.h"

int main()
{
    constexpr int WINDOW_WIDTH = 1200;
    constexpr int WINDOW_HEIGHT = 800;
    constexpr int CELL_SIZE = 4;
    int FPS = 60;

    constexpr Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
    SetTargetFPS(FPS);
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

        if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }

        if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            const auto [x, y] = GetMousePosition();
            const int row = y / CELL_SIZE;
            const int column = x / CELL_SIZE;
            simulation.ToggleCell(row, column);
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
