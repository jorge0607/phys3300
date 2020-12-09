#include "GGBody.h"
/* aqui en esta seccion para que el cuerpo tenga un movimiento en vord se pone posicion,velocidad y fuerza  y aqui 
tambien se vera  declara la masa y lo inverso para que se vea como se usa para se usa el engine en algi¿un problema con la fisica
ya resuelta*/
GGBody::GGBody()
{
	position.setZero();

	velocity.setZero();

	force.setZero();

	mass = 1.0f;
	invMass = 1.0f; /* 1/mass */
}
/* aqui va la funcion de agregar fueza al cuerpo si es necesario ya declarado*/
void GGBody::addForce(const vec2D& f)
{
	force += f;
}
/* aqui se como lamasa que agregas y como se veria si fuera reciproca a esta que sera constante pero depende como quiere que
 sea el cuerpo*/
void GGBody::setMass(const float& m)
{
	mass = m;
	invMass = 1 / m;
}
/* aqui se ve como el cuerpo luegode haber declarado todo y puesto masa,ect. Este se aplica al world que luego hace que se vea como
un cuerpo tiene masa,pos,ect.*/
void GGBody::displayBodyInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "Inv mass: " << invMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;
}