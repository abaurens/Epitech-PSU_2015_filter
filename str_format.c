/*
** str_format.c for filter in /home/bauren_a/Work/tek-1/PSU/PSU_year_filter
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sun Dec 20 02:33:13 2015 Arthur
** Last update Sun Dec 20 03:15:19 2015 Arthur
*/

#include "filter.h"
#include <stdlib.h>

char    *rm_str(char *str, const char *to_rm, int case_sensi)
{
  char  *tmp;
  char  *result;
  int   size;
  int   i;
  int   j;
  int   k;

  size = 0;
  i = 0;
  while (str[i + (j = 0)])
    while (char_equals(str[i++], to_rm[j++], case_sensi))
      size++;
  result = malloc(sizeof(char) * ((i - size) + 1) + (k = 0));
  i = 0;
  while (str[i] && (j = 0) == 0)
    {
      while (char_equals(str[i + j], to_rm[j], case_sensi))
	j++;
      if (j == size)
	i += j;
      result[k++] = str[i++];
    }
  result[k] = 0;
  free(str);
  return (result);
}
