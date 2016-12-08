/*
** particular_square.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 09:58:43 2016 
** Last update Thu Dec  8 11:57:10 2016 
*/

#include	<unistd.h>
#include	"my.h"

int	particular_map_2(char **tab, int nb_ligne, int lenght)
{
  int	idx;

  idx = 0;
  while (tab[idx] != NULL && tab[idx][0] == 'o')
    {
      write(1, &tab[idx][0], 1);
      write(1, "\n", 1);
      idx++;
    }
  if (tab[idx] != NULL)
    {
      my_putstr("x");
      idx++;
    }
  else
    return (0);
  while (tab[idx] != NULL)
    {
      write(1, "\n", 1);
      my_putstr(tab[idx]);
      idx++;
    }
  write(1, "\n", 1);
  return (0);
}

int	particular_map(char **tab, int nb_ligne, int lenght)
{
  int	idx;

  idx = 0;
  if (nb_ligne == 1 && lenght == 1 && tab[0][0] == '.')
    my_putstr("x\n");
  if (nb_ligne == 1 && lenght == 1 && tab[0][0] == 'o')
    my_putstr("o\n");
  if (nb_ligne == 1 && lenght != 1)
    {
      while (tab[0][idx] != '\0' && tab[0][idx] == 'o')
	{
	  write(1, &tab[0][idx], 1);
	  idx++;
	}
      if (tab[0][idx] != '\0')
	{
	  my_putstr("x");
	  idx++;
	}
      my_putstr(&tab[0][idx]);
      write(1, "\n", 1);
    }
  if (nb_ligne != 1 && lenght == 1)
    particular_map_2(tab, nb_ligne, lenght);
  return (0);
}
