#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <utility>
#include <stack>

using namespace std;

const int HighAttribute=100 ;
const int MidAttribute=50 ;
const int LowAttribute=0 ;




//---------------------------数据设计------------------------------

/*
    表示阶段：不同阶段会触发不同的事件  调用不同事件的树 若是死亡或者永生则调用结束函数
    0表示幼儿时期 1表示大学时期
    2表示研究生时期 3表示工作时期
    4表示无业时期 5表示咸鱼期
    6表示创业期 7表示退休期
    8表示死亡 9表示永生
*/
extern int flag;


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
    表示18岁之前的选择性事件
*/
//人生选择 18岁之前的一些选择以及选择带来的一些影响
struct youngChoiceEffects
{
    string description;//事件描述
    Bonus improvebonus;
    string outcome;//表示事件发生在界面上所返回的一些句子
};//代表18岁之前的选择以及影响


/*
    表示18岁之前的选择性事件集合
*/
struct YoungAgeChoices
{
    int age; // 年龄阶段，例如：12表示12岁，15表示15岁
    vector<youngChoiceEffects> choices; // 选择列表

    /*
        负责人：崇
        功能：展示事件描述以及选择供玩家选择
        返回值：void
    */
    void showYoungAgeChoices();


};

extern vector<YoungAgeChoices> YoungEvents;

#define MINHEALTH 50//
#define WINDOW_HEIGHT 768// 窗口高度
#define WINDOW_WIDTH 1024//窗口宽度
extern ExMessage msg;


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

extern person p;//实例化主角




extern Bonus b;//实例化Bonus结构体

/*
    触发事件的属性限制  如{"IQ": 100, "CodingLevel": 80}
*/
typedef struct
{
    int Age;
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

extern vector<talent> talents;//存储可选天赋
extern vector<talent> randtalents;//存储在天赋页面上展现的天赋
extern vector<int> talentChoices;//选择的3个天赋id




// 定义18岁之前的选择数据



/*高考选择*/
extern bool isExam;//表示是否参加高考 若参加根据当前的属性来判断所能考取的分数范围 再利用随机数获取分数



struct examSocre//表示高考分数范围
{
    int IQ; // 达到该范围的最小IQ值
    int min_score;//表示最低所能考取的分数
    int max_score;//表示最高所能考取的分数
};

/*
表示高考分数的三个范围100~300 300~500 500~700

*/
extern vector<examSocre> examScores;

extern int score;//表示当前的最终分数




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
    limit eventlimit;//表示发生该事情的属性限制
    string description;           // 事件描述
    vector<mainEvent*> children;  // 子事件节点
    Bonus eventBonus; //表示该事件对玩家属性的影响

    /*
  Event的构造函数
      负责人：灰机
      功能：用于初始化事件类内的属性
      参数：string limit分别表示事件描述 和 事件的属性限制
      返回值： 无返回值

  */
    mainEvent(string description, limit event);

    /*
     负责人：灵泽
    判断事件是否发生函数：
        功能：传入人物当前属性值 判断是否可以发生该事件
        参数：person
        返回值：bool
    */
    bool isTrigger(person p);


    /*
        负责人：liz
        功能：
            展示事件的内容并且 如果是节点只有一个则是只展示事件 如果节点有多个则是选择事件
            并且调用mouseClick函数用于接受用户输入根据输入进入下一节点
        参数：void
        返回值: void
    */
    void showAndChooseEvent();
};




/*
    表示随机事件  其中包含事件的表示 事件的效果 以及发生的概率等
*/

struct randEvent
{
    string description;  // 事件描述，例如“突然得癌症”、“交通事故”
    Bonus effect;  // 事件效果，例如减少健康值、减少寿命等
    limit randlimit;//随机事件发生的 属性限制
    float possibility;   // 事件发生的概率，0到1之间  
    bool isafectPossibility;//人物属性是否影响事件发生的概率
    bool ishappend;//表示该事件是否以及发生
    //------------------------内置函数-------------------------------
    /*
        负责人：fan
        功能：
            根据角色属性的下降 来给对应事件一个增加一个概率
        参数： randevent 和 person
        返回值： float
    */
    float adjustPossibility(person& p, randEvent event);



    /*
        负责人：fan
        功能：传入人物属性 判断该事件是否会发生 若跟人物属性无关联则直接 生成一个随机数与possibility进行比较 若大于则可以发生 若小于则不能发生
        参数：person
        返回值： bool

    */
    bool triggerEvent(person &p,randEvent &event);


    /*
        负责人：fan
        功能：
            处理随机事件 对应给人物增加的属性 或 导致人物出先某些状况
        参数：玩家对象 和 randEvent
        返回值：void

    */
    void checkRandEvents(person &p, randEvent& event);


    /*
        负责人：灵泽
        功能：
            展现随机事件发生的结果描述随机事件等
        参数：void
        返回值：void
    */
    void showRandEvent();
};

/*
    表示随机事件的集合
*/
extern vector<randEvent> ranEvents;


//表示大学阶段事件 继承
class UniversityEvent :public mainEvent {};

/*
    读研线
*/
class postgraduateEvent :public mainEvent {};


/*
    工作线
*/
class jobEvent :public mainEvent {};


/*
    创业线
*/
class EnterpriseEvent :public mainEvent {};


/*
    失败线
*/
class defeatEvent : public mainEvent {};


/*
    退休线
*/
class retireEvent : public mainEvent {};


/*
    表示已经发生事件的集合 每次初始化时候遍历展现到消息界面上
*/
extern vector<string> happenEvent;


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
    负责人：faivm
    功能：
        初始化界面，根据已经发生的事件在消息框进行一个展示
        以及初始化角色的初始属性
    参数：void
    返回值：void
*/
void init();


/*
    负责人：小逸
    功能：
        天赋对属性的影响
            根据玩家所选择的天赋卡对属性值进行修改
    参数：玩家对象，由talentChooseView函数传入的天赋卡ID号容器
    返回值：void

*/
void TalentBonus(person& p, vector<int>& talentId);

/*
    负责人：飞
    功能：
        初始化随机事件表
            往randomEvents容器中添加事件
    参数：void
    返回值：void

*/
void initRandomEvents();


/*
    负责人：liz
    功能：
        构建事件树
            由关键时间节点事件组成
    参数：void
    返回值：void

*/
void buildEventTree();


//写一条主线，记录固定交互事件的时间点？
/*
    负责人：GT
    功能：
        事件循环函数
            按18岁之前的事件>故事线上的事件>随机事件的顺序进行判断 每年最多同时发生俩件事
                while(age<100){
                    根据年龄，检查是否有固定交互事件

                    根据当前flag判断哪个处于哪个阶段进行故事线的推进 同时推进完故事线时也会判断随机事件是否发生
                    除了18岁之前 随机事件不会发生等
                    或者用flag记录阶段、前面那些类主要用作存储对应故事线下的事件
                    检查玩家的健康值，达到死亡条件时跳出循环
                }
            游戏结束endView()
    参数：玩家对象player，当前事件节点currentEvent
    返回值：void

*/
void gameLoop(person, mainEvent*);
void traverseTree(mainEvent* root, person p);


/*
    负责人：飞
    功能：
        根据传入的智力获取一个高考所能获得的分数范围
    参数：int
    返回值：pair<int,int>
*/
pair<int,int> getScoreRange(int iq);


/*
    负责人：飞
    功能：
        调用getScoreRange函数来获取一个分数范围再 从返回的分数范围内利用随机数返回最后的实际的高考分数
    参数：int
    返回值：void
*/
int getScore(int iq);



/*
    负责人：小逸
    功能：
        玩家通过鼠标点击的方式来处理鼠标消息进行选择然后根据选择
        来推导剧情的走向 包括选择事件的点击 和 下一年 以及登录 游戏中各个按钮的点击事件是否成功的函数
    参数：int 表示用户鼠标点击时候的坐标
    返回值：bool
*/
bool mouseClick(int x, int y);






/*
    负责人：faivm
    功能：
        根据事件影响修改玩家属性值
    参数：void
    返回值：void

*/
void EventBonus();



//---------------------------service-------------------------------



//-----------------------------view--------------------------------
/*
    负责人：崇
    功能：
        用于在gameView的基础上展现一个小的界面 用于展示
    随机事件的事件发生描述
    参数：void
    返回值：void
*/
void thingView();
/*
   负责人：崇
   功能：
       初始化主菜单界面
           展示选择选项：
               开始游戏：进入游戏界面
               游戏说明 ：说明游戏玩法
               退出游戏：退出程序
   参数：void
   返回值：void
*/

void menuView();
/*
   负责人：崇
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
void beginView();


/*
    负责人：崇
    功能：提供用户输入账户和密码
        有俩个按钮
        一个是登录按钮  进入游戏开始界面
        一个是取消按钮 用于返回主菜单，进入主菜单页面
    参数 void
    返回值 void
*/
void loginView();

/*
    负责人：崇
    功能：
        用于用户注册账号
        有俩个按钮一个是注册 一个是返回 二者均返回至登录页面
    参数：void
    返回值：void
*/
void registerView();


/*
    负责人：崇
    功能：
        有三个按钮
        一个是开始游戏的按钮进入抽卡界面
        一个是人生履历按钮进入生涯界面
        一个是成就按钮进入成就界面
    参数：void
    返回值：void
*/
void gameBeginView();


/*

    负责人：小逸
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
     负责人：崇
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
    负责人：崇
    功能：
        用于在gameView的基础上展现一个小的界面 用于展示

        1.选择事件的事件描述 加上选择选项
    参数：void
    返回值：void
*/
void popView();


/*
    负责人：崇
    功能：
        用于展现设置界面  敬请期待……
    参数：void
    返回值：void
*/
void settingView();


/*
      负责人：GT
    功能：
        用于展现玩家在游戏中重开的次数 以及获得的最高分数
        里面有一个按钮用于返回游戏开始界面
    参数：void
    返回值：void
*/
void careerView();


/*
    负责人：崇
    功能：
        用于展现玩家所获得成就
        里面有一个返回按钮用于返回游戏开始界面
    参数：void
    返回值：void
*/
void achievementView();


/*
    负责人：灵泽
    功能：
        用于展示玩家游戏结束后产生的结局
        可以返回主菜单 可以重新开始游戏（进入GameView）
*/
void endView();


//-----------------------------view--------------------------------
