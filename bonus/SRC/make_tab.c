/*
** make_tab.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 14:39:36 2016 
** Last update Fri Dec  9 19:31:52 2016 
*/

#include	<stdlib.h>
#include	"my.h"

int	my_strlen_ligne(char *str, int check)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0' && str[idx] != '\n')
    {
      if (check == 0 && (str[idx] < '0' || str[idx] > '9'))
	return (-84);
      idx++;
    }
  return (idx);
}

int	found_ligne(int *nb_ligne, char *str, int *good, int *check)
{
  char	*tmp;
  int	lenght;

  (*good) = 0;
  lenght =  my_strlen_ligne(str, 0);
  (*check) = lenght;
  if (lenght <= 0 || str[lenght] == '\0')
    return (-84);
  if ((tmp = malloc(lenght + 1)) == NULL)
    return (-84);
  tmp[lenght] = '\0';
  my_strncpy(tmp, str, lenght, 0);
  if (((*nb_ligne) = my_getnbr(tmp)) == 0)
    return (-84);
  free(tmp);
  return (lenght);
}

int	make_tab(char ***tab, int *nb_ligne, char *str, int *save)
{
  int	idx;
  int	good;
  int	tmp;

  tmp = 0;
  if ((idx = found_ligne(nb_ligne, str, &good, &idx) + 1) == -84 ||
      ((*tab = malloc(sizeof(char *) * ((*nb_ligne) + 1))) == NULL))
    return (84);
  while (good < (*nb_ligne) && str[idx] != '\0')
    {
      tmp = my_strlen_ligne(&str[idx], 1);
      if ((*save) == 0)
	(*save) = tmp;
      if ((*save) != tmp)
	return (84);
      if (((*tab)[good] = malloc(sizeof(char) * (tmp + 1))) == NULL)
	return (84);
      my_strncpy((*tab)[good], &str[idx], tmp, good);
      good++;
      idx += tmp + 1;
    }
  (*tab)[good] = NULL;
  if (good != (*nb_ligne))
    return (84);
  return (0);
}
