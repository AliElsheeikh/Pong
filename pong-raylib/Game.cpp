#include"Game.h"



Game::Game(int screenWidth, int screenHeight)
{

    assert(!GetWindowHandle()); // if assertion triggers : window is already open
    InitWindow(screenWidth, screenHeight, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);
    //ball init
    ball.initBall(500, 500, 15);
    //left paddle init

    leftPaddle.position(50, GetScreenHeight() / 2);

    leftScore = '0';
    //right paddle init

    rightPaddle.position(GetScreenWidth() - 50, GetScreenHeight() / 2);
    rightScore = '0';

    //winner

    winnerMassage = nullptr;

    start = false;


}

Game::~Game()
{
    // Close window
    CloseWindow();
}

bool Game::GameshouldClose()
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();

    UpdateKey();


    EndDrawing();
}

void Game::Draw()
{

    ClearBackground(BLACK);

    ball.Draw();
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), RAYWHITE);
    DrawFPS(70, 10);
    leftPaddle.Draw(RED);
    rightPaddle.Draw(DARKBLUE);
    DrawText(leftScore.c_str(), GetScreenWidth() / 2 - 80, GetScreenHeight() - 50, 40, GREEN);
    DrawText(rightScore.c_str(), GetScreenWidth() / 2 + 70, GetScreenHeight() - 50, 40, GREEN);


}

void Game::Update()
{
    if (start == false)
    {
        if (IsKeyPressed(KEY_SPACE))
        {

            ball.x += ball.ballSpeed_X * GetFrameTime();
            ball.y += ball.ballSpeed_Y * GetFrameTime();
            start = true;
        }

    }
    else
    {
        ball.x += ball.ballSpeed_X * GetFrameTime();
        ball.y += ball.ballSpeed_Y * GetFrameTime();



        if (ball.y < 0)
        {
            ball.y = 0;
            ball.ballSpeed_Y *= -1;
        }
        if (ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.ballSpeed_Y *= -1;
        }






        //check collision circle rectangle "left paddle"
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, leftPaddle.GetRect()))
        {
            if (ball.ballSpeed_X < 0)
            {
                ball.ballSpeed_X *= -1.1f;

            }

        }

        //check collision circle rectangle "right paddle"
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, rightPaddle.GetRect()))
        {
            if (ball.ballSpeed_X > 0)
            {
                ball.ballSpeed_X *= -1.1f;

            }
        }


        //winner massage 
        if (ball.x < 0)
        {

            winnerMassage = "Right Player Wins!";



        }

        if (ball.x > GetScreenWidth())
        {

            winnerMassage = "Left Player Wins!";


        }

        if (winnerMassage && IsKeyPressed(KEY_SPACE))
        {
            if (ball.x < 0)
            {
                rightScore = to_string(rightPaddle.UpScore());



                ball.speed(400, 400);
            }

            if (ball.x > GetScreenWidth())
            {
                leftScore = to_string(leftPaddle.UpScore());
                ball.speed(-1 * 400, 400);

            }



            ball.x = GetScreenWidth() / 2.0f;
            ball.y = GetScreenHeight() / 2.0f;

            leftPaddle.y = GetScreenHeight() / 2;
            rightPaddle.y = GetScreenHeight() / 2;

            winnerMassage = nullptr;

        }
        if (winnerMassage)
        {
            int widthText = MeasureText(winnerMassage, 60);
            DrawText(winnerMassage, GetScreenWidth() / 2 - widthText / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
        }

    }

}

void Game::UpdateKey()
{



    //right key player

    if (IsKeyDown(KEY_W))
    {
        if (leftPaddle.y > 50) {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }

    }


    if (IsKeyDown(KEY_S))
    {
        if (leftPaddle.y < GetScreenHeight() - 55)
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }

    }

    //left key player
    if (IsKeyDown(KEY_UP))
    {
        if (rightPaddle.y > 55)
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
    }


    if (IsKeyDown(KEY_DOWN))
    {
        if (rightPaddle.y < GetScreenHeight() - 55)
        {

            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }
    }

    //----------------------------------------------------------------------------------

}

