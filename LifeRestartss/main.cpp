#include "functions.h"



int main()
{
    person player;
    mainEvent* eventTree = buildEventTree(); //初始化事件树
    gameLoop(player, eventTree); //进入游戏主循环
    deleteEventTree(eventTree);
    return 0;
}