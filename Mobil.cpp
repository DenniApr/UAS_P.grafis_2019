#include <windows.h>
#include <GL/glut.h>
#include <math.h>


GLUquadric *q = gluNewQuadric();
GLfloat camY = 0.0;
GLfloat camX = 0.0;
GLfloat camZ = 0.0;
GLfloat angle = 1;
GLfloat direction = 1;

void cylinder(float alas,float atas,float tinggi);
void kerucut(float ngisor, float nduwur, float dowo);
void blok(float tebal,int ratiol,int ratiop);

GLfloat  source_light[]={0.30,0.30,0.30,0.50};
double Loop,LoopAll=0;



void Mobil(void)
{
 glClearColor(0.0,0.0,0.0,0.0);  //blackground
 glShadeModel(GL_SMOOTH);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(50.0,1.5,10.0,1000.0);

 glEnable  (GL_DEPTH_TEST);
 glPolygonMode   (GL_FRONT_AND_BACK,GL_FILL);
 glEnable  (GL_LIGHTING);
 glLightfv  (GL_LIGHT7,GL_DIFFUSE,source_light);
 glEnable  (GL_LIGHT7);
 glEnable  (GL_COLOR_MATERIAL);
 glColorMaterial (GL_FRONT_AND_BACK,GL_AMBIENT);

}



void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


  glTranslatef(1,1,-100);// besar kecilnya mobil

  Loop++;
     glRotatef(Loop*camZ*camX*direction,0.10,6.0,0.8);//mobil berotasi

 glPushMatrix();//body
 //glpushmatrix();
 glColor3f(1.0,0.0,1.0);
 blok(10, 3, 2);

 glTranslatef(0, 9, 0);
 blok(10, 3, 2);
 glTranslatef(10, -10,0);
 blok(10, 5.5, 2);
 glRotatef(-35, 0, 0, 15);
 glTranslatef(0, 7,0);
 blok(10, 2, 2);
 glTranslatef(2, 4.9,-2.5);
 glColor3f(0.9,0.9,0.9);// warna kaca
 blok(0.5, 20, 31);

 glRotatef(180, 45, -45, 0);
 //glTranslatef(0, 10,0);
 //blok(3, 2, 5);
 //cylinder(2,2,30);CB
 //glTranslatef(-10, -10,0);
 //glRotatef(90, 45,-45, 0);
 //cylinder(2,2,30);
 //glRotatef(90, -45, 90, 90);
 //blok(5, 3, 2);

 glPopMatrix();


 glPushMatrix();//roda
 glColor3f(0.0,0.0,0.0);
 glTranslatef(20, -8,-7);
 cylinder(5, 5,3);

 glColor3f(0.0,0.0,0.0);
 glTranslatef(-20, 8,7);
 glTranslatef(-5, -8,-7);
 cylinder(5, 5,3);

 glColor3f(0.0,0.0,0.0);
 glTranslatef(5, 8,7);
 glRotatef(180,0,180,0);
 glTranslatef(3,-8,-17);
 cylinder(5, 5,3);

 glColor3f(0.0,0.0,0.0);
 glTranslatef(-3,8,17);
 glTranslatef(-22,-8,-17);
 cylinder(5, 5,3);

 glColor3f(1.0,1.0,1.0);

 glRotatef(90,1,0,0);
 glTranslatef(8, 2.5,-15);
 blok(2, 4, 5);


 glRotatef(90,0,1,0);
 glTranslatef(0,-0.2,7);
 blok(2, 4, 8);


 glRotatef(0,0,0,0);
 glTranslatef(0,19.2,0);
 blok(2, 4, 8);

 glRotatef(90,0,1,0);
 glTranslatef(7, 0,-8);
 blok(2, 4, 5);

 glColor3f(9.9,9.9,0.0);//lampu
 glRotatef(90,0,1,0);
 glTranslatef(0,-3,20);
 cylinder(2, 2,3);

 glColor3f(9.9,9.9,0.0);//lampu
 glRotatef(0,0,0,0);
 glTranslatef(0,-12,0);
 cylinder(2, 2,3);

 glColor3f(0.0,0.0,0.0);//knalpot
 glRotatef(0,0,0,0);
 glTranslatef(0,0,-52);
 cylinder(1, 1,3);

 glColor3f(1.0,1.0,1.0);
 glRotatef(90,1,0,0);
 glTranslatef(-8,3.5,-12);
 blok(2, 4, 8);

 glColor3f(9.0,0.0,0.0);//lampu atas
 glRotatef(0,0,0,0);
 glTranslatef(-8,28,0);
 cylinder(1, 1,12);


 glPopMatrix();


 glFlush();
 glutSwapBuffers();

}

void kerucut(float ngisor, float nduwur, float dowo)
{
 float i;
 glPushMatrix();
 glTranslatef(1.0,0.0,ngisor/24);
 glutSolidCone(ngisor,0,32,4);
 for(i=0;i<=dowo;i+=ngisor/24)
 {
  glTranslatef(0.0,0.0,ngisor/24);
  glutSolidTorus(ngisor/4,ngisor-((i*(ngisor-nduwur))/dowo),16,16);
 }
 glTranslatef(0.0,0.0,ngisor/4);
 glutSolidCone(nduwur,0,20,1);
 glColor3f(0.,1.,1.);
 glPopMatrix();
}
void cylinder(float alas,float atas,float tinggi)
{
 float i;
 glPushMatrix();
 glTranslatef(1.0,0.0,-alas/8);
 glutSolidCone(alas,0,32,4);
 for(i=0;i<=tinggi;i+=alas/24)
 {
  glTranslatef(0.0,0.0,alas/24);
  glutSolidTorus(alas/4,alas-((i*(alas-atas))/tinggi),16,16);
 }
 glTranslatef(0.0,0.0,alas/4);
 glutSolidCone(atas,0,20,1);
 glColor3f(1.,0.,0.);
 glPopMatrix();
}

void blok(float tebal,int ratiol,int ratiop)
{
 float i,j;
 glPushMatrix();
 for(i=0;i<ratiop;i++)
 {
  glTranslatef(-(ratiol+1)*tebal/2,0.0,0.0);
  for(j=0;j<ratiol;j++)
  {
   glTranslatef(tebal,0.0,0.0);
   glutSolidCube(tebal);
  }
  glTranslatef(-(ratiol-1)*tebal/2,0.0,tebal);
 }
 glPopMatrix();
}
void tampil()
{
 display();
}

void timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(15, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyControl(int k, int x, int y)
{
  switch(k) {
    case GLUT_KEY_UP: camZ --; break;
    case GLUT_KEY_DOWN: camZ ++; break;
    case GLUT_KEY_LEFT: camX --; break;
    case GLUT_KEY_RIGHT: camX ++; break;
  }
}

void mouseControl(int button, int state, int x, int y)
{
  switch(button) {
    case GLUT_LEFT_BUTTON: direction = -direction; break;
  }
}


int main(int argc,char **argv)
{


 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);//|GLUT_DEPTH);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(1000,700);
 glutCreateWindow("Mobil");
 glClearColor(0.5,0.5,0.0,0.0);
 glutDisplayFunc(display);
 glutTimerFunc(0, timer, 0);
 glutSpecialFunc(keyControl);
 glutMouseFunc(mouseControl);
 gluOrtho2D(-320., 320., -240.0, 240.0);
 glutIdleFunc(tampil);
 Mobil();
 glutMainLoop();
 return(0);
} 
