/*
** my_putstr.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ/SRC
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 10:32:49 2016 
** Last update Sun Dec  4 10:33:31 2016 
*/

#include	<unistd.h>
#include	"my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
