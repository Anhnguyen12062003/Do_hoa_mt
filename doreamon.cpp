//////#include<iostream>
//////#include<GL/glut.h>
//////#include<GL/gl.h>
//////#include<GL/glu.h>
//////#include<math.h>
//////#include<vector>
//////
//////using namespace std;
//////
//////#define PI 3.14159265359
//////#define SIZE_SPACE 300.0
//////#define ANGLE_MOVE_LEGS 40
//////#define ANGLE_MOVE_ARMS 40
//////
//////float angleRotate = 0;
//////
//////bool up = true;
//////bool move = false;
//////float angleMove = 0;
//////float coordinates = 0;
//////
//////void moveUp (int value) {
//////	if(angleMove <= ANGLE_MOVE_LEGS + 0.05 || angleMove >= -ANGLE_MOVE_LEGS - 0.05) {
//////        if(angleMove <= ANGLE_MOVE_LEGS && up) {
//////        	angleMove += 10;
//////           	if(angleMove > ANGLE_MOVE_LEGS) {
//////           		up = false;
//////			}
//////		}
//////		if(angleMove >= -ANGLE_MOVE_LEGS && !up) {
//////			angleMove -= 10;
//////           	if(angleMove < -ANGLE_MOVE_LEGS) {
//////           		up = true;
//////			}
//////		}
//////	}
//////	if(move) {
//////		glutTimerFunc(80, moveUp, 0);
//////	}
//////}
//////
//////// Catch Event
//////void keyboardCallback(unsigned char key, int x, int y) {
//////    if(key == 'a') {
//////    	move = !move;
//////    	cout << move;
//////    	glutTimerFunc(0, moveUp, 0);
//////	}
//////}
//////
//////void specialKeyCallback(int key, int x, int y) {
//////    switch (key) {
//////        case GLUT_KEY_UP:
//////        	if(angleRotate/180 != int(angleRotate/180)) {
//////        		int temp = int(angleRotate / 180);
//////        		if(angleRotate > 0) {
//////        			if(temp % 2 == 1) {
//////        				coordinates++;
//////					} else {
//////						coordinates--;
//////					}
//////				} else {
//////					if(temp % 2 == 1) {
//////        				coordinates--;
//////					} else {
//////						coordinates++;
//////					}
//////				}
//////			}
//////            if(angleMove <= ANGLE_MOVE_LEGS && up) {
//////            	angleMove += 10;
//////            	if(angleMove > ANGLE_MOVE_LEGS) {
//////            		up = false;
//////				}
//////			}
//////			if(angleMove >= -ANGLE_MOVE_LEGS && !up) {
//////				angleMove -= 10;
//////            	if(angleMove < -ANGLE_MOVE_LEGS) {
//////            		up = true;
//////				}
//////			}
//////            break;
//////        case GLUT_KEY_DOWN:
//////            break;
//////        case GLUT_KEY_LEFT:
//////            angleRotate += 5;
//////            break;
//////        case GLUT_KEY_RIGHT:
//////            angleRotate -= 5;
//////            break;
//////        default:
//////        	cout << "Doraemon";
//////            break;
//////        
//////    }
//////}
//////
//////void vetruc() {
//////	glLineWidth(1);
//////	glColor3f(1, 0, 0);
//////	GLfloat color1[] = { 1, 0, 0, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color1);
//////	glBegin(GL_LINES);	// bat dau ve
//////	glVertex3f(- 2*SIZE_SPACE, 0.0, 0.0);	// toa do bat dau
//////	glVertex3f(SIZE_SPACE, 0.0, 0.0);	// toa do ket thuc
//////	glEnd();	// ket thúc ve
//////
//////	glColor3f(0, 1, 0);
//////	GLfloat color2[] = { 0, 1, 0, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color2);
//////	glBegin(GL_LINES);
//////	glVertex3f(0.0, - 2*SIZE_SPACE, 0.0);
//////	glVertex3f(0.0, SIZE_SPACE, 0.0);
//////	glEnd();
//////	
//////	glColor3f(0, 0, 1);
//////	GLfloat color3[] = { 0, 0, 1, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color3);
//////	glBegin(GL_LINES);
//////	glVertex3f(0.0, 0.0, - 2*SIZE_SPACE);
//////	glVertex3f(0.0, 0.0, SIZE_SPACE);
//////	glEnd();
//////}
//////
//////// Draw Shapes
//////void drawStraightLine(float x1, float y1, float z1, float x2, float y2, float z2,
//////					  float red, float green, float blue,
//////					  float x = 0, float y = 0, float z = 0,
//////					  float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0) {
//////					  	
//////	glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	
//////	glColor3f(red, green, blue);
//////	GLfloat color1[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color1);
//////	glLineWidth(2);
//////	glBegin(GL_LINES);	// bat dau ve
//////	glVertex3f(x1, y1, z1);	// toa do bat dau
//////	glVertex3f(x2, y2, z2);	// toa do ket thuc
//////	glEnd();	// ket thúc ve
//////	
//////	glPopMatrix();				
//////}
//////
//////void drawSquare(double Size, float red, float green, float blue,
//////				float x = 0, float y = 0, float z = 0,
//////				float scaleX = 1, float scaleY = 1, float scaleZ = 1,
//////				float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0) {
//////					
//////	double size = Size/2;
//////	
//////	glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	glScalef(scaleX, scaleY, scaleZ); // Co dãn
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////    glBegin(GL_QUADS);
//////	
//////	// Front Face
//////	glNormal3f(0.0, 0.0, 1.0);
//////	glVertex3f(-size, -size, size);
//////	glVertex3f( size, -size, size);
//////	glVertex3f( size, size, size);
//////	glVertex3f(-size, size, size);
//////	// Back Face
//////	glNormal3f(0.0, 0.0, -1.0);
//////	glVertex3f(-size, -size, -size);
//////	glVertex3f(-size, size, -size);
//////	glVertex3f(size, size, -size);
//////	glVertex3f(size, -size, -size);
//////	// Top Face
//////	glNormal3f(0.0, 1.0, 0.0);
//////	glVertex3f(-size, size, -size);
//////	glVertex3f(-size, size, size);
//////	glVertex3f( size, size, size);
//////	glVertex3f( size, size, -size);
//////	// Bottom Face
//////	glNormal3f(0.0, -1.0, 0.0);
//////	glVertex3f(-size, -size, -size);
//////	glVertex3f( size, -size, -size);
//////	glVertex3f( size, -size, size);
//////	glVertex3f(-size, -size, size);
//////	// Right face
//////	glNormal3f(1.0, 0.0, 0.0);
//////	glVertex3f( size, -size, -size);
//////	glVertex3f( size, size, -size);
//////	glVertex3f( size, size, size);
//////	glVertex3f( size, -size, size);
//////	// Left Face
//////	glNormal3f(-1.0, 0.0, 0.0);
//////	glVertex3f(-size, -size, -size);
//////	glVertex3f(-size, -size, size);
//////	glVertex3f(-size, size, size);
//////	glVertex3f(-size, size, -size);
//////	
//////	glEnd();
//////	glPopMatrix();
//////}
//////
//////void drawSolidSphere(double radius, float red, float green, float blue,
//////					 float x = 0, float y = 0, float z = 0,
//////					 float scaleX = 1, float scaleY = 1, float scaleZ = 1,
//////					 float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0) {
//////					 	
//////	glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	glScalef(scaleX, scaleY, scaleZ);	
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////    glutSolidSphere(radius, 50, 50);
//////    glPopMatrix();
//////}
//////
//////
//////void drawBezierCurve(GLfloat ctrlPoints[][3], float red, float green, float blue,
//////					 float x = 0, float y = 0, float z = 0,
//////					 float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0
//////					 ) {
//////	glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////	
//////    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints[0][0]);
//////    glEnable(GL_MAP1_VERTEX_3);
//////
//////    glBegin(GL_LINE_STRIP);
//////    for (int i = 0; i <= 30; i++) {
//////        glEvalCoord1f((GLfloat)i / 30.0);
//////    }
//////    glEnd();
//////    glPopMatrix();
//////}
//////
//////void drawCircle(float radiusX, float radiusZ, float width,
//////				float red, float green, float blue,
//////				float x = 0, float y = 0, float z = 0,
//////				float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0) {
//////
//////    glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////	glEnable(GL_LINE_SMOOTH); // on antialiasing
//////
//////	glLineWidth(width);
//////    glBegin(GL_LINE_LOOP);
//////    for (int i = 0; i < 500; i++) {
//////        float angle = 2.0 * M_PI * i / 500;
//////        float x = radiusX * cos(angle);
//////        float z = radiusZ * sin(angle);
//////        glVertex3f(x, 0, z);
//////    }
//////    glEnd();
//////    glDisable(GL_LINE_SMOOTH); // off antialiasing
//////    glPopMatrix();
//////}
//////
//////void drawHalfCircle(float radiusX, float radiusZ, float width,
//////				float red, float green, float blue,
//////				float x = 0, float y = 0, float z = 0,
//////				float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0) {
//////
//////    glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////	glEnable(GL_LINE_SMOOTH); // on antialiasing
//////
//////	glLineWidth(width);
//////    glBegin(GL_LINE_LOOP);
//////    for (int i = 0; i < 500; i++) {
//////        float angle = M_PI * i / 500;
//////        float x = radiusX * cos(angle);
//////        float z = radiusZ * sin(angle);
//////        glVertex3f(x, 0, z);
//////    }
//////    glEnd();
//////    glDisable(GL_LINE_SMOOTH); // off antialiasing
//////    glPopMatrix();
//////}
//////
//////void drawCylinder(GLdouble botRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks,
//////                  GLfloat red, GLfloat green, GLfloat blue,
//////                  GLfloat x = 0, GLfloat y = 0, GLfloat z = 0,
//////                  GLfloat angle = 0, GLfloat axisX = 0, GLfloat axisY = 0, GLfloat axisZ = 0,
//////				  float scaleX = 1, float scaleY = 1, float scaleZ = 1) {
//////
//////    glPushMatrix();
//////    glTranslatef(x, y, z);
//////    glRotatef(angle, axisX, axisY, axisZ);
//////    glRotatef(90, 1, 0, 0);
//////    glScalef(scaleX, scaleY, scaleZ); // Co dãn
//////
//////    GLfloat color[] = { red, green, blue, 1 };
//////    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////
//////    GLUquadric *quadric = gluNewQuadric();
//////    gluQuadricNormals(quadric, GLU_SMOOTH);
//////    gluQuadricTexture(quadric, GL_TRUE);
//////
//////    gluCylinder(quadric, botRadius, topRadius, height, slices, stacks);
//////
//////    gluDeleteQuadric(quadric);
//////    glPopMatrix();
//////}
//////
//////void halfSphere (double radius, double startAngle, double endAngle,
//////				 double red, double green, double blue,
//////				 GLfloat x = 0, GLfloat y = 0, GLfloat z = 0,
//////                 GLfloat angle = 0, GLfloat axisX = 0, GLfloat axisY = 0, GLfloat axisZ = 0) {
//////
//////    glPushMatrix();
//////	glTranslatef(x, y, z);
//////	glRotatef(angle, axisX, axisY, axisZ);
//////	
//////	GLfloat color[] = { red, green, blue, 1 };
//////	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
//////
//////	GLUquadric *quad = gluNewQuadric();
//////    gluPartialDisk(quad, 0, radius, 50, 50, startAngle, endAngle); // Draw a partial disk
//////	
//////    glEnd();
//////    glPopMatrix();
//////}
//////
//////// Components
//////// Head
//////void eyes() {
//////	glPushMatrix();
//////	glTranslatef(0, 40, 45);
//////	glRotatef(-30, 1, 0, 0);
////////	glScalef(scaleX, scaleY, scaleZ);
//////	
////////	Right
//////	drawSolidSphere(15, 1, 1, 1, -13, 0, 0, 0.9, 1, 0.3);
//////	drawSolidSphere(6, 0, 0, 0, -8, -2, 5, 1, 1, 0.3);
//////	drawSolidSphere(2, 1, 1, 1, -8, -2, 7, 1, 1, 0.3);
////////	Left
//////	drawSolidSphere(15, 1, 1, 1, 13, 0, 0, 0.9, 1, 0.3);
//////	drawSolidSphere(6, 0, 0, 0, 8, -2, 5, 1, 1, 0.3);
//////	drawSolidSphere(2, 1, 1, 1, 8, -2, 7, 1, 1, 0.3);
//////
//////	glPopMatrix();
//////}
//////
//////void breads() {
//////	glPushMatrix();
//////	glTranslatef(0, 15, 58);
//////	glRotatef(90, 0, 1, 0);
//////	
////////	Right
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, 0, 8, -10, 1, 0, 0);
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, -10, 8, 3, 1, 0, 0);
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, -20, 8, 10, 1, 0, 0);
////////	Left
//////	glRotatef(180, 0, 1, 0);
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, 0, 8, -10, 1, 0, 0);
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, -10, 8, 3, 1, 0, 0);
//////	drawStraightLine(0, 0, 0, 0, 0, 25, 30.0/255, 30.0/255, 30.0/255, 0, -20, 8, 10, 1, 0, 0);
//////
//////	glPopMatrix();
//////}
//////
//////void head() {
//////	glPushMatrix();
//////	
//////	glTranslatef(0, 53, 0);
//////	glRotatef(25, 1, 0, 0);
////////	glScalef(scaleX, scaleY, scaleZ);
//////
////////	Head
//////	drawSolidSphere(55, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0, 1, 1, 1);
////////	Face
//////    drawSolidSphere(42, 1, 1, 1, 0, 0, 37, 1, 1, 0.5, 0, 1, 0, 0);
////////  Eyes
//////	eyes();
////////	Nose
//////	drawSolidSphere(8, 1, 0, 0, 0, 28, 60, 1, 1, 1);
//////	drawSolidSphere(2, 1, 1, 1, -2, 32, 65, 1, 1, 1);
////////  Beards
//////	breads();
////////	Mouth
//////	drawStraightLine(0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 20, 58, 90, 1, 0, 0);
//////	GLfloat ctrlpoints[4][3] = {
//////	    {0, 0, 0},
//////	    {0, -29, 20},
//////	    {0, -29, 40},
//////	    {0, 0, 60},
//////	};
//////	drawBezierCurve(ctrlpoints, 0, 0, 0, -30, 0, 56, 90, 0, 1, 0);
//////	
//////    glPopMatrix();
//////}
//////
//////// Body
//////void leftArm() {
//////	glPushMatrix();
//////    glTranslatef(38, -15, 0);
//////    glRotatef(angleMove, 1, 0, 0);
//////    glRotatef(35, 0, 0, 1);
//////	
//////	drawCylinder(10, 10, 35, 20, 20, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0, 0, 0, 0, 1);
//////	drawSolidSphere(10, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(12, 1, 1, 1, 0, -40, 0);
//////
//////	glPopMatrix();
//////}
//////
//////void rightArm() {
//////	glPushMatrix();
//////    glTranslatef(-38, -15, 0);
//////    glRotatef(-angleMove, 1, 0, 0);
//////    glRotatef(-35, 0, 0, 1);
//////	
//////	drawCylinder(10, 10, 35, 20, 20, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0, 0, 0, 0, 1);
//////	drawSolidSphere(10, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(12, 1, 1, 1, 0, -40, 0);
//////
//////	glPopMatrix();
//////}
//////
//////void leftLeg() {
//////	glPushMatrix();
//////    glTranslatef(-18, -57, 0);
//////    glRotatef(angleMove, 1, 0, 0);
//////	
//////	drawCylinder(18, 15, 15, 20, 20, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(17, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(18, 1, 1, 1, 0, -23, 0, 1, 0.8, 1);
//////
//////	glPopMatrix();
//////}
//////
//////void rightLeg() {
//////	glPushMatrix();
//////    glTranslatef(18, -57, 0);
//////    glRotatef(-angleMove, 1, 0, 0);
//////	
//////	drawCylinder(18, 15, 15, 20, 20, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(17, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(18, 1, 1, 1, 0, -23, 0, 1, 0.8, 1);
//////
//////	glPopMatrix();
//////}
//////
//////void tail() {
//////	glPushMatrix();
//////	glTranslatef(0, -40, -33);
//////	glRotatef(-30, 1, 0, 0);
//////	
//////	drawStraightLine(0, 0, 0, 0, 0, 20, 30.0/255, 30.0/255, 30.0/255, 0, 0, 0, 180, 0, 1, 0);
//////	drawSolidSphere(8, 1, 0, 0, 0, 0, -20);
//////	
//////	glPopMatrix();
//////}
//////
//////void body() {
//////	glPushMatrix();
//////	
////////	glTranslatef(0, 50, 0);
////////	glRotatef(25, 1, 0, 0);
////////	glScalef(scaleX, scaleY, scaleZ);
//////
////////	Necklace
//////	drawCircle(36, 38, 9, 1, 0.05, 0.05, 0, 3, 0);
////////	Ring
//////	drawSolidSphere(7, 245.0/255, 228.0/255, 42.0/255, 0, -2, 40);
////////	Body
////////	drawCylinder(36, 36, 55, 50, 50, 4.0/255, 123.0/255, 198.0/255, 0, 0, 0);
//////	drawSolidSphere(46, 4.0/255, 123.0/255, 198.0/255, 0, -25, 0, 1, 0.8, 1);
////////	Legs
//////	leftLeg();
//////	rightLeg();
////////	Arms
//////	leftArm();
//////	rightArm();
////////	Belly
//////    drawSolidSphere(25, 1, 1, 1, 0, -25, 37, 1.2, 1, 0.4, 0, 1, 0, 0);
////////  Bag
//////	drawHalfCircle(20, 20, 1, 0, 0, 0, 0, -25, 48, 90, 1, 0, 0);
////////	Tail
//////	tail();
//////	
//////    glPopMatrix();
//////}
//////
//////void MyDisplay() {
//////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// làm moi bo dem mau va bo dem sau
//////	glLoadIdentity();	// Ðat ma tran hien tai thành ma tran don vi
////////	gluLookAt(50, 100, 500, 0, 0, 0, 0, 1, 0);	// moi 3 diem ung voi toa do mat - toa do cua diem muc tieu - gia tri vector huong len tren
//////	gluLookAt(0, 0, 500, 0, 0, 0, 0, 1, 0);
//////	
//////	// Nguon sáng
//////    GLfloat light_position[] = { 500, 1000, 3000, 1 };  // Thiet lap vi trí nguon sáng
//////    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//////    GLfloat light_diffuse[] = { 1.3, 1.3, 1.3, 1 };		// Thiet lap màu sáng
//////    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//////    GLfloat ambient_light[] = { 0.7, 0.7, 0.7, 1.0 };  // Thiet lap do sáng tong the
//////	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
//////	
//////	vetruc();
//////	
//////	glTranslatef(coordinates, 0, 0);
//////	glRotatef(-angleRotate, 0, 1, 0);
//////    head();
//////    body();
////////
//////	
////////
//////	
////////	glFlush();
//////	glutSwapBuffers(); // Khi dã hoàn thành ve khung hình, goi glutSwapBuffers de hien thi(di kem voi che do GLUT_DOUBLE)
//////	glutPostRedisplay();
//////}
//////
//////void ReShape(int width, int height) {
//////	// glViewport(0, 0, width, height);	// thiet lap kích thuoc và vi trí cua viewport, (0,0) la goc trai duoi man hinh
//////	glMatrixMode(GL_PROJECTION);
//////	// GL_MODELVIEW: xác dinh vi trí, huong cua doi tuong trong không gian 3D, nhu di chuyen (translate), quay (rotate), co giãn (scale),...
//////	// GL_PROJECTION:  không gian 3D duoc chuyen doi thành không gian cua so
//////	glLoadIdentity();
//////	float ratio = (float)width / (float)height;
//////	gluPerspective(50.0, ratio, 1, 1000);	// set ma tran chieu phoi canh (Góc mo, scale khung hình, Khoang cách mat toi gan nhat, Khoang cách mat toi xa nhat)
//////	glMatrixMode(GL_MODELVIEW);
//////}
//////
//////void init() {
//////	glClearColor(1.0, 1.0, 1.0, 1.0); // Ðat màu nen thành trang
//////	glEnable(GL_DEPTH_TEST); // kiem tra do sau, de cac doi tuong sau khong de len cac doi tuong truóc
//////	glEnable(GL_LIGHTING);  // Kích hoat che do ánh sáng và vat lieu
//////    glEnable(GL_LIGHT0);    // Kích hoat nguon sáng 0
//////}
//////
//////int main(int argc, char** argv) {
//////	// glClear(GL_COLOR_BUFFER_BIT); // Xóa màn hình và dat màu nen thành den
//////	glutInit(&argc, argv);
//////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//////	glEnable(GLUT_MULTISAMPLE); // on antialiasing
//////    
//////    glutInitWindowPosition(150, 50);
//////    glutInitWindowSize(1000, 600);
//////	
//////	
//////	glutCreateWindow("My Project");
//////	init();
//////	
//////	// Ðang ký các hàm callback de bat su kien bàn phím
//////    glutKeyboardFunc(keyboardCallback);
//////    glutSpecialFunc(specialKeyCallback);
//////	
//////	glutReshapeFunc(ReShape);
//////	glutDisplayFunc(MyDisplay);
//////	glutMainLoop();
//////	
//////	return 0;
//////}
////
////
////
////
//
//
//
//
//
//
//
//
//
//#include <GL/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
///* Kh?i t?o */
//
//GLfloat anpha = 0.0;
//GLfloat beta = 0.0;
//GLfloat x = 0.0;
//GLfloat n = 0.0009;
//GLUquadricObj* p = gluNewQuadric();
//
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glEnable(GL_DEPTH_TEST); // b?t ch?c n?ng cho phép lo?i b? m?t ph?n c?a ??i t??ng b? che b?i ??i t??ng khác
//	//glShadeModel(GL_FLAT);
//
//		// kh?i ??ng ngu?n sáng
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0); //b?t ngu?n sáng light0
//
//	GLfloat mat_ambient[] = { 1.0 ,1.0 ,1.0 ,1.0 }; // 
//	GLfloat mat_diffuse[] = { 1.0 ,1.0 ,1.0 ,1.0 };
//	GLfloat mat_specular[] = { 1.0 ,1.0 ,1.0 ,1.0 };
//	GLfloat mat_shininess[] = { 100.0 };
//
//	GLfloat light_ambient[] = { 0.0 ,0.0 ,0.0 ,1.0 }; // 
//	GLfloat light_diffuse[] = { 0.5 ,0.5 ,0.5 ,1.0 };
//	GLfloat light_specular[] = { 1.0 ,1.0 ,1.0 ,1.0 };
//	GLfloat light_position[] = { 5.0 ,5.0 ,5.0 ,0.0 };
//
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
////	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
////	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//
//
//}
//
////??u
//void head() {
//
//	//tai ph?i
//	glColor3d(0, 1, 0);
//	glPushMatrix();
//	glTranslated(0.2, 2.58, 0);
//	glRotated(-90, 1, 0, 0);
//	glutSolidCone(0.1, 0.5, 4, 4); //2,2
//	glPopMatrix();
//
//	//tai trái
//	glColor3d(0, 1, 0);
//	glPushMatrix();
//	glTranslated(-0.2, 2.58, 0);
//	glRotated(-90, 1, 0, 0);
//	glutSolidCone(0.1, 0.5, 4,4);
//	glPopMatrix();
//
//	//??u
//	glColor3d(209.0 / 255, 209.0 / 255, 209.0 / 255);
//	glPushMatrix();
//	glTranslatef(0, 2, 0);
//	glutSolidCube(1.2);
//	glPopMatrix();
//
//	//m?t ph?i
//	glColor3d(1,1,0);
//	glPushMatrix();
//	glTranslatef(0.3, 2.25, 0.7); //0.18
//	glutSolidSphere(0.14,20,20);
//	glPopMatrix();
//
//	//m?t trái
//	glColor3d(1, 1, 0);
//	glPushMatrix();
//	glTranslatef(-0.3, 2.25, 0.7);
//	glutSolidSphere(0.14, 20, 20); //0.06
//	glPopMatrix();
//
//	//mi?ng
//	glColor3d(1, 0, 1);
//	glPushMatrix();
//	glTranslatef(0, 1.7, 0.6);
//	glScaled(0.8, 0.2, 0.5);
//	glutSolidCube(0.5);
//	glPopMatrix();
//}
//
////c?
//void neck() {
//	//c?
//	glColor3f(1, 0, 0);
//	glPushMatrix();
//	glTranslated(0, 1.35, 0);
//	glScaled(0.6, 0.6, 0.6);
//	glutSolidCube(1);
//	glPopMatrix();
//}
//
////thân
//void body() {
//	//thân
//	glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	glPushMatrix();
//	glTranslated(0, 0.1, 0);
//	glScalef(1, 1.2, 1);
//	glutSolidCube(1.8); //1.7
//	glPopMatrix();
//
//	//? pin
//	glColor3f(126.0 / 255, 163.0 / 255, 227.0 / 255);
//	glPushMatrix();
//	glTranslated(0, 0.5, 0.7);
//	glutSolidCube(0.6);
//	glPopMatrix();
//
//}
//
////tay trái
//void handleft() {
//
//	 //tay
//	glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	glPushMatrix();
//	glTranslatef(-1.25, 0.2, 0); //1.35
//	glScaled(0.35, 1.0, 0.35); //1.2
//	glutSolidCube(1);
//	glPopMatrix();
//
//	//kh?p
//	glColor3d(1, 1, 0);
//	glPushMatrix();
//	glTranslatef(-1.25, -0.37, 0); //0.37
//	glutSolidSphere(0.2, 20, 20); //0.06
//	glPopMatrix();
//
//	//tay
//	glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	glPushMatrix();
//	glTranslatef(-1.25, -1.1, 0); //1.35 , -0.95
//	glScaled(0.35, 1.2, 0.35);//1.0
//	glutSolidCube(1);
//	glPopMatrix();
//
//	////bàn tay
//	glColor3d(1, 1, 0);
//	glPushMatrix();
//	glTranslatef(-1.25, -1.8, 0); //1.2, -1.7
//	glutSolidSphere(0.2, 20, 20); //0.06
//	glPopMatrix();
//}
//
////tay ph?i
// void handright() {
//	 //tay
//	 glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(1.25, 0.2, 0); //1.35
//	 glScaled(0.35,1.0,0.35); //1.2
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //kh?p
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(1.25, -0.4, 0); //-0.35
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//	 //tay
//	 glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(1.25, -1.1, 0); //1.35, -0.95
//	 glScaled(0.35, 1.2, 0.35); //1.0
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 ////bàn tay
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(1.25, -1.8, 0); //1.2, -1.5
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//}
//
////chân trái
// void legleft() {
//	 //?ùi
//	 glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(-0.4, -1.72, 0);
//	 glScaled(0.5, 1.2, 0.5);
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //kh?p
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(-0.4, -2.5, 0); //-2.4
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//	 //chân
//	 glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(-0.4, -3.28, 0); //-3.1
//	 glScaled(0.5, 1.4, 0.5); //1.2
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 ////bàn chân
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(-0.4, -4.1, 0); //-3.8
//	 glScaled(0.5, 0.3, 0.8);
//	 glutSolidSphere(0.6, 20, 20); //0.06
//	 glPopMatrix();
//}
//
////chân ph?i
// void legright() {
//	 //kh?p
//	 //glColor3d(1, 1, 0);
//	 //glPushMatrix();
//	 //glTranslatef(0.4, -0.85, 0);
//	 //glutSolidSphere(0.3, 20, 20); //0.06
//	 //glPopMatrix();
//
//	 //?ùi
//	 glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(0.4,-1.72,0);
//	 glScaled(0.5, 1.2, 0.5);
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //kh?p
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	glTranslatef(0.4, -2.5, 0); //
//	glutSolidSphere(0.2, 20, 20); //0.06
//	glPopMatrix();
//
//	//chân
//	glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	glPushMatrix();
//	glTranslatef(0.4, -3.28, 0); //
//	glScaled(0.5, 1.4, 0.5); //1.2
//	glutSolidCube(1);
//	glPopMatrix();
//
//	 //bàn chân
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(0.4, -4.1, 0); //
//	 glScaled(0.5, 0.3, 0.8);
//	 glutSolidSphere(0.6, 20, 20); //0.06
//	 glPopMatrix();
//
// }
//
// void robot() {
//	 head();
//	 neck();
//	 body();
//
//	 ////kh?p tay trái
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(-1, 0.8, 0);
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//	 ////kh?p tay ph?i
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(1, 0.8, 0);
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//	 //kh?p chân trái
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(-0.4, -0.85, 0);
//	 glutSolidSphere(0.3, 20, 20); //0.06
//	 glPopMatrix();
//
//	 //kh?p chân ph?i
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(0.4, -0.85, 0);
//	 glutSolidSphere(0.3, 20, 20); //0.06
//	 glPopMatrix();
// }
//
// //tay gaapj
// void taygapphai() {
//	 //tay
//	 glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(1.25, 0.2, 0); //1.35
//	 glScaled(0.35, 1.0, 0.35); //1.2
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //kh?p
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(1.25, -0.35, 0);
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
//	 //tay
//	 glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(1.25, -0.6, 0.6); //1.35
//	 glRotatef(90, 1, 0, 0);
//	 glScaled(0.35, 1.2, 0.35); //1.0
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //bàn tay
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(1.25, -0.6, 1.25); //1.2
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
//
// }
//
// //chân ph?i
// void chanphai() {
//	 //?ùi
//	 glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(0.4, -1.72, 0);
//	 glScaled(0.5, 1.2, 0.5);
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //kh?p
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(0.4, -2.4, 0); //
//	 glutSolidSphere(0.2, 20, 20); //0.06
//	 glPopMatrix();
// }
//
// //kh?p chân
// void khopchanphai() {
//	 //chân
//	 glColor3f(128.0 / 255, 128.0 / 255, 128.0 / 255);
//	 glPushMatrix();
//	 glTranslatef(0.4, -3.1, 0); //
//	 glScaled(0.5, 1.4, 0.5); //1.2
//	 glutSolidCube(1);
//	 glPopMatrix();
//
//	 //bàn chân
//	 glColor3d(1, 1, 0);
//	 glPushMatrix();
//	 glTranslatef(0.4, -3.8, 0); //
//	 glScaled(0.5, 0.3, 0.8);
//	 glutSolidSphere(0.6, 20, 20); //0.06
//	 glPopMatrix();
//
//}
//
//
// void dichuyen(void)
// {
//	 static float mf = 0.05;
//
//	 beta += mf;
//
//	 if (beta > 17.0) { //15
//		 mf = -0.1;
//	 }
//	 if (beta < -17.0) { //-5
//		 mf = 0.10;
//	 }
//	 
//	 glutPostRedisplay();
// }
// 
///* hàm v? */
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	robot();
//
//	glPushMatrix();
//	//robot();
////	glRotatef(beta, 1, 0, 0);
////	//taygap();
////	glPopMatrix();
////
////	glPushMatrix();
////	glTranslated(0, anpha, 0.0);
//	
//	anpha += n;
//	if (anpha <=-0.5) {
//		n = 0.0009;
//	}
//	else if (anpha >=0.25) {
//		n = -0.0009;
//	}
//	//glRotated(-beta, 1.0, 0.0, 0.0f);
////	robot();
////	//body();
////	legleft();
////	legright();
//
//	//tay trái
//	glPushMatrix();
//	//glTranslated(-0.30, 1.0, 0.0);
//	////glRotated(-120, 1, 0, 0);
//	//glRotated(beta, 1.0, 0.0, 0.0f);
//	//glTranslated(0.30, -1.0, 0.0);
//	glTranslated(-2.5, 1, 0.0);
//	glRotated(-160, 0, 0, 1);
//	glRotated(-beta, 1.0, 0.0, 0.0f);
//	handleft(); 
//	glPopMatrix();
//
//	//tay ph?i
//	glPushMatrix();
//	//glTranslated(2.5, 1, 0.0);
//	//glRotated(160, 0, 0, 1);
//	glTranslated(0, 0.2, 0);
//	glRotated(-beta, 1.0, 0.0, 0.0f); //-beta, 1.0, 0.0, 0.0f
//	//glTranslated(-0.30, -1.0, 0.0);
//	handright();
//	glPopMatrix();
//	glPopMatrix();
//	//chân trái
//	glPushMatrix();
//	glRotated(-beta, 1.0, 0.0, 0.0f);
//	legleft();
//	glPopMatrix();
//
//	//chân ph?i
//	glPushMatrix();
//	glRotated(beta, 1.0, 0.0, 0.0f);
//	legright();
//	glPopMatrix();
//
////	di chuyeenr
////	glPushMatrix();
////	glRotatef(beta, 1, 0, 0);
////	legleft();
////	glPopMatrix();
////	glPushMatrix();
////	glRotatef(-beta, 1, 0, 0);
////	legright();
////	glPopMatrix();
//
//	//	xoay ??u
////	glPushMatrix();
////	glRotatef(-beta, 0, 0, 1);
////	head();
////	neck();
////	glPopMatrix();
//
//	glFlush();
//}
///* x? lý khi c?a s? b? thay ??i */
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); // thay ??i kích th??c viewport
//	/* xét thao tác trên chi?u */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // th?c hi?n phép chi?u ph?i c?nh
//	/* xét thao tác trên ModelView */
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 4, 10,0, 0, 0, 0, 10, 0);
//
//
//}
//int main(int argc, char** argv)
//{
//	//tao vi tri
//	glutInit(&argc, argv);               //thiet lap che do do hoa, ktra man hinh
//	glutInitDisplayMode(GLUT_RGB);			//thiet lap mo hinh hien thi
//	glutInitWindowSize(800, 800);			//thiet lap kich co cua so hien thi
//	glutInitWindowPosition(0, 0);			//......... vi tri hien thi
//	//tao cua so
//	glutCreateWindow("Bai Tap Lon");	//tao 1 cua so
//	init();
//	glutDisplayFunc(display);
//	glutIdleFunc(dichuyen); //
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}
