#include <string>
#include <string.h>

using namespace std;


int main()
{
	
	// The log file name
	string fileNamePrefix = "log";
	
	// The file name
	string fileName;
	
	// Let's generate 10 file names named log1.txt, log2.txt...log10.txt
	for(int fileNum = 1; fileNum < 11; ++fileNum)
	{
	
		// Create a numbered file name
		fileName = fileNamePrefix + to_string(fileNum) + ".txt";
		
		fprintf(stderr, "File name: %s\n", fileName.c_str());
		
	}

}
