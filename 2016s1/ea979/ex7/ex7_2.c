/*
 * minimal.c
 *
 *  Created on: 01/05/2013
 *      Author: valle
 */

// gcc minimal_exe6.c -o test -lGL -lGLU -lglut
// ./test


#if __APPLE__
   #include <GLUT/glut.h>
   #include <OpenGL/gl.h>
   #include <OpenGL/glu.h>
#else
   #include <GL/glut.h>
   #include <GL/gl.h>
   #include <GL/glu.h>
#endif

#include <stdlib.h>
#include <math.h>

static int cameraX = -90;
static int cameraY = 0;
static int cameraZ = 0;


void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}


void sen3dz(
            float xi, float yi, 
            float xf, float yf, 
            float dx, float dy, 
            float A, float f){
    
     glBegin(GL_QUAD_STRIP); 
     for (float x=xi; x<=xf; x+=dx) { 
       
       float z = A*sin(f*x);
       glVertex3d(x, yi, z);
        
       z = A*sin(f*x+dx);
       glVertex3d(x+dx, yf, z); 
     }
     glEnd();
}


void cylinder(int n, float mult, float v) {

    glBegin(GL_QUAD_STRIP);
      for(int i = 0; i < 480; i += (360 / n)) {
        float a = i * M_PI / 180;
        glVertex3f(mult * cos(a), mult * sin(a), 0.0);
        glVertex3f(mult * cos(a), mult * sin(a), v);
      }
    glEnd();
}
 
void cone(int n, float mult, float v) {

    glBegin(GL_TRIANGLES);
      for(int i = 0; i < 480; i += (360 / n)) {
        float a = i * M_PI / 180;
        float b = (i+(360 / n)) * M_PI / 180;
        glVertex3f(mult * cos(a), mult * sin(a), 0.0);
        glVertex3f(mult * cos(b), mult * sin(b), 0.0);
        glVertex3f(0, 0, v);
      }
    glEnd();
}




void display(void) {
   
   glClear (GL_COLOR_BUFFER_BIT);
    
    
   // Grama
   glPushMatrix();
   glRotatef(cameraX, 1.0, 0.0, 0.0);
   glRotatef(cameraY, 0.0, 1.0, 0.0);
   glRotatef(cameraZ, 0.0, 0.0, 1.0);
   glColor3f(0.0, 0.6, 0.0);
   glTranslated(0,0,-1);
   sen3dz(-50,-50,50,50,.01,.01,.03,10);
   glPopMatrix();    

    // Estrela
   glPushMatrix();
   glRotatef(cameraX, 1.0, 0.0, 0.0);
   glRotatef(cameraY, 0.0, 1.0, 0.0);
   glRotatef(cameraZ, 0.0, 0.0, 1.0);
   glColor3f(1.0, 1.0, 0.5);
   glTranslated(5,8,8);
   cone(16,.1,.5);
   glRotatef(180,1.,1.,0.);
   cone(16,.1,.5);
   glRotatef(180,0.,1.,1.);
   cone(16,.1,.5);
   glRotatef(180,0.,1.,1.);
   cone(16,.1,.5);
   glRotatef(180,1.,1.,0.);
   cone(16,.1,.5);
   glRotatef(180,1.,1.,0.);
   cone(16,.1,.5);
   glRotatef(180,1.,0.,1.);
   cone(16,.1,.5);
   glRotatef(180,1.,0.,1.);
   cone(16,.1,.5);
   glPopMatrix();   
 
   // Foguete  
   glPushMatrix();
   glRotatef(cameraX, 1.0, 0.0, 0.0);
   glRotatef(cameraY, 0.0, 1.0, 0.0);
   glRotatef(cameraZ, 0.0, 0.0, 1.0);
   glColor3f(1.0, 0.8, 0.8);
   glTranslated(0,2,-1);
   cylinder(32,.3,2);
   glTranslated(0,0,2);
   cone(32,.3,2);
   glPopMatrix();  

 
   glutSwapBuffers();
}


void reshape (int w, int h) {
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void keyboard (unsigned char key, int x, int y) {
   switch (key) {
      case 'w':
         cameraX = (cameraX + 1) % 360;
         break;
      case 's':
         cameraX = (cameraX - 1) % 360;
         break;
      case 'a':
         cameraY = (cameraY + 1) % 360;
         break;
      case 'd':
         cameraY = (cameraY - 1) % 360;
         break;
      case 'q':
         cameraZ = (cameraZ + 1) % 360;
         break;
      case 'e':
         cameraZ = (cameraZ - 1) % 360;
         break;
      default:
         return;
   }
   glutPostRedisplay();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);

   init();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   
   return 0;
}
