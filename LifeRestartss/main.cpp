#include "functions.h"

int main()
{
    person player;
    mainEvent* eventTree = buildEventTree(); //��ʼ���¼���
    gameLoop(player, eventTree); //������Ϸ��ѭ��
    return 0;
}