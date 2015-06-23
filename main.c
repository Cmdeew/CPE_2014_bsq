/*
** main.c for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Sat Jan 17 11:46:24 2015 thomas rieux-laucat
** Last update Tue Jun 23 17:13:14 2015 Thomas-Rieux-Laucat
*/

#include "include/bsq.h"

int	main(int argc, char **argv)
{
  char	**tab;
  int	**tab_int;

  if (argc == 1 || argc > 2)
    {
      my_putstr("USAGE: ./bsq [map]\n");
      return (1);
    }
  if (check_arg(argv[1]) == 1)
    return (1);
  tab = put_in_tab(argv);
  tab_int = convert_my_tab(tab);
  get_max(tab, tab_int);
  return (0);
}
