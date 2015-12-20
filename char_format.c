/*
** int_format.c for filter in /home/bauren_a/Work/tek-1/PSU/PSU_year_filter
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sun Dec 20 02:28:01 2015 Arthur
** Last update Sun Dec 20 02:50:16 2015 Arthur
*/

#include "filter.h"
#include <stdlib.h>

int	char_equals(char c1, char c2, int case_sensi)
{
  if (c1 == c2)
    return (1);
  else if (case_sensi == 1)
    {
      if (c1 >= 'A' && c1 <= 'Z')
	c1 += ('a' - 'A');
      if (c2 >= 'A' && c2 <= 'Z')
	c2 += ('a' - 'A');
      if (c1 == c2)
	return (1);
    }
  return (0);
}

char    *rm_char(char *str, char c, int case_sensi)
{
  char  *tmp;
  char  *result;
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (char_equals(str[i], c, case_sensi) == 0)
	j++;
      i++;
    }
  result = malloc(sizeof(char) * (j + 1));
  i = 0;
  j = 0;
  while (str[i])
    {
      if (char_equals(str[i], c, case_sensi) == 0)
	{
	  result[j] = str[i];
	  j++;
	}
      i++;
    }
  result[j] = 0;
  free(str);
  return (result);
}
