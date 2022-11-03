#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	/* The command buffer */
	string cmdBuff;
	
	/* The ID of the child process */
	pid_t pid;

	
	/* Keep running until the user has typed "exit" */
	do 
	{
		/* Prompt the user to enter the command */
		cerr << "cmd>  ";
		cin >> cmdBuff;
		

		int childEventInfo;

		int waitReturn; 

		
		/* If the user wants to exit */
		if(cmdBuff != "exit")
		{
			
			/* TODO: Create a child */

			pid = fork();

			if(pid == 0){
				int ls = 

				/*** TODO: If I am child, I will do this: ****/
			/* Call execlp() to replace my program with that specified at the command line.
			 * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because 
			 * cmdBuff is an object of type string (i.e., a class) and execlp() expects
 			 * an arry of characters.  However, you can pass cmdBuff.c_str(), which will
			 * return an array of characters representation of the string object.
			 * 
			 * Also, please do not forget to error check your exelp() system calls.
			 */

					//execlp("/bin/ls", "ls", "-l", "a", NULL);
					execlp("/bin/", "ls", "-l", "a", NULL);
				

			}
			/* TODO: Error check to make sure the child was successfully created */
			else if (pid < 0 ){

					perror("fork");
					
					printf("There is no process running ");
					
					exit(1);
				}

			else{ 

				/*** TODO: If I am a parent, I will do the following ***?
			/* Wait for the child process to terminate */

				waitReturn = wait(&childEventInfo);
				
				printf("Child has been completed");
				
				
			}
			
			
				
			
			
			
			
		}
	}
	while(cmdBuff != "exit");
	
	return 0;	
}
