#include <raylib.h>

int main()
{
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;

    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
