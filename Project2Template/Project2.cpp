// Project2.cpp : Defines the entry point for the console application.
//
// Eric Monestime and Amornrat Ajmo

#include <iostream>
#include <string>
#include <vector>  //include are done at the top of the source code, not in the middle
#include <cassert>
#include <fstream>
#include <sstream>

//using, instead of always doing std:cout 
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using namespace std;
using std::string;

/*
   argc:is the number of arguments you passed on the command line
   argv: each individual argument on the command line

   The program on the command line is the 1st parameter you will receive(argv[0])
*/
class Ratio{

private:
	int population;
	int restaurant;

public:
	Ratio(const int ppopulation, const int prestaurant){
		population = ppopulation;
		restaurant = prestaurant;
		this->population = ppopulation;
		this->restaurant = prestaurant;
	}

	//destructor
	virtual ~Ratio(){}

	//copy constructor
	Ratio(const Ratio &obj){
		this->population = obj.population;
		this->restaurant = obj.restaurant;
	}
	//copy-assignment operator
	Ratio & operator=(const Ratio & other) {
		population = other.population;
		restaurant = other.restaurant;
		return *this;
	}
	virtual const int getRatio() {return this->population / this->restaurant;}
};


int main( int argc, const char* argv[] )
{
	ifstream RestaurantsFile;
    RestaurantsFile.open("FastFoodRestaurants.csv",std::ios::in); //read file

    ifstream PopulationsFile;
    PopulationsFile.open("Annual_Population_Estimates_for_New_York_State_and_Counties__Beginning_1970.csv", std::ios::in); // read file

    cout << "\nRestaurants: " << endl;
    int numberOfRestaurants = 0;

    if (RestaurantsFile.is_open()){
        string line = "";
        while (getline(RestaurantsFile, line))
        {
            if (line.find("Plattsburgh") != std::string::npos) // find string if it match then print it
            {
              cout << line << endl;
              numberOfRestaurants++; // increment number count
            }       
        }
    }
  	cout << "\nFound numberOfRestaurants: " << numberOfRestaurants << " restaurants in Plattsburgh!" << endl;

	cout << "\nPopulation: " << endl;
    if (PopulationsFile.is_open())
      {
        string line = "";
        int year;
        int population;
        
        while (getline(PopulationsFile, line))
        {
            if (line.find("Clinton") != std::string::npos) // find string if it match then print it
            {
                cout << "\n" << line << endl;

                  vector<string> vect; // store sub string from what we have found

                  stringstream ss(line); // read string

                  int value = 1;
          
                  while( ss.good() ) // check if the stream is good
                  {
                    string substr;
                    getline( ss, substr, ',' ); // output sub string with ','
                    vect.push_back( substr ); // store in vector
                    
                    if (value == 3) // 3rd value = year
                    {
                        year = stoi(substr); // stoi convert a string to an integer
                        cout << "year: " << year << endl;
                    }
                    else if (value == 5) // 5th value = population
                    {
                        cout << "difference in population: " << (stoi(substr) - population) << endl;
                        cout << "percentage: " << (stoi(substr) - population)/ (population*1.0) * 100  << "%" << endl;
                        cout << "score: " << 100 - ((stoi(substr) - population)/ (population*1.0) * 100)  << " points" << endl;
  
                        population = stoi(substr); // update value to this
                        cout << "population: " << population << endl;

						            Ratio r(population, numberOfRestaurants); // call class Ratio
						            cout << "Ratio: " << r.getRatio() << endl;
						
                    }
                    value++; // increment value
                  }
            } // end if
          } // end while
        } // end if
		

	/*cout << "# of arguments:" << argc << endl;

	//the 1st parameter is always the name of the program being
	//executed
	//
	// in the subdirectory ".vscode", there is a file "launch.json"
	// there is an attribute 'args', which is the equivalent of using the 
	// command line to pass the parameters to your program

	for ( int x = 0 ; x < argc ; x++) {
		cout << "Parameter #:" << x + 1 << " " << argv[x] << endl;
	}*/
}
