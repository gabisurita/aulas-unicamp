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


static int camera = 0;


void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}


void display(void) {
   glClear (GL_COLOR_BUFFER_BIT);

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,1.0f,0.0f);
   glutWireSphere(1.0, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,0.0f,0.0f);
   glTranslated(0.0,-1.2,-1);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,1.0f,1.0f);
   glTranslated(0.0,1.2,1);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(0.0f,1.0f,1.0f);
   glTranslated(0.0,-1,1.2);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(0.0f,0.0f,1.0f);
   glTranslated(0.0,1,-1.2);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix(); 



   glutSwapBuffers();
}


void reshape (int w, int h) {
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   //glViewport (0, 0,w/1.5,h); // ex1
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   //gluPerspective(60.0, 2*w/h, 1.0, 20.0); // ex 2
   //gluPerspective(90.0, w/h, 1.0, 20.0); //ex 3
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void keyboard (unsigned char key, int x, int y) {
   switch (key) {
      case 'c':
         camera = (camera + 10) % 360;
         break;
      case 'C':
         camera = (camera - 10) % 360;
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
