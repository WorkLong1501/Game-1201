/*
luật chơi: điều khiển xe bằng 4 phím a,d,w,s tránh né các vật thể(rơi xuống) và
vật cản (xuất hiện ngẫu nhiên) đạt điểm khi vật thể rơi đến vị trí đáy dưới.
xe sẽ to hơn sau mỗi vòng lặp.
*/
#pragma once
#include "stdlib.h"
#include "Dependencies/glew\glew.h"
#include "Dependencies/freeglut\freeglut.h"


static int windowW = 460;
static int windowH = 920;



void init(void);
//vẽ khung và trục
void drawOXY();
//vẽ vật thể
void drawSquad(GLfloat x, GLfloat y, GLfloat z);
void reshape(int w, int h);

//xe, mình điều khiển
static float carX = 0.0f;
static float carY = 4.0f;
static float carZ = 0.0f;
static float carSize = 1.0f;

//vật thể chuyển dộng trên xuống
static const float rockZ = 0.0f;
static float rockX = -3;
static float rockY = 24;

//vật thể chuyển dộng trên xuống
static const float rockZ1 = 0.0f;
static float rockX1 = 3;
static float rockY1 = 24;

//vật cản xuất hiện ngẫu nhiên
static const float rockZZ = 0.0f;
static float rockXX = -3.0f;
static float rockYY = 24.0f;

//vẽ xe
void carDraw();
//tạo vật cản và vật thể rơi
void rockCreated(GLfloat& x, GLfloat& y);
void rockCreatedXX(GLfloat& rx, GLfloat& ry);
void rockCreated1(GLfloat& x, GLfloat& y);
void keyboard(unsigned char key, int x, int y); //keyboard

#include "sys/utime.h"
#include "sys/timeb.h"
static int Max_Fps = 244;
static float Time_Frame = 1000.0f / Max_Fps; //time trên lý thuyết
static bool gameRunning = true;
static bool flat = false;
static GLfloat x, y;
static	bool test = true;

void playGame();//hàm gọi
void display(); //draw

void idle(); // loop
void gameUpdate(GLfloat& rX, GLfloat& rY, GLfloat& rXX, GLfloat& rYY, GLfloat& rX1, GLfloat& rY1);
void gameLaw(GLfloat x, GLfloat y, GLfloat s);
//hàm vẽ text
void drawText(const char* text, int lenght, const unsigned int x, const unsigned int y, const float r, const float g, const float b);
void gameOver();
#include <string> 



double camX, camY, camZ, centerX, centerY, centerZ;
void camSetting(double camX, double camY, double camZ);
double PI = 3.14;
double alp = 0;
void special(int key, int, int);