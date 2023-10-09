#include<graphics.h>
void bkgrcl();
//背景颜色设计
void bkgrdg();
//图像背景设计
void chess();
//棋子设置
short pepa(short);
//预设功能设计
//落子计算
void csdown(MOUSEMSG);
//图片制造与输出计算需要分开
void imgin();
void imgout();
#ifndef white
#define white 1
#endif
#ifndef black
#define black 0
#endif
//判断棋子练成五子
void five(MOUSEMSG);
