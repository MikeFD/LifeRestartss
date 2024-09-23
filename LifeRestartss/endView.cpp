#include<functions.h>
#include <graphics.h>

void endView()
{
	initgraph(640, 480); // 创建一个宽640像素，高480像素的窗口
	setbkcolor(LIGHTGRAY); // 设置背景颜色
	cleardevice(); // 清空屏幕
	settextstyle(24, 0, _T("Arial")); // 设置文本字体为Arial，大小为24
	settextcolor(BLACK); // 设置文本颜色为黑色

	outtextxy(50, 50, _T"游戏结束！"); // 显示游戏结束
	
	outtextxy(50, 100, Ending); // 显示结局信息
	setfillcolor(BLUE); // 设置填充颜色为蓝色
	setlinecolor(BLUE); // 设置边框颜色为蓝色
	fillrectangle(220, 200, 420, 230); // 绘制矩形按钮
	settextstyle(20, 0, _T("Arial")); // 设置文本字体和大小
	settextcolor(WHITE); // 设置文本颜色为白色
	outtextxy(250, 210, _T("返回主菜单")); // 显示按钮文本
	fillrectangle(220, 250, 420, 280); // 绘制矩形按钮
	outtextxy(250, 260, _T("重新开始游戏")); // 显示按钮文本
	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) { // 检测鼠标左键点击
			if (m.x >= 220 && m.x <= 420 && m.y >= 200 && m.y <= 230) { // 返回主菜单按钮
				return menuView(); // 调用返回主菜单的函数
			}
			if (m.x >= 220 && m.x <= 420 && m.y >= 250 && m.y <= 280) { // 重新开始游戏按钮
				return gameBeignView(); // 调用开始游戏的函数
			}
		}
	}
	closegraph(); // 关闭图形窗口
	
}