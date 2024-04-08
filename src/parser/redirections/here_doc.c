#include "minishell.h"

void    here_doc(char *delimiter)
{
    char	*line;
	char	fd[2];
	
	line = NULL;
	if (!delimiter || pipe())
		return(-1);
	while(1)
	{
		line = readline("> ");

		if (!line || (line != NULL && 
		ft_strcmp(line,delimiter,ft_strlen(delimiter))))
			break ;
		write(fd[1],line,ft_strlen(line));
		write(fd[1],"\n",ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd[1]);
	//cmd->fd_in = fd[0]; extremo de lectura dentro del fdin, este lee a fd[1]
	
}