#include<stdio.h>
#include"����ͷ�ļ�.h"
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

//��������
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
//��������
// **************************************************
//Ԥ�躯��������Ԥ������������
//��������ȫ�ּ����Ƿ���������Ӽ���
//���������������Ӽ���
//
//
//********************************************************

void chess() {
	//��ȡ�����Ϣ�����������Ԥ�����ӵ�λ��
	MOUSEMSG msg;
	
	
	while (1)
	{
		
		
		msg = GetMouseMsg();
		if (msg.uMsg == WM_MOUSEMOVE) {
			cleardevice();
			BeginBatchDraw();
			//*****************************************************
			imgout();//��Ҫ�Ľ�ΪͼƬ����ʽ
			//**************************************************
			//Sleep(100);
			
			fillcircle(pepa(msg.x),(pepa(msg.y)), 10);//ʹ��Ԥ�躯���������������
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
//Ԥ�蹦��ʵ��
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
//���Ӽ��㣬��Ҫ�㿪��ɫ��洢�ڰ��ӵ����Ӽ���
void csdown(MOUSEMSG msg)
{



	fillcircle(pepa(msg.x), (pepa(msg.y)), 10);
	imgin();
	five(msg);
}
//�����ͼƬ�Ĵ洢�����
void imgin()
{
	
	getimage(&img, 0, 0, 400, 400);
	
}
void imgout() {
	putimage(0, 0, &img);
}
//������ӵ��ж�
//����������㷨�ж���һ�����⣬������һ�����ˣ�����ĳһ�����ӷ���ʱ�����Ա��жϳɹ��ģ���������·�û�б��ж�
void five(MOUSEMSG msg) {
	unsigned i;
	short x, y;
	setfont(20, 20, "����");
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