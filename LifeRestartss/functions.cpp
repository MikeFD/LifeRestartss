#include "functions.h"


int flag;
int score;


vector<randEvent> ranEvents;
vector<string> happenEvent;

vector<examSocre> examScores = { {HighAttribute, 500, 700}, {MidAttribute, 300, 500 }, {LowAttribute, 100, 300} };
vector<talent> talents;//存储可选天赋
vector<int> talentChoices;//选择的3个天赋id

void YoungAgeChoices::showYoungAgeChoices()
{
	char ans[100];
	for (auto x : choices) {
		sprintf_s(ans, "%s \n ", x.description.c_str());
	}
	printf("%s", ans);
}

void init(person& p)
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
	vector<wstring> messages;


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

void initRandomEvents() /*初始化随机事件表*/
{
    ranEvents.clear(); /*清空容器*/

    // 添加随机事件及其效果
    ranEvents.emplace_back(randEvent{
        "正当你心情有点儿小郁闷时，突然一道彩虹挂在天边，宛如画中仙境，心情瞬间晴朗起来！",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在公园溜达一圈，长椅上躺着一张钞票，你感觉真是天上掉馅饼",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在咖啡馆喝咖啡时，与久别的挚友不期而遇，聊起当年趣事，犹在眼前",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你遇到一位迷路的外国友人，给他指路，他十分感谢，自己心里也满满的成就感。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "街头转角，一只软萌的流浪猫蹭蹭你的腿，眼神里全是渴望，你因为爱心收留了它！",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "超市大促销，你抢到心仪的打折商品，省下的银子可以再买包零食庆祝一番！",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.06f, // 6% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在广场上，看见一位街头艺人的精彩表演，你也跟着high了起来。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "下班路上你抬头一看，发现晚霞满天，美得让人窒息，让奔波的灵魂得到了片刻安宁。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "小区门口新开的餐馆，你尝鲜之后发现竟是意外的美味，从此多了个心头好！",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你和家人一起过节，餐桌上摆满了熟悉的食物，谈笑风生之间，那份亲情和归属感油然而生。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在一堆堆书山中挖宝，终于找到那本期待已久的书，那种兴奋感简直爆棚！",
        Bonus{5, 0, 0, 0}, // 增加5点智商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在商场逛街时，背景音乐刚好是你的最爱，让你平淡的生活增添了几许浪漫气息，整个人都被治愈了。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你过生日时意外地收到朋友邮寄的神秘礼物，那份惊喜和感动直接拉满！",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你清晨公园散步时，耳边响起鸟儿们的欢快歌声，感觉整个世界都在欢迎新的一天。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "帮助老爷爷老奶奶过马路，他们的笑容比太阳还要灿烂，感觉自己做了件很了不起的事情。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "在巷弄里，你与你的朋友把一面墙绘成了五彩斑斓的艺术品，你们十分开心。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在散步时突然被一阵热烈的鼓掌吸引，你一看是有位街头表演者正在献艺，那股激情和活力感染了你。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你扶老人安全过马路，他们的微笑是对善良行为最好的回报。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你购买的彩票竟然中奖了，虽然金额不大，但那份惊喜如同中了大奖一般。",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在旅游途中，误打误撞进入一个风景如画的小镇，留下了一生中最美的回忆。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你学习烹饪，成功做出一道美味佳肴。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你在美术馆偶遇一幅触动心灵的作品，那份艺术与情感的交汇让你感慨万千。",
        Bonus{5, 5, 0, 0}, // 增加5点智商和5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        "你读到一篇励志文章，其中的观点和感悟如同及时雨般滋养了你干涸的心灵。",
        Bonus{5, 5, 0, 0}, // 增加5点智商和5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });
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
bool mainEvent::isTrigger(person p, mainEvent* event)
{
    if (p.Age<eventlimit.Age||p.IQ < eventlimit.IQ || p.EQ < eventlimit.EQ || p.ProgramingSkill < eventlimit.ProgramingSkill || p.Health < eventlimit.Health)
    {
        return false; // 属性不满足条件
    }

	return true;
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
    //outtextxy(50, 50, re.description);
   // outtextxy(50, 70, re.effect);



    // 关闭图形窗口
    closegraph();
}

mainEvent* buildEventTree() {
    /*
        主要故事线变量定义
    */
    // 大学阶段
    mainEvent* university = new mainEvent(
        "进入大学，开始新的学习生活。",
        { 18, 80, 0, 0, 0 }, // 年龄18-22岁，智商大于80
        { 5, 5, 5, -5 }, // 智商+5，情商+5，编程能力+5，健康-5
        false // 不是选择事件
    );

    // 工作线
    mainEvent* job = new mainEvent(
        "找到一份工作，开始职业生涯。",
        { 22, 90, 0, 70, 0 }, // 年龄大于22岁，智商大于90，编程能力大于70
        { 10, 10, 15, -10 }, // 智商+10，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    // 读研线
    mainEvent* postgradu = new mainEvent(
        "决定继续深造，攻读研究生学位。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 15, 10, 10, -15 }, // 智商+15，情商+10，编程能力+10，健康-15
        true // 是选择事件
    );

    // 创业线
    mainEvent* enterprise = new mainEvent(
        "决定创业，开始自己的事业。",
        { 25, 110, 90, 80, 0 }, // 年龄大于25岁，智商大于110，情商大于90，编程能力大于80
        { 20, 20, 25, -20 }, // 智商+20，情商+20，编程能力+25，健康-20
        true // 是选择事件
    );

    mainEvent* defeatOrenterprise = new mainEvent(
        "创业线或失败线选择事件。",
        { 0, 0, 0, 0, 0 }, // 无特定限制
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    ); //创业线有可能被触发。 

    // 失败线
    mainEvent* defeat = new mainEvent(
        "遭遇重大失败，生活陷入低谷。",
        { 0, 0, 0, 0, 0 }, // 无特定限制
        { -30, -30, -30, -30 }, // 智商-30，情商-30，编程能力-30，健康-30
        false // 不是选择事件
    );

    // 退休线
    mainEvent* retire = new mainEvent(
        "退休，享受晚年生活。",
        { 60, 80, 80, 50, 60 }, // 年龄大于60岁，智商大于80，情商大于80，编程能力大于50，健康大于60
        { -10, -10, -10, 20 }, // 智商-10，情商-10，编程能力-10，健康+20
        false // 不是选择事件
    );

    /*
        失败线和创业线二选一
    */
    defeatOrenterprise->children.push_back(defeat);
    defeatOrenterprise->children.push_back(enterprise);
    /*
        大学阶段：填充关键事件——读研、工作
    */
    university->children.push_back(postgradu);
    university->children.push_back(job);

    /*
        工作线：定义事件变量
    */
    mainEvent* discharge = new mainEvent(
        "被裁员。",
        { 22, 90, 0, 70, 0 }, // 年龄大于22岁，智商大于90，编程能力大于70
        { -10, -10, -10, -10 }, // 智商-10，情商-10，编程能力-10，健康-10
        false // 不是选择事件
    ); //裁员
    /*
        工作线：填充关键事件
    */
    //没找到工作
    job->children.push_back(defeat);
    //找到工作： 
    job->children.push_back(discharge); //是否被裁员 
    //被裁员： 
    discharge->children.push_back(defeat); //进入失败线 
    discharge->children.push_back(enterprise); //激发创业线 
    //没被裁：
    discharge->children.push_back(retire); //进入退休线 

    /*
        读研线：定义事件变量
    */
    // 读研态度
    mainEvent* study_attitude = new mainEvent(
        "决定读研的态度，是积极还是消极。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 10, 5, 10, -5 }, // 积极态度：智商+10，情商+5，编程能力+10，健康-5
        true // 是选择事件
    );
    // 是否加入实验室
    mainEvent* join_lab = new mainEvent(
        "决定是否加入实验室进行科研。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 15, 10, 15, -10 }, // 加入实验室：智商+15，情商+10，编程能力+15，健康-10
        true // 是选择事件
    );

    // 读研选择技术
    mainEvent* tech_choose = new mainEvent(
        "选择读研的技术方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    // 神经网络技术线
    mainEvent* network_tech = new mainEvent(
        "选择神经网络技术作为研究方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    // 人工智能技术线
    mainEvent* ai_tech = new mainEvent(
        "选择人工智能技术作为研究方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    // 破解人类神经网络数据化
    mainEvent* solveNetworkdatalize = new mainEvent(
        "成功破解人类神经网络数据化技术。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 30, 20, 30, -20 }, // 智商+30，情商+20，编程能力+30，健康-20
        false // 不是选择事件
    );

    // 研究脑际接口，看看能否将动物神经网络数据上传
    mainEvent* uploadAnimalsNetwork = new mainEvent(
        "研究脑际接口，尝试将动物神经网络数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 25, 15, 25, -15 }, // 智商+25，情商+15，编程能力+25，健康-15
        false // 不是选择事件
    );

    // 上传成功
    mainEvent* Uploaded = new mainEvent(
        "成功将动物神经网络数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 30, 20, 30, -20 }, // 智商+30，情商+20，编程能力+30，健康-20
        false // 不是选择事件
    );

    // 上传失败
    mainEvent* failToUpload = new mainEvent(
        "尝试上传动物神经网络数据失败。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { -10, -10, -10, -10 }, // 智商-10，情商-10，编程能力-10，健康-10
        false // 不是选择事件
    );

    // 对动物神经数据化感到敬畏，放弃继续研究
    mainEvent* failEnd = new mainEvent(
        "对动物神经数据化感到敬畏，决定放弃继续研究。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { -10, -10, -10, 10 }, // 智商-10，情商-10，编程能力-10，健康+10
        false // 不是选择事件
    );

    // 获得批准后研究人脑数据上传
    mainEvent* UploadPermission = new mainEvent(
        "获得批准后，开始研究人脑数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 25, 15, 25, -15 }, // 智商+25，情商+15，编程能力+25，健康-15
        false // 不是选择事件
    );
    // 是否坚持研发
    mainEvent* network_insist = new mainEvent(
        "在神经网络技术线上是否坚持研发。",
        { 25, 110, 90, 80, 0 }, // 年龄25-30岁，智商大于110，情商大于90，编程能力大于80
        { 25, 15, 25, -20 }, // 坚持研发：智商+25，情商+15，编程能力+25，健康-20
        true // 是选择事件
    );

    // 继续坚持研究，直到死亡也没成功
    mainEvent* studyToDie = new mainEvent(
        "继续坚持研究，直到死亡也没成功。",
        { 60, 120, 100, 90, 0 }, // 年龄大于60岁，智商大于120，情商大于100，编程能力大于90
        { -30, -30, -30, -30 }, // 智商-30，情商-30，编程能力-30，健康-30
        false // 不是选择事件
    );

    // 你实现了脑机接口，将人类意识成功上传
    mainEvent* solveTheproblem = new mainEvent(
        "你实现了脑机接口，将人类意识成功上传。",
        { 60, 120, 100, 90, 0 }, // 年龄大于60岁，智商大于120，情商大于100，编程能力大于90
        { 50, 30, 50, -30 }, // 智商+50，情商+30，编程能力+50，健康-30
        false // 不是选择事件
    );
    /*
        读研线：填充关键事件
    */
    //没考上 
    postgradu->children.push_back(defeatOrenterprise);//能够进入创业线或者defeat线的选择事件，但是这个触发需要一定的创业属性达标。
    postgradu->children.push_back(defeat);//不能直接进入defeat线吧  
    //考上了： 
    //学习态度： 
    postgradu->children.push_back(study_attitude);
    study_attitude->children.push_back(defeatOrenterprise);//能够进入创业线或者defeat线的选择事件，但是这个触发需要一定的创业属性达标。
    study_attitude->children.push_back(defeat); //学习态度不好，进入失败线

    //是否加入实验室： 
    study_attitude->children.push_back(join_lab);
    join_lab->children.push_back(defeatOrenterprise);//能够进入创业线或者defeat线的选择事件，但是这个触发需要一定的创业属性达标。
    join_lab->children.push_back(defeat); //不加入则进入失败线 

    //加入实验室后选择哪条技术线路 ： 
    join_lab->children.push_back(tech_choose);
    tech_choose->children.push_back(network_tech); //选择神经网络技术线
    tech_choose->children.push_back(ai_tech); //选择人工智能线

    /*
        进入神经网络技术线：
    */
    network_tech->children.push_back(solveNetworkdatalize); //坚持，是否上传意识 
    solveNetworkdatalize->children.push_back(uploadAnimalsNetwork);
    uploadAnimalsNetwork->children.push_back(Uploaded);
    uploadAnimalsNetwork->children.push_back(failToUpload);
    failToUpload->children.push_back(failEnd);
    failEnd->children.push_back(defeatOrenterprise);
    failEnd->children.push_back(defeat);
    Uploaded->children.push_back(UploadPermission);
    network_insist->children.push_back(solveTheproblem);
    network_insist->children.push_back(studyToDie);

    // 失败线：定义事件变量
    mainEvent* deliver = new mainEvent(
        "成为一名外卖员，勉强维持生计",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -5, -5, -5, -10 }, // 智商-5，情商-5，编程能力-5，健康-10
        false // 不是选择事件
    );

    mainEvent* java_fry = new mainEvent(
        "转行做Java炒饭，勉强维持生计。",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -10, -10, -10, -15 }, // 智商-10，情商-10，编程能力-10，健康-15
        false // 不是选择事件
    );

    mainEvent* live = new mainEvent(
        "尝试开直播，勉强维持生计。",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -5, 5, -5, -10 }, // 智商-5，情商5，编程能力-5，健康-10
        false // 不是选择事件
    );

    mainEvent* die_early = new mainEvent(
        "因生活压力过大，早逝。",
        { 20, 80, 70, 50, 50 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50，健康小于50
        { -30, -30, -30, -30 }, // 智商-30，情商-30，编程能力-30，健康-30
        false // 不是选择事件
    );

    // 失败线：填充关键事件
    defeat->children.push_back(deliver);
    defeat->children.push_back(java_fry);
    defeat->children.push_back(live);
    defeat->children.push_back(die_early);

    // 获得股票
    mainEvent* getStock = new mainEvent(
        "获得公司股票，成为股东。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 10, 10, -5 }, // 智商+10，情商+10，编程能力+10，健康-5
        false // 不是选择事件
    );

    // 新概念
    mainEvent* newConception = new mainEvent(
        "提出一个创新概念，获得广泛关注。",
        { 25, 100, 90, 80, 0 }, // 年龄大于25岁，智商大于100，情商大于90，编程能力大于80
        { 20, 15, 20, -10 }, // 智商+20，情商+15，编程能力+20，健康-10
        false // 不是选择事件
    );

    // 成为明星
    mainEvent* beStar = new mainEvent(
        "因为某个项目或成就，成为行业明星。",
        { 25, 100, 90, 80, 0 }, // 年龄大于25岁，智商大于100，情商大于90，编程能力大于80
        { 15, 20, 15, -10 }, // 智商+15，情商+20，编程能力+15，健康-10
        false // 不是选择事件
    );

    deliver->children.push_back(getStock);
    deliver->children.push_back(die_early);
    java_fry->children.push_back(newConception);
    java_fry->children.push_back(die_early);
    live->children.push_back(beStar);
    live->children.push_back(die_early);

    // 创业线：定义事件变量
    mainEvent* finance = new mainEvent(
        "积累创业所需的资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* work = new mainEvent(
        "在大厂打工，积累创业资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 10, 15, -10 }, // 智商+10，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    mainEvent* invest = new mainEvent(
        "通过风险投资积累创业资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 15, 20, -15 }, // 智商+15，情商+15，编程能力+20，健康-15
        false // 不是选择事件
    );

    mainEvent* authorize = new mainEvent(
        "决定企业的所有权形式。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* cofounder = new mainEvent(
        "与他人合伙创办企业。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* single = new mainEvent(
        "个人独资创办企业。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 10, 15, -15 }, // 智商+15，情商+10，编程能力+15，健康-15
        false // 不是选择事件
    );

    mainEvent* found_team = new mainEvent(
        "创建创业团队。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* self_cultivate = new mainEvent(
        "自我培养，提升能力。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 10, 15, -10 }, // 智商+15，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    mainEvent* elite = new mainEvent(
        "挖角精英人才。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 20, 20, 20, -20 }, // 智商+20，情商+20，编程能力+20，健康-20
        false // 不是选择事件
    );

    mainEvent* direction = new mainEvent(
        "决定企业的发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* high_tech = new mainEvent(
        "选择高科技作为发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    mainEvent* daily_need = new mainEvent(
        "选择日常需求作为发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* future_plan = new mainEvent(
        "制定企业的未来规划。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* go_public = new mainEvent(
        "企业上市融资。",
        { 30, 100, 90, 80, 0 }, // 年龄大于30岁，智商大于100，情商大于90，编程能力大于80
        { 25, 20, 25, -20 }, // 智商+25，情商+20，编程能力+25，健康-20
        false // 不是选择事件
    );

    mainEvent* self_run = new mainEvent(
        "企业私有化运营。",
        { 30, 100, 90, 80, 0 }, // 年龄大于30岁，智商大于100，情商大于90，编程能力大于80
        { 20, 15, 20, -15 }, // 智商+20，情商+15，编程能力+20，健康-15
        false // 不是选择事件
    );
    /*
        创业线：填充关键事件
    */
    //先填入各阶段：本阶段的第一个子事件是下一个阶段 
    enterprise->children.push_back(finance);
    finance->children.push_back(authorize);
    authorize->children.push_back(found_team);
    found_team->children.push_back(direction);
    direction->children.push_back(future_plan);
    //填入各阶段的选择：
    finance->children.push_back(work);
    finance->children.push_back(invest);
    authorize->children.push_back(cofounder);
    authorize->children.push_back(single);
    found_team->children.push_back(self_cultivate);
    found_team->children.push_back(elite);
    direction->children.push_back(high_tech);
    direction->children.push_back(daily_need);
    future_plan->children.push_back(go_public);
    future_plan->children.push_back(self_run);

    /*
        退休线：根据flag值进入
    */
    return university;
}
void deleteEventTree(mainEvent* event) {
    if (event == nullptr) {
        return;
    }

    // 递归删除所有子事件
    for (mainEvent* child : event->children) {
        deleteEventTree(child);
    }

    // 删除当前事件
    delete event;
}
bool is_mainEvent(mainEvent*& root, person p) {//判断子节点是否有符合条件的
    if (root == nullptr) {
        return true;
    }
	if (!root->is_choose) {
		for (auto child : root->children) {
			if (child->isTrigger(p, root)) {
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
// 
// 

//void gameLoop(person& p, mainEvent*& event) {
//    srand(static_cast<unsigned int>(time(nullptr)));
//    int randId = rand() % 20;
//    initRandomEvents();
//    if (p.Age < 18) {
//        if (p.Age == 17) {
//            score = getScore(p.IQ);
//
//            //有没有大学相关的判断功能，比如我去了哪个大学,属性需要发生什么更改。
//            //University_lor();
//        }
//        else {
//            if (YoungEvents[p.Age].choices.size() > 1) {
//                //是不是还要加一些数值传入什么
//                Bonus delta = YoungEvents[p.Age].choices[0].improvebonus;//这行代码的数值传入尚未解决。就那个0
//                p.IQ += delta.IQBonus;
//                p.EQ += delta.EQBonus;
//                p.ProgramingSkill += delta.ProgramingSkillBonus;
//                p.Health += delta.HealthBonus;
//            }
//            else if (YoungEvents[p.Age].choices.size() == 1) {
//                //直接显示事件
//                YoungEvents[p.Age].showYoungAgeChoices();
//
//
//            }
//        }
//    }
//    else if (is_mainEvent(event, p)) {
//        //这里是要判断主事件的发生情况，主事件的发生也包含了那些支线树。
//        string arr = event->description;//故事
//        p.IQ += event->eventBonus.IQBonus;
//        p.EQ += event->eventBonus.EQBonus;
//        p.Health += event->eventBonus.HealthBonus;
//        p.ProgramingSkill += event->eventBonus.ProgramingSkillBonus;
//
//    }
//}

void TalentBonus(person& p, vector<int>& talentId)
{
    for (vector<int>::iterator it1 = talentId.begin(); it1 != talentId.end(); it1++) {
        for (vector<talent>::iterator it2 =talents.begin(); it2 != talents.end(); it2++) {
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
		adjustposibility += float(abs(p.Health - 50) * 0.5);
	}
	if (p.Age > 0)
	{
		adjustposibility =float( p.Age * 0.25);
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
/*
	负责人：飞
	功能：
		根据传入的智力获取一个高考所能获得的分数范围
*/
pair<int, int> getScoreRange(int iq)
{
	for (int i = 0; i < examScores.size(); i++) {
		const auto& score = examScores[i];
		if (iq >= score.IQ)
			return make_pair(examScores[i].min_score,examScores[i].max_score);
	}
	return make_pair(0, 0);
}
// 调用 getScoreRange 函数来获取一个分数范围再 从返回的分数范围内利用随机数返回最后的实际的高考分数
int getScore(int iq) {
	int score;
	std::pair<int, int> scoreRange = getScoreRange(iq);
	/*std::srand(std::time(0));*/
	score = scoreRange.first + (std::rand() % (scoreRange.second - scoreRange.first + 1));
	return score;
}

