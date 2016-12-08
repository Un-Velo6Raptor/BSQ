/*
** my_strncpy.c for  in /home/januar_m/delivery/CPool_Day06
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Mon Oct 10 10:18:18 2016 Martin Januario
** Last update Thu Dec  8 09:56:41 2016 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char	*my_strncpy(char *dest, char *src, int n, int good)
{
  int	idx;

  idx = 0;
  if (n < 0)
    return (0);
  while (idx < n)
    {
      if (good != 0 && src[idx] != 'o' && src[idx] != '.')
	{
	  write(2, "Bad map.\n", 9);
	  exit(84);
	}
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
