/*
** my.h for  in /home/januar_m/delivery/CPool_rush2/include
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Sat Oct 15 21:50:07 2016 Martin Januario
** Last update Tue Dec  6 16:17:54 2016 
*/

#ifndef MY_H_
# define MY_H_

void	my_putstr(char *);
int	my_strlen(char *);
int	make_tab(char ***, int *, char *, int *);
int	free_tab(char **);
int	my_getnbr(char *);
char	*my_strncpy(char *, char *, int);
void	my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
int	make_obs(int ***, char **, int, int);
int	bsq(char **, int **, int, int);

#endif /* MY_H_ */
