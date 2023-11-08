// HW2.cpp : Defines the entry point for the application.

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
	vector<Flight> flights;

public:
	Plane(const string& from, const string& to)
		: wait_time(0.0), pos(0.0), vel(0.0), distance(0.0), loiter_time(0.0), at_SCE(false), origin(from), destination(to) {
	
	}

	virtual ~Plane(){
	
	}

	void operate(double dt){

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
		return distance;
	}

	virtual double time_on_ground() {
		return 0.0;
	}

	virtual string plane_type() {
		return "String";
	}

	static double draw_from_normal_dist(double mean, double std_dev) {
		// Implementation for the "draw_from_normal_dist" function
		default_random_engine rand_generator;
		normal_distribution<double> distribution(mean, std_dev);
		return distribution(rand_generator);

};

class Q3
{

}

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
