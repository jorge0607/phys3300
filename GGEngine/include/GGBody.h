#ifndef GGBODY_H
#define GGBODY_H

#include "GGMath.h"

struct GGBody
{

	/* aqui se declara la construccion de esta clase */
	GGBody();

	/* aqui se declara la masa del cuerpo y vicerversa. Ejemplo que un cuerpo pese 2.50  */
	float mass;
	float invMass;

	/* aqui se declara la posicion del cuerpo pero esto es lineal porque va una sola direccion. ejemplo que el cuerpo este
	 en la posicion x= 3.4 y y=5.0*/
	vec2D position;

	/* aqui se declara una velocidad lineal ya que aunque haya dos o mas puede ser diferemte de un cuerpo y cambia 
	la masa en una posicion x y y. ejemplo que un cuerpo tenga una posicion x,y v= 3.40 y otro que tenga  */
	vec2D velocity;

	/* aqui se declara la fuerza por las leyes de newton y su fisca para poder comprender  que fuerza es necesaria para que ocurra
     algo.*/
	vec2D force;

	/* aqui se añaden fuerza si es necesaria segun la tercera ley de newton que dice que toda accion tiene una reaccion */
	void addForce(const vec2D& f);

	/* aqui se agrega una masa constante  que debe un cuerpo tener aunque varia dependiendo de lo quiere verse fisicamente */
	void setMass(const float& m);

	/* aqui se pude verse la informacion necesaria para que pueda verse, velocidad, masa , fuerza , posicion , ect.*/
	void displayBodyInfo();

};

#endif

