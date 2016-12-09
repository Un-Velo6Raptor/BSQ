/*
** my.h for  in /home/januar_m/delivery/CPool_rush2/include
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Sat Oct 15 21:50:07 2016 Martin Januario
** Last update Fri Dec  9 20:43:23 2016 
*/

#ifndef MY_H_
# define MY_H_

#include	"bsq.h"

void	my_putstr(char *);
int	my_strlen(char *);
int	make_tab(char ***, int *, char *, int *);
int	free_tab(char **);
int	my_getnbr(char *);
char	*my_strncpy(char *, char *, int, int);
void	my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
int	particular_map(char **, int, int, char);
void	disp_tab(char **, t_coo *, char);
int	make_obs(int ***, char **, int, int);
t_coo	*bsq(char **, int **, int, int);
int	we_are_the_saviors(t_coo *);
void	ini_coor(t_coo *, int, int);
void	disp_one(char, int);

#endif /* !MY_H_ */
