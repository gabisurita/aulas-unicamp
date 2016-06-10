

#if __APPLE__
   #include <GLUT/glut.h>
   #include <OpenGL/gl.h>
   #include <OpenGL/glu.h>
#else
   #include <GL/glut.h>
   #include <GL/gl.h>
   #include <GL/glu.h>
#endif


static int camera_vertical = 0;
static int camera_horizontal = 0;


void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void bolinha (float r, float g, float b, float radius){

   glRotatef ((GLfloat) camera_horizontal, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) camera_vertical, 1.0, 0.0, 0.0);
   glColor3f(r,g,b);
   glutWireSphere(radius, 20, 16);

}


void display(void) {
   glClear (GL_COLOR_BUFFER_BIT);

   glPushMatrix();
   bolinha(1.0,1.0,0.0, 1.0); /* amarela */
   glTranslatef(0.0, 0.0, 1.6);  
   bolinha(1.0, 0, 0, 0.4); /*vermelho*/
   glTranslatef(0.0, 0.2, 3.2);  
   bolinha(0, 0, 1, 0.4); /*azul*/

   glTranslatef(0, 0, 3.2);  
   bolinha(1, 1, 1, 0.4); /*branca*/
   glTranslatef(0, 0, 1.6);  
   bolinha(0, 1, 1, 0.4); /*ciano*/


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
         camera_vertical = (camera_vertical + 10) % 360;
         break;
      case 's':
         camera_vertical = (camera_vertical - 10) % 360;
         break;
      case 'a':
         camera_horizontal = (camera_horizontal + 10) % 360;
         break;
      case 'd':
         camera_horizontal = (camera_horizontal - 10) % 360;
         break;
      default:
         return;
   }
   glutPostRedisplay();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   glutInitWindowPosition (500, 100);
   glutCreateWindow (argv[0]);

   init();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);

   glutKeyboardFunc(keyboard);

   glutMainLoop();
   
   return 0;
}
