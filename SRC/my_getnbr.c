/*
** my_getnbr.c for  in /home/januar_m/delivery/CPool_Day04
** 
** Made by Martin Januario
** Login   <januar_m@epitech.net>
** 
** Started on  Thu Oct  6 16:18:50 2016 Martin Januario
** Last update Fri Oct  7 14:56:43 2016 Martin Januario
*/

int		check_s(char *str)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 1;
  while (str[idx] != '\0' && (str[idx] < '0' || str[idx] > '9'))
    {
      if (str[idx] == '-')
	cpt = cpt * -1;
      idx++;
    }
  return (cpt);
}

int		start_idx(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] != '-' && str[idx] != '+')
	return (idx);
      idx++;
    }
  return (0);
}

int		check_ovfl(long int nb, int cpt, int tmp)
{
  int		res;

  res = 0;
  if (cpt == 1)
    {
      nb = nb * tmp;
      if (nb > 2147483647)
	return (1);
      else if (nb < -2147483648)
	return (1);
      return (0);
    }
  if (cpt == 2)
    {
      nb = nb * tmp;
      res = nb;
      return (res);
    }
}

int		my_getnbr(char *str)
{
  int		idx;
  long int	result;

  result = 0;
  idx = start_idx(str);
  while (str[idx] != '\0')
    {
      if (str[idx] >= '0' && str[idx] <= '9')
	{
	  if (result == 0)
	    result = str[idx] - 48;
	  else
	    {
	      result = result * 10;
	      result = result + (str[idx] - 48);
	      if (result < 0 || check_ovfl(result, 1, check_s(str)) == 1)
		return (0);
	    }
	}
      else
	return (check_ovfl(result, 2, check_s(str)));
      idx++;
    }
  return (check_ovfl(result, 2, check_s(str)));
}
