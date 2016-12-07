/*
** my_strncpy.c for  in /home/januar_m/delivery/CPool_Day06
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Mon Oct 10 10:18:18 2016 Martin Januario
** Last update Sun Dec  4 16:11:09 2016 
*/

#include	"my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	idx;

  idx = 0;
  if (n < 0)
    return (0);
  while (idx < n)
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
