/*
** disp_tab.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 16:07:01 2016 
** Last update Tue Dec  6 16:22:57 2016 
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"bsq.h"

void	disp_int2(int ***tab, int nb_ligne, int lenght)
{
  int	idx;
  int	idx2;

  idx = 0;
  idx2 = 0;
  while (idx < nb_ligne)
    {
      while (idx2 < lenght)
	{
	  printf("%d, ", (*tab)[idx][idx2]);
	  idx2++;
	}
      printf("\n");
      idx2 = 0;
      idx++;
    }
}
void	disp_int(int **tab, int nb_ligne, int lenght)
{
  int	idx;
  int	idx2;

  idx = 0;
  idx2 = 0;
  while (idx < nb_ligne)
    {
      while (idx2 < lenght)
	{
	  printf("%d, ", tab[idx][idx2]);
	  idx2++;
	}
      printf("\n");
      idx2 = 0;
      idx++;
    }
}

void	disp_tab(char **tab, t_coo *coor)
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
	  idx2 = 0;
	  while (idx2 < coor->x_min && tab[idx][idx2] != '\0')
	    {
	      write(1, &tab[idx][idx2], 1);
	      idx2++;
	    }
	  while (idx2 <= coor->x_max && tab[idx][idx2] != '\0')
	    {
	      my_putstr("x");
	      idx2++;
	    }
	  while (tab[idx][idx2] != '\0')
	    {
	      write(1, &tab[idx][idx2], 1);
	      idx2++;
	    }
	}
      my_putstr("\n");
      idx++;
    }
}
