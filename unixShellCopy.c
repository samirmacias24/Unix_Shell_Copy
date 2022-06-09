#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
	char input [50];
	char * split [50];
	printf("Welcome to the new Bash Shell. Enter 'exit' to quit program\n");
	int fork_rv; // return value from fork
    
	while(1)
	{
		// ask user for input (a specific command)
		printf("Enter a command: ");
       		// read input from the user
		scanf("%[^\n]%*c", input);
		
		//if user wants to exit the program, then quit program (returns control to the shell)
		if(strcmp(input, "exit") == 0){
			exit(0);
		}
		// create new process
		fork_rv = fork();      

    		// check for error
    		if(fork_rv == -1) {     
        		perror("fork");
        	}
    		else if(fork_rv == 0){
			// here the c string is split word-by-word
			char * ptr;
  			ptr = strtok(input," ,");
  			int count = 0;
  			// placing the input from the user into the split array
  			while (ptr != NULL)
  			{
   				split[count] = ptr;
    				ptr = strtok(NULL, " ,");
    				count++;
  			}
  			// adding null to the end of the character array
  			split[count + 1] = 0;
  			// having the child process exec the new program
			execvp(split[0], split);
			// if execvp fails
			perror("execvp failed");
			exit(1);
		}
    		else{
    			int wait_exit_value;
    			int wait_rv;
    			wait_rv = wait(&wait_exit_value);
        	}
	}
	return 0;
}