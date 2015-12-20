/*
** int_format.c for filter in /home/bauren_a/Work/tek-1/PSU/PSU_year_filter
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sun Dec 20 02:28:01 2015 Arthur
** Last update Sun Dec 20 02:30:46 2015 Arthur
*/

#include "filter.h"
#include <stdlib.h>

void    precalc_nbr(char *str, int nb, int *i, int *size)
{
  int   j;
  int   rm_s;
  char  *to_rm;

  j = 0;
  *i = 0;
  *size = 0;
  to_rm = itoa(nb);
  rm_s = str_len(to_rm);
  while (str[*i + (j = 0)])
    {
      if ((*i > 0 && is_digit(str[*i - 1]) == 0) || *i == 0)
	while (str[(*i)++] == to_rm[j++])
	  if (j == rm_s && (str[(*i)++] < '0' || str[(*i)++] > '9'))
	    *size += j;
      (*i)++;
    }
}

char    *rm_nbr(char *str, int nb)
{
  int   i;
  int   j;
  int   k;
  int   rm_s;
  int   size;
  char  *result;
  char  *to_rm;

  to_rm = itoa(nb);
  rm_s = str_len(to_rm);
  precalc_nbr(str, nb, &i, &size);
  result = malloc(sizeof(char) * (i - size + (k = 0)));
  i = 0;
  while (str[i + (j = 0)])
    {
      if (i > 0 && is_digit(str[i - 1]) == 0)
	while (str[i + j] == to_rm[j++])
	  if (j == rm_s && (str[i + j] < '0' || str[i + j] > '9'))
	    i += j;
      result[k++] = str[i++];
    }
  result[k] = 0;
  free(to_rm);
  free(str);
  return (result);
}
