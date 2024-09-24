//图形化区
#include "functions.h"
#include "Easytext.h"
ExMessage msg = { 0 };
void menuView()
{
	cleardevice();
	IMAGE main;
	loadimage(&main, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);

	while (true)
	{
		BeginBatchDraw();
		putimage(0, 0, &main);
		setbkcolor(BLACK);

		setlinecolor(BLACK);            // 设置画线颜色
		setbkcolor(WHITE);                // 设置背景颜色
		setfillcolor(RGB(248, 193, 90));            // 设置填充颜色

		settextstyle(30, 0, "字魂无外润黑体(商用需授权)");
		settextcolor(BLACK);
		fillrectangle(340, 200, 700, 240);
		outtextxy(470, 205, "开始游戏");
		//fillrectangle(340, 270, 700, 310);
		//outtextxy(470, 275, "结算界面");
		//fillrectangle(340, 340, 700, 380);
		//outtextxy(470, 345, " 排行榜 ");
		//fillrectangle(340, 410, 700, 450);
		//outtextxy(470, 415, "更换皮肤");
		fillrectangle(340, 480, 700, 520);
		outtextxy(470, 485, "游戏说明");
		fillrectangle(340, 550, 700, 590);
		outtextxy(470, 555, "退出游戏");
		EndBatchDraw();
		//
		if (peekmessage(&msg, EX_MOUSE) && msg.message == WM_LBUTTONDOWN)
		{
			if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 200 && msg.y <= 240)
			{
				gameBeignView();//开始游戏
				cout << "点击鼠标右键1" << endl;
			}
			//
			//			if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 270 && msg.y <= 310)
			//			{
			//
			//				//Endthingview();//游戏设置界面
			//				//cout << "点击鼠标右键2" << endl;
			//			}
			//
			//			//if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 340 && msg.y <= 380)
			//			//{
			//			//	
			//			//	mciSendString("setaudio musicMenu volume to 0", NULL, 0, NULL);
			//			//	rankView();//排行榜界面
			//			//	cout << "点击鼠标右键3" << endl;
			//			//}
			//
			//			//if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 410 && msg.y <= 450)
			//			//{
			//			//
			//			//	mciSendString("setaudio musicMenu volume to 0", NULL, 0, NULL);
			//			//	skinView();//更换皮肤
			//			//	cout << "点击鼠标右键4" << endl;
			//			//}
			//
						if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 480 && msg.y <= 520)
						{
			
			
							//explainView();//游戏说明
							cout << "点击鼠标右键5" << endl;
						}
			//
						if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 550 && msg.y <= 590)
						{
			
							exit(0);// 退出游戏
							cout << "点击鼠标右键6" << endl;
						}
		}
	}
}
void popView()
{
	EasyButton 	btnthing;
	EasyButton btntext;
	EasyButton btnreturn;
	cout << 3 << endl;
	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btntext.Create(400, 220, 560, 280, "选择事件", NULL);
		btnthing.Create(220, 300, 760, 570, "", NULL);
		btnreturn.Create(180, 650, 800, 690, "结束此阶段", thingView);
		EndBatchDraw();
		while (true)
		{
			msg = getmessage(EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (btnreturn.Check(msg.x, msg.y)) {

					btnreturn.OnMessage();
				}
			}
		}
	}
}
void thingView()
{
	EasyButton 	btnthing;
	EasyButton btnnext;
	EasyButton btnreturn;
	cout << 2;

	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		//btn.Create(400,220,560,280,"选择事件",NULL);
		btnthing.Create(220, 130, 760, 570, "", NULL);
		btnreturn.Create(180, 650, 800, 690, "结束此阶段", gameView);
		btnnext.Create(420, 590, 540, 630, "开始事件", popView);



		EndBatchDraw();

		while (true)
		{
			msg = getmessage(EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (btnreturn.Check(msg.x, msg.y)) {

					btnreturn.OnMessage();
				}
				if (btnnext.Check(msg.x, msg.y)) {

					btnnext.OnMessage();
				}
			}


		}


	}
}
void gameView()
{
	EasyButton 	btnthing;
	EasyButton btnnext;
	EasyButton btnnature;
	cout << 1 << endl;
	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btnthing.Create(220, 130, 760, 570, "", NULL);
		btnnext.Create(420, 590, 540, 630, "开始事件", thingView);
		btnnature.Create(180, 650, 800, 690, "属性 : 智商:    情商： 编程能力： 体质：  ", NULL);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);//文本填充色：透明
		//字体大小&类型字魂无外润黑体(商用需授权)
		//outtextxy(WINDOW_WIDTH / 2 - textwidth("人生重开模拟器---我要做程序员") / 2, 200 - textheight("人生重开模拟器---我要做程序员") / 2, "人生重开模拟器---我要做程序员");//标题文本
		EndBatchDraw();
		while (true)
		{
			msg = getmessage(EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (btnnext.Check(msg.x, msg.y)) {

					btnnext.OnMessage();
				}
			}
		}
	}
}
void gameBeignView()
{
	EasyButton 	btningame;
	EasyButton btnLife;
	EasyButton btnach;
	while (true)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btningame.Create(320, 200, 700, 240, "点击开始你的程序员的一生", gameView);
		btnLife.Create(200, 500, 350, 540, "人生", NULL);
		btnach.Create(650, 500, 780, 540, "成就", NULL);
		EndBatchDraw();
		while (true)
		{
			msg = getmessage(EX_MOUSE);            // 获取消息输入

			if (msg.message == WM_LBUTTONDOWN)
			{
				// 判断控件
				if (btningame.Check(msg.x, msg.y)) {

					btningame.OnMessage();
				}

				// 判断控件
				if (btnLife.Check(msg.x, msg.y)) {

					btnLife.OnMessage();
				}

				// 判断控件
				if (btnach.Check(msg.x, msg.y)) {
					;
					btnach.OnMessage();
				}
			}
		}
	}
}
void loginView()
{
	EasyTextBox LoginView_txtUsername;

	EasyTextBox LoginView_txtPassword;

	EasyButton LoginView_btnConfirm;
	EasyButton LoginView_btnBack;
	BeginBatchDraw();
	cleardevice();
	//设置窗口颜色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	IMAGE login;
	loadimage(&login, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
	putimage(0, 0, &login);
	settextcolor(RGB(239, 218, 187));
	setbkmode(TRANSPARENT); // 文本填充色：透明
	settextstyle(100, 0, "字魂无外润黑体(商用需授权)"); // 字体大小&类型字魂无外润黑体(商用需授权)
	outtextxy(WINDOW_WIDTH / 2 - textwidth("登录账号") / 2, 200 - textheight("登录账号") / 2, "登录账号"); // 标题文本
	settextcolor(RGB(239, 218, 187)); // 文本颜色：黑色
	settextstyle(30, 0, "字魂无外润黑体(商用需授权)");
	setbkmode(TRANSPARENT);
	outtextxy(300, 378, "账号");
	outtextxy(300, 438, "密码");
	settextcolor(BLACK);
	LoginView_btnConfirm.Create(470, 610, 575, 650, "确认", menuView);
	LoginView_btnBack.Create(470, 670, 575, 710, "返回", beginView);
	settextstyle(20, 0, "字魂无外润黑体(商用需授权)");//字体大小&类型字魂无外润黑体(商用需授权)
	settextcolor(BLACK);

	LoginView_txtUsername.Create(370, 375, 700, 405, 20);
	LoginView_txtPassword.Create(370, 435, 700, 465, 20);

	EndBatchDraw();
	while (true)
	{
		ExMessage msg = getmessage(EX_MOUSE | EX_KEY);
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (LoginView_txtUsername.Check(msg.x, msg.y))
			{
				LoginView_txtUsername.OnMessage();
			}
			else if (LoginView_txtPassword.Check(msg.x, msg.y))
			{
				LoginView_txtPassword.OnMessage();
			}
			else if (LoginView_btnConfirm.Check(msg.x, msg.y))
			{
				LoginView_btnConfirm.OnMessage();
			}
			else if (LoginView_btnBack.Check(msg.x, msg.y))
			{
				LoginView_btnBack.OnMessage();// 返回主界面
			}
		}

	}
	closegraph();
}
void registerView()
{
	EasyTextBox registerView_txtUsername;

	EasyTextBox registerView_txtPassword;

	EasyButton registerView_btnConfirm;
	EasyButton registerView_btnBack;
	BeginBatchDraw();
	cleardevice();
	//设置窗口颜色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	IMAGE login;
	loadimage(&login, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
	putimage(0, 0, &login);
	settextcolor(RGB(239, 218, 187));
	setbkmode(TRANSPARENT); // 文本填充色：透明
	settextstyle(100, 0, "字魂无外润黑体(商用需授权)"); // 字体大小&类型字魂无外润黑体(商用需授权)
	outtextxy(WINDOW_WIDTH / 2 - textwidth("注册账号") / 2, 200 - textheight("注册账号") / 2, "登录账号"); // 标题文本
	settextcolor(RGB(239, 218, 187)); // 文本颜色：黑色
	settextstyle(30, 0, "字魂无外润黑体(商用需授权)");
	setbkmode(TRANSPARENT);
	outtextxy(200, 378, "设置账号");
	outtextxy(200, 438, "设置密码");
	settextcolor(BLACK);
	registerView_btnConfirm.Create(470, 610, 575, 650, "确认", beginView);
	registerView_btnBack.Create(470, 670, 575, 710, "返回", beginView);
	settextstyle(20, 0, "字魂无外润黑体(商用需授权)");//字体大小&类型字魂无外润黑体(商用需授权)
	settextcolor(BLACK);

	registerView_txtUsername.Create(370, 375, 700, 405, 20);
	registerView_txtPassword.Create(370, 435, 700, 465, 20);

	EndBatchDraw();
	while (true)
	{
		ExMessage msg = getmessage(EX_MOUSE | EX_KEY);
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (registerView_txtUsername.Check(msg.x, msg.y))
			{
				registerView_txtUsername.OnMessage();
			}
			else if (registerView_txtPassword.Check(msg.x, msg.y))
			{
				registerView_txtPassword.OnMessage();
			}
			else if (registerView_btnConfirm.Check(msg.x, msg.y))
			{
				registerView_btnConfirm.OnMessage();
			}
			else if (registerView_btnBack.Check(msg.x, msg.y))
			{
				registerView_btnBack.OnMessage();// 返回主界面
			}
		}

	}
	closegraph();
}
void beginView()
{
	EasyButton btnLogIn;
	EasyButton btnRegister;
	EasyButton btnEnd;
	cleardevice();
	BeginBatchDraw();
	IMAGE login;
	loadimage(&login, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
	putimage(0, 0, &login);
	settextcolor(RGB(239, 218, 187));
	setbkmode(TRANSPARENT);//文本填充色：透明
	settextstyle(50, 0, "字魂无外润黑体(商用需授权)");//字体大小&类型字魂无外润黑体(商用需授权)
	outtextxy(WINDOW_WIDTH / 2 - textwidth("人生重开模拟器---我要做程序员") / 2, 200 - textheight("人生重开模拟器---我要做程序员") / 2, "人生重开模拟器---我要做程序员");//标题文本
	//
	settextcolor(RGB(239, 218, 187));//文本颜色：黑色
	settextstyle(30, 0, "字魂无外润黑体(商用需授权)");
	setbkmode(TRANSPARENT);

	settextcolor(BLACK);
	btnLogIn.Create(350, 300, 650, 340, "登录账号", loginView);
	btnRegister.Create(350, 410, 650, 450, "注册账号", registerView);
	btnEnd.Create(350, 520, 650, 560, "退出游戏", NULL);

	EndBatchDraw();
	while (true)
	{
		msg = getmessage(EX_MOUSE);            // 获取消息输入

		if (msg.message == WM_LBUTTONDOWN)
		{
			// 判断控件
			if (btnLogIn.Check(msg.x, msg.y)) {
				btnLogIn.OnMessage();
			}
			if (btnRegister.Check(msg.x, msg.y)) {

				btnRegister.OnMessage();
			}if (btnEnd.Check(msg.x, msg.y)) {

				exit(0);
			}
		}
	}
}

void careerView() {

}