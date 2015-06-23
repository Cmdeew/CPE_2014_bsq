/*
** my_fonction.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Thu Jan 15 19:13:40 2015 thomas rieux-laucat
** Last update Fri Jan 16 22:29:46 2015 thomas rieux-laucat
*/

#include "include/bsq.h"

int	my_min(int a, int b, int c)
{
  int	min;

  if (a <= b && a <= c)
    min = a;
  if (b <= a && b <= c)
    min = b;
  if (c <= a && c <= b)
    min = c;
  return (min + 1);
}


void	print_my_square(char **tab, int max, int y, int x)
{
  int	i;
  int	j;
  int	counti;
  int	county;

  i = x;
  counti = 0;
  while (counti < max)
    {
      county = 0;
      j = y;
      while (county < max)
	{
	  tab[i][j] = 'X';
	  j--;
	  county++;
	}
      i--;
      counti++;
    }
  my_aff_tab(tab);
}

void	get_max(char **tab, int **tab_int)
{
  int	i;
  int	x;
  int	j;
  int	y;
  int	max;

  i = 0;
  max = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab_int[i][j] > max)
	    {
	      max = tab_int[i][j];
	      x = i;
	      y = j;
	    }
	  j++;
	}
      i++;
    }
  print_my_square(tab, max, y, x);
}
