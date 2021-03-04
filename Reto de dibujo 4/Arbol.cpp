#include "Arbol.h"

int numSeg = 5;

Arbol::Arbol(){

}

void Arbol::dibujar(float x, float y, float z){
	glPushMatrix();
		glTranslatef(x, y, z);

		//Cola
		glPushMatrix();
			glRotatef((GLfloat)30, 0.0, 0.0, 1.0);
			glTranslatef(0.25, 0.0, 0.0);

			glPushMatrix();
				glScalef(0.5, 0.4, 1.0);
				glutSolidCube(1.0);
			glPopMatrix();

			//Cola
			for (int i = 0; i < numSeg + 4; ++i) {
				glTranslatef(0.25, 0.0, 0.0);
				glRotatef((GLfloat)10, 0.0, 0.0, 1.0);
				glTranslatef(0.25, 0.0, 0.0);

				glPushMatrix();
				glScalef(0.5, 0.4, 1.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}

			/*for (int i = 0; i < numSeg + 6; ++i) {
				glTranslatef(0.0, -0.5, 0.0);
				glRotatef((GLfloat)15, 0.0, 0.0, 1.0);
				glTranslatef(0.0, -0.5, 0.0);

				glPushMatrix();
				glScalef(1.0, 0.4, 1.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}*/

			//Punta de la cola
			glPushMatrix();
			glTranslatef(0.5, 0.0, 0.0);
			for (int i = 0; i < numSeg; ++i) {
				glTranslatef(-0.5, 0.0, 0.0);
				glRotatef((GLfloat)210, 0.0, 0.0, 1.0);
				glTranslatef(-0.5, 0.0, 0.0);

				glPushMatrix();
				glScalef(2.0, 0.4, 1.0);
				//glutWireCube(1.0);
				glutSolidCube(1.0);
				glPopMatrix();
			}
			glPopMatrix();
		glPopMatrix();

		//Cuerpo
		glPushMatrix();
			//Torso
			glPushMatrix();
				glTranslatef(-3, 0, 0);
				glScalef(1, 0.5, 1);
				//glutWireSphere(3, 20, 20);
				glutSolidSphere(3, 20, 20);
			glPopMatrix();

			//Cabeza
			glPushMatrix();
				glTranslatef(-7, 0, 0);

				//Cabeza
				glPushMatrix();
					glutSolidSphere(1, 20, 20);
				glPopMatrix();

				//Orejas
				glPushMatrix();
					glTranslatef(0, 0.75, 0);

					//Oreja del frente
					glPushMatrix();
						glTranslatef(0, 0, 1);
						glBegin(GL_TRIANGLES);
							glVertex3d(-0.5, 0,0);
							glVertex3d(0.5,0,0);
							glVertex3d(0, 0.5*sqrt(3), 0);
						glEnd();
					glPopMatrix();

					//Oreja de atras
					glPushMatrix();
						glTranslatef(0, 0, -1);
						glBegin(GL_TRIANGLES);
							glVertex3d(-0.5, 0, 0);
							glVertex3d(0.5, 0, 0);
							glVertex3d(0, 0.5 * sqrt(3), 0);
						glEnd();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//glutSolidCube(3.0);
	glPopMatrix();
}

Arbol::~Arbol(){}