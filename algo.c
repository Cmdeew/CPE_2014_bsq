/*
** algo.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Jan 12 14:54:38 2015 thomas rieux-laucat
** Last update Sun Jan 18 23:47:42 2015 thomas rieux-laucat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/bsq.h"

char	**put_in_tab(char **argv)
{
  char	*str;
  char	*file;
  char	**tab;
  int	fd;
  int	nb_l;
  int	i;

  nb_l = 0;
  i = 0;
  file = argv[1];
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(1);
  str = get_next_line(fd);
  nb_l = my_getnbr(str);
  if ((tab = malloc(sizeof(char *) * (nb_l + 1))) == NULL)
    exit(1);
  free(str);
  while ((str = get_next_line(fd)))
    {
      tab[i] = str;
      i++;
    }
  close(fd);
  return (tab);
}

void	condition(char **tab, int **tab_int, int i, int j)
{
  if (tab[i][j] == 'o')
    tab_int[i][j] = 0;
  else if ((i == 0) || (j == 0))
    tab_int[i][j] = 1;
  else
    tab_int[i][j] = my_min(tab_int[i][j - 1], 
			   tab_int[i - 1][j - 1], tab_int[i - 1][j]);
}

int	**convert_my_tab(char **tab)
{
  int	**tab_int;
  int	i;
  int	j;

  i = check_column(tab);
  j = check_line(tab);
  if ((tab_int = malloc(i * sizeof(int *))) == NULL)
    exit(1);
  i = 0;
  while (tab[i] != '\0')
    {
      if ((tab_int[i] = malloc(sizeof(int) * j)) == NULL)
	exit(1);
      j = 0;
      while (tab[i][j])
	{
	  condition(tab, tab_int, i, j);
	  j++;
	}
      i++;
    }
  return (tab_int);
}

void	print_int(int **tab_int, char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_putnbr(tab_int[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}

void	my_aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      free(tab[i]);
      i++;
      my_putchar('\n');
    }
}
