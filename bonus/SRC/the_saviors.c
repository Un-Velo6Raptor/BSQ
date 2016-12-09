/*
** the_saviors.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 11:53:45 2016 
** Last update Thu Dec  8 11:54:33 2016 
*/

#include	"my.h"
#include	"bsq.h"

void	ini_coor(t_coo *coor, int nb1, int nb2)
{
  coor->tmp_val = 0;
  coor->x = 0;
  coor->y = 0;
  coor->x_tmp = 0;
  coor->y_tmp = 0;
  coor->nb_check = 0;
  coor->nb_ligne = nb2;
  coor->lenght = nb1 - 1;
  coor->x_min = -1;
  coor->y_max = -1;
  coor->y_min = -1;
  coor->x_max = -1;
}

int	we_are_the_saviors(t_coo *coor)
{
  if (coor->x_max - coor->x_min < coor->nb_check)
    {
      coor->x_min = coor->x_tmp;
      coor->y_min = coor->y_tmp;
      coor->x_max = coor->x_tmp + coor->nb_check;
      coor->y_max = coor->y_tmp + coor->nb_check;
      return (-1);
    }
  return (-1);
}
