/*
** disp_tab.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 16:07:01 2016 
** Last update Fri Dec  9 20:44:03 2016 
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"bsq.h"

void	my_putnstr(char *str, int nb)
{
  write(1, str, nb);
}

void	disp_tab(char **tab, t_coo *coor, char tmp)
{
  int	idx;
  int	idx2;

  idx = 0;
  while (tab[idx] != NULL)
    {
      if (idx < coor->y_min || idx > coor->y_max)
	my_putstr(tab[idx]);
      else
	{
	  idx2 = coor->x_min;
	  my_putnstr(tab[idx], coor->x_min);
	  my_putstr("\033[34;01m");
	  while (idx2 <= coor->x_max)
	    {
	      write(1, &tmp, 1);
	      idx2++;
	    }
	  my_putstr("\033[00m");
	  my_putstr(&tab[idx][idx2]);
	}
      my_putstr("\n");
      idx++;
    }
}
