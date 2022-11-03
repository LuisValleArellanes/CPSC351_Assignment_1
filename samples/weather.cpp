#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
/** The program reads the latitude and longitude location from the specified file.**/

std::string filename;

std::cout << "Enter file name: ";
std::cin >> filename;

std::ifstream myfile; 
myfile.open(filename);

if(myfile.is_open)


/** The program creates a child that uses the curl program to contact the weather service, fetch the weather information (in JSON format), and save it to the file.**/


/** The program creates a child that uses the curl program to contact the weather service, fetch the weather information (in JSON format), and save it to the file.**/


/** a serial fetcher: which will fetch the city information one city at a time. That is, the parent must wait for each child to finish fetching the weather for its location before creating another child. **/


/**a parallel fetching: the parent will create a child for each location (i.e., without waiting for a child to complete) and only once all children have been created, the parent will wait for all of them to terminate. You will then compare the performance of the two types of fetchers using the time utility. Both fetchers will use the Linux curl program in order to communicate with the weather API and fetch the weather information that is formatted according to the JavaScript Object Notation format. You can read more about the https://www.tutorialspoint.com/json/json quick guide.htm. The command line to fetch the JSON weather data for location at latitude location 52.52 and longitude location 13.41 and then save it in file file1.json is as follows: /usr/bin/curl -o file1.json "https://api.open-meteo.com/v1/forecast?latitude=52.520000&longitude=13.410000&current weather=True Where • /usr/bin/curl: The name of the curl program • -o: Specifies that we want to save the data fetched to the file. • file1.json: The name of the file where we want to save the fetched data. • https://api.open-meteo.com/v1/forecast?latitude=52.520000&longitude=13.410000&current weather=True: is the URL of the web API from which to fetch the data. The values in bold blue represent latitude and longitude of locations from which to fetch the weather. You can practice the command in the shell before continuing. **/





}
