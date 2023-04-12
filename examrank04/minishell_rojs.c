#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/* Here is the explanation for the code above:
1. First we check if there is a pipe or a semicolon in the arguments
2. If there is a pipe, we create a pipe, and we fork the process.
3. If we are in the child, we use the dup2 to replace the standard input with the fd[0] of the pipe, and we replace the standard output with the fd[1] of the pipe. We also close the fd[0] and fd[1] of the pipe, and the temporary file descriptor.
4. We execute the command and close the file descriptor.
5. If we are in the parent, we close the fd[1] of the pipe and the temporary file descriptor, and we replace the temporary file descriptor with the fd[0] of the pipe.
6. If there is a semicolon, we fork the process.
7. If we are in the child, we replace the standard input with the temporary file descriptor, and we close it.
8. We execute the command and close the file descriptor.
9. If we are in the parent, we close the temporary file descriptor, and we wait for the child to finish.
10. We repeat the process until we have no more commands to execute.
11. We close the temporary file descriptor, and return 0. */

void putstr_fd2(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	write(2,str,i);
}
​
int ft_execute(char *argv[], int i , char *env[])
{
	argv[i] = NULL;
	execve(argv[0], argv, env);
	putstr_fd2("error: cannot execute ");
	putstr_fd2(argv[0]);
	write(2, "\n", 1);
	return(1);
}
​
int main (int argc, char *argv[], char *env[])
{
	int i = 0;
	int pid = 0;
	int fd[2];
	int tmp_fd = dup(STDIN_FILENO);
	(void)argc;
​
	while(argv[i] && argv[i+1])
	{
		argv = &argv[i+1];
		i = 0;
		while(argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if( i != 2)
				putstr_fd2("error: cd: bad arguments");
			else if(chdir(argv[1]) != 0)
			{
				putstr_fd2("error: cd: cannot change direcory to ");
				putstr_fd2("error: cd: cannot change direcory to ");
				write(2,"\n",1);
			}
		}
		else if(i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if(pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
				if(ft_execute(argv, i, env))
					return 1;
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if(pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				close(tmp_fd);
				if(ft_execute(argv, i, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
		close(tmp_fd);
		return 0;
}
