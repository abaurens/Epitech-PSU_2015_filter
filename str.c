/*
** str.c for C3 in /home/bauren_a/Work/Colles/Colle 3/Piscine_C_colles-Semaine_03
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sun Oct 25 04:49:13 2015 Arthur
** Last update Sat Dec 19 15:01:47 2015 Arthur
*/

#include <stdlib.h>
#include "filter.h"

int	str_len(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *str1, char *str2, int	len2)
{
  int	i;
  int	len;
  char	*ret;

  i = 0;
  len = str_len(str1);
  if ((ret = malloc(sizeof(char) * (len + len2) + 1)) == NULL)
    return (NULL);
  while (*str1)
    {
      ret[i] = str1[0];
      str1 = &str1[1];
      i++;
    }
  while (*str2)
    {
      ret[i] = str2[0];
      str2 = &str2[1];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

int	char_is_in_str(char c, char *str)
{
  while (*str)
    {
      if (c == str[0])
	return (1);
      str = &str[1];
    }
  return (0);
}

char	*my_strcpy(char *str)
{
  int	i;
  int	len;
  char	*ret;

  i = 0;
  len = str_len(str);
  if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  while (i < len)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
