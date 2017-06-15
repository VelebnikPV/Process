#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() 
{
/*pid_t child_pid;
printf("The main program process ID is %d\n",(int)getpid());
child_pid = fork();
	if (child_pid != 0) 
	{
	printf("This is the parent process, with ID %d\n", (int)getpid());
	printf("The child's process ID is %d\n", (int)child_pid);
	} 
	else 
	{
	printf("This is the child process, with ID %d\n", (int)getpid());
	}*/
char *argv[3] = {"Command-line", ".", NULL};

	int pid = fork();

	if ( pid == 0 ) {
		execvp( "find", argv );
	}

	/* Put the parent to sleep for 2 seconds--let the child finished executing */
	wait( 2 );

	printf( "Finished executing the parent process\n"
	        " - the child won't get here--you will only see this once\n" );
	return 0;

}


