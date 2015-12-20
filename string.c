/*
** string.c for fdf2 in /home/bauren_a/Work/tek-1/infographie/gfx_fdf2
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Thu Dec 17 14:08:55 2015 Arthur
** Last update Sun Dec 20 02:41:11 2015 Arthur
*/

#include <stdio.h>
#include <stdlib.h>

int	compare_str(const char *str1, const char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}

int	getnbr(const char *str)
{
  int	i;

  int	sign;
  int	result;

  i = 0;
  sign = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign *= -1;
      i++;
    }
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (result * sign);
      result *= 10;
      result += (str[i] - '0');
      i++;
    }
  return (result * sign);
}

char	*itoa(int nb)
{
  char	*result;
  char	buffer[10];
  int	sign;
  int	i;
  int	j;

  sign = 0;
  if ((i = 0) == 0 && nb < 0 && (sign = 1) == 1)
    nb = -nb;
  while (nb != 0)
    {
      buffer[i] = (nb % 10) + '0';
      nb /= 10;
      i++;
    }
  result = malloc(sizeof(char) * (i + 1 + sign + (j = 0)));
  if (sign == 1)
    result[j++] = '-';
  while (j < (i + sign))
    {
      result[j] = buffer[i - (j + 1 - sign)];
      j++;
    }
  result[j] = 0;
  return (result);
}

int	is_digit(char c)
{
  if ((c >= '0' && c <= '9') || c == '+' || c == '-')
    return (1);
  return (0);
}
