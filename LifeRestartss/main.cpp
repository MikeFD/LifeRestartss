#include "functions.h"
#include "Easytext.h"

person Person;
mainEvent* eventTree;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    youngEvent();
    AddFontResourceEx(L"font.ttf", FR_PRIVATE, NULL);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();
 
    beginView();
    eventTree = buildEventTree();
    Person = { 0,0,0,0,0 };
    gameLoop(Person, eventTree);
    //需要一个结局界面
    deleteEventTree(eventTree);
    RemoveFontResourceEx(L"font.ttf", FR_PRIVATE, NULL);
    system("pause");
    delete defeat;
    
    return 0;
}