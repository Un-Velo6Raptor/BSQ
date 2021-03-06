/*
** make_obs.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec  5 10:54:35 2016 
** Last update Thu Dec  8 11:49:41 2016 
*/

#include	<stdlib.h>
#include	"my.h"

int	malloc_obs(int ***obs, int nb_ligne, int lenght)
{
  if (((*obs) = malloc(sizeof(int *) * nb_ligne + 1)) == NULL)
    return (84);
  return (0);
}

void	make_obs_ligne(int ***obs, char **tab, int idx, int lenght)
{
  int	good;
  int	idx_lenght;

  good = 0;
  idx_lenght = 0;
  while (tab[idx][idx_lenght] != '\0')
    {
      if (tab[idx][idx_lenght] == 'o')
	{
	  (*obs)[idx][good] = idx_lenght;
	  good++;
	}
      idx_lenght++;
    }
  (*obs)[idx][good] = lenght;
  good++;
  (*obs)[idx][good] = -1;
}

int	make_obs(int ***obs, char **tab, int nb_ligne, int lenght)
{
  int	idx;

  idx = 0;
  if (malloc_obs(obs, nb_ligne, lenght) == 84)
    return (84);
  while (idx < nb_ligne)
    {
      if (((*obs)[idx] = malloc(sizeof(int) * lenght + 5)) == NULL)
	return (84);
      make_obs_ligne(obs, tab, idx, lenght);
      idx++;
    }
  return (0);
}
