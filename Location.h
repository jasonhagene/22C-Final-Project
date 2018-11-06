#pragma once
#include <string>
#define pi 3.14159265358979323846
//Constant for radius of the Earth in desired units. Currently miles
#define radius 3959
class Location {
private:
	std::string name, phoneNumber, type, address;
	double latitude, longitude, relativeDistance /*Used for sorting algorithms/lists so they don't need to call a trig funtion 12 times per distance check*/;
	double toRadians(double degrees) { return (degrees * pi) / 180; }
public:
	Location();
	Location(std::string, std::string, std::string, double, double);

	//Returns the distance between 2 different Location classes using the Great Circle Formula
	double getDistance(Location);
	std::string getName() { return name; }	
	std::string getNumber() { return phoneNumber; }
	std::string getType() { return type; }
	std::string getAddress() { return address; }
	std::string getCoordiantes();
	void setRelativeDistance(Location);
	void setRelativeDistance(double d) { relativeDistance = d; }
	double getRelativeDistance() { return relativeDistance; }
};