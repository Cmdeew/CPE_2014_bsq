/*
** bsq.h for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq/include
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Jan 12 18:29:06 2015 thomas rieux-laucat
** Last update Sun Jan 18 23:44:45 2015 thomas rieux-laucat
*/

#ifndef BSQ_H_
# define BSQ_H_

# define         BUF_SIZE 5000
# define         BUF_READ 5000

typedef struct  s_var
{
  char          *buffer;
  int           i;
  int           pos;
  int           nb_read;
}               t_var;

/*get_next_line**********/

char	*get_next_line(const int);
char	*my_realloc(char *, int);
int	my_strlen(char	*);

/* fonction tab ********/

char	**put_in_tab(char **);
void	my_aff_tab(char **);
int	my_min(int, int, int);
int	**convert_my_tab(char **);
void	get_max(char **, int **);
int	check_column(char **);
int	check_line(char **);
void	free_tab(char **, int **);

/* Base fonction *******/

int	my_getnbr(char *);
void	my_putstr(char *);
void	my_putchar(char);
void  	my_putnbr(int);
void	print_int(int **, char **);
int	check_arg(char *);
int	check_file(char *);
void	*my_malloc(int);

#endif /*!BSQ_H_*/
