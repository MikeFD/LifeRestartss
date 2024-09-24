#include "functions.h"


int flag;
int score;


vector<randEvent> ranEvents;
vector<string> happenEvent;

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
					YoungEvents[p.Age].showYoungAgeChoices();
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
		{

		}
	}	
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
	// 在主程序或初始化函数中调用一次
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

void  randEvent::checkRandEvents(person &p,randEvent &event)
{
	if (triggerEvent(p,event))
	{
		p.Health = event.effect.HealthBonus;
		p.EQ = event.effect.EQBonus;
		p.IQ = event.effect.IQBonus;
		p.ProgramingSkill = event.effect.ProgramingSkillBonus;
	}
}


