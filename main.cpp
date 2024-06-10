#include <raylib.h>

#include "grid.h"

int main()
{
    constexpr int WINDOW_WIDTH = 750;
    constexpr int WINDOW_HEIGHT = 750;
    constexpr int CELL_SIZE = 25;

    constexpr Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
    SetTargetFPS(60);

    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREY);

        grid.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
