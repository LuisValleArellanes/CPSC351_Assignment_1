#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 200

int main()
{
	// Assume that we have lattitude and longitude variables as follows
	float lattitude = 52.52, longitude = 13.41;
	
	// The buffer to store the final URL with lattitude and longitude filled in
	char finalURLBuff[MAX_BUF_SIZE];	
	
	// snprintf will replace the fist %f (representing the floating point place holder for a floating point value
	// that should be taken from the third argument of snprintf and converted into string), and similarly will replace the
	// the second %f with the fourth argument of snprintf().
	
	// This function will take the third argument (i.e., the formatting string), will replace the formatting directives
	// (i.e., %f) with the arguments lattitude and longitude, respectively and store the resulting string in the finalURLBuff
	// MAX_BUF_SIZE tells the function to stop if the resulting string exceeds the MAMAX_BUF_SIZE (don't want to go out of bounds
	// of the finalURLBuff)
	// For more information in snprintf() please check
	// https://www.geeksforgeeks.org/snprintf-c-library/ 
	snprintf(finalURLBuff, MAX_BUF_SIZE, "https://api.open-meteo.com/v1/forecast?latitude=%f&longitude=%f&current_weather=True", lattitude, longitude); 
	
	fprintf(stderr, "The final URL is %s\n", finalURLBuff);

	return 0;
}







