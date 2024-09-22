
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//---------------------------�������------------------------------

/*
    ��ʾ�׶Σ���ͬ�׶λᴥ����ͬ���¼�  ���ò�ͬ�¼����� ��������������������ý�������
    0��ʾ�׶�ʱ�� 1��ʾ��ѧʱ��
    2��ʾ�о���ʱ�� 3��ʾ����ʱ��
    4��ʾ��ҵʱ�� 5��ʾ������
    6��ʾ��ҵ�� 7��ʾ������
    8��ʾ���� 9��ʾ����
*/
int flag;


/*
    �������
    ���䡢���̡����̡��������������
*/
typedef struct
{
    int Age;//����
    int IQ;//����
    int EQ;//����
    int ProgramingSkill;//�������
    int Health;//����
}person;


/*
    ������Ӱ�� ��/��
*/
typedef struct
{
    int IQBonus;
    int EQBonus;
    int ProgramingSkillBonus;
    int HealthBonus;
}Bonus;


/*
    �����¼�����������  ��{"IQ": 100, "CodingLevel": 80}
*/
typedef struct
{
    int IQ;
    int EQ;
    int ProgramingSkill;
    int Health;
}limit;


/*
    �츳����
*/
typedef struct {
    int talentID; //�츳��ID
    string description; //�츳����
    Bonus talentBonus; //�츳�����Ե�Ӱ��
}talent;


/*
    �¼���ĸ���   ���������б�ʾ ���ڵ��ʾ��ǰ�¼�  �ӽڵ��ʾ��һ�������¼���ѡ��
            ��û���ӽڵ��������һ���׶�
            ��ֻ��һ���ӽڵ���ֱ�ӷ��ʸ��ӽڵ�
            ���ж���ӽڵ���Ϊѡ�����¼������ѡ�� ѡ����ٷ��ʸýڵ�
            �������������������limit �������¼����� ��ô�ڵ㱣�ֲ��� �¼���չͣ�� ���磺���䲻��25�겻�ᴥ���󳧲�Ա���¼�
    ��Ա�������¼����� description   �������� limit�������¼��������������Ҫ��)
    �¼����ӽڵ� children ��ʾ
*/
class mainEvent
{
public:
    string description;           // �¼�����
    vector<mainEvent*> children;  // ���¼��ڵ�
    Bonus eventBonus; //��ʾ���¼���������Ե�Ӱ��
    int triggerAge;  //����ǹ̶��¼�������Ϊ��Ӧ�����䣬�����¼�������Ϊ-1

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


//��ʾ��ѧ�׶��¼� �̳�
class UniversityEvent :public mainEvent {};

//��ʾ�о����׶��¼� �̳�
class postgraduateEvent :public mainEvent {};


//��ʾ�����׶��¼�
class jobEvent :public mainEvent {};


//��ʾ��ҵ�׶��¼�
class EnterpriseEvent :public mainEvent {};


//��ʾʧ�ܽ׶��¼�
class defeatEvent : public mainEvent {};


//��ʾ���ݽ׶��¼�
class retireEvent : public mainEvent {};


/*
    ��ʾ����¼�
    ��Ա�������¼��ı�ʾ �¼���Ч�� �����ĸ��ʵ�
*/

struct rndEvent
{
    string description;  // �¼����������硰ͻȻ�ð�֢��������ͨ�¹ʡ�
    Bonus effect;  // �¼�Ч����������ٽ���ֵ������������
    float probability;   // �¼������ĸ��ʣ�0��1֮��
    //------------------------���ú���-------------------------------
};

/*
    ��ʾ����¼��ļ���
*/
vector<rndEvent> rndEvents;


/*
    ��ʾ�Ѿ������¼��ļ��� ÿ�γ�ʼ��ʱ�����չ�ֵ���Ϣ������
*/
vector<string> happenEvent;


/*
  ����������
*/

// �������
typedef struct
{
    string description; // ��ֵ���ϸ����
    int score; // ������֣�A��B��C��
    bool isHidden; // �Ƿ�Ϊ���ؽ�� �������һЩ�ʵ�֮��ı�����������ؽ��չ�ֵ�ҳ�治ͬ
} Ending;

// ��ִ������������Ը������Ի��¼����趨
typedef struct
{
    limit endlimit;//�����������
    vector<mainEvent> preevent;//��ʾ������ֵ�����Ҫ������ǰ���¼�
} EndingCondition;

// ����ж��봥��
typedef struct
{
    Ending ending; // ����Ľ������
    EndingCondition condition; // �����ý�ֵ�����
} EndingEvent;

//---------------------------�������------------------------------



//---------------------------service-------------------------------

/*
    �����ˣ�
    ���ܣ�
        ��ʼ������¼���
        ��ʼ����Ϸ����
    ������void
    ����ֵ��void

*/
void init();


/*
    �����ˣ�
    ���ܣ�
        �츳�����Ե�Ӱ��
            ���������ѡ����츳��������ֵ�����޸�
    ��������Ҷ�����talentChooseView����������츳��ID������
    ����ֵ��void

*/
void TalentBonus(person, vector<int>);

/*
    �����ˣ�
    ���ܣ�
        ��ʼ������¼���
            ��randomEvents�����������¼�
    ������void
    ����ֵ��void

*/
void initRandomEvents();


/*
    �����ˣ�
    ���ܣ�
        �����¼���
    ������void
    ����ֵ��������������¼�

*/
mainEvent* buildEventTree();


/*
    �����ˣ�
    ���ܣ�
        �¼�ѭ������
            ���̶��¼�>�����¼�>����¼���˳��ȷ��ÿ��ֻ����һ���¼�
                while(age<100){
                    ����Ƿ��й̶��¼�

                    û�У����齻���¼�

                    û�й̶��¼��������¼�����������¼�


                    �¼������������������

                    �����ҵĽ���ֵ���ﵽ��������ʱ����ѭ��
                }
            ��Ϸ����endView()
    ��������Ҷ���player����ǰ�¼��ڵ�currentEvent
    ����ֵ��void

*/
void gameLoop(person, mainEvent*);


/*
    �����ˣ�
    ���ܣ�
        ���������������checkRandomEvents()�����б�����
    ������void
    ����ֵ�����ɵ������

*/
float generateRandom();

/*
    �����ˣ�
    ���ܣ�
        ����generateRandom()�������ɵ������������Ƿ񴥷�����¼�
    ��������Ҷ���
    ����ֵ��void

*/
void checkRandomEvents(person);


/*
    �����ˣ�
    ���ܣ�
        ���������¼�
    ������void
    ����ֵ��void

*/
void handleInteractiveEvent();


/*
    �����ˣ�
    ���ܣ�
        �����¼�Ӱ���޸��������ֵ
    ������void
    ����ֵ��void

*/
void EventBonus();


//---------------------------service-------------------------------



//-----------------------------view--------------------------------

 /*
    �����ˣ�
    ���ܣ�
        ��ʼ�����˵�����
            չʾѡ��ѡ�
                ��¼�˻��������¼����
                ע���˻�������ע�����
                ��Ϸ���ã�������Ϸ���ý��� //��չ
                �˳���Ϸ���˳�����
    ������void
    ����ֵ��void
*/
void menuView();


/*
    �����ˣ�
    ���ܣ��ṩ�û������˻�������
        ��������ť
        һ���ǵ�¼��ť  ������Ϸ��ʼ����
        һ����ȡ����ť ���ڷ������˵����������˵�ҳ��
    ���� void
    ����ֵ void
*/
void loginView();

/*
    �����ˣ�
    ���ܣ�
        �����û�ע���˺�
        ��������ťһ����ע�� һ���Ƿ��� ���߾���������¼ҳ��
    ������void
    ����ֵ��void
*/
void registerView();

/*
    �����ˣ�
    ���ܣ�
        ��������ť
        һ���ǿ�ʼ��Ϸ�İ�ť����鿨����
        һ��������������ť�������Ľ���
        һ���ǳɾͰ�ť����ɾͽ���
    ������void
    ����ֵ��void
*/
void gameBeignView();


/*

    �����ˣ�
    ���ܣ�
      չ���츳ѡ��
            ���û�ѡȡ�츳����ѡȡ���츳����3�������ѡ��
            ����TalentBonus()�����������츳�޸�����ֵ
      ��һ��ѡ��ť ѡ��֮���������Ϸ����
    ������void
    ����ֵ��void
*/
void talentChooseView();


/*
     �����ˣ�
     ���ܣ�
        ����init()��ʼ����Ϸ����
        ������ʾ��ɫ���� ��һЩ������Ϣ
        ��ʾһ���ı�������չʾ�Ѿ��������¼� ��һЩ��Ȼ�¼�
        ����һ����ť���û������һ��
     ������void
     ����ֵ�� void
*/
void gameView();


/*
    �����ˣ�
    ���ܣ�
        ������gameView�Ļ�����չ��һ��С�Ľ��� ����չʾ
        1.����¼����¼���������
        2.ѡ���¼����¼����� ����ѡ��ѡ��
    ������void
    ����ֵ��void
*/
void popView();


/*
    �����ˣ�
    ���ܣ�
        ����չ�����ý���  �����ڴ�����
    ������void
    ����ֵ��void
*/
void settingView();


/*
      �����ˣ�
    ���ܣ�
        ����չ���������Ϸ���ؿ��Ĵ��� �Լ���õ���߷���
        ������һ����ť���ڷ�����Ϸ��ʼ����
    ������void
    ����ֵ��void
*/
void careerView();


/*
    �����ˣ�
    ���ܣ�
        ����չ���������óɾ�
        ������һ�����ذ�ť���ڷ�����Ϸ��ʼ����
    ������void
    ����ֵ��void
*/
void achievementView();


/*
    �����ˣ�
    ���ܣ�
        ����չʾ�����Ϸ����������Ľ��
        ���Է������˵� �������¿�ʼ��Ϸ������GameView��
*/
void endView();


//-----------------------------view--------------------------------



int main()
{
    person player;
    mainEvent* eventTree = buildEventTree(); //��ʼ���¼���
    gameLoop(player, eventTree); //������Ϸ��ѭ��
    return 0;
}
