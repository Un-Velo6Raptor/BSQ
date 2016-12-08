/*
** bsq.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec  5 13:09:22 2016 
** Last update Thu Dec  8 10:45:16 2016 
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"bsq.h"
#include	"my.h"

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

int	found_check_max(t_coo *coor, int **obs, int idx_y)
{
  int	idx;

  idx = 0;
  while (coor->x_tmp > obs[idx_y][idx] && obs[idx_y][idx] != -1)
    idx++;
  coor->tmp_val = obs[idx_y][idx];
  if (idx == 0 && obs[idx_y][idx] == -1)
    return (-1);
  if (idx == 0 && obs[idx_y][idx] != -1)
    return (obs[idx_y][idx]);
  else
    return (obs[idx_y][idx - 1]);
}

int	check_square(t_coo *coor, int **obs)
{
  int	idx_y;
  int	tmp;
  
  idx_y = coor->y_tmp;
  tmp = 0;
  while (idx_y < coor->nb_ligne && idx_y <= coor->nb_check + coor->y_tmp)
    {
      tmp = found_check_max(coor, obs, idx_y);
      if ((tmp >= coor->x_tmp && tmp <= coor->x_tmp + coor->nb_check) ||
	  (coor->tmp_val >= coor->x_tmp && coor->tmp_val <= coor->x_tmp + coor->nb_check))
	return (1);
      if (idx_y - coor->y_tmp == coor->nb_check)
	we_are_the_saviors(coor);
      idx_y++;
    }
  return (-1);
}

int	start_boucle(t_coo *coor, int **obs)
{
  int	idx_x;
  int	check;
  int	save;
  int	idx;

  idx_x = coor->x_tmp;
  save = coor->nb_check;
  idx = 0;
  while (coor->x_max - coor->x_min < coor->nb_check) 
    {
      check = 0;
      while (coor->nb_check != 0 && check != -1)
	{
	  check = check_square(coor, obs);
	  coor->nb_check--;
	}
      coor->x_tmp++;
      idx++;
      coor->nb_check = save - idx;
    }
  return (0);
}

int	prepare_start(t_coo *coor, int **obs)
{
  coor->y_tmp = coor->y;
  if (coor->x == 0)
    {
      coor->x_tmp = 0;
      coor->nb_check = obs[coor->y][coor->x] - 1;
    }
  else if (obs[coor->y][coor->x] == -1)
    {
      coor->x_tmp = obs[coor->y][coor->x - 1] + 1;
      coor->nb_check = coor->lenght - obs[coor->y][coor->x - 1] - 1;
    }
  else
    {
      coor->x_tmp = obs[coor->y][coor->x - 1] + 1;
      coor->nb_check = obs[coor->y][coor->x] - obs[coor->y][coor->x - 1] - 2;
    }
  start_boucle(coor, obs);
  return (0);
}

int	bsq(char **tab, int **obs, int nb_ligne, int lenght)
{
  t_coo	*coor;
  
  if ((coor = malloc(sizeof(t_coo) * 1)) == NULL)
    return (84);
  ini_coor(coor, lenght, nb_ligne);
  while (coor->y < nb_ligne && coor->y_max - coor->y_min + coor->y < nb_ligne)
    {
      coor->x = 0;
      if (obs[coor->y][coor->x] != -1)
	
      while (obs[coor->y][coor->x] != -1)
	{
	  if (obs[coor->y][coor->x] != obs[coor->y][coor->x] + 1)
	    prepare_start(coor, obs);
	  coor->x += 1;
	}
      if (obs[coor->y][coor->x - 1] != lenght - 1 && obs[coor->y][coor->x] == -1)
	prepare_start(coor, obs);
      coor->y += 1;
    }
  disp_tab(tab, coor);
  return (84);
}
