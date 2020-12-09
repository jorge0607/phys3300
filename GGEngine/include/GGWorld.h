#ifndef GGWORLD_H
#define GGWORLD_H

#include "GGBody.h"
#include <vector>

struct GGWorld
{
	/* aqui construimos el constructor del world */
	GGWorld() {}
	GGWorld(vec2D gravity) : gravity(gravity) {}

	/* aqui se declara la gravedad del cuerpo que ocurre en el world*/
	vec2D gravity;

	/*Declaramos un vector que contenga todos los cuerpos en este world y ademas se agjunta con la gravedad para que todos 
	y cada uno de los cuerpos*/
	std::vector<GGBody*> bodies;

	/* aqui ocurre que todos los cuerpos se establezcan con la gravedad que le ponga el progrmador para que tengan una gravedad
	 que los tengan todos y por esa razon es constante.*/
	void setGravity(const vec2D& g);

	/* aqui hace la funcion de agregar un cuerpo mas en el programa*/
	void addBody(GGBody* b);

	// Creamos la función Step. Esta es la encargada de la simulación.
	void Step(float dt); //El dt suele ser el tiempo que toma pasar de un frame al otro. 

};

#endif




