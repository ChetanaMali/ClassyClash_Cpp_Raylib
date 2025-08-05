#include "raylib.h"
#include "raymath.h"

int main()
{
    //Initialize the window
    int windowWidth = 384;
    int windowHeight = 384;
    InitWindow(windowWidth,windowHeight,"ClassyClashGame");

    //Draw textures
    Texture2D mapTexture = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    float speed = 4;

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1 ;
        if(IsKeyDown(KEY_D)) direction.x += 1 ;
        if(IsKeyDown(KEY_W)) direction.y -= 1 ;
        if(IsKeyDown(KEY_S)) direction.y += 1 ;

        if(Vector2Length(direction) != 0) {
            // set mapPosition = mappose - direction
            //first normalize the direction vector for digonal movement 
            //used scaleVector2 to increase speed of movement

            mapPos = Vector2Subtract(mapPos , Vector2Scale(Vector2Normalize(direction), speed));
        }
        
        DrawTextureEx(mapTexture, mapPos, 0, 4, WHITE);

        EndDrawing();
    }
    CloseWindow();
}