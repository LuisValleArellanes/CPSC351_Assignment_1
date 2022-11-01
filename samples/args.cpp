#include <stdio.h>

// Illustrates how the argument passing works

// @argc -- the number of arguments passed (including the program name itself)
// @argv - the array of arguments
int main(int argc, char** argv)
{
	fprintf(stderr, "The number of arguments is %d\n", argc);
	
	// Loop through the arguments
	for(int index = 0; index < argc; ++index)
	{
		fprintf(stderr, "argv[%d] = %s\n", index, argv[index]);
	}
	
	return 0;
}
