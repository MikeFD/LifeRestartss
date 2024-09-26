#include "functions.h"
#include "Easytext.h"


int flag;
int score;

wstring key_text;//用于将故事内容放入gameView文本框中
wstring choose_text;//用于选择中的题目
vector<wstring> btnChoices;//用于存储按钮内容


vector<randEvent> ranEvents;
vector<wstring> happenEvent;
vector<YoungAgeChoices> YoungEvents;

vector<examSocre> examScores = { {HighAttribute, 500, 700}, {MidAttribute, 300, 500 }, {LowAttribute, 100, 300} };
vector<talent> talents;//存储可选天赋
vector<int> talentChoices;//选择的3个天赋id

mainEvent* defeat;

void YoungAgeChoices::showYoungAgeChoices()
{
	char ans[100];
	for (auto x : choices) {
		sprintf_s(ans, "%s \n ", x.description.c_str());
	}
	printf("%s", ans);
}
YoungAgeChoices::YoungAgeChoices(int age) {
    this->age = age;
}

void init(person& p)
{

	//初始化属性

	p.Age = 0;
	p.EQ = 0;
	p.Health = 100; 
	p.IQ = 0;
	p.ProgramingSkill = 0;
}

void initRandomEvents() /*初始化随机事件表*/
{
    ranEvents.clear(); /*清空容器*/

    // 添加随机事件及其效果
    ranEvents.emplace_back(randEvent{
        L"正当你心情有点儿小郁闷时，突然一道彩虹挂在天边，宛如画中仙境，心情瞬间晴朗起来！",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在公园溜达一圈，长椅上躺着一张钞票，你感觉真是天上掉馅饼",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在咖啡馆喝咖啡时，与久别的挚友不期而遇，聊起当年趣事，犹在眼前",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你遇到一位迷路的外国友人，给他指路，他十分感谢，自己心里也满满的成就感。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"街头转角，一只软萌的流浪猫蹭蹭你的腿，眼神里全是渴望，你因为爱心收留了它！",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"超市大促销，你抢到心仪的打折商品，省下的银子可以再买包零食庆祝一番！",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.06f, // 6% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在广场上，看见一位街头艺人的精彩表演，你也跟着high了起来。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"下班路上你抬头一看，发现晚霞满天，美得让人窒息，让奔波的灵魂得到了片刻安宁。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"小区门口新开的餐馆，你尝鲜之后发现竟是意外的美味，从此多了个心头好！",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你和家人一起过节，餐桌上摆满了熟悉的食物，谈笑风生之间，那份亲情和归属感油然而生。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在一堆堆书山中挖宝，终于找到那本期待已久的书，那种兴奋感简直爆棚！",
        Bonus{5, 0, 0, 0}, // 增加5点智商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在商场逛街时，背景音乐刚好是你的最爱，让你平淡的生活增添了几许浪漫气息，整个人都被治愈了。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你过生日时意外地收到朋友邮寄的神秘礼物，那份惊喜和感动直接拉满！",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你清晨公园散步时，耳边响起鸟儿们的欢快歌声，感觉整个世界都在欢迎新的一天。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.1f, // 10% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"帮助老爷爷老奶奶过马路，他们的笑容比太阳还要灿烂，感觉自己做了件很了不起的事情。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"在巷弄里，你与你的朋友把一面墙绘成了五彩斑斓的艺术品，你们十分开心。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在散步时突然被一阵热烈的鼓掌吸引，你一看是有位街头表演者正在献艺，那股激情和活力感染了你。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你扶老人安全过马路，他们的微笑是对善良行为最好的回报。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你购买的彩票竟然中奖了，虽然金额不大，但那份惊喜如同中了大奖一般。",
        Bonus{0, 0, 0, 0}, // 无属性影响
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.05f, // 5% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在旅游途中，误打误撞进入一个风景如画的小镇，留下了一生中最美的回忆。",
        Bonus{0, 10, 0, 0}, // 增加10点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.08f, // 8% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你学习烹饪，成功做出一道美味佳肴。",
        Bonus{0, 5, 0, 0}, // 增加5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.07f, // 7% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你在美术馆偶遇一幅触动心灵的作品，那份艺术与情感的交汇让你感慨万千。",
        Bonus{5, 5, 0, 0}, // 增加5点智商和5点情商
        limit{0, 0, 0, 0, 0}, // 无属性限制
        0.09f, // 9% 的概率
        false, // 属性不影响概率
        false // 事件未发生
        });

    ranEvents.emplace_back(randEvent{
        L"你读到一篇励志文章，其中的观点和感悟如同及时雨般滋养了你干涸的心灵。",
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
        L"进入大学，开始新的学习生活。",
        { 18, 80, 0, 0, 0 }, // 年龄18-22岁，智商大于80
        { 5, 5, 5, -5 }, // 智商+5，情商+5，编程能力+5，健康-5
        false // 不是选择事件
    );

    // 工作线
    mainEvent* job = new mainEvent(
        L"找到一份工作，开始职业生涯。",
        { 22, 90, 0, 70, 0 }, // 年龄大于22岁，智商大于90，编程能力大于70
        { 10, 10, 15, -10 }, // 智商+10，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    // 读研线
    mainEvent* postgradu = new mainEvent(
        L"决定继续深造，攻读研究生学位。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 15, 10, 10, -15 }, // 智商+15，情商+10，编程能力+10，健康-15
        true // 是选择事件
    );

    // 创业线
    mainEvent* enterprise = new mainEvent(
        L"决定创业，开始自己的事业。",
        { 25, 110, 90, 80, 0 }, // 年龄大于25岁，智商大于110，情商大于90，编程能力大于80
        { 20, 20, 25, -20 }, // 智商+20，情商+20，编程能力+25，健康-20
        true // 是选择事件
    );

    mainEvent* defeatOrenterprise = new mainEvent(
        L"创业线或失败线选择事件。",
        { 0, 0, 0, 0, 0 }, // 无特定限制
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    ); //创业线有可能被触发。 

    // 失败线
    mainEvent* defeat = new mainEvent(
        L"遭遇重大失败，生活陷入低谷。",
        { 0, 0, 0, 0, 0 }, // 无特定限制
        { -30, -30, -30, -30 }, // 智商-30，情商-30，编程能力-30，健康-30
        false // 不是选择事件
    );

    // 退休线
    mainEvent* retire = new mainEvent(
        L"退休，享受晚年生活。",
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
        L"被裁员。",
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
        L"决定读研的态度，是积极还是消极。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 10, 5, 10, -5 }, // 积极态度：智商+10，情商+5，编程能力+10，健康-5
        true // 是选择事件
    );
    // 是否加入实验室
    mainEvent* join_lab = new mainEvent(
        L"决定是否加入实验室进行科研。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 15, 10, 15, -10 }, // 加入实验室：智商+15，情商+10，编程能力+15，健康-10
        true // 是选择事件
    );

    // 读研选择技术
    mainEvent* tech_choose = new mainEvent(
        L"选择读研的技术方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    // 神经网络技术线
    mainEvent* network_tech = new mainEvent(
        L"选择神经网络技术作为研究方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    // 人工智能技术线
    mainEvent* ai_tech = new mainEvent(
        L"选择人工智能技术作为研究方向。",
        { 22, 100, 80, 0, 0 }, // 年龄22-25岁，智商大于100，情商大于80
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    // 破解人类神经网络数据化
    mainEvent* solveNetworkdatalize = new mainEvent(
        L"成功破解人类神经网络数据化技术。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 30, 20, 30, -20 }, // 智商+30，情商+20，编程能力+30，健康-20
        false // 不是选择事件
    );

    // 研究脑际接口，看看能否将动物神经网络数据上传
    mainEvent* uploadAnimalsNetwork = new mainEvent(
        L"研究脑际接口，尝试将动物神经网络数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 25, 15, 25, -15 }, // 智商+25，情商+15，编程能力+25，健康-15
        false // 不是选择事件
    );

    // 上传成功
    mainEvent* Uploaded = new mainEvent(
        L"成功将动物神经网络数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 30, 20, 30, -20 }, // 智商+30，情商+20，编程能力+30，健康-20
        false // 不是选择事件
    );

    // 上传失败
    mainEvent* failToUpload = new mainEvent(
        L"尝试上传动物神经网络数据失败。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { -10, -10, -10, -10 }, // 智商-10，情商-10，编程能力-10，健康-10
        false // 不是选择事件
    );

    // 对动物神经数据化感到敬畏，放弃继续研究
    mainEvent* failEnd = new mainEvent(
        L"对动物神经数据化感到敬畏，决定放弃继续研究。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { -10, -10, -10, 10 }, // 智商-10，情商-10，编程能力-10，健康+10
        false // 不是选择事件
    );

    // 获得批准后研究人脑数据上传
    mainEvent* UploadPermission = new mainEvent(
        L"获得批准后，开始研究人脑数据上传。",
        { 30, 120, 100, 90, 0 }, // 年龄30-40岁，智商大于120，情商大于100，编程能力大于90
        { 25, 15, 25, -15 }, // 智商+25，情商+15，编程能力+25，健康-15
        false // 不是选择事件
    );
    // 是否坚持研发
    mainEvent* network_insist = new mainEvent(
        L"在神经网络技术线上是否坚持研发。",
        { 25, 110, 90, 80, 0 }, // 年龄25-30岁，智商大于110，情商大于90，编程能力大于80
        { 25, 15, 25, -20 }, // 坚持研发：智商+25，情商+15，编程能力+25，健康-20
        true // 是选择事件
    );

    // 继续坚持研究，直到死亡也没成功
    mainEvent* studyToDie = new mainEvent(
        L"继续坚持研究，直到死亡也没成功。",
        { 60, 120, 100, 90, 0 }, // 年龄大于60岁，智商大于120，情商大于100，编程能力大于90
        { -30, -30, -30, -30 }, // 智商-30，情商-30，编程能力-30，健康-30
        false // 不是选择事件
    );

    // 你实现了脑机接口，将人类意识成功上传
    mainEvent* solveTheproblem = new mainEvent(
        L"你实现了脑机接口，将人类意识成功上传。",
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
        L"成为一名外卖员，勉强维持生计",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -5, -5, -5, -10 }, // 智商-5，情商-5，编程能力-5，健康-10
        false // 不是选择事件
    );

    mainEvent* java_fry = new mainEvent(
        L"转行做Java炒饭，勉强维持生计。",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -10, -10, -10, -15 }, // 智商-10，情商-10，编程能力-10，健康-15
        false // 不是选择事件
    );

    mainEvent* live = new mainEvent(
        L"尝试开直播，勉强维持生计。",
        { 20, 80, 70, 50, 0 }, // 年龄大于20岁，智商小于80，情商小于70，编程能力小于50
        { -5, 5, -5, -10 }, // 智商-5，情商5，编程能力-5，健康-10
        false // 不是选择事件
    );

    mainEvent* die_early = new mainEvent(
        L"因生活压力过大，早逝。",
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
        L"获得公司股票，成为股东。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 10, 10, -5 }, // 智商+10，情商+10，编程能力+10，健康-5
        false // 不是选择事件
    );

    // 新概念
    mainEvent* newConception = new mainEvent(
        L"提出一个创新概念，获得广泛关注。",
        { 25, 100, 90, 80, 0 }, // 年龄大于25岁，智商大于100，情商大于90，编程能力大于80
        { 20, 15, 20, -10 }, // 智商+20，情商+15，编程能力+20，健康-10
        false // 不是选择事件
    );

    // 成为明星
    mainEvent* beStar = new mainEvent(
        L"因为某个项目或成就，成为行业明星。",
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
        L"积累创业所需的资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* work = new mainEvent(
        L"在大厂打工，积累创业资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 10, 15, -10 }, // 智商+10，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    mainEvent* invest = new mainEvent(
        L"通过风险投资积累创业资金。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 15, 20, -15 }, // 智商+15，情商+15，编程能力+20，健康-15
        false // 不是选择事件
    );

    mainEvent* authorize = new mainEvent(
        L"决定企业的所有权形式。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* cofounder = new mainEvent(
        L"与他人合伙创办企业。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* single = new mainEvent(
        L"个人独资创办企业。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 10, 15, -15 }, // 智商+15，情商+10，编程能力+15，健康-15
        false // 不是选择事件
    );

    mainEvent* found_team = new mainEvent(
        L"创建创业团队。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* self_cultivate = new mainEvent(
        L"自我培养，提升能力。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 15, 10, 15, -10 }, // 智商+15，情商+10，编程能力+15，健康-10
        false // 不是选择事件
    );

    mainEvent* elite = new mainEvent(
        L"挖角精英人才。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 20, 20, 20, -20 }, // 智商+20，情商+20，编程能力+20，健康-20
        false // 不是选择事件
    );

    mainEvent* direction = new mainEvent(
        L"决定企业的发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* high_tech = new mainEvent(
        L"选择高科技作为发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 20, 10, 20, -15 }, // 智商+20，情商+10，编程能力+20，健康-15
        false // 不是选择事件
    );

    mainEvent* daily_need = new mainEvent(
        L"选择日常需求作为发展方向。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 10, 15, 10, -10 }, // 智商+10，情商+15，编程能力+10，健康-10
        false // 不是选择事件
    );

    mainEvent* future_plan = new mainEvent(
        L"制定企业的未来规划。",
        { 25, 90, 80, 70, 0 }, // 年龄大于25岁，智商大于90，情商大于80，编程能力大于70
        { 0, 0, 0, 0 }, // 无直接影响
        true // 是选择事件
    );

    mainEvent* go_public = new mainEvent(
        L"企业上市融资。",
        { 30, 100, 90, 80, 0 }, // 年龄大于30岁，智商大于100，情商大于90，编程能力大于80
        { 25, 20, 25, -20 }, // 智商+25，情商+20，编程能力+25，健康-20
        false // 不是选择事件
    );

    mainEvent* self_run = new mainEvent(
        L"企业私有化运营。",
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
    if (root == nullptr) {//当节点为nullptr的时候，说明故事结束了
        return true;
    }
	if (!root->is_choose) {//判断这个事件树的子节点到底是选的还是属性触发的，这里明显就不是选的
		for (auto child : root->children) {//遍历事件
			if (child->isTrigger(p, root)) {//看看能不能触发
				root = child;
				return true;
			}
		}
	}
    else if(root->is_choose && root != defeat){//由于失败线是三个节点选择，跟popView()不相符，所以单独领出来处理
        //选择并返回事件id
        int chooseId = popView();//返回选择的事件。
        root = root->children[chooseId];
        return true;
    }
    else if (root->is_choose && root == defeat) {//逻辑与上文类似，只是单独处理defeat;
        int chooseId = popView3();
        root = root->children[chooseId];
        return true;
    }
	return false;
	
}

//GT写的
// 
// 
void youngEvent() {
    YoungAgeChoices birth(1);
    YoungAgeChoices two(2);
    YoungAgeChoices three(3);
    YoungAgeChoices four(4);
    YoungAgeChoices five(5);
    YoungAgeChoices six(6);
    YoungAgeChoices seven(7);
    YoungAgeChoices eight(8);
    YoungAgeChoices nine(9);
    YoungAgeChoices ten(10);
    YoungAgeChoices eleven(11);
    YoungAgeChoices twelve(12);
    YoungAgeChoices thirteen(13);
    YoungAgeChoices fourteen(14);
    YoungAgeChoices fifteen(15);
    YoungAgeChoices sixteen(16);
    YoungAgeChoices seventeen(17);

    srand(static_cast<unsigned int>(time(0)));
    int rnd_sex = rand();
    if (rnd_sex % 2 == 0)
        birth.choices.push_back({
            L"你出生了是个女孩",
            {3, 0, 0, 3},
            L""
            });
    else
        birth.choices.push_back({
            L"你出生了是个男孩",
            {3, 0, 0, 3},
            L""
            });

    two.choices.push_back({
        L"你两岁了",
        {2, 1, 0, 1},
        L"你学会了走路，学会叫爸爸妈妈"
        });

    // 智力 情商 编程能力 体力
    three.choices.push_back({
        L"你三岁了",
        {3, 0, 0, -1},
        L"你选择玩益智类游戏"
        });
    three.choices.push_back({
        L"你三岁了",
        {-1, 0, 0, 3},
        L"你选择跑跑跳跳"
        });

    four.choices.push_back({
        L"你四岁了，在家无聊",
        {2, 0, 0, 0},
        L"你选择学着玩拼图"
        });
    four.choices.push_back({
        L"你四岁了，在家无聊",
        {1, 1, 0, 0},
        L"你选择学着看小人书"
        });

    five.choices.push_back({
        L"你五岁了",
        {3, -1, 0, -1},
        L"你选择做数学题"
        });
    five.choices.push_back({
        L"你五岁了",
        {-2, 1, 0, 2},
        L"你选择和朋友玩"
        });

    six.choices.push_back({
        L"你六岁了，你数学考试考了100分",
        {2, 0, 1, 0},
        L""
        });

    seven.choices.push_back({
        L"你七岁了，父母给你买了电脑",
        {1, 0, 1, 0},
        L"你选择玩游戏"
        });
    seven.choices.push_back({
        L"你七岁了，父母给你买了电脑",
        {1, 1, 0, 0},
        L"你选择看动画片"
        });

    eight.choices.push_back({
        L"你八岁了",
        {1, 2, 0, 0},
        L"你选择学习钢琴"
        });
    eight.choices.push_back({
        L"你八岁了",
        {3, 0, 0, 0},
        L"你选择学习下棋"
        });

    nine.choices.push_back({
        L"你九岁了，学校组织了训练营，要参加吗",
        {0, 1, 0, 2},
        L"你选择参加"
        });
    nine.choices.push_back({
        L"你九岁了，学校组织了训练营，要参加吗",
        {2, 0, 2, -1},
        L"你选择不参加，在家玩电脑"
        });

    ten.choices.push_back({
        L"你十岁了",
        {3, -1, 0, 0},
        L"你选择参加棋类比赛"
        });
    ten.choices.push_back({
        L"你十岁了",
        {1, 2, 0, 0},
        L"你选择阅读大量经典小说"
        });

    eleven.choices.push_back({
        L"你十一岁了",
        {-1, 1, 0, 2},
        L"你去朋友家玩了"
        });

    twelve.choices.push_back({
        L"你十二岁了，上初中了，要竞选班长吗",
        {1, 3, 0, 2},
        L"你选择参加竞选"
        });
    twelve.choices.push_back({
        L"你十二岁了，上初中了，要竞选班长吗",
        {5, 0, 0, 0},
        L"你选择不参加竞选，专心学习"
        });

    thirteen.choices.push_back({
        L"你十三岁了",
        {0, 2, 0, 1},
        L"你选择积极参加社交活动"
        });
    thirteen.choices.push_back({
        L"你十三岁了",
        {4, 0, 0, -1},
        L"你选择参加补课班"
        });

    fourteen.choices.push_back({
        L"你十四岁了，通过游戏了解到编程",
        {2, 0, 2, 0},
        L"你选择学习编程"
        });
    fourteen.choices.push_back({
        L"你十四岁了，通过游戏了解到编程",
        {-1, 0, -1, -2},
        L"你选择继续玩游戏"
        });

    fifteen.choices.push_back({
        L"你十五岁了，即将中考体测，要准备吗",
        {-1, 0, 0, 4},
        L"你选择努力训练"
        });
    fifteen.choices.push_back({
        L"你十五岁了，即将中考体测，要准备吗",
        {4, 0, 0, -2},
        L"你选择不管体测，专心学习"
        });

    sixteen.choices.push_back({
        L"你十六岁了，英语成绩是班里垫底，要努力学习吗",
        {2, 0, 0, 0},
        L"你下定决心努力学习"
        });
    sixteen.choices.push_back({
        L"你十六岁了，英语成绩是班里垫底，要努力学习吗",
        {0, 0, 2, 0},
        L"你选择不学英语，改bug去了"
        });

    seventeen.choices.push_back({
        L"你十七岁了，要高考了",
        {},
        L""
        });

    YoungEvents.push_back(birth);
    YoungEvents.push_back(two);
    YoungEvents.push_back(three);
    YoungEvents.push_back(four);
    YoungEvents.push_back(five);
    YoungEvents.push_back(six);
    YoungEvents.push_back(seven);
    YoungEvents.push_back(eight);
    YoungEvents.push_back(nine);
    YoungEvents.push_back(ten);
    YoungEvents.push_back(eleven);
    YoungEvents.push_back(twelve);
    YoungEvents.push_back(thirteen);
    YoungEvents.push_back(fourteen);
    YoungEvents.push_back(fifteen);
    YoungEvents.push_back(sixteen);
    YoungEvents.push_back(seventeen);
}
void University_lor(person& p) {
    // 根据高考分数决定大学，并调整属性
    if (score >= 500) {
        // 进入顶尖大学
        p.IQ += 10;
        p.EQ += 5;
        p.ProgramingSkill += 15;
        p.Health -= 5;
        key_text = L"你以优异的成绩进入了顶尖大学,你的成绩是" + to_wstring(score) + L"分";
    }
    else if (score >= 300) {
        // 进入普通大学
        p.IQ += 5;
        p.EQ += 3;
        p.ProgramingSkill += 10;
        p.Health -= 3;
        key_text = L"你成绩平平，进入了普通大学,你的成绩是" + to_wstring(score) + L"分";
    }
    else {
        // 未能进入大学
        p.IQ += 2;
        p.EQ += 1;
        p.ProgramingSkill += 5;
        p.Health -= 1;
        key_text = L"很遗憾，你未能进入大学,你的成绩是" + to_wstring(score) + L"分";
    }
}

void handleYoungAgeChoices(person& p, int age) {
    int real_age = age - 1;
    choose_text = YoungEvents[real_age].choices[0].description;//choose_text是wstring类，用于显示出选择题时的题目
    if (YoungEvents[real_age].choices.size() > 1) {//判断是否是选择题，当子节点超过1时，就是选择题
        // 选择事件
        // 假设玩家选择了第一个选项
        int chooseId = popView();//我在popView里进行了返回事件的处理
        Bonus delta = YoungEvents[age].choices[chooseId].improvebonus;
        p.IQ += delta.IQBonus;
        p.EQ += delta.EQBonus;
        p.ProgramingSkill += delta.ProgramingSkillBonus;
        p.Health += delta.HealthBonus;
        key_text = YoungEvents[real_age].choices[chooseId].outcome;//key_text也是wstring类，全局变量，用于显示故事文本
    }
    else if (YoungEvents[real_age].choices.size() == 1) {
        // 直接显示事件
        key_text = YoungEvents[real_age].choices[0].outcome;
        Bonus delta = YoungEvents[real_age].choices[0].improvebonus;
        p.IQ += delta.IQBonus;
        p.EQ += delta.EQBonus;
        p.ProgramingSkill += delta.ProgramingSkillBonus;
        p.Health += delta.HealthBonus;
    }
}

void handleMainEvent(person& p, mainEvent*& event) {
    key_text = event->description; // key_text用于显示故事文本
    p.IQ += event->eventBonus.IQBonus;
    p.EQ += event->eventBonus.EQBonus;
    p.Health += event->eventBonus.HealthBonus;
    p.ProgramingSkill += event->eventBonus.ProgramingSkillBonus;
}

void handleRandomEvent(person& p) {
    int randId = rand() % ranEvents.size();
    if (ranEvents[randId].triggerEvent(p, ranEvents[randId])) {
        p.Health += ranEvents[randId].effect.HealthBonus;
        p.EQ += ranEvents[randId].effect.EQBonus;
        p.IQ += ranEvents[randId].effect.IQBonus;
        p.ProgramingSkill += ranEvents[randId].effect.ProgramingSkillBonus;
    }
}

void gameLoop(person& p, mainEvent*& event) {
    srand(static_cast<unsigned int>(time(nullptr)));
    initRandomEvents();

    if (p.Age < 18) {
        if (p.Age == 17) {//17岁是高考的年纪
            score = getScore(p.IQ);//获得分数
            University_lor(p);//取决于自己上什么大学，从而影响属性的变化。
        }
        else {
            handleYoungAgeChoices(p, p.Age);//不是17岁，一切以剧本为主
        }
    }
    else if (is_mainEvent(event, p)) {//判断主事件是否可以发生，主事件有选择事件以及属性触发事件，相关类有所提及
        if (event == nullptr) {
            return;//当事件达到结局，直接退出gameLoop;
        }
        handleMainEvent(p, event);//处理主事件逻辑
    }
    else {
        handleRandomEvent(p);//处理随机事件逻辑
    }
    p.Age++;//加年龄
}

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


mainEvent::mainEvent(wstring description, limit event, Bonus eventBonus, bool choose) {
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

