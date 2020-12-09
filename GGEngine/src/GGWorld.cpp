#include "GGWorld.h"
/* aqui se declara la gravedad en este caso es g lo que hce que tenga un valor y asi mismo esto se vera afectado cuando entre
al mundo de forma tal que la gravedad hace que caiga o sube dependiendo de las leyes de newton que se necesario aplicar.*/
void GGWorld :: setGravity(const vec2D& g)
{
	gravity = g;
}
/* aqui se agrega un cuerpo al mundo de tal forma que la pantalla se vea el cuerpo o los cuerpos que quieras ya cuando declares tu 
gravedad , velocidad que se use , entre otros.*/
void GGWorld::addBody(GGBody* b)
{
	bodies.push_back(b);
}
/* aqui se ve el cuerpo como afecta por el frame time que depende de como el cuerpo se maneja y luego gracias  de uqe se haya hecho lo
necesario que se mueva con la gravedad,ect y luego se hace o mismo pero solo con posicion  y velocidad, aplicando las leyes de la
 seegunda y tercera de newton para quese mueva con la velocidad del frame time que se mueva el cuerpo con el world*/
void GGWorld::Step(float dt)
{
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]->force.x * bodies[counter]->invMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->invMass) * dt;
	}

	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x += bodies[counter]->velocity.x * dt;
		bodies[counter]->position.y += bodies[counter]->velocity.y * dt;

		bodies[counter]->force.setZero();
	}
