#include"raylib.h"
#include"Game.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main()
{
    // Initialization
    const int screenWidth = 1000;
    const int screenHeight = 600;
    

    Game game(screenWidth, screenHeight);

    // Main game loop
   
        while (!game.GameshouldClose()) // Detect window close button or ESC key
        {
            game.Tick();
        }
    
    return 0;
}

