#include "GGWorld.h"

int main()
{
	/*aqui se habla de el mundo y el cuerpo se relacionan de manera que hablando fisicamente aqui se de 
	la velocidad en la que se mueve en posicion y de aho tambien va a la velocidad que va. ejemplo: un cuerpo que va cayendonse
	con la gravedad */
	GGWorld firstSimulation(vec2D(0.0f, 9.81f));
	GGBody firstBody;
	GGBody secondBody;
	secondBody.position = vec2D(5.0f, 10.0f);
	secondBody.velocity = vec2D(7.5f, 3.8f);
	/* aqui se añade los cuerpos a la pantalla*/
	firstSimulation.addBody(&firstBody);
	firstSimulation.addBody(&secondBody);
	/* aqui va el tiempo que ocurre con el cada frame que ocurre y el contandor hace que empieze desde cero hasta que se mueva o caiga
	 depediendo de como quiere imaginarse el cuerpo que lo programe.*/
	float frameTime = 0.5f; 
	int counter = 0;
	/* aqui va el contador  de la veces que puede ocurrir  y te dice que esta haciendo el cuerpo especificamente durante el tiempo
	de los frame*/
	while (counter < 10) {
		firstBody.displayBodyInfo();
		secondBody.displayBodyInfo();
		firstSimulation.Step(frameTime);
		counter++;
	}

	return 0;
}