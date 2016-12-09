/*
** free_tab.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 16:08:39 2016 
** Last update Sun Dec  4 16:31:00 2016 
*/

#include	<stdlib.h>
#include	"my.h"

int	free_tab(char **tab)
{
  int	idx;

  idx = 0;
  while (tab[idx] != NULL)
    {
      free(tab[idx]);
      idx++;
    }
  free(tab);
  return (0);
}
