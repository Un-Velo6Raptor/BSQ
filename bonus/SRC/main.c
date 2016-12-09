/*
** main.c for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ/SRC
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Dec  4 10:35:12 2016 
** Last update Fri Dec  9 20:41:43 2016 
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"bsq.h"
#include	"my.h"

char	*my_realloc(char *res, char *buffer, int idx, int size)
{
  char	*new_str;

  if (idx == 0)
    res = my_strdup(buffer);
  else
    {
      if ((new_str = malloc(sizeof(char) *
			    (my_strlen(res) + size + 1))) == NULL)
	return (NULL);
      my_strcpy(new_str, res);
      my_strcat(new_str, buffer);
      free(res);
      return (new_str);
    }
  return (res);
}

char	*read_file(char *res, int fd)
{
  char	buffer[1048576];
  int	size;
  int	idx;

  size = 0;
  res = NULL;
  idx = 0;
  while ((size = read(fd, buffer, 1048575)) > 0)
    {
      buffer[size] = '\0';
      if ((res = my_realloc(res, buffer, idx, size)) == NULL)
	return (NULL);
      idx++;
    }
  return (res);
}

char	*take_file(char *path)
{
  char	*res;
  int	fd;

  fd = 0;
  res = NULL;
  if ((fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  res = read_file(res, fd);
  if (close(fd) == -1)
    return (NULL);
  return (res);
}

char	what_disp(int argc, char **argv)
{
  char	tmp;

  tmp = 'x';
  if (argc == 3 && my_strlen(argv[2]) != 1)
    exit(84);
  else if (argc == 3)
    tmp = argv[2][0];
  return (tmp);
}

int	main(int argc, char **argv)
{
  char	**tab;
  int	**obs;
  char	**res;
  char	*str;
  int	lenght;
  int	nb_ligne;
  char	disp;
  t_coo	*coor;

  lenght = 0;
  nb_ligne = 0;
  if (argc == 1 || argc > 3)
    return (84);
  disp = what_disp(argc, argv);
  if ((str = take_file(argv[1])) == NULL)
    return (84);
  if (make_tab(&tab, &nb_ligne, str, &lenght) == 84)
    return (84);
  if (lenght == 1 || nb_ligne == 1)
    return (particular_map(tab, nb_ligne, lenght, disp));
  if (make_obs(&obs, tab, nb_ligne, lenght) == 84)
    return (84);
  coor = bsq(tab, obs, nb_ligne, lenght);
  disp_tab(tab, coor, disp);
  return (free_tab(tab));
}
