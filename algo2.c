/*
** algo2.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Fri Jan 16 22:40:24 2015 thomas rieux-laucat
** Last update Tue Jan 20 14:26:38 2015 thomas rieux-laucat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/bsq.h"

int	check_arg(char *arg)
{
  int	i;
  int	j;
  char	*chr;

  chr = "./:;,?!*%$&~#'([]){}-_@=+><";
  i = 0;
  while (arg[i])
    {
      j = 0;
      while (chr[j])
	{
	  if (arg[i] == chr[j])
	    {
	      my_putstr("File not valid.\n");
	      return(1);
	    }
	  else
	    j++;
	}
      i++;
    }
  if ((check_file(arg)) == 1)
    return (1);
  return (0);
}

int	check_file(char *arg)
{
  int	fd;
  char	*file;
  char	*str;

  file = arg;
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_putstr("Failed to open the file/directory \"");
      my_putstr(arg);
      my_putstr("\".\n");
      return (1);
    }
  str = get_next_line(fd);
  if (str == NULL)
    {
      my_putstr("Failed to open the file/directory \"");
      my_putstr(arg);
      my_putstr("\".\n");
      return (1);
    }
  if (str[0] > '9' || str[0] < '0')
    {
      my_putstr("File not valid.\n");
      return(1);
    }
  close(fd);
  return (0);
}

void	free_tab(char **tab, int **tab_int)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      while (tab[i + 1])
	free(tab_int[i++]);
      free(tab[i++]);
    }
}

int	check_column(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[i])
    {
      while (tab[i][j])
	j++;
      i++;
    }
  return (j);
}

int check_line(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
