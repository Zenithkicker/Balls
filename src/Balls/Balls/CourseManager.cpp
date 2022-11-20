#include "pch.h"
#include "CourseManager.h"

CourseManager::CourseManager() 
{

}

void CourseManager::CreateDefaultCourse(ServerWrapper& sw)
{
	if (sw.IsNull())
	{
		LOG("[CourseManager::CreateDefaultCourse]::ServerWrapper Is Null");
		return;
	}
}

void CourseManager::SpawnGate(ServerWrapper& sw, float gateDistanceFromCar)
{
	if (sw.IsNull())
	{
		LOG("[CourseManager::CreateDefaultCourse]::ServerWrapper Is Null");
		return;
	}

	CarWrapper cw = sw.GetGameCar();
	if (cw.IsNull())
	{
		LOG("[CourseManager::CreateDefaultCourse]::CarWrapper Is Null");
		return;
	}

	BallWrapper ballWrapper = sw.GetBall();
	if (ballWrapper.IsNull())
	{
		LOG("[CourseManager::CreateDefaultCourse]::BallWrapper Is Null");
		return;
	}

	Vector carPos = cw.GetLocation();

	Vector gateLeftSpawnPos = Vector(carPos.X - gateDistanceFromCar, carPos.Y, carPos.Z);
	Vector gateRightSpawnPos = Vector(carPos.X + gateDistanceFromCar, carPos.Y, carPos.Z);
	
	sw.SpawnBall(gateLeftSpawnPos, false, false);
	sw.SpawnBall(gateRightSpawnPos, false, false);
}