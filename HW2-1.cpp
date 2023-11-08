﻿// HW2.cpp : Defines the entry point for the application.

#include <iostream>
#include <string>
#include <vector>
#include "HW2.h"

using namespace std;

struct Flight {
	string departure;
	string destination;
	int distance;

	Flight(const string& source, const string& destination, int dist)
		: departure(source), destination(destination), distance(dist) {}
};

//Question 2:
class Plane
{
protected:
	double wait_time;
private:
	double pos;
	double vel;
	double distance;
	double loiter_time;
	bool at_SCE;
	string origin, destination;
public:

	/*A constructor that takes in two strings “from” and “to” as input
		arguments.
		- A virtual deconstructor.
		- A function named “operate” with a double variables “dt” as an
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
		- A virtual function named “plane_type” that returns string.
		- A static function named “draw_from_normal_dist” that takes in two
		double variables(mean and standard deviation), and returns back a
		random number from a normal distribution.*/
};

int main()
{
	// Question 1
	vector<Flight> flights;

	flights.push_back(Flight("SCE", "PHL", 160));
	flights.push_back(Flight("SCE", "ORD", 640));
	flights.push_back(Flight("SCE", "EWR", 220));

	string sourceAirport = "SCE";
	string destinationAirport = "PHL";
	return 0;
}
