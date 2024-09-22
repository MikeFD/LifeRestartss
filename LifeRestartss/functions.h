#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//---------------------------数据设计------------------------------

/*
    表示阶段：不同阶段会触发不同的事件  调用不同事件的树 若是死亡或者永生则调用结束函数
    0表示幼儿时期 1表示大学时期
    2表示研究生时期 3表示工作时期
    4表示无业时期 5表示咸鱼期
    6表示创业期 7表示退休期
    8表示死亡 9表示永生
*/
int flag;


/*
    玩家设置
    年龄、智商、情商、编程能力、健康
*/
typedef struct
{
    int Age;//年龄
    int IQ;//智商
    int EQ;//情商
    int ProgramingSkill;//编程能力
    int Health;//健康
}person;


/*
    属性受影响 加/减
*/
typedef struct
{
    int IQBonus;
    int EQBonus;
    int ProgramingSkillBonus;
    int HealthBonus;
}Bonus;


/*
    触发事件的属性限制  如{"IQ": 100, "CodingLevel": 80}
*/
typedef struct
{
    int IQ;
    int EQ;
    int ProgramingSkill;
    int Health;
}limit;


/*
    天赋设置
*/
typedef struct {
    int talentID; //天赋卡ID
    string description; //天赋描述
    Bonus talentBonus; //天赋对属性的影响
}talent;


/*
    事件类的父类   用树来进行表示 根节点表示当前事件  子节点表示下一个发生事件的选择
            若没有子节点则进入下一个阶段
            若只有一个子节点则直接访问该子节点
            若有多个子节点作为选择性事件供玩家选择 选择后再访问该节点
            特殊情况：若属性限制limit 限制了事件发生 那么节点保持不变 事件发展停滞 例如：年龄不到25岁不会触发大厂裁员的事件
    成员变量：事件描述 description   属性限制 limit（限制事件发生的最低属性要求)
    事件的子节点 children 表示
*/
class mainEvent
{
public:
    string description;           // 事件描述
    vector<mainEvent*> children;  // 子事件节点
    Bonus eventBonus; //表示该事件对玩家属性的影响
    int triggerAge;  //如果是固定事件则设置为对应的年龄，交互事件则设置为-1

    virtual ~mainEvent() {};
};


class interactiveEvent : public mainEvent {
public:
    void chooseEvent(person& person) {

    }
};

class rndEvent :public mainEvent {
public:
    bool shouldTrigger() {

    }
};


//表示大学阶段事件 继承
class UniversityEvent :public mainEvent {};

//表示研究生阶段事件 继承
class postgraduateEvent :public mainEvent {};


//表示工作阶段事件
class jobEvent :public mainEvent {};


//表示创业阶段事件
class EnterpriseEvent :public mainEvent {};


//表示失败阶段事件
class defeatEvent : public mainEvent {};


//表示退休阶段事件
class retireEvent : public mainEvent {};


/*
    表示随机事件
    成员变量：事件的表示 事件的效果 发生的概率等
*/

struct rndEvent
{
    string description;  // 事件描述，例如“突然得癌症”、“交通事故”
    Bonus effect;  // 事件效果，例如减少健康值、减少寿命等
    float probability;   // 事件发生的概率，0到1之间
    //------------------------内置函数-------------------------------
};

/*
    表示随机事件的集合
*/
vector<rndEvent> rndEvents;


/*
    表示已经发生事件的集合 每次初始化时候遍历展现到消息界面上
*/
vector<string> happenEvent;


/*
  结局相关设置
*/

// 描述结局
typedef struct
{
    string description; // 结局的详细描述
    int score; // 结局评分，A、B、C等
    bool isHidden; // 是否为隐藏结局 可以设计一些彩蛋之类的比如如果是隐藏结局展现的页面不同
} Ending;

// 结局触发条件，可以根据属性或事件来设定
typedef struct
{
    limit endlimit;//结局属性条件
    vector<mainEvent> preevent;//表示触发结局的所需要发生的前置事件
} EndingCondition;

// 结局判断与触发
typedef struct
{
    Ending ending; // 具体的结局描述
    EndingCondition condition; // 触发该结局的条件
} EndingEvent;

//---------------------------数据设计------------------------------



//---------------------------service-------------------------------

/*
    负责人：
    功能：
        初始化随机事件表
        初始化游戏数据
    参数：void
    返回值：void

*/
void init();


/*
    负责人：
    功能：
        天赋对属性的影响
            根据玩家所选择的天赋卡对属性值进行修改
    参数：玩家对象，由talentChooseView函数传入的天赋卡ID号容器
    返回值：void

*/
void TalentBonus(person, vector<int>);

/*
    负责人：
    功能：
        初始化随机事件表
            往randomEvents容器中添加事件
    参数：void
    返回值：void

*/
void initRandomEvents();


/*
    负责人：
    功能：
        构建事件树
    参数：void
    返回值：返回人生起点事件

*/
mainEvent* buildEventTree();


/*
    负责人：
    功能：
        事件循环函数
            按固定事件>交互事件>随机事件的顺序，确保每年只触发一个事件
                while(age<100){
                    检查是否有固定事件

                    没有，则检查交互事件

                    没有固定事件、交互事件，则检查随机事件


                    事件发生后玩家年龄增加

                    检查玩家的健康值，达到死亡条件时跳出循环
                }
            游戏结束endView()
    参数：玩家对象player，当前事件节点currentEvent
    返回值：void

*/
void gameLoop(person, mainEvent*);


/*
    负责人：
    功能：
        随机数生成器，在checkRandomEvents()函数中被调用
    参数：void
    返回值：生成的随机数

*/
float generateRandom();

/*
    负责人：
    功能：
        根据generateRandom()函数生成的随机数，检查是否触发随机事件
    参数：玩家对象
    返回值：void

*/
void checkRandomEvents(person);


/*
    负责人：
    功能：
        处理交互事件
    参数：void
    返回值：void

*/
void handleInteractiveEvent();


/*
    负责人：
    功能：
        根据事件影响修改玩家属性值
    参数：void
    返回值：void

*/
void EventBonus();


//---------------------------service-------------------------------



//-----------------------------view--------------------------------

 /*
    负责人：
    功能：
        初始化主菜单界面
            展示选择选项：
                登录账户：进入登录界面
                注册账户：进入注册界面
                游戏设置：进入游戏设置界面 //扩展
                退出游戏：退出程序
    参数：void
    返回值：void
*/
void menuView();


/*
    负责人：
    功能：提供用户输入账户和密码
        有俩个按钮
        一个是登录按钮  进入游戏开始界面
        一个是取消按钮 用于返回主菜单，进入主菜单页面
    参数 void
    返回值 void
*/
void loginView();

/*
    负责人：
    功能：
        用于用户注册账号
        有俩个按钮一个是注册 一个是返回 二者均返回至登录页面
    参数：void
    返回值：void
*/
void registerView();

/*
    负责人：
    功能：
        有三个按钮
        一个是开始游戏的按钮进入抽卡界面
        一个是人生履历按钮进入生涯界面
        一个是成就按钮进入成就界面
    参数：void
    返回值：void
*/
void gameBeignView();


/*

    负责人：
    功能：
      展现天赋选项
            让用户选取天赋，若选取的天赋少于3个则继续选择
            调用TalentBonus()函数，根据天赋修改属性值
      有一个选择按钮 选择之后则进入游戏界面
    参数：void
    返回值：void
*/
void talentChooseView();


/*
     负责人：
     功能：
        调用init()初始化游戏数据
        用于显示角色属性 和一些基本信息
        显示一个文本框用于展示已经发生的事件 和一些必然事件
        还有一个按钮供用户点击下一年
     参数：void
     返回值： void
*/
void gameView();


/*
    负责人：
    功能：
        用于在gameView的基础上展现一个小的界面 用于展示
        1.随机事件的事件发生描述
        2.选择事件的事件描述 加上选择选项
    参数：void
    返回值：void
*/
void popView();


/*
    负责人：
    功能：
        用于展现设置界面  敬请期待……
    参数：void
    返回值：void
*/
void settingView();


/*
      负责人：
    功能：
        用于展现玩家在游戏中重开的次数 以及获得的最高分数
        里面有一个按钮用于返回游戏开始界面
    参数：void
    返回值：void
*/
void careerView();


/*
    负责人：
    功能：
        用于展现玩家所获得成就
        里面有一个返回按钮用于返回游戏开始界面
    参数：void
    返回值：void
*/
void achievementView();


/*
    负责人：
    功能：
        用于展示玩家游戏结束后产生的结局
        可以返回主菜单 可以重新开始游戏（进入GameView）
*/
void endView();


//-----------------------------view--------------------------------



int main()
{
    person player;
    mainEvent* eventTree = buildEventTree(); //初始化事件树
    gameLoop(player, eventTree); //进入游戏主循环
    return 0;
}