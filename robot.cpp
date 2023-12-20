#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <unistd.h> 

#define SIZE_SPACE 500.0
#define PI 3.14159265359

#define ANGLE_MOVE_LEGS 40
#define ANGLE_MOVE_ARMS 40

GLfloat anpha = 0.0;
GLfloat beta = 0.0;
GLfloat x = 0.0;
GLfloat n = 0.00009;
GLUquadricObj* p = gluNewQuadric();

float robotRotation = 0;

//khoi tao 3D
void init(void){

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	
	// Áp dung chieu sáng
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {0.8, 0.3, 0.8, 0.8};

    // Chat lieu màu hong nhat
    GLfloat robot_diffuse_color[] = {0.5, 0.3, 0.5, 0.3}; // Màu tim nhat
    GLfloat robot_specular_color[] = {0.5, 0.5, 0.5, 0.5}; // Màu tim nhat

    glMaterialfv(GL_FRONT, GL_DIFFUSE, robot_diffuse_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robot_specular_color);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}

void dichuyen(void){
	static float mf = 0.5;
	beta += mf;
	if(beta > 17.0){
		mf = -0.3;
		
	}
	if(beta < -17.0){
		mf = 0.30;
	}
	glutPostRedisplay();
}

void vetruc() {
glLineWidth(1);
	glPushAttrib(GL_LIGHTING_BIT); // Luu trang thái ánh sáng và vat lieu hien tai
    glDisable(GL_LIGHTING); // Tat ánh sáng de ve truc

    glLineWidth(1);
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(-2 * SIZE_SPACE, 0.0, 0.0);
    glVertex3f(SIZE_SPACE, 0.0, 0.0);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -2 * SIZE_SPACE, 0.0);
    glVertex3f(0.0, SIZE_SPACE, 0.0);
    glEnd();
    

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -2 * SIZE_SPACE);
    glVertex3f(0.0, 0.0, SIZE_SPACE);
    glEnd();

    glPopAttrib(); // Khôi phuc trang thái ánh sáng và vat lieu truc dây
}


void than(){
	//Ve than
	glPushMatrix(); //chèn vào ngan xep
	glColor3f(0.0, 0.5, 0.0); 
	glTranslatef(0.0,0.0,0.0);
	glScalef(4.0, 5.0, 4.0);
    glutSolidCube(1.0);
    glPopMatrix(); // xoá trong ngan xep
	
}
void dau(){
	//Ve dau
	glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(0.0, 4.5 , 0.0);
//	glRotatef(beta, 1, 0, 0);
	glScalef(6.0, 4.0, 6.0);
    glutSolidCube(1.0);
    glPopMatrix(); 
    
    
    //mat phai
    glPushMatrix(); 
	glColor3f(0.0, 0.0, 0.0); 
	glTranslatef(1.5, 5.0 , 3.25);
    glutSolidSphere(0.4, 100, 100);
    glPopMatrix(); 
    
    //mat trai
    glPushMatrix(); 
	glColor3f(0.0, 0.0, 0.0); 
	glTranslatef(-1.5, 5.0 , 3.25);
    glutSolidSphere(0.4, 100, 100);
    glPopMatrix(); 
    
    //Ve mieng
    glPushMatrix(); 
    glColor3f(0.0, 0.0, 0.0); 
	glTranslatef(0.0, 3.5 , 3.0);
	glScalef(1.7, 0.3 , 1.0);
    glutSolidCube(1.0);
    glPopMatrix(); 
    
}

void tayphai(){
	
	//ve tay phai
	glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(4.2, 1.5 , 0.0);
	//glRotatef(90, 0, 0, 1);
	glScalef(3.75, 1.5, 1.5);
    glutSolidCube(1.0);
    glPopMatrix(); 
       
}

void taytrai(){	
	//ve tay trai
	glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(-4.2, 1.5 , 0.0);
	//glRotatef(90, 0, 0, 1);
	glScalef(3.75, 1.5, 1.5);
    glutSolidCube(1.0);
    glPopMatrix(); 
 
}

void chanphai(){
	//chan phai
    glPushMatrix();
    glTranslatef(1.0, -4.5, 0.0);
    glScalef(1.5, 4.0, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    //Ve giay phai
    glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(1.0, -6.5, 0.0);
	glScalef(1.5, 1.0, 2.0);
    glutSolidSphere(1.0, 100, 100);
    glPopMatrix(); 	
}

    
void chantrai(){
	//chan trai
    glPushMatrix();
    glTranslatef(-1.0, -4.5, 0.0);
    glScalef(1.5, 4.0, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    //Ve giay trai
    glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(-1.0, -6.5, 0.0);
	glScalef(-1.5, 1.0, 2.0);
    glutSolidSphere(1.0, 100, 100);
    glPopMatrix(); 
}

void drawRobot(){
glPushMatrix();
	//Ve dau
	dau();
	
	//Ve than
	than();
	
    //Ve hoa phai: 
    glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(5.0, 6.5 , 0.0);
    //glRotatef(-90, 0, 1, 0);
    glLineWidth(2); // Tang do day duong cong
    glBegin(GL_LINE_STRIP); // Ve duong cong
    for (float x = 0; x >= M_PI; x -= 0.1) { 
        float y = sin(-x);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glutSolidSphere(0.5, 100, 100); //Ve khoi cau dac
    glPopMatrix(); 
    
    //Ve hoa trai
    glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(-5.0, 6.5 , 0.0);
	glRotatef(180, 0, 1, 0);
    glLineWidth(2); 
    glBegin(GL_LINE_STRIP);
    for (float x = 0; x >= -M_PI; x -= 0.1) { 
        float y = sin(-x);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix(); 
        
    //Ve tay
//	tayphai();
//	taytrai();
	
	//Ve khop tay phai
	glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(2.0, 1.5 , 0.0);
    glutSolidSphere(0.8, 100, 100);
    glPopMatrix();  
    
    //Ve khop tay trai
	glPushMatrix(); 
	glColor3f(0.0, 0.6, 0.0); 
	glTranslatef(-2.0, 1.5 , 0.0);
    glutSolidSphere(0.8, 100, 100);
    glPopMatrix();  

    //Ve chan
//	chantrai();
//	chanphai();
       
glPopMatrix();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	vetruc();

	glRotatef( robotRotation, 0.0, 1.0, 0.0); //Quay robot quanh truc oy


    // Ve con robot
    drawRobot();
    
    //Ve tay trai
	glPushMatrix();
	glRotated(beta, 0.0, 1.0, 0.0f);
	taytrai();
	glPopMatrix();
    
    //Ve tay phai
	glPushMatrix();
	glRotated(beta, 0.0, 1.0, 0.0f);
	tayphai();
	glPopMatrix();
    
    
    //Ve va di chuyen chan trai
    glPushMatrix();
	glRotated(-beta, 1.0, 0.0, 0.0f);
	chantrai();
	glPopMatrix();

    //Ve va di chuyen chan phai
    glPushMatrix();
	glRotated(beta, 1.0, 0.0, 0.0f);
	chanphai();
	glPopMatrix();
	
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Bam nut chuot phai
        robotRotation += 25.0; // Tang goc len 25 do
    }

    glutPostRedisplay(); // Yeu cau ve lai anh
}


void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv){
	
  	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
	init();
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutIdleFunc(dichuyen); 
    glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
    
    glutMainLoop();

    return 0;
}

















