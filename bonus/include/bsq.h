/*
** bsq.h for  in /home/januar_m/delivery/CPE/CPE_2016_BSQ
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Dec  5 16:51:44 2016 
** Last update Wed Dec  7 21:42:38 2016 
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct s_coo
{
  int	x;
  int	y;
  int	x_tmp;
  int	y_tmp;
  int	nb_check;
  int	nb_ligne;
  int	lenght;
  int	x_min;
  int	y_min;
  int	x_max;
  int	y_max;

  int	tmp_val;
} t_coo;

#endif /* !BSQ_H_ */
