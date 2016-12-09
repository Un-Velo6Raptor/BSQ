/*
** particular_square.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Dec  8 09:58:43 2016 
** Last update Fri Dec  9 20:22:42 2016 
*/

#include	<unistd.h>
#include	"my.h"

void	disp_one(char disp, int check)
{
  my_putstr("\033[34;01m");
  write(1, &disp, 1);
  my_putstr("\033[00m");
  if (check == 1)
    write(1, "\n", 1);
}

int	particular_map_2(char **tab, int nb_ligne, int lenght, char disp)
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
      disp_one(disp, 0);
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

int	particular_map(char **tab, int nb_ligne, int lenght, char disp)
{
  int	idx;

  idx = 0;
  if (nb_ligne == 1 && lenght == 1 && tab[0][0] == '.')
    disp_one(disp, 1);
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
	  disp_one(disp, 0);
	  idx++;
	}
      my_putstr(&tab[0][idx]);
      write(1, "\n", 1);
    }
  if (nb_ligne != 1 && lenght == 1)
    particular_map_2(tab, nb_ligne, lenght, disp);
  return (0);
}
