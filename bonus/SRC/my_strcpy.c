/*
** my_strcpy.c for  in /home/januar_m/delivery/CPool_Day06
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Mon Oct 10 09:39:21 2016 Martin Januario
** Last update Mon Nov 21 19:38:05 2016 
*/

#include	"my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	idx;

  idx = 0;
  while (src[idx] != '\0')
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
