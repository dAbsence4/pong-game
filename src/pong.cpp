#include <raylib.h>

#define V_SCREEN_WIDTH 256
#define V_SCREEN_HEIGHT 160
#define V_SCALE 5

int main(void)
{
    const char* screenTitle = "Pong";   //  name of game
    const int screenWidth = V_SCREEN_WIDTH * V_SCALE;
    const int screenHeight = V_SCREEN_HEIGHT * V_SCALE;

    SetConfigFlags(FLAG_VSYNC_HINT);    // Monitor must finish drawing a frame before it loads a new one from the GPU
    InitWindow(screenWidth, screenHeight, screenTitle);
    SetTargetFPS(60);   // 60 frames per second

    const RenderTexture2D renderTexture = LoadRenderTexture(V_SCREEN_WIDTH, V_SCREEN_HEIGHT);

    const Rectangle renderTextureSrc = (Rectangle){ 0.0f, 0.0f, V_SCREEN_WIDTH, -V_SCREEN_HEIGHT };
    const Rectangle renderTextureDest = (Rectangle){ 0.0f, 0.0f, screenWidth, screenHeight };

    float paddlePosX = screenWidth / 2.0f;
    float paddlePosY = screenHeight / 2.0f;
    float paddleWidth = 20;
    float paddleHeight = 90;

    Rectangle paddle = { paddlePosX, paddlePosY, paddleWidth, paddleHeight };

    while (!WindowShouldClose())
    {
        // Event Handling

        // Update
        
        // Drawing
        BeginTextureMode(renderTexture);
            ClearBackground(WHITE);
            DrawRectanglePro(paddle, (Vector2){ paddle.width/2, paddle.height/2 }, 0, WHITE);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK); // Pong game background must be black
            DrawFPS(0, 0);
            DrawTexturePro(renderTexture.texture, renderTextureSrc, renderTextureDest, (Vector2){ paddle.width/2, paddle.height/2 }, 0, WHITE);
        EndDrawing();
    }

    // remember to unload the texture when finished using it
    UnloadRenderTexture(renderTexture);

    CloseWindow();

    return 0;
}
