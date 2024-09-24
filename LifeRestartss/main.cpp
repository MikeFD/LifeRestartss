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

    return 0;
}