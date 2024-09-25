#include "functions.h"


int flag;
int score;


vector<randEvent> ranEvents;
vector<string> happenEvent;

vector<YoungAgeChoices> YoungEvents;//存储18岁以前的年龄事件
vector<examSocre> examScores = { {HighAttribute, 500, 700}, {MidAttribute, 300, 500 }, {LowAttribute, 100, 300} };


void init()
{

	//初始化属性

	p.Age = 0;
	p.EQ = 0;
	p.Health = 100;
	p.IQ = 0;
	p.ProgramingSkill = 0;


	//消息框


	//消息框的大小
	const int BOX_WIDTH = 400;
	const int BOX_HEIGHT = 300;

	//消息框的位置
	const int BOX_X = 50;
	const int BOX_Y = 50;

	//每行高度
	const int LINE_HEIGHT = 20;

	//最大行数
	const int MAX_LINES = BOX_HEIGHT / LINE_HEIGHT;

	//储存事件的容器
	vector<string> messages;


	// 滚动偏移量，表示当前显示的消息的起始行
	int scroll_offset = 0;

	//绘制消息框
	setfillcolor(WHITE);
	bar(BOX_X, BOX_Y, BOX_X + BOX_WIDTH, BOX_Y + BOX_HEIGHT);

	// 绘制消息框的边框
	setlinecolor(BLACK);
	rectangle(BOX_X, BOX_Y, BOX_X + BOX_WIDTH, BOX_Y + BOX_HEIGHT);

	// 绘制消息
	int start_line = scroll_offset;//起始行
	int end_line = start_line + MAX_LINES;//结束行

	for (int i = start_line; i < end_line && i < messages.size(); ++i) 
	{
		//绘制每行消息
		outtextxy(BOX_X + 10, BOX_Y + 10 + (i - start_line) * LINE_HEIGHT, messages[i].c_str());//(i - start_line) * LINE_HEIGHT每行间隔,messages[i].c_str()转换成c语言风格的字符串
	}


	if (_kbhit()) //检测是否有键盘输入
	{
		char key = _getch();
		if (key == 'w' && scroll_offset > 0) {
			scroll_offset--;
		}
		else if (key == 's' && scroll_offset < messages.size() - MAX_LINES) {
			scroll_offset++;
		}
	}

}
void EventBonus(person& p, Bonus b)
{
	p.EQ += b.EQBonus;
	p.Health += b.HealthBonus;
	p.IQ += b.IQBonus;
	p.ProgramingSkill += b.ProgramingSkillBonus;
}


/*
 负责人：灵泽
判断事件是否发生函数：
    功能：传入人物当前属性值 判断是否可以发生该事件
    参数：person
    返回值：bool
*/
bool mainEvent::isTrigger(person p)
{
    if (p.IQ < eventlimit.IQ || p.EQ < eventlimit.EQ || p.ProgramingSkill < eventlimit.ProgramingSkill || p.Health < eventlimit.Health)
    {
        return false; // 属性不满足条件
    }

    struct YoungAgeChoices y;
    if (p.Age == y.age)
    {
        return true;
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

bool is_mainEvent(mainEvent*& root, person p) {//判断子节点是否有符合条件的
	if (root == nullptr) {
		return true;
	}
	if (!root->is_choose) {
		for (auto child : root->children) {
			if (child->isTrigger(p)) {
				root = child;
				return true;
			}
		}
	}
	else {
		//选择并返回事件id
		root = root->children[0];
		return true;
	}
	return false;
	
}

//GT写的
void gameLoop(person& p, mainEvent*& event) {
	srand(static_cast<unsigned int>(time(nullptr)));
	int randId = rand() % 20;
	mainEvent* treeEvent = event;
	if (p.Age < 18) {
		if (p.Age == 17) {
			score = getScore(p.IQ);

			//有没有大学相关的判断功能，比如我去了哪个大学,属性需要发生什么更改。
			//University_lor();
		}
		else {
			if (YoungEvents[p.Age].choices.size() > 1) {
				YoungEvents[p.Age].showYoungAgeChoices();
				//是不是还要加一些数值传入什么
				Bonus delta = YoungEvents[p.Age].choices[0].improve;//这行代码的数值传入尚未解决。就那个0
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
	else if (is_mainEvent(event, p)) {
		//这里是要判断主事件的发生情况，主事件的发生也包含了那些支线树。
		string arr = event->description;//故事
		p.IQ += event->eventBonus.IQBonus;
		p.EQ += event->eventBonus.EQBonus;
		p.Health += event->eventBonus.HealthBonus;
		p.ProgramingSkill += event->eventBonus.ProgramingSkillBonus;
		

	}
	else if (ranEvents[randId].triggerEvent(p, ranEvents[randId])) {
		//这里判断随机事件的发生情况
		randEvent cEvent = ranEvents[randId];
		string arr = cEvent.description;
		p.IQ += cEvent.effect.IQBonus;
		p.EQ += cEvent.effect.EQBonus;
		p.ProgramingSkill += cEvent.effect.ProgramingSkillBonus;
		p.Health += cEvent.effect.HealthBonus;
	}
}

void TalentBonus(person& p, vector<int>& talentId)
{
    for (vector<int>::iterator it1 = talentId.begin(); it1 != talentId.end(); it1++) {
        for (vector<talent>::iterator it2 = talents.begin(); it2 != talents.end(); it2++) {
            if (it2->talentID == *it1) {
                p.IQ += it2->talentBonus.IQBonus;
                p.EQ += it2->talentBonus.EQBonus;
                p.ProgramingSkill += it2->talentBonus.ProgramingSkillBonus;
                p.Health += it2->talentBonus.HealthBonus;
            }
        }
    }
        
  
}
mainEvent::mainEvent(string description, limit event, Bonus eventBonus, bool choose) {
	this->description = description;
	this->eventlimit = event;
	this->eventBonus = eventBonus;
	this->is_choose = choose;
}

float randEvent::adjustPossibility(person& p, randEvent event)
{
	if (!event.isafectPossibility) return event.possibility;
	float adjustposibility = event.possibility;
	if (p.Health < 50)
	{
		adjustposibility += abs(p.Health - 50) * 0.5;
	}
	if (p.Age > 0)
	{
		adjustposibility = p.Age * 0.25;
	}
	return min(100.0f, adjustposibility);

	
}

bool randEvent::triggerEvent(person &p,randEvent &event)
{
	// 在初始化的时候使用
	//srand(static_cast<unsigned>(time(NULL)));
	float randnum;
	event.possibility = adjustPossibility(p, event);
	if (event.ishappend)
	{

		
		if (p.Age >= randlimit.Age && p.Health >= randlimit.Health && p.EQ >= randlimit.EQ && p.IQ >= randlimit.IQ && p.ProgramingSkill >= randlimit.ProgramingSkill)
		{
			
			randnum = static_cast<float>(rand() % 100);
			return randnum < event.possibility;
		}
	}
	return false;
}

void randEvent::checkRandEvents(person &p,randEvent &event)
{
	if (triggerEvent(p,event))
	{
		p.Health = event.effect.HealthBonus;
		p.EQ = event.effect.EQBonus;
		p.IQ = event.effect.IQBonus;
		p.ProgramingSkill = event.effect.ProgramingSkillBonus;
	}
}

