#include<stdio.h>
#include"设置头文件.h"
#include<string.h>
#include<graphics.h>
#include<string.h>
IMAGE img;
int oricolor =black;
void bkgrcl() {
	initgraph(400, 400);
	setbkcolor(RGB(159,252,253));
	cleardevice();
	bkgrdg();
	//getchar();
}

//绘制棋盘
void bkgrdg() {
	setlinecolor(BLACK);
	for (int i = 0, x = 20; i < 20; i++)
	{
		
		moveto(x, 0);
		lineto(x, 900);
		x += 20;

	}
	for (int i = 0, x = 20; i < 20; i++)
	{

		moveto(0, x);
		lineto(900, x);
		x += 20;

	}
}
//绘制棋子
// **************************************************
//预设函数，用于预算棋子下在哪
//用来进行全局检验是否有五颗棋子计算
//用来进行棋子落子计算
//
//
//********************************************************

void chess() {
	//获取鼠标信息，并作出鼠标预下棋子的位置
	MOUSEMSG msg;
	
	
	while (1)
	{
		
		
		msg = GetMouseMsg();
		if (msg.uMsg == WM_MOUSEMOVE) {
			cleardevice();
			BeginBatchDraw();
			//*****************************************************
			imgout();//需要改进为图片的形式
			//**************************************************
			//Sleep(100);
			
			fillcircle(pepa(msg.x),(pepa(msg.y)), 10);//使用预设函数来解决描述问题
			EndBatchDraw();
			
		}
		if((msg.uMsg==WM_LBUTTONDOWN))
		{
			if (oricolor == black) {
				setfillcolor(BLACK);
				oricolor = white;
				goto A;
			}
			
			if (oricolor == white)
			{
				setfillcolor(WHITE);
				oricolor = black;
			}

			A:csdown(msg);
		}
		
		
	}
}
//预设功能实现
short pepa(short n) {
	int i = n / 20;
	int t;
	if ((t=n%20)<=10)
	{
		return 20 * i;
	}
	if ((t = n % 20) > 10)
	{
		return 20 * (i+1);
	}
}
//落子计算，需要搞开颜色与存储黑白子的五子计算
void csdown(MOUSEMSG msg)
{



	fillcircle(pepa(msg.x), (pepa(msg.y)), 10);
	imgin();
	five(msg);
}
//先完成图片的存储与输出
void imgin()
{
	
	getimage(&img, 0, 0, 400, 400);
	
}
void imgout() {
	putimage(0, 0, &img);
}
//完成五子的判断
//这里的五子算法判断有一个问题，但是那一个忘了，就是某一种连接方法时不可以被判断成功的，但是这个下发没有别判断
void five(MOUSEMSG msg) {
	unsigned i;
	short x, y;
	setfont(20, 20, "宋体");
	setcolor(RED);
	x = pepa(msg.x) + 5;
	y = pepa(msg.y) + 5;
	i = getpixel(x,y);
	if ((i==getpixel(x+20,y))||(i==getpixel(x-20,y)))
	{
		if ((i == getpixel(x + 40, y)) || (i == getpixel(x - 40, y)))
		{
			if ((i == getpixel(x + 60, y)) || (i == getpixel(x - 60, y))) {
				if ((i == getpixel(x + 80, y)) || (i == getpixel(x - 80, y)))
				{

					outtextxy(100, 200, "you are winner");
					getchar();
					exit(1);
				}
			}
		}
	}
	if ((i == getpixel(x + 20, y+20)) || (i == getpixel(x - 20, y-20)))
	{
		if ((i == getpixel(x + 40, y+40)) || (i == getpixel(x - 40, y-40)))
		{
			if ((i == getpixel(x + 60, y+60)) || (i == getpixel(x - 60, y-60))) {
				if ((i == getpixel(x + 80, y+80)) || (i == getpixel(x - 80, y-80)))
				{

					outtextxy(100, 200, "you are winner");
					getchar();
					exit(1);
				}
			}
		}
	}
	if ((i == getpixel(x + 20, y-20)) || (i == getpixel(x - 20, y+20)))
	{
		if ((i == getpixel(x + 40, y-40)) || (i == getpixel(x - 40, y+40)))
		{
			if ((i == getpixel(x + 60, y-60)) || (i == getpixel(x - 60, y+60))) {
				if ((i == getpixel(x + 80, y-80)) || (i == getpixel(x - 80, y+80)))
				{

					outtextxy(100, 200, "you are winner");
					getchar();
					exit(1);
				}
			}
		}
	}
	if ((i == getpixel(x , y+20)) || (i == getpixel(x , y-20)))
	{
		if ((i == getpixel(x , y+40)) || (i == getpixel(x , y-40)))
		{
			if ((i == getpixel(x , y+60)) || (i == getpixel(x , y-60))) {
				if ((i == getpixel(x , y+80)) || (i == getpixel(x , y-80)))
				{

					outtextxy(100, 200, "you are winner");
					getchar();
					exit(1);
				}
			}
		}
	}
}
void main() {
	bkgrcl();
	getimage(&img, 0, 0, 400, 400);
	while (1)
	{
		chess();
	}
		

		//getchar();
	
}