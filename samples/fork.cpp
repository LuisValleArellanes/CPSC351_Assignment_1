#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
	// The variable to store the process id
	pid_t pid;

	// Create a child
	pid = fork();
	
	// Stores information about events in the child (e.g., child termination/exit status)
	int childEventInfo;
	
	// The return value of execlp
	int execlpRetVal;
	
	// The return value of wait
	int waitReturn; 

	// Sanity checks -- if fork has failed, then we are done
	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}
	
	if(pid == 0) //  This the child
	{
		// Let's print the process id of the child and the parent
		// gepid() returns the process id of the current process
		// getppid() returns the process id of the parent
		fprintf(stderr, "Child: I am a child. My process id is %d\n", getpid());
		fprintf(stderr, "Child: The process id of my parent is %d\n", getppid());
		
		// Replace the child's code with the code of the program
		// located at "/usr/bin/ls".  ls will be passed the following
		// arguments: 
		// argv[0] -- "ls"
		// argv[1] -- "-l"
		// The NULL argument is necessary
		// On success, there is no return value -- the entire program
		// replaced with the new program and the new program starts 
		// executing starting with the first instruction
		// On faliure, returns -1 and the current program continues 
		execlpRetVal = execlp("/usr/bin/ls", "ls", "-l", NULL);

		// This code is unreachable unless execlp has failed 
		if(execlpRetVal < 0)
		{
			perror("execlp");
			exit(1);
		}
	}
	
	else // This is the parent
	{
		// Wait for the child to finish
		// waitReturn will store the process
		// id of the recently terminated child
		// childExitStatus will store information
		// about child termination (as a bitmap). 
		// We need to use a few macros to extract 
		// the actual exit code
		waitReturn = wait(&childEventInfo);

		// Sanity checks -- wait failed?
		if(waitReturn < 0)
		{
			perror("wait");
			exit(1);
		}
		
		// If the reason why wait has stopped waiting
		// was child termination (could be other reasns
		// in practice!), let's print the child's exit status
		// WIFEXITED macro checks the bits in the childEventInfo
		// to see if the reason why the wait has stopped waiting
		// was child termination
		if(WIFEXITED(childEventInfo))
		{
			// Print the terminated child's process id
			fprintf(stderr, "Parent: The child with pid=%d has terminated\n", waitReturn);
			
			// WEXITSTATUS extracts the child's exit code from the childEventInfo
			fprintf(stderr, "Paent: The child's exit code is %d\n", WEXITSTATUS(childEventInfo));	
		}
	}
	
	
}
