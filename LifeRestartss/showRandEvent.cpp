#include <graphics.h>
#include <functions.h>


void showRandEvent(const randEvent& re) {
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT); // 初始化图形窗口

    // 设置文本样式
    settextcolor(BLACK);
    settextstyle(24, 0, _T("宋体"));

    // 绘制事件描述
    outtextxy(50, 50, re.description);
    outtextxy(50, 70, re.effect);

    

    // 关闭图形窗口
    closegraph();
}

