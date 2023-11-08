// HW2.cpp: Defines the entry point for the application
// Working together with Tom Hansen and Kameron Metfcalf

#include <iostream>
#include <string>
#include "HW2.h"

using namespace std;

class Plane
{
protected:
	double wait_time;
private:
	double pos; //position
	double vel; //velocity
	double distance; //distance
	double loiter_time; //amount of time airplanes need for possible landings
	bool at_SCE; //State College Airport
	string origin, destination; //origin and destination
public:

	/*A constructor that takes in two strings “from” and “to” as input
		arguments.
		- A virtual deconstructor.
		- A function named “operate” with a double variable “dt” as an
		input, and return nothing.
		- get function for “pos” variable.
		- get functions for “vel” variable.
		- get functions for “loiter_time” variable.
		- get function for “origin” variable.
		- get function for “destination” variable.
		- get function for “at_SCE” variable.
		- set functions for “vel” variable.
		- set functions for “loiter_time” variable.
		- A function named “distance_to_SCE” that returns double.
		- A virtual function named “time_on_ground”.
		- A virtual function named “plane_type” that returns a string.
		- A static function named “draw_from_normal_dist” that takes in two
		double variables(mean and standard deviation), and returns back a
		random number from a normal distribution.*/
};

int main()
{
	// Question 1

	;
	return 0;
}
