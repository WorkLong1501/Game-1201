#include "Global.h"
void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT); glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_RGBA);

	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(450, 50);
	glutCreateWindow("Hanh Tinh Co Don");
	
	//gán gtri ban dau
	camX = 0.0f;
	camY = 0.0f;
	camZ = 20.0f;
	centerX = 0;
	centerY = 10;
	centerZ = 0;
}
void camSetting(double camX, double camY, double camZ)
{
	camX *= sin(alp * PI / 360);
	camZ *= cos(alp * PI / 360);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camX, camY, camZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
}
void drawOXY() // vẽ trục tọa độ
{
	glPushMatrix();
	glBegin(GL_LINES);
	//glColor3f(1, 0, 0); glVertex3f(50, 0, 0); glVertex3f(-100, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 50, 0); glVertex3f(0, -100, 0);
	//glColor3f(0, 1, 1); glVertex3f(0, 0, 50); glVertex3f(0, 0, -100);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES); // vẽ khung trò chơi
	glColor3f(1, 0, 1); glVertex3f(50, 0, 0); glVertex3f(-100, 0, 0);
	glColor3f(1, 0, 1); glVertex3f(4, 0, 0); glVertex3f(4, 24, 0);
	glColor3f(1, 0, 1); glVertex3f(-4, 0, 0); glVertex3f(-4, 24, 0);
	glColor3f(1, 0, 1); glVertex3f(-4, 24, 0); glVertex3f(4, 24, 0);
	glEnd();
	glPopMatrix();
}
void drawSquad(GLfloat x, GLfloat y, GLfloat z)
{
	static GLfloat r = 0;
	static GLfloat g = 0;
	static GLfloat b = 0;
	
	static GLfloat alpha = 0;
	glPushMatrix();
	glTranslatef(x, y, z);
	//glScalef(2, 2, 2);
	glRotatef(60, 0, 0, 0);
	glRotatef(alpha, 0, 1, 0);
	glColor3f(r, g, b);
	glBegin(GL_QUADS);

	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);


	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);


	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);


	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);


	glVertex3f(-1, -1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, -1, -1);

	
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);

	glEnd();
	if (test)
	{
		r = (GLfloat)(rand() % 2);
		g = (GLfloat)(rand() % 2);
		b = (GLfloat)(rand() % 2);
		test = !test;
	}
	
	alpha = alpha + 0.1;
	//glFlush();
	//glutSwapBuffers();
	//glutPostRedisplay(); k can
	glPopMatrix();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 10.0, 1000);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camX, camY, camZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
	//gluLookAt(0, 0, 20, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0); // goc nhìn điểm đặt mắt(1,2,20), điểm nhìn vào (1,10,0), vecto đi lên (0,1,0)
}
void carDraw()
{
	static double alpha = 0;
	glPushMatrix();
		glTranslatef(carX, carY, carZ);
		glRotatef(60, 1, 0, 0);
		glRotatef((GLfloat)alpha, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glutWireSphere((GLfloat)carSize, 9, 5);
		alpha = (int)(alpha + 0.5) % 360;
	glutPostRedisplay();
	//xem tọa độ xe
	glPopMatrix();
	glPushMatrix();
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1); glVertex3f(carX,carY,carZ);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	
	
}                                                                      
void rockCreated(GLfloat& x, GLfloat& y)
{
	bool f; 
	f = (rand() % 2 == 1) ? true : false;

	if (f)	//sinh ra bên phải
	{
		x = (rand() % 5); y = 28;
		
	}
	else //sinh ra bên trái
	{
		x = -(rand() % 5); y = 28;
		
	}
	carSize += 0.05f;
}
void rockCreated1(GLfloat& x, GLfloat& y)
{
	bool f;
	f = (rand() % 2 == 1) ? true : false;

	if (f)	//sinh ra bên phải
	{
		x = (rand() % 5); y = 28;

	}
	else //sinh ra bên trái
	{
		x = -(rand() % 5); y = 28;

	}
	carSize += 0.05f;
}
void rockCreatedXX(GLfloat& rx, GLfloat& ry)
{
	bool f;
	f = (rand() % 2 == 1) ? true : false;

	if (f)	//sinh ra bên phải
	{
		rx = rand() % 5;
	}
	else //sinh ra bên trái
	{
		rx = -rand() % 5;
	}
	ry = rand() % 20;
	//hàm tránh việc vật thể sinh ra trùng với tọa độ hiện tại của xe
	if (rockXX >= (carX - carSize) + 0.015 && rockXX <= (carX + carSize) - 0.015)
	{
		if (rockYY >= (carX - carSize) + 0.015 && rockYY <= (carY + carSize) - 0.015)
		{
			rockCreatedXX(rockXX, rockYY);
		}
	}
}
int dem = 1;
void keyboard(unsigned char key, int x, int y)
{
	
	switch (key)
	{ 
	case 'a': carX -= 1.0f;
		if (carX < -4)
			carX += 1.0f; // giới hạn biên trái
		glutPostRedisplay(); break;
	case 'd': carX += 1.0f;
		if (carX > 4)
			carX -= 1.0f;
		glutPostRedisplay(); break;
	case 'w': carY += 1.0f;
		if (carY > 24)
			carY -= 1.0f;
		glutPostRedisplay(); break;
	case 's': carY -= 1.0f;
		if (carY < 0)
			carY += 1.0f;
		glutPostRedisplay(); break;
	case 'q': 
		gameRunning = false;
		 break;
	case 32:
		gameRunning = true;
		glutDestroyWindow(dem++);
		rockX = 0;
		rockY = 24;
		rockXX = -3.0f;
		rockYY = 24.0f;
		rockX1 = 3;
		rockY1 = 24;

		carSize = 1;
		//ReplayGame();
		playGame();
		break;
	case 27: 
		glutLeaveMainLoop();
	case 'j': alp -= 1.0f;  break;
	case 'i': camY += 0.1f; break;
	case 'l': alp += 1.0f; break;
	case 'k': camY -= 0.1f; break;
	default:
		break;
	}
	
}

void special(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		centerY -= 1.0f;
		break;
	case GLUT_KEY_UP:
		centerY += 1.0f;
		break;
	case GLUT_KEY_LEFT:
		centerX -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		centerX += 1.0f;
		break;
	default:
		break;
	}
}
int getMill()
{
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}
void sleep(int sleepTime)
{
	int count = 0;
	int beginSleep = getMill();
	while (getMill() - beginSleep < sleepTime)
	{
		count++;
	}
}


void playGame()
{
	init();
	int beginFrame = getMill();

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);

	int timeDiff = getMill() - beginFrame;
	if (timeDiff < Time_Frame)
	{
		sleep(Time_Frame - timeDiff);
	}
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
 	glutIdleFunc(idle);
	glutMainLoop();

}

//void ReplayGame()
//{
//	init();
//	int beginFrame = getMill();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//
//	int timeDiff = getMill() - beginFrame;
//	if (timeDiff < Time_Frame)
//	{
//		sleep(Time_Frame - timeDiff);
//	}
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//	glutMainLoop();
//
//}


void display()
{
	camSetting(camX, camY, camZ);
	if (gameRunning)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// xóa hình cũ
		drawOXY();
		carDraw();// xe
		drawSquad(rockX, rockY, rockZ); // cục rơi xuống
		// vật cản xuất hiện ngẫu nhiên
		drawSquad(rockXX, rockYY, rockZZ);
		drawSquad(rockX1, rockY1, rockZ1);
		glPushMatrix();
		char array[60];
		sprintf_s(array, "your score: %.2f", (carSize - 1.00f) / 0.05);
		drawText(array, strlen(array), 0, 30, 1, 1, 0);
		char HD[60];
		sprintf_s(HD, "move by: a, d, s, w ");
		drawText(HD, strlen(HD), 400, 30, 0, 1, 0);
		char HD1[60];
		sprintf_s(HD1, "exit game: esc || die: q ");
		drawText(HD1, strlen(HD1), 400, 20, 0, 1, 0);
		glPopMatrix();
	}
	else
	{
		int i = 0;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// xóa hình cũ
		while (i++ <= 300)
		{
			gameOver();
		}
		
		//glutLeaveGameMode();
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void idle()
{

	gameUpdate(rockX, rockY, rockXX, rockYY,rockX1,rockY1);
	gameLaw(carX,carY,carSize);

	glutPostRedisplay();

}

void gameUpdate(GLfloat& rX, GLfloat& rY, GLfloat& rXX, GLfloat& rYY, GLfloat& rX1, GLfloat& rY1)
{
	if (flat)
	{
		rockCreated(rX, rY);
		rockCreatedXX(rockXX, rockYY);
		rockCreated1(rX1, rY1);
		flat = false; glutPostRedisplay();
		test = !test;
	}
	else
	{
		rY -= 0.02f; glutPostRedisplay();
		for  (int i = 1; i < 10;  i++)
		{
			if ((carSize - 1) >= i*2*0.05f) // mỗi 3 điểm thay dổi tốc độ 
			{
				rY -= 0.01f;
			}
		}
		rY1 -= 0.02f; glutPostRedisplay();
		
	}
	
}

void gameLaw(GLfloat x,GLfloat y, GLfloat s)
{
	if (rockY <= 0)
		flat = true;
	GLfloat cX = x ;
	GLfloat cY = y ;
	GLfloat cS = s ;
	if (rockX >= (cX - cS)  && rockX <= (cX + cS) )
	{
		glutPostRedisplay();
		if (rockY >= (cY - cS)  && rockY <= (cY + cS) )
		{
			glutPostRedisplay();
			gameRunning = false;
		}
	}

	if (rockXX >= (cX - cS)  && rockXX <= (cX + cS) )
	{
		glutPostRedisplay();
		if (rockYY >= (cY - cS)  && rockYY <= (cY + cS) )
		{
			glutPostRedisplay();
			gameRunning = false;
		}
	}
	if (rockX1 >= (cX - cS) && rockX1 <= (cX + cS))
	{
		glutPostRedisplay();
		if (rockY1 >= (cY - cS) && rockY1 <= (cY + cS))
		{
			glutPostRedisplay();
			gameRunning = false;
		}
	}

}

void drawText(const char *text,int lenght, const unsigned int x, const unsigned int y, const float r, const float g, const float b)
{
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[28];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 15);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glColor3f(r, g, b);
	glRasterPos2i(x, y);
	for  (int  i= 0; i  < lenght; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void gameOver()
{
	glPushMatrix();
	char gOver[20] = "Game Over!!!";
	drawText(gOver, strlen(gOver), windowW / 2, windowH / 2 + 40, 1, 1, 0);
	char array[60];
	sprintf_s(array, "your score: %.2f", (carSize - 1.0f) / 0.05);
	drawText(array, strlen(array), windowW / 2 , windowH / 2 +20, 1, 1, 0);
	char HD[60];
	sprintf_s(HD, "exit game: esc || replay game: space ");
	drawText(HD, strlen(HD), windowW/2, windowH/2, 0, 1, 0);
	glPopMatrix();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	playGame();
	return 0;
}

