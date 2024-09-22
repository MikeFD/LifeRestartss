<<<<<<< HEAD
#pragma once
#include <iostream>

using namespace std;


/*
### 研究线

#### 成功读上研究生
- 权重比：智商（60%）、情商（20%）、体质（10%）、编程能力（10%）
- 解释：读研究生主要依赖于学术能力和智商，情商和编程能力也有一定影响，体质影响较小。

#### 研究脑机接口，并将动物神经网络数据上传，上传成功
- 权重比：智商（50%）、编程能力（30%）、情商（10%）、体质（10%）
- 解释：脑机接口研究需要高智商和编程能力，情商和体质影响较小。

#### 研究脑际接口的时候，难以将人类情感数据化，坚持研发，且成功
- 权重比：智商（40%）、情商（30%）、编程能力（20%）、体质（10%）
- 解释：情感数据化研究需要智商、情商和编程能力的综合应用，体质影响较小。

### 工作线

#### 找到工作
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：找到工作需要情商和智商，编程能力和体质也有一定影响。

#### 被裁员
- 权重比：情商（50%）、智商（20%）、编程能力（20%）、体质（10%）
- 解释：被裁员主要与情商和团队合作能力有关，智商和编程能力也有一定影响，体质影响较小。

#### 升职
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：升职需要情商和智商，编程能力和体质也有一定影响。

### 创业线

### 触发创业
- 权重比： 情商（35%）、智商（30%）、编程能力（25%）、体质（10%）
- 解释： 触发创业需要高情商来建立团队和处理人际关系，高智商用于制定战略和解决问题，编程能力用于应对技术挑战，体质用于应对高强度的工作压力。

通过这样的权重比设定，可以更好地模拟触发创业所需的各方面能力，从而增加游戏的真实性和可玩性。

#### 确定企业所有权，是个人独资的话，创业的成功
- 权重比：情商（30%）、智商（30%）、编程能力（20%）、体质（20%）
- 解释：个人独资创业需要情商、智商、编程能力和体质的综合应用。

#### 是合伙创办的话，创业的成功
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：合伙创业需要情商和智商，编程能力和体质也有一定影响。

#### 在创业中团队创建
- 权重比：情商（50%）、智商（20%）、编程能力（20%）、体质（10%）
- 解释：团队创建主要依赖于情商和团队合作能力，智商和编程能力也有一定影响，体质影响较小。

#### 自我培养人才，创业的成功
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：自我培养人才需要情商和智商，编程能力和体质也有一定影响。

#### 直接挖业界精英墙角后，创业的成功
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：挖业界精英需要情商和智商，编程能力和体质也有一定影响。

#### 确定创业方向
- 权重比：智商（40%）、情商（30%）、编程能力（20%）、体质（10%）
- 解释：确定创业方向需要智商和情商，编程能力和体质也有一定影响。

#### 是高科技领域中，创业成功
- 权重比：智商（50%）、编程能力（30%）、情商（10%）、体质（10%）
- 解释：高科技领域创业需要高智商和编程能力，情商和体质影响较小。

#### 日常需求领域（做市场上的互联网项目），创业的成功
- 权重比：情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- 解释：日常需求领域创业需要情商和智商，编程能力和体质也有一定影响。

### 失败线

#### 你因为英年早逝死亡了
- **权重比：** 体质（80%）、情商（10%）、智商（5%）、编程能力（5%）
- **解释：** 英年早逝主要与体质有关，其他属性影响较小。

#### 你草草的结束了自己的一生
- **权重比：** 体质（60%）、情商（20%）、智商（10%）、编程能力（10%）
- **解释：** 草草结束一生可能与体质和情商有关，智商和编程能力影响较小。

#### 你因干活勤练得到了外卖公司的股份
- **权重比：** 体质（50%）、情商（30%）、智商（10%）、编程能力（10%）
- **解释：** 得到股份主要依赖于体质和情商，智商和编程能力也有一定影响。

#### 你成为网红
- **权重比：** 情商（50%）、智商（20%）、编程能力（20%）、体质（10%）
- **解释：** 成为网红需要高情商来吸引观众和互动，智商和编程能力用于内容制作和技术支持，体质影响较小。

#### 快乐过完一生
- **权重比：** 情商（40%）、智商（20%）、编程能力（20%）、体质（20%）
- **解释：** 快乐过完一生需要情商和智商，编程能力和体质也有一定影响。

#### 你炒出了炒饭新概念，赚到了不少钱
- **权重比：** 智商（40%）、情商（30%）、编程能力（20%）、体质（10%）
- **解释：** 炒出新概念需要高智商和情商，编程能力用于可能的线上推广，体质影响较小。

#### 耗光了钱草草结束了一生
- **权重比：** 情商（40%）、智商（30%）、编程能力（20%）、体质（10%）
- **解释：** 耗光钱草草结束一生可能与情商和智商有关，编程能力和体质影响较小。
*/

=======
>>>>>>> origin/main
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

<<<<<<< HEAD
//---------------------------锟斤拷锟斤拷锟斤拷锟?-----------------------------

/*
    锟斤拷示锟阶段ｏ拷锟斤拷同锟阶段会触锟斤拷锟斤拷同锟斤拷锟铰硷拷  锟斤拷锟矫诧拷同锟铰硷拷锟斤拷锟斤拷 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷媒锟斤拷锟斤拷锟斤拷锟?
    0锟斤拷示锟阶讹拷时锟斤拷 1锟斤拷示锟斤拷学时锟斤拷
    2锟斤拷示锟叫撅拷锟斤拷时锟斤拷 3锟斤拷示锟斤拷锟斤拷时锟斤拷
    4锟斤拷示锟斤拷业时锟斤拷 5锟斤拷示锟斤拷锟斤拷锟斤拷
    6锟斤拷示锟斤拷业锟斤拷 7锟斤拷示锟斤拷锟斤拷锟斤拷
    8锟斤拷示锟斤拷锟斤拷 9锟斤拷示锟斤拷锟斤拷
=======
//---------------------------鏁版嵁璁捐------------------------------

/*
    琛ㄧず闃舵锛氫笉鍚岄樁娈典細瑙﹀彂涓嶅悓鐨勪簨浠�  璋冪敤涓嶅悓浜嬩欢鐨勬爲 鑻ユ槸姝讳骸鎴栬�呮案鐢熷垯璋冪敤缁撴潫鍑芥暟
    0琛ㄧず骞煎効鏃舵湡 1琛ㄧず澶у鏃舵湡
    2琛ㄧず鐮旂┒鐢熸椂鏈� 3琛ㄧず宸ヤ綔鏃舵湡
    4琛ㄧず鏃犱笟鏃舵湡 5琛ㄧず鍜搁奔鏈�
    6琛ㄧず鍒涗笟鏈� 7琛ㄧず閫�浼戞湡
    8琛ㄧず姝讳骸 9琛ㄧず姘哥敓
>>>>>>> origin/main
*/
int flag;


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟斤拷锟?
    锟斤拷锟戒、锟斤拷锟教★拷锟斤拷锟教★拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
*/
typedef struct
{
    int Age;//锟斤拷锟斤拷
    int IQ;//锟斤拷锟斤拷
    int EQ;//锟斤拷锟斤拷
    int ProgramingSkill;//锟斤拷锟斤拷锟斤拷锟?
    int Health;//锟斤拷锟斤拷
=======
    鐜╁璁剧疆
    骞撮緞銆佹櫤鍟嗐�佹儏鍟嗐�佺紪绋嬭兘鍔涖�佸仴搴�
*/
typedef struct
{
    int Age;//骞撮緞
    int IQ;//鏅哄晢
    int EQ;//鎯呭晢
    int ProgramingSkill;//缂栫▼鑳藉姏
    int Health;//鍋ュ悍
>>>>>>> origin/main
}person;


/*
    灞炴�у彈褰卞搷 鍔�/鍑�
*/
typedef struct
{
    int IQBonus;
    int EQBonus;
    int ProgramingSkillBonus;
    int HealthBonus;
}Bonus;


/*
    瑙﹀彂浜嬩欢鐨勫睘鎬ч檺鍒�  濡倇"IQ": 100, "CodingLevel": 80}
*/
typedef struct
{
    int IQ;
    int EQ;
    int ProgramingSkill;
    int Health;
}limit;


/*
    澶╄祴璁剧疆
*/
typedef struct {
    int talentID; //澶╄祴鍗D
    string description; //澶╄祴鎻忚堪
    Bonus talentBonus; //澶╄祴瀵瑰睘鎬х殑褰卞搷
}talent;


/*
<<<<<<< HEAD
    锟铰硷拷锟斤拷母锟斤拷锟?  锟斤拷锟斤拷锟斤拷锟斤拷锟叫憋拷示 锟斤拷锟节碉拷锟绞撅拷锟角帮拷录锟? 锟接节碉拷锟绞撅拷锟揭伙拷锟斤拷锟斤拷锟斤拷录锟斤拷锟窖★拷锟?
            锟斤拷没锟斤拷锟接节碉拷锟斤拷锟斤拷锟斤拷锟揭伙拷锟斤拷锥锟?
            锟斤拷只锟斤拷一锟斤拷锟接节碉拷锟斤拷直锟接凤拷锟绞革拷锟接节碉拷
            锟斤拷锟叫讹拷锟斤拷咏诘锟斤拷锟轿★拷锟斤拷锟斤拷录锟斤拷锟斤拷锟斤拷选锟斤拷 选锟斤拷锟斤拷俜锟斤拷矢媒诘锟?
            锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟絣imit 锟斤拷锟斤拷锟斤拷锟铰硷拷锟斤拷锟斤拷 锟斤拷么锟节点保锟街诧拷锟斤拷 锟铰硷拷锟斤拷展停锟斤拷 锟斤拷锟界：锟斤拷锟戒不锟斤拷25锟疥不锟结触锟斤拷锟襟厂诧拷员锟斤拷锟铰硷拷
    锟斤拷员锟斤拷锟斤拷锟斤拷锟铰硷拷锟斤拷锟斤拷 description   锟斤拷锟斤拷锟斤拷锟斤拷 limit锟斤拷锟斤拷锟斤拷锟铰硷拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟揭拷锟?
    锟铰硷拷锟斤拷锟接节碉拷 children 锟斤拷示
=======
    浜嬩欢绫荤殑鐖剁被   鐢ㄦ爲鏉ヨ繘琛岃〃绀� 鏍硅妭鐐硅〃绀哄綋鍓嶄簨浠�  瀛愯妭鐐硅〃绀轰笅涓�涓彂鐢熶簨浠剁殑閫夋嫨
            鑻ユ病鏈夊瓙鑺傜偣鍒欒繘鍏ヤ笅涓�涓樁娈�
            鑻ュ彧鏈変竴涓瓙鑺傜偣鍒欑洿鎺ヨ闂瀛愯妭鐐�
            鑻ユ湁澶氫釜瀛愯妭鐐逛綔涓洪�夋嫨鎬т簨浠朵緵鐜╁閫夋嫨 閫夋嫨鍚庡啀璁块棶璇ヨ妭鐐�
            鐗规畩鎯呭喌锛氳嫢灞炴�ч檺鍒秎imit 闄愬埗浜嗕簨浠跺彂鐢� 閭ｄ箞鑺傜偣淇濇寔涓嶅彉 浜嬩欢鍙戝睍鍋滄粸 渚嬪锛氬勾榫勪笉鍒�25宀佷笉浼氳Е鍙戝ぇ鍘傝鍛樼殑浜嬩欢
    鎴愬憳鍙橀噺锛氫簨浠舵弿杩� description   灞炴�ч檺鍒� limit锛堥檺鍒朵簨浠跺彂鐢熺殑鏈�浣庡睘鎬ц姹�)
    浜嬩欢鐨勫瓙鑺傜偣 children 琛ㄧず
>>>>>>> origin/main
*/
class mainEvent
{
public:
<<<<<<< HEAD
    string description;           // 锟铰硷拷锟斤拷锟斤拷
    vector<mainEvent*> children;  // 锟斤拷锟铰硷拷锟节碉拷
    Bonus eventBonus; //锟斤拷示锟斤拷锟铰硷拷锟斤拷锟斤拷锟斤拷锟斤拷缘锟接帮拷锟?
    int triggerAge;  //锟斤拷锟斤拷枪潭锟斤拷录锟斤拷锟斤拷锟斤拷锟轿拷锟接︼拷锟斤拷锟斤拷洌拷锟斤拷锟斤拷录锟斤拷锟斤拷锟斤拷锟轿?1
=======
    string description;           // 浜嬩欢鎻忚堪
    vector<mainEvent*> children;  // 瀛愪簨浠惰妭鐐�
    Bonus eventBonus; //琛ㄧず璇ヤ簨浠跺鐜╁灞炴�х殑褰卞搷
    int triggerAge;  //濡傛灉鏄浐瀹氫簨浠跺垯璁剧疆涓哄搴旂殑骞撮緞锛屼氦浜掍簨浠跺垯璁剧疆涓�-1
>>>>>>> origin/main

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


//琛ㄧず澶у闃舵浜嬩欢 缁ф壙
class UniversityEvent :public mainEvent {};

//琛ㄧず鐮旂┒鐢熼樁娈典簨浠� 缁ф壙
class postgraduateEvent :public mainEvent {};


//琛ㄧず宸ヤ綔闃舵浜嬩欢
class jobEvent :public mainEvent {};


//琛ㄧず鍒涗笟闃舵浜嬩欢
class EnterpriseEvent :public mainEvent {};


//琛ㄧず澶辫触闃舵浜嬩欢
class defeatEvent : public mainEvent {};


//琛ㄧず閫�浼戦樁娈典簨浠�
class retireEvent : public mainEvent {};


/*
<<<<<<< HEAD
    锟斤拷示锟斤拷锟斤拷录锟?
    锟斤拷员锟斤拷锟斤拷锟斤拷锟铰硷拷锟侥憋拷示 锟铰硷拷锟斤拷效锟斤拷 锟斤拷锟斤拷锟侥革拷锟绞碉拷
=======
    琛ㄧず闅忔満浜嬩欢
    鎴愬憳鍙橀噺锛氫簨浠剁殑琛ㄧず 浜嬩欢鐨勬晥鏋� 鍙戠敓鐨勬鐜囩瓑
>>>>>>> origin/main
*/

struct rndEvent
{
<<<<<<< HEAD
    string description;  // 锟铰硷拷锟斤拷锟斤拷锟斤拷锟斤拷锟界“突然锟矫帮拷症锟斤拷锟斤拷锟斤拷锟斤拷通锟铰故★拷
    Bonus effect;  // 锟铰硷拷效锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷俳锟斤拷锟街碉拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
    float probability;   // 锟铰硷拷锟斤拷锟斤拷锟侥革拷锟绞ｏ拷0锟斤拷1之锟斤拷
    //------------------------锟斤拷锟矫猴拷锟斤拷-------------------------------
};

/*
    锟斤拷示锟斤拷锟斤拷录锟斤拷募锟斤拷锟?
=======
    string description;  // 浜嬩欢鎻忚堪锛屼緥濡傗�滅獊鐒跺緱鐧岀棁鈥濄�佲�滀氦閫氫簨鏁呪��
    Bonus effect;  // 浜嬩欢鏁堟灉锛屼緥濡傚噺灏戝仴搴峰�笺�佸噺灏戝鍛界瓑
    float probability;   // 浜嬩欢鍙戠敓鐨勬鐜囷紝0鍒�1涔嬮棿
    //------------------------鍐呯疆鍑芥暟-------------------------------
};

/*
    琛ㄧず闅忔満浜嬩欢鐨勯泦鍚�
>>>>>>> origin/main
*/
vector<rndEvent> rndEvents;


/*
<<<<<<< HEAD
    锟斤拷示锟窖撅拷锟斤拷锟斤拷锟铰硷拷锟侥硷拷锟斤拷 每锟轿筹拷始锟斤拷时锟斤拷锟斤拷锟秸癸拷值锟斤拷锟较拷锟斤拷锟斤拷锟?
=======
    琛ㄧず宸茬粡鍙戠敓浜嬩欢鐨勯泦鍚� 姣忔鍒濆鍖栨椂鍊欓亶鍘嗗睍鐜板埌娑堟伅鐣岄潰涓�
>>>>>>> origin/main
*/
vector<string> happenEvent;


/*
  缁撳眬鐩稿叧璁剧疆
*/

<<<<<<< HEAD
// 锟斤拷锟斤拷锟斤拷锟?
typedef struct
{
    string description; // 锟斤拷值锟斤拷锟较革拷锟斤拷锟?
    int score; // 锟斤拷锟斤拷锟斤拷郑锟紸锟斤拷B锟斤拷C锟斤拷
    bool isHidden; // 锟角凤拷为锟斤拷锟截斤拷锟?锟斤拷锟斤拷锟斤拷锟揭恍╋拷实锟街拷锟侥憋拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷亟锟斤拷展锟街碉拷页锟芥不同
} Ending;

// 锟斤拷执锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷愿锟斤拷锟斤拷锟斤拷曰锟斤拷录锟斤拷锟斤拷瓒?
typedef struct
{
    limit endlimit;//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
    vector<mainEvent> preevent;//锟斤拷示锟斤拷锟斤拷锟斤拷值锟斤拷锟斤拷锟揭拷锟斤拷锟斤拷锟角帮拷锟斤拷录锟?
} EndingCondition;

// 锟斤拷锟斤拷卸锟斤拷氪ワ拷锟?
typedef struct
{
    Ending ending; // 锟斤拷锟斤拷慕锟斤拷锟斤拷锟斤拷
    EndingCondition condition; // 锟斤拷锟斤拷锟矫斤拷值锟斤拷锟斤拷锟?
} EndingEvent;

//---------------------------锟斤拷锟斤拷锟斤拷锟?-----------------------------
=======
// 鎻忚堪缁撳眬
typedef struct
{
    string description; // 缁撳眬鐨勮缁嗘弿杩�
    int score; // 缁撳眬璇勫垎锛孉銆丅銆丆绛�
    bool isHidden; // 鏄惁涓洪殣钘忕粨灞� 鍙互璁捐涓�浜涘僵铔嬩箣绫荤殑姣斿濡傛灉鏄殣钘忕粨灞�灞曠幇鐨勯〉闈笉鍚�
} Ending;

// 缁撳眬瑙﹀彂鏉′欢锛屽彲浠ユ牴鎹睘鎬ф垨浜嬩欢鏉ヨ瀹�
typedef struct
{
    limit endlimit;//缁撳眬灞炴�ф潯浠�
    vector<mainEvent> preevent;//琛ㄧず瑙﹀彂缁撳眬鐨勬墍闇�瑕佸彂鐢熺殑鍓嶇疆浜嬩欢
} EndingCondition;

// 缁撳眬鍒ゆ柇涓庤Е鍙�
typedef struct
{
    Ending ending; // 鍏蜂綋鐨勭粨灞�鎻忚堪
    EndingCondition condition; // 瑙﹀彂璇ョ粨灞�鐨勬潯浠�
} EndingEvent;

//---------------------------鏁版嵁璁捐------------------------------
>>>>>>> origin/main



//---------------------------service-------------------------------

/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷始锟斤拷锟斤拷锟斤拷录锟斤拷锟?
        锟斤拷始锟斤拷锟斤拷戏锟斤拷锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鍒濆鍖栭殢鏈轰簨浠惰〃
        鍒濆鍖栨父鎴忔暟鎹�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main

*/
void init();


/*
    璐熻矗浜猴細
    鍔熻兘锛�
        澶╄祴瀵瑰睘鎬х殑褰卞搷
            鏍规嵁鐜╁鎵�閫夋嫨鐨勫ぉ璧嬪崱瀵瑰睘鎬у�艰繘琛屼慨鏀�
    鍙傛暟锛氱帺瀹跺璞★紝鐢眛alentChooseView鍑芥暟浼犲叆鐨勫ぉ璧嬪崱ID鍙峰鍣�
    杩斿洖鍊硷細void

*/
void TalentBonus(person, vector<int>);

/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷始锟斤拷锟斤拷锟斤拷录锟斤拷锟?
            锟斤拷randomEvents锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟铰硷拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鍒濆鍖栭殢鏈轰簨浠惰〃
            寰�randomEvents瀹瑰櫒涓坊鍔犱簨浠�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main

*/
void initRandomEvents();


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷锟铰硷拷锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷录锟?
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鏋勫缓浜嬩欢鏍�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細杩斿洖浜虹敓璧风偣浜嬩欢
>>>>>>> origin/main

*/
mainEvent* buildEventTree();


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟铰硷拷循锟斤拷锟斤拷锟斤拷
            锟斤拷锟教讹拷锟铰硷拷>锟斤拷锟斤拷锟铰硷拷>锟斤拷锟斤拷录锟斤拷锟剿筹拷锟饺凤拷锟矫匡拷锟街伙拷锟斤拷锟揭伙拷锟斤拷录锟?
                while(age<100){
                    锟斤拷锟斤拷欠锟斤拷泄潭锟斤拷录锟?
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        浜嬩欢寰幆鍑芥暟
            鎸夊浐瀹氫簨浠�>浜や簰浜嬩欢>闅忔満浜嬩欢鐨勯『搴忥紝纭繚姣忓勾鍙Е鍙戜竴涓簨浠�
                while(age<100){
                    妫�鏌ユ槸鍚︽湁鍥哄畾浜嬩欢
>>>>>>> origin/main

                    娌℃湁锛屽垯妫�鏌ヤ氦浜掍簨浠�

<<<<<<< HEAD
                    没锟叫固讹拷锟铰硷拷锟斤拷锟斤拷锟斤拷锟铰硷拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷录锟?


                    锟铰硷拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
=======
                    娌℃湁鍥哄畾浜嬩欢銆佷氦浜掍簨浠讹紝鍒欐鏌ラ殢鏈轰簨浠�


                    浜嬩欢鍙戠敓鍚庣帺瀹跺勾榫勫鍔�
>>>>>>> origin/main

                    妫�鏌ョ帺瀹剁殑鍋ュ悍鍊硷紝杈惧埌姝讳骸鏉′欢鏃惰烦鍑哄惊鐜�
                }
            娓告垙缁撴潫endView()
    鍙傛暟锛氱帺瀹跺璞layer锛屽綋鍓嶄簨浠惰妭鐐筩urrentEvent
    杩斿洖鍊硷細void

*/
void gameLoop(person, mainEvent*);


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟絚heckRandomEvents()锟斤拷锟斤拷锟叫憋拷锟斤拷锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷锟斤拷锟缴碉拷锟斤拷锟斤拷锟?
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        闅忔満鏁扮敓鎴愬櫒锛屽湪checkRandomEvents()鍑芥暟涓璋冪敤
    鍙傛暟锛歷oid
    杩斿洖鍊硷細鐢熸垚鐨勯殢鏈烘暟
>>>>>>> origin/main

*/
float generateRandom();

/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷generateRandom()锟斤拷锟斤拷锟斤拷锟缴碉拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟角否触凤拷锟斤拷锟斤拷录锟?
    锟斤拷锟斤拷锟斤拷锟斤拷叶锟斤拷锟?
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鏍规嵁generateRandom()鍑芥暟鐢熸垚鐨勯殢鏈烘暟锛屾鏌ユ槸鍚﹁Е鍙戦殢鏈轰簨浠�
    鍙傛暟锛氱帺瀹跺璞�
    杩斿洖鍊硷細void
>>>>>>> origin/main

*/
void checkRandomEvents(person);


/*
    璐熻矗浜猴細
    鍔熻兘锛�
        澶勭悊浜や簰浜嬩欢
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void

*/
void handleInteractiveEvent();


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷锟铰硷拷影锟斤拷锟睫革拷锟斤拷锟斤拷锟斤拷锟街?
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鏍规嵁浜嬩欢褰卞搷淇敼鐜╁灞炴�у��
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main

*/
void EventBonus();


//---------------------------service-------------------------------



//-----------------------------view--------------------------------

 /*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷始锟斤拷锟斤拷锟剿碉拷锟斤拷锟斤拷
            展示选锟斤拷选锟筋：
                锟斤拷录锟剿伙拷锟斤拷锟斤拷锟斤拷锟铰硷拷锟斤拷锟?
                注锟斤拷锟剿伙拷锟斤拷锟斤拷锟斤拷注锟斤拷锟斤拷锟?
                锟斤拷戏锟斤拷锟矫ｏ拷锟斤拷锟斤拷锟斤拷戏锟斤拷锟矫斤拷锟斤拷 //锟斤拷展
                锟剿筹拷锟斤拷戏锟斤拷锟剿筹拷锟斤拷锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鍒濆鍖栦富鑿滃崟鐣岄潰
            灞曠ず閫夋嫨閫夐」锛�
                鐧诲綍璐︽埛锛氳繘鍏ョ櫥褰曠晫闈�
                娉ㄥ唽璐︽埛锛氳繘鍏ユ敞鍐岀晫闈�
                娓告垙璁剧疆锛氳繘鍏ユ父鎴忚缃晫闈� //鎵╁睍
                閫�鍑烘父鎴忥細閫�鍑虹▼搴�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main
*/
void menuView();


/*
    璐熻矗浜猴細
    鍔熻兘锛氭彁渚涚敤鎴疯緭鍏ヨ处鎴峰拰瀵嗙爜
        鏈変咯涓寜閽�
        涓�涓槸鐧诲綍鎸夐挳  杩涘叆娓告垙寮�濮嬬晫闈�
        涓�涓槸鍙栨秷鎸夐挳 鐢ㄤ簬杩斿洖涓昏彍鍗曪紝杩涘叆涓昏彍鍗曢〉闈�
    鍙傛暟 void
    杩斿洖鍊� void
*/
void loginView();

/*
    璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬鐢ㄦ埛娉ㄥ唽璐﹀彿
        鏈変咯涓寜閽竴涓槸娉ㄥ唽 涓�涓槸杩斿洖 浜岃�呭潎杩斿洖鑷崇櫥褰曢〉闈�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
*/
void registerView();

/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷锟斤拷锟斤拷钮
        一锟斤拷锟角匡拷始锟斤拷戏锟侥帮拷钮锟斤拷锟斤拷榭拷锟斤拷锟?
        一锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷钮锟斤拷锟斤拷锟斤拷锟侥斤拷锟斤拷
        一锟斤拷锟角成就帮拷钮锟斤拷锟斤拷删徒锟斤拷锟?
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鏈変笁涓寜閽�
        涓�涓槸寮�濮嬫父鎴忕殑鎸夐挳杩涘叆鎶藉崱鐣岄潰
        涓�涓槸浜虹敓灞ュ巻鎸夐挳杩涘叆鐢熸动鐣岄潰
        涓�涓槸鎴愬氨鎸夐挳杩涘叆鎴愬氨鐣岄潰
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main
*/
void gameBeignView();


/*

<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
      展锟斤拷锟届赋选锟斤拷
            锟斤拷锟矫伙拷选取锟届赋锟斤拷锟斤拷选取锟斤拷锟届赋锟斤拷锟斤拷3锟斤拷锟斤拷锟斤拷锟窖★拷锟?
            锟斤拷锟斤拷TalentBonus()锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟届赋锟睫革拷锟斤拷锟斤拷值
      锟斤拷一锟斤拷选锟斤拷钮 选锟斤拷之锟斤拷锟斤拷锟斤拷锟斤拷锟较凤拷锟斤拷锟?
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
      灞曠幇澶╄祴閫夐」
            璁╃敤鎴烽�夊彇澶╄祴锛岃嫢閫夊彇鐨勫ぉ璧嬪皯浜�3涓垯缁х画閫夋嫨
            璋冪敤TalentBonus()鍑芥暟锛屾牴鎹ぉ璧嬩慨鏀瑰睘鎬у��
      鏈変竴涓�夋嫨鎸夐挳 閫夋嫨涔嬪悗鍒欒繘鍏ユ父鎴忕晫闈�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main
*/
void talentChooseView();


/*
<<<<<<< HEAD
     锟斤拷锟斤拷锟剿ｏ拷
     锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷init()锟斤拷始锟斤拷锟斤拷戏锟斤拷锟斤拷
        锟斤拷锟斤拷锟斤拷示锟斤拷色锟斤拷锟斤拷 锟斤拷一些锟斤拷锟斤拷锟斤拷息
        锟斤拷示一锟斤拷锟侥憋拷锟斤拷锟斤拷锟斤拷展示锟窖撅拷锟斤拷锟斤拷锟斤拷锟铰硷拷 锟斤拷一些锟斤拷然锟铰硷拷
        锟斤拷锟斤拷一锟斤拷锟斤拷钮锟斤拷锟矫伙拷锟斤拷锟斤拷锟揭伙拷锟?
     锟斤拷锟斤拷锟斤拷void
     锟斤拷锟斤拷值锟斤拷 void
=======
     璐熻矗浜猴細
     鍔熻兘锛�
        璋冪敤init()鍒濆鍖栨父鎴忔暟鎹�
        鐢ㄤ簬鏄剧ず瑙掕壊灞炴�� 鍜屼竴浜涘熀鏈俊鎭�
        鏄剧ず涓�涓枃鏈鐢ㄤ簬灞曠ず宸茬粡鍙戠敓鐨勪簨浠� 鍜屼竴浜涘繀鐒朵簨浠�
        杩樻湁涓�涓寜閽緵鐢ㄦ埛鐐瑰嚮涓嬩竴骞�
     鍙傛暟锛歷oid
     杩斿洖鍊硷細 void
>>>>>>> origin/main
*/
void gameView();


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷锟斤拷gameView锟侥伙拷锟斤拷锟斤拷展锟斤拷一锟斤拷小锟侥斤拷锟斤拷 锟斤拷锟斤拷展示
        1.锟斤拷锟斤拷录锟斤拷锟斤拷录锟斤拷锟斤拷锟斤拷锟斤拷锟?
        2.选锟斤拷锟铰硷拷锟斤拷锟铰硷拷锟斤拷锟斤拷 锟斤拷锟斤拷选锟斤拷选锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬鍦╣ameView鐨勫熀纭�涓婂睍鐜颁竴涓皬鐨勭晫闈� 鐢ㄤ簬灞曠ず
        1.闅忔満浜嬩欢鐨勪簨浠跺彂鐢熸弿杩�
        2.閫夋嫨浜嬩欢鐨勪簨浠舵弿杩� 鍔犱笂閫夋嫨閫夐」
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main
*/
void popView();


/*
    璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬灞曠幇璁剧疆鐣岄潰  鏁鏈熷緟鈥︹��
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
*/
void settingView();


/*
<<<<<<< HEAD
      锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷展锟斤拷锟斤拷锟斤拷锟斤拷锟较凤拷锟斤拷乜锟斤拷拇锟斤拷锟?锟皆硷拷锟斤拷玫锟斤拷锟竭凤拷锟斤拷
        锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷钮锟斤拷锟节凤拷锟斤拷锟斤拷戏锟斤拷始锟斤拷锟斤拷
    锟斤拷锟斤拷锟斤拷void
    锟斤拷锟斤拷值锟斤拷void
=======
      璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬灞曠幇鐜╁鍦ㄦ父鎴忎腑閲嶅紑鐨勬鏁� 浠ュ強鑾峰緱鐨勬渶楂樺垎鏁�
        閲岄潰鏈変竴涓寜閽敤浜庤繑鍥炴父鎴忓紑濮嬬晫闈�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
>>>>>>> origin/main
*/
void careerView();


/*
    璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬灞曠幇鐜╁鎵�鑾峰緱鎴愬氨
        閲岄潰鏈変竴涓繑鍥炴寜閽敤浜庤繑鍥炴父鎴忓紑濮嬬晫闈�
    鍙傛暟锛歷oid
    杩斿洖鍊硷細void
*/
void achievementView();


/*
<<<<<<< HEAD
    锟斤拷锟斤拷锟剿ｏ拷
    锟斤拷锟杰ｏ拷
        锟斤拷锟斤拷展示锟斤拷锟斤拷锟较凤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥斤拷锟?
        锟斤拷锟皆凤拷锟斤拷锟斤拷锟剿碉拷 锟斤拷锟斤拷锟斤拷锟铰匡拷始锟斤拷戏锟斤拷锟斤拷锟斤拷GameView锟斤拷
=======
    璐熻矗浜猴細
    鍔熻兘锛�
        鐢ㄤ簬灞曠ず鐜╁娓告垙缁撴潫鍚庝骇鐢熺殑缁撳眬
        鍙互杩斿洖涓昏彍鍗� 鍙互閲嶆柊寮�濮嬫父鎴忥紙杩涘叆GameView锛�
>>>>>>> origin/main
*/
void endView();


//-----------------------------view--------------------------------



<<<<<<< HEAD
=======
int main()
{
    person player;
    mainEvent* eventTree = buildEventTree(); //鍒濆鍖栦簨浠舵爲
    gameLoop(player, eventTree); //杩涘叆娓告垙涓诲惊鐜�
    return 0;
}
>>>>>>> origin/main
