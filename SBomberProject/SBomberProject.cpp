
#include <conio.h>
#include <Windows.h>
#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================
FileLogger logger("log.txt");

int main(void)
{
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();
        Sleep(30);

        game.TimeFinish();

    } while (!game.GetExitFlag());

    return 0;
}
