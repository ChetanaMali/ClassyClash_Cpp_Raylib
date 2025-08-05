#include "raylib.h"

int main()
{
    //Initialize the window
    int windowWidth = 384;
    int windowHeight = 384;
    InitWindow(windowWidth,windowHeight,"ClassyClashGame");

    //Draw textures
    Texture2D mapTexture = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(mapTexture, mapPos, 0, 4, WHITE);

        EndDrawing();
    }
    CloseWindow();
}