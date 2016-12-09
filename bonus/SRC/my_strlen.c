/*
** my_strlen.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ/SRC
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 10:33:39 2016 
** Last update Sun Dec  4 10:34:50 2016 
*/

#include	"my.h"

int	my_strlen(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
