#include "functions.h"

int main()
{
    AddFontResourceEx("font.ttf", FR_PRIVATE, NULL);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();
    beginView();
    RemoveFontResourceEx("font.ttf", FR_PRIVATE, NULL);
    system("pause");

    person player;
    mainEvent* eventTree = buildEventTree(); //初始化事件树
    gameLoop(player, eventTree); //进入游戏主循环
    deleteEventTree(eventTree);
    return 0;
}