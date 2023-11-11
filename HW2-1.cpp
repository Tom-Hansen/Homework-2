// HW2.cpp : Defines the entry point for the application.

// Homework 2
// Ian Atkinson, Tom Hansen, Kameron Metcalf
// we couldn't get SDL2 to link with CMake which is why the code isnt able to run

#include <iostream>
#include <string>
#include <vector>
#include "HW2.h"
#include <random>
#include "HW2_Visualizer.h"

using namespace std;

// The airports and distances, Question 1
vector<string> airport_start = { "PHL", "ORD", "EWR"};
vector<string> airport_end = { "SCE", "SCE", "SCE"};
vector<int> airport_distance = { 160, 640, 220 };

//Question 2 & 3:
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
	vector<string> Plane_Start = airport_start; // Importing the containers
	vector<string> Plane_End = airport_end; //where the planes end at
	vector<int> Plane_Dist = airport_distance; //plane distance

public:
	Plane() : pos(0), vel(0), wait_time(0), loiter_time(0), at_SCE(false)
	{
		// Made a default constructor to avoid issues in the Airliner class
	}
	void PlaneTwo(const string& from, const string& to)
	{
		int i = 0; //int set to 0
		origin = from; //origin is set to from
		destination = to; //destination is set to to
		distance = Plane_Dist[i]; //plane distance is set to distance
		pos = 0; //position set to 0
		vel = 0; //velocity set to 0
		wait_time = 0; //wait time is 0
		loiter_time = 0; //loiter time is 0
		at_SCE = 0; //at state college airport is 0
		
	}

	virtual ~Plane() {

	}

	void operate(double dt) {
		if (loiter_time != 0) //if else statement for planes operations
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

	double getPos() const { //return position
		return pos;
	}

	double getVel() const { //return velocity
		return vel;
	}

	double get_loiter_time() const { //return loiter time
		return loiter_time;
	}

	string getOrigin() const { //return origim
		return origin;
	}

	string getDestination() const { //return destination
		return destination;
	}

	bool getAtSCE() const { //return the at State College Airport
		return at_SCE;
	}

	double setVel(double vel2) { //Velocity 1 is equal to Velocity 2
		vel = vel2;
		return(vel);
	}

	void setLoiterTime(double loiter_time2) { //Loiter time 1 is equal to Loiter time 2
		loiter_time = loiter_time2;
	}

	double distance_to_SCE() { //Calculation for destination State College
		if(destination == "SCE")
			return (distance - pos);
	}

	virtual double time_on_ground() { //Value for time on ground
		return 0.0;
	}

	virtual string plane_type() { //Plane type is GA
		return "GA";
	}

	static double draw_from_normal_dist(double m, double sd) {  
		std::random_device rd{};
		std::mt19937 gen{ rd() };
		std::normal_distribution<> d{ m, sd };
		return d(gen);
	}
	friend class ATC;
};
// Class representing an Airliner, inheriting privately from the Plane class
class Airliner : private Plane
{
private:
	string Airline; // Private member variable storing the airline name
public:
// Constructor for Airliner, taking airline, departure, and destination as parameters
	Airliner(const string& airline, const string& from, const string& to)
	{
		Airline = airline; // kept one variable lowercase to avoid errors
		PlaneTwo(from, to); // Call the PlaneTwo function from the base class with departure and destination
	}
	~Airliner()
	{

	}
    // Member function to get the type of the plane (returns the Airline)
	string plane_type()
	{
		return Airline;
	};
	double time_on_ground()
	{
	  // Set wait_time using a normal distribution function with parameters 1800 and 600
		wait_time = draw_from_normal_dist(1800, 600);
		return(wait_time);// Return the calculated wait_time
	}
};
// Class representing General Aviation, inheriting publicly from the Plane class
class GeneralAviation : public Plane
{
public:
    // Constructor for GeneralAviation, taking departure and destination as parameters
	GeneralAviation(const string& from, const string& to)
	{
		PlaneTwo(from, to); // Call the PlaneTwo function from the base class with departure and destination
	}
	~GeneralAviation()
	{
	
	}
    // Member function to calculate the time the plane spends on the ground
	double time_on_ground()
	{
		        // Set wait_time using a normal distribution function with parameters 600 and 60
		wait_time = draw_from_normal_dist(600, 60);
		return(wait_time);// Return the calculated wait_time
	}
};
// Class representing Air Traffic Control (ATC), inheriting publicly from the Plane class
class ATC : public Plane
{
	Plane P; // Object of the Plane class as a private member
private:
	string registered_planes;
	int MAX_LANDED_PLANE_NUM = 2;// Constant for maximum number of landed planes
	int AIRSPACE_DISTANCE = 50;// Constant for airspace distance
public:
    // Constructor for ATC
	ATC()
	{

	}
    // Destructor for ATC
	~ATC()
	{

	}

	double register_plane;// Member variable storing the registered planes
    // Function to control air traffic
	int control_traffic()
	{
		int landed_planes = 0;// Variable to count landed planes
		int i = 0;// Loop variable
		// Loop through 7 iterations 
		for (i = 0; i < 7; i++)
		{
			if (i < register_plane)
			{
				// Increment landed_planes by the number of planes at SCE 
				landed_planes += Plane::getAtSCE();
				i++;
				continue;
			}
			if (landed_planes >= MAX_LANDED_PLANE_NUM)
			{
				i = 0;// Reset the loop variable if the maximum number of landed planes is reached
			}
			if (i >= register_plane)// Exit the loop if i is greater than or equal to register_plane
			{
				break;
			}
			// Continue loop while i is less than register_plane
			while (i < register_plane)
			{
				// Check conditions for loiter time and airspace distance
				if (at_SCE == 0 && distance_to_SCE() <= AIRSPACE_DISTANCE && loiter_time == 0)
				{
					loiter_time = 100; // Set loiter_time to 100
					i++;
				}
				else
					continue; // Continue the loop
			}
		}
	}
};
//Main Function
int main(int argc, char** argv)
{
	HW2_VIZ viz;// Create an object of the HW2_VIZ class
	Plane P;// Create an object of the Plane class

	viz.visualize_plane();
    // Create instances of Airliner and GeneralAviation classes with different parameters
	Airliner Aircraft1("AA", "SCE", "PHL");
	Airliner Aircraft2("UA", "SCE", "ORD");
	Airliner Aircraft3("UA", "SCE", "EWR");
	Airliner Aircraft4("AA", "SCE", "ORD");
	GeneralAviation Aircraft5("SCE", "PHL");
	GeneralAviation Aircraft6("SCE", "EWR");
	GeneralAviation Aircraft7("SCE", "ORD");
    // Set different speeds for the Plane object
	double speed1 = P.setVel(470);
	double speed2 = P.setVel(515);
	double speed3 = P.setVel(480);
	double speed4 = P.setVel(500);
	double speed5 = P.setVel(140);
	double speed6 = P.setVel(160);
	double speed7 = P.setVel(180);

	int timestep = 11;// Initial timestep value
	// Infinite loop
	while (true)
	{
		P.operate(timestep); // Call the operate function from the Plane object
		cout << "Timestep: " << timestep << endl; // Output the current timestep
		//cout << Aircraft1 << endl;
		//cout << Aircraft2 << endl;
		//cout << Aircraft3 << endl;
		//cout << Aircraft4 << endl;
		//cout << Aircraft5 << endl;
		//cout << Aircraft6 << endl;
		//cout << Aircraft7 << endl;
		cout << endl;
		timestep += 1;
		viz.update(timestep);// Call the update function from the viz object
	}

	return 0;
}

// Need help with:
// How to actually get position
// What Airline = Airline means
// If while(true) is correct
// If I set up airline list correctly
// How to do the operate part
