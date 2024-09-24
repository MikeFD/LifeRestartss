#include "functions.h"

int flag;
int score;

vector<randEvent> ranEvents;
vector<string> happenEvent;

/*
 负责人：灵泽
判断事件是否发生函数：
    功能：传入人物当前属性值 判断是否可以发生该事件
    参数：person
    返回值：bool
*/
bool isTrigger(person p)
{
    if (p.IQ < eventlimit.IQ || p.EQ < eventlimit.EQ || p.ProgramingSkill < eventlimit.ProgramingSkill || p.Health < eventlimit.Health)
    {
        return false; // 属性不满足条件
    }

    struct YoungAgeChoices y;
    if (p.Age == y.age)
    {
        return ture;
    }
}


/*
     负责人：灵泽
     功能：
         展现随机事件发生的结果描述随机事件等
     参数：void
     返回值：void
 */
void showRandEvent()
{
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


void endView();
{
    initgraph(640, 480); // 创建一个宽640像素，高480像素的窗口
    setbkcolor(GREEN); // 设置背景颜色
    cleardevice(); // 清空屏幕
    settextstyle(24, 0, _T("Arial")); // 设置文本字体为Arial，大小为24
    settextcolor(BLACK); // 设置文本颜色为黑色

    outtextxy(50, 50, _T("游戏结束！")); // 显示游戏结束

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

vector<YoungAgeChoices> YoungEvents;//存储18岁以前的年龄事件
vector<examSocre> examScores = { {HighAttribute, 500, 700}, {MidAttribute, 300, 500 }, {LowAttribute, 100, 300} };


void gameLoop(person& p, mainEvent& event) {
	for (p.Age = 0; p.Age <= 100; p.Age++) {
		if (flag == 0) {
			if (p.Age == 17) {
				score = getScore(p.IQ);
			}
			else {
				if (YoungEvents[p.Age].choices.size() > 1) {
					YoungEvents[p.Age].showYoungAgeChoices();
					//是不是还要加一些数值传入什么
					Bonus delta = YoungEvents[p.Age].choices[0].improve;
					p.IQ += delta.IQBonus;
					p.EQ += delta.EQBonus;
					p.ProgramingSkill += delta.ProgramingSkillBonus;
					p.Health += delta.HealthBonus;
				}
				else if (YoungEvents[p.Age].choices.size() == 1) {
					//直接显示事件
					YoungAgeChoices[p.Age].showYoungAgeChoices();
				}
			}
		}
		else if (flag == 1) {

		}
		else if (flag == 2) {

		}
		else if (flag == 3) {

		}
		else if (flag == 4) {

		}
		else if (flag == 5) {

		}
		else if (flag == 6)
	}

	
}

