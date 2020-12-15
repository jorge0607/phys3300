#include <Box2D/include/box2d.h>
#include "Game.h"

int main(int argc, char* args[])
{
	const float FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime = 0.0f;

	Game* game = nullptr;
	game = new Game();
	game->init("Demo-Box2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, false);

	/*
		PIXEL PER METER VALUE
	*/

	float ppm = 64.0f;

	/* creamos el world */

	b2World gameWorld(b2Vec2(0.0f, 10.0f));

	/* creamos el contact listener*/

	MyContactListener mainListener;
	gameWorld.SetContactListener(&mainListener);

	/* crear el cuerpo del personaje*/

	b2BodyDef charBodyDef;
	charBodyDef.position.Set(100.0f / ppm, 100.0f / ppm);
	charBodyDef.type = b2_dynamicBody;

	b2Body* charBody = gameWorld.CreateBody(&charBodyDef);

	b2PolygonShape charBox;
	charBox.SetAsBox(35.0f * 0.5f / ppm, 54.0f * 0.5f / ppm);

	b2FixtureDef charBodyFixtures;
	charBodyFixtures.shape = &charBox;
	charBodyFixtures.density = 1.0f;
	charBodyFixtures.friction = 0.0f;

	charBody->CreateFixture(&charBodyFixtures);
	charBody->SetFixedRotation(true);

	/* sensor del personaje */

	charBodyFixtures.isSensor = true;
	b2Fixture* sensorFixture = charBody->CreateFixture(&charBodyFixtures);
	b2FixtureUserData* sensor_data = &sensorFixture->GetUserData();
	sensor_data->pointer = 25;

	/* creamos el suelo*/

	b2BodyDef floorDef;
	floorDef.position.Set(320.0f / ppm, 340.0f / ppm);

	b2Body* floorBody = gameWorld.CreateBody(&floorDef);

	b2PolygonShape floorBox;
	floorBox.SetAsBox(640.0f * 0.5f / ppm, 25.0f * 0.5f / ppm);

	b2FixtureDef floorFixtures;
	floorFixtures.shape = &floorBox;
	floorFixtures.density = 0.0f;

	floorBody->CreateFixture(&floorFixtures);

	/* sensor para el suelo*/

	floorFixtures.isSensor = true;
	b2Fixture* floorSensorFixture = floorBody->CreateFixture(&floorFixtures);
	b2FixtureUserData* floor_sensor_data = &floorSensorFixture->GetUserData();
	floor_sensor_data->pointer = 35;

	/* plataforma 1 */
	b2BodyDef plat1Def;
	plat1Def.position.Set(328.0f / ppm, 264.0f / ppm);

	b2Body* plat1Body = gameWorld.CreateBody(&plat1Def);

	b2PolygonShape plat1Box;
	plat1Box.SetAsBox(80.0f * 0.5f / ppm, 16.0f * 0.5f /ppm);

	b2FixtureDef plat1Fixtures;
	plat1Fixtures.shape =&plat1Box;
	plat1Fixtures.density = 0.0f;

	plat1Body->CreateFixture(&plat1Fixtures);

	/* crear un sensor para plataforma 1*/

	plat1Fixtures.isSensor = true;
	b2Fixture* plat1SensorFixture = plat1Body->CreateFixture(&plat1Fixtures);
	b2FixtureUserData* plat1_sensor_data = &plat1SensorFixture->GetUserData();
	plat1_sensor_data->pointer = 1;


	/* plataforma 2 */
	b2BodyDef plat2Def;
	plat2Def.position.Set(216.0f / ppm, 216.0f / ppm);

	b2Body* plat2Body = gameWorld.CreateBody(&plat2Def);

	b2PolygonShape plat2Box;
	plat2Box.SetAsBox(80.0f * 0.5f / ppm, 16.0f * 0.5f / ppm);

	b2FixtureDef plat2Fixtures;
	plat2Fixtures.shape = &plat2Box;
	plat2Fixtures.density = 0.0f;

	plat2Body->CreateFixture(&plat2Fixtures);

	/* crear un sensor para plataforma 2*/

	plat2Fixtures.isSensor = true;
	b2Fixture* plat2SensorFixture = plat2Body->CreateFixture(&plat2Fixtures);
	b2FixtureUserData* plat2_sensor_data = &plat2SensorFixture->GetUserData();
	plat2_sensor_data->pointer = 2;

	/* plataforma 3 */
	b2BodyDef plat3Def;
	plat3Def.position.Set(120.0f / ppm, 168.0f/ ppm);

	b2Body* plat3Body = gameWorld.CreateBody(&plat3Def);

	b2PolygonShape plat3Box;
	plat3Box.SetAsBox(80.0f * 0.5f / ppm, 16.0f * 0.5f / ppm);

	b2FixtureDef plat3Fixtures;
	plat3Fixtures.shape = &plat2Box;
	plat3Fixtures.density = 0.0f;

	plat3Body->CreateFixture(&plat3Fixtures);

	/* crear un sensor para plataforma 3*/

	plat3Fixtures.isSensor = true;
	b2Fixture* plat3SensorFixture = plat3Body->CreateFixture(&plat3Fixtures);
	b2FixtureUserData* plat3_sensor_data = &plat3SensorFixture->GetUserData();
	plat3_sensor_data->pointer = 3;

	/* plataforma 4*/
	b2BodyDef plat4Def;
	plat4Def.position.Set(40.0f / ppm, 120.0f / ppm);

	b2Body* plat4Body = gameWorld.CreateBody(&plat4Def);

	b2PolygonShape plat4Box;
	plat4Box.SetAsBox(80.0f * 0.5f / ppm, 16.0f * 0.5f / ppm);

	b2FixtureDef plat4Fixtures;
	plat4Fixtures.shape = &plat4Box;
	plat4Fixtures.density = 0.0f;

	plat4Body->CreateFixture(&plat4Fixtures);

	/* crear un sensor para plataforma 4*/

	plat4Fixtures.isSensor = true;
	b2Fixture* plat4SensorFixture = plat4Body->CreateFixture(&plat4Fixtures);
	b2FixtureUserData* plat4_sensor_data = &plat4SensorFixture->GetUserData();
	plat4_sensor_data->pointer = 4;


	/*
		INICIA LA SIMULACIÓN.
	*/

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents(charBody, mainListener.onAir);
		game->update(charBody->GetPosition().x * ppm, charBody->GetPosition().y * ppm);
		game->render();

		/*
			AQUÍ VA EL STEP() DEL WORLD.
		*/

		gameWorld.Step(frameTime / 1000.0f, 6, 2);

		/*
			SE CALCULA EL FRAMETIME Y SE CORRIGE EL FRAMERATE SI ES NECESARIO.
		*/

		frameEnd = SDL_GetTicks();
		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameTime = SDL_GetTicks() - frameStart;
	}

	game->clean();

	return 0;
}