#include<functions.h>


bool mainEvent::isTrigger(person p);
{
    // 检查属性是否满足最低要求
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