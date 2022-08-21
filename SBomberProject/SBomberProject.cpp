
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "windows.h"
using namespace std;

//========================================================================================================================

int main(void)
{
    MyTools::LoggerSingleton::getInstance().OpenLogFile("log.txt");

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

    MyTools::LoggerSingleton::getInstance().CloseLogFile();

    return 0;
}
