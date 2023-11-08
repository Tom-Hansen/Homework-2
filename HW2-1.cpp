﻿// HW2.cpp : Defines the entry point for the application.

#include <iostream>
#include <string>
#include <vector>
#include "HW2.h"
#include <random>

using namespace std;

struct Flight {
	string departure;
	string destination;
	int distance;

	Flight(const string& source, const string& destination, int dist)
		: departure(source), destination(destination), distance(dist) {}
};

//Question 2 & 3:
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
	vector<Flight> flights;

public:
	Plane(const string& from, const string& to, const double& dist)
	{
		string origin = from;
		string destination = to;
		double distance = dist;
		pos = 0;
		vel = 0;
		wait_time = 0;
		loiter_time - 0;
		at_SCE = 0;
	}

	virtual ~Plane() {

	}

	void operate(double dt) {
		if (loiter_time != 0)
		{
			loiter_time -= dt; //seconds
		}
		else if (wait_time != 0)
		{
			wait_time -= dt; //seconds
		}
		else if (pos < distance)
		{
			pos += (vel * dt);
			at_SCE = 0;
		}
		else if (destination == "SCE")
		{
			at_SCE = 1;
		}
		else
		{
			time_on_ground();
			pos = 0.0;
		}
	}

	double getPos() const {
		return pos;
	}

	double getVel() const {
		return vel;
	}

	double get_loiter_time() const {
		return loiter_time;
	}

	string getOrigin() const {
		return origin;
	}

	string getDestination() const {
		return destination;
	}

	bool getAtSCE() const {
		return at_SCE;
	}

	void setVel(double vel2) {
		vel = vel2;
	}

	void setLoiterTime(double loiter_time2) {
		loiter_time = loiter_time2;
	}

	double distance_to_SCE() {
		if(destination == "SCE")
			return (distance - pos);
	}

	virtual double time_on_ground() {
		return 0.0;
	}

	virtual string plane_type() {
		return "GA";
	}

	static double draw_from_normal_dist(double m, double sd) {
		std::random_device rd{};
		std::mt19937 gen{ rd() };
		std::normal_distribution<> d{ m, sd };
		return d(gen);
	}
};


class Airliner : public Plane
{
private:

};

class GeneralAviation : public Plane
{

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
