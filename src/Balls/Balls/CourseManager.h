#pragma once

class CourseManager
{
private:
	

public:
	CourseManager();
	void CreateDefaultCourse(ServerWrapper& sw);
	void SpawnGate(ServerWrapper& sw, float gateDistanceFromCar);
};

