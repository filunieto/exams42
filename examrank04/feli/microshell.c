#include <unistd.h> //dup, write
#include <string.h> //strcmp
#include <sys/wait.h> //waitpid

//trucos empezar y acabar con el close. Donde usamos DUP y dup2
//cuantas veces escribimos close(temporary_file_descriptor);
//cuantas temporary_file_descriptor
//malloc, free, write (1), close (2), fork(3), waitpid(4), signal, kill, exit, chdir(5), execve(6), dup(7), dup2(8), pipe (9), strcmp(10), strncmp
#define ERR1 "error: cannot execute "
#define ERR2 "error: cd: bad arguments"
#define ERR3 "error: cd: cannot change directory to "

int	write_error(char *string, char *argv)
{
	while (string && *string)
		write(2, string++, 1);
	if (argv)
		while(*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_exe(char **argv, int i, int temporary_file_descrip, char **env)
{
	argv[i] = NULL;
	dup2(temporary_file_descrip, STDIN_FILENO);
	close(temporary_file_descrip);
	execve(argv[0], argv, env);
	return(write_error(ERR1, argv[0]));
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	int fd[2];
	int temporary_file_descrip;
	(void) argc;


	temporary_file_descrip = dup(STDIN_FILENO); //escribir el close a la vez, y contar cuantas veces hay que escribirla
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") != 0 && strcmp(argv[i], "|") != 0) //empezamos a incrementar i hasta llegar a l ; o |
			i++;
		if (strcmp(argv[0], "cd") == 0) //recuerda el index 0
		{
			if (i != 2)
				write_error(ERR2, NULL);
			else if (chdir(argv[1]) != 0)
				write_error(ERR3, argv[1]);
		}
		else if ((i != 0) && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) //recuerda index i
		{
			if ( fork () == 0)
			{
				if (ft_exe(argv, i, temporary_file_descrip, env)) //se repite
					return 1;
			}
			else
			{
				close(temporary_file_descrip);
				while (waitpid(-1, NULL, WUNTRACED ) != -1 );
				temporary_file_descrip = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if ( fork () == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exe(argv, i, temporary_file_descrip, env)) //se repite
					return 1;
			}
			else
			{
				close(fd[1]);
				close(temporary_file_descrip);
				temporary_file_descrip = fd[0];
			}
		}
	}
	close(temporary_file_descrip); //escribir estas 2 lineas juntas
	return 0;
}