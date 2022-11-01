#include "json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

int main(int argc, char** argv)
{
	
	// Make sure the user provided a URL file
	if(argc < 2)
	{
		fprintf(stderr, "USAGE: %s <JSON FILE NAME>\n", argv[0]);
		exit(1);
	}
	
	// Open the file
	std::ifstream jsonFile(argv[1]);
			
	// Could not open the file
	if(!jsonFile.is_open())
	{
		std::cerr << "Could not open file " << argv[1] << std::endl;
		exit(1);
	}
	
	// Parse the JSON file	
	json data = json::parse(jsonFile);
	
	

	// Print the information	
	std::cerr << "This is the weather for latitude = " << data["latitude"];
	
	std::cerr << " and longitude = " << data["longitude"]
	<< std::endl;
	
	std::cerr << "----------------------------------------------------------------" << std::endl;
	
	std::cerr << "Currrent temperature: " << data["current_weather"]["temperature"] 
		  << std::endl;	
	
	std::cerr << "Current windspeed: " << data["current_weather"]["windspeed"]
		  << std::endl;
	
	std::cerr << "Current Wind direction: " << data["current_weather"]["winddirection"]
		 << std::endl;	
	
	
	return 0;
}
