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
		fillrectangle(340, 270, 700, 310);
		outtextxy(470, 275, "结算界面");
		//fillrectangle(340, 340, 700, 380);
		//outtextxy(470, 345, " 排行榜 ");
		//fillrectangle(340, 410, 700, 450);
		//outtextxy(470, 415, "更换皮肤");
		fillrectangle(340, 480, 700, 520);
		outtextxy(470, 485, "展示设置");
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

			if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 270 && msg.y <= 310)
			{

				endView();//游戏设置界面
				cout << "点击鼠标右键2" << endl;
			}
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


				settingView();//游戏说明
				//cout << "点击鼠标右键5" << endl;
			}
			//
			if (msg.x >= 340 && msg.x < 340 + 360 && msg.y >= 550 && msg.y <= 590)
			{

				exit(0);// 退出游戏
				//				cout << "点击鼠标右键6" << endl;
			}
		}
	}
}
void achievementView()
{
	EasyButton 	btnthing;
	EasyButton btnnext;
	EasyButton btnreturn;
	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btnthing.Create(220, 130, 760, 570, "", NULL);
		btnreturn.Create(420, 130, 540, 180, "成就", NULL);
		btnnext.Create(420, 590, 540, 630, "返回游戏", gameBeignView);
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
void endView()
{
	EasyButton 	btnthing;
	EasyButton btntext;
	EasyButton btnreturn;
	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btnthing.Create(220, 300, 760, 570, "", NULL);
		btnreturn.Create(180, 650, 320, 690, "返回菜单", menuView);
		btntext.Create(660, 650, 800, 690, "再来一局", gameBeignView);
		EndBatchDraw();
		while (true)
		{
			ExMessage msg = getmessage(EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (btnreturn.Check(msg.x, msg.y)) {

					btnreturn.OnMessage();
				}
				if (btntext.Check(msg.x, msg.y)) {

					btntext.OnMessage();
				}
			}
		}
	}
}
void settingView()
{
	EasyButton btntext;
	EasyButton btnreturn;
	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);
		btnreturn.Create(400, 590, 560, 650, "返回菜单", menuView);
		btntext.Create(400, 220, 560, 280, "敬请期待", NULL);
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
void popView()
{
	EasyButton 	btnthing;
	EasyButton btntext;
	EasyButton btnreturn;
	EasyButton btnreturn1;
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
		btnreturn.Create(260, 570, 380, 610, "A", gameView);
		btnreturn1.Create(580, 570, 720, 610, "B", gameView);
		EndBatchDraw();
		while (true)
		{
			msg = getmessage(EX_MOUSE);
			if (msg.message == WM_LBUTTONDOWN)
			{
				if (btnreturn.Check(msg.x, msg.y)) {

					btnreturn.OnMessage();
				}
				if (btnreturn1.Check(msg.x, msg.y)) {

					btnreturn1.OnMessage();
				}
			}
		}
	}
}






void talentChooseView()
{
	// 测试案例
	vector<talent> randtalents;
	Bonus improve = { 10, 10, 10, 10 };
	talent a = { 1, "一个很牛逼的天赋", improve };
	for (int i = 0; i < 10; i++)
	{
		randtalents.push_back(a);
	}

	EasyButton btnthing;
	EasyButton btntext;
	EasyButton btnreturn;
	EasyButton btnreturn1;
	EasyButton btnchoices[10];

	int selectedCount = 0; // 选中的天赋数量
  vector<bool> selected(randtalents.size(), false); // 用于跟踪每个天赋的选中状态

  bool showDialog = false; // 控制弹窗显示
  const char* dialogMessage = ""; // 弹窗消息内容

	while (1)
	{

		BeginBatchDraw();
	setbkcolor(BLACK);
	IMAGE game;
	loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
	putimage(0, 0, &game);
	settextcolor(BLACK);
	settextstyle(25, 0, "字魂无外润黑体(商用需授权)"); // 字体大小&类型字魂无外润黑体(商用需授权)
	// 创建按钮
	btnthing.Create(220, 50, 760, 700, "", NULL);
	btntext.Create(400, 50, 560, 90, "选择天赋", NULL);
	btnreturn.Create(260, 700, 380, 740, "取消", gameBeginView);
	btnreturn1.Create(580, 700, 720, 740, "确认", gameView);

	settextcolor(RGB(239, 218, 187));
	settextstyle(25, 0, "字魂无外润黑体(商用需授权)");

	// 绘制天赋选项
	for (int i = 0; i < randtalents.size(); i++)
	{
		// 绘制按钮的背景
		btnchoices[i].Create(290, 80 + (i + 1) * 50, 690, 130 + (i + 1) * 50, "", NULL);

		// 根据选中状态改变按钮的文字颜色
		settextcolor(selected[i] ? RGB(255, 0, 0) : RGB(239, 218, 187)); // 选中/未选中颜色

		// 绘制文本
		outtextxy(300, 90 + (i + 1) * 50, randtalents[i].description.c_str());
	}
	FlushBatchDraw();

	// 弹窗逻辑
	while (showDialog)
	{
		// 设置弹窗背景色
		setfillcolor(RGB(173, 216, 230)); // 弹窗背景色
		fillrectangle(280, 250, 700, 400); // 弹窗位置和大小

		// 绘制弹窗边框
		setlinecolor(RGB(0, 0, 139)); // 边框颜色
		rectangle(280, 250, 700, 400);

		// 绘制消息
		settextcolor(RGB(50, 50, 50)); // 文字颜色
		settextstyle(25, 0, "黑体");
		outtextxy(300, 280, dialogMessage); // 绘制消息文本

		// 创建确定按钮
		EasyButton btnOk;
		btnOk.Create(430, 375, 530 ,425 , "确定", NULL);

		// 检查鼠标事件
		msg = getmessage();
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (btnOk.Check(msg.x, msg.y))
			{
				showDialog = false; // 关闭弹窗
				break; // 退出弹窗循环，继续主循环
			}
		}
		FlushBatchDraw();
	}

	// 处理鼠标事件
	msg = getmessage(EX_MOUSE);
	if (msg.message == WM_LBUTTONDOWN)
	{
		if (btnreturn.Check(msg.x, msg.y)) {
			btnreturn.OnMessage(); // 返回主界面
		}

		if (btnreturn1.Check(msg.x, msg.y)) {
			if (selectedCount < 3)
			{
				dialogMessage = "请选择三个天赋"; // 设置弹窗消息
				showDialog = true; // 显示弹窗
			}
			else
			{
				btnreturn1.OnMessage(); // 确认选择
			}
		}

		// 遍历所有按钮，检查是否被点击
		for (int i = 0; i < randtalents.size(); i++)
		{
			if (btnchoices[i].Check(msg.x, msg.y))
			{
				// 切换选中状态
				if (!selected[i])
				{
					if (selectedCount < 3)
					{
						selected[i] = true; // 选中
						selectedCount++;
					}
				}
				else
				{
					selected[i] = false; // 取消选中
					selectedCount--;
				}
			}
		}
	}
	
	}
}


void careerView()
{
	EasyButton 	btnthing;
	EasyButton btnnext;
	EasyButton btnreturn;
	cout << 4;

	while (1)
	{
		BeginBatchDraw();
		setbkcolor(BLACK);
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		settextcolor(BLACK);

		btnthing.Create(220, 130, 760, 570, "", NULL);
		btnnext.Create(420, 590, 540, 630, "返回游戏", gameBeignView);



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

void gameView()
{

	const int HighAttribute = 100;
	const int MidAttribute = 50;
	const int LowAttribute = 0;

	EasyButton btnreturn;
	std::vector<std::string> messages;
	int scroll_offset = 0;
	const int BOX_WIDTH = WINDOW_WIDTH / 4 * 3;
	const int BOX_HEIGHT = WINDOW_HEIGHT / 4 * 3;
	const int BOX_X = 100;
	const int BOX_Y = 50;
	const int LINE_HEIGHT = 20;
	const int MAX_LINES = BOX_HEIGHT / LINE_HEIGHT;
	messages.push_back("Message 1");
	messages.push_back("Message 2");
	messages.push_back("Message 3");
	messages.push_back("Message 4");
	messages.push_back("Message 5");
	messages.push_back("Message 6");
	messages.push_back("Message 7");
	messages.push_back("Message 8");
	messages.push_back("Message 9");
	messages.push_back("Message 10");
	messages.push_back("Message 11");
	messages.push_back("Message 12");
	messages.push_back("Message 13");
	messages.push_back("Message 14");
	messages.push_back("Message 15");
	messages.push_back("Message 1");
	messages.push_back("Message 2");
	messages.push_back("Message 3");
	messages.push_back("Message 4");
	messages.push_back("Message 5");
	messages.push_back("Message 6");
	messages.push_back("Message 7");
	messages.push_back("Message 8");
	messages.push_back("Message 9");
	messages.push_back("Message 10");
	messages.push_back("Message 11");
	messages.push_back("Message 12");
	messages.push_back("Message 13");
	messages.push_back("Message 14");
	messages.push_back("Message 15");

	while (true)
	{
		BeginBatchDraw();
		cleardevice();
		IMAGE game;
		loadimage(&game, "./background.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
		putimage(0, 0, &game);
		setfillcolor(WHITE);
		bar(BOX_X, BOX_Y, BOX_X + BOX_WIDTH, BOX_Y + BOX_HEIGHT);

		// 绘制消息框的边框
		setlinecolor(BLACK);
		rectangle(BOX_X, BOX_Y, BOX_X + BOX_WIDTH, BOX_Y + BOX_HEIGHT);

		// 绘制消息
		int start_line = scroll_offset;
		int end_line = start_line + MAX_LINES;

		

		for (int i = start_line; i < end_line && i < messages.size(); ++i) {
			outtextxy(BOX_X + 10, BOX_Y + 10 + (i - start_line) * LINE_HEIGHT, messages[i].c_str());//messages[i].c_str()转换成c语言风格的字符串
		}
		EasyButton btnnext;
		settextcolor(BLACK);
		btnreturn.Create(200, 660, 360, 710, "上一年(请按w)", NULL);
		btnnext.Create(600, 660, 760, 710, "下一年(请按s)", NULL);
		if (_kbhit()) //检测是否有输入
		{
			char key = _getch();//获取按键
			if (key == 'w' && scroll_offset > 0) {
				scroll_offset--;
			}
			else if (key == 's' && scroll_offset < messages.size() - MAX_LINES) {
				scroll_offset++;
			}
		}
		Sleep(10);
		FlushBatchDraw();
	}
	EndBatchDraw();

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
		btningame.Create(320, 200, 700, 240, "点击开始你的程序员的一生", talentChooseView);
		btnLife.Create(200, 500, 350, 540, "人生", careerView);
		btnach.Create(650, 500, 780, 540, "成就", achievementView);
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
			if (LoginView_txtPassword.Check(msg.x, msg.y))
			{
				LoginView_txtPassword.OnMessage();
			}
			if (LoginView_btnConfirm.Check(msg.x, msg.y))
			{
				LoginView_btnConfirm.OnMessage();
			}
			if (LoginView_btnBack.Check(msg.x, msg.y))
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
			if (registerView_txtPassword.Check(msg.x, msg.y))
			{
				registerView_txtPassword.OnMessage();
			}
			if (registerView_btnConfirm.Check(msg.x, msg.y))
			{
				registerView_btnConfirm.OnMessage();
			}
			if (registerView_btnBack.Check(msg.x, msg.y))
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

