/*
** filter.c for filter in /home/bauren_a/Work/tek-1/PSU_year_filter
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Tue Dec 15 18:13:18 2015 Arthur
** Last update Sun Dec 20 03:22:12 2015 Arthur
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include "filter.h"

char	*load_file(const char *filename)
{
  char	buffer[1024 + 1];
  char	*result;
  char	*tmp;
  int	flen;
  int	len;
  int	fd;

  result = NULL;
  flen = 0;
  fd = open(filename, O_RDONLY);
  while ((len = read(fd, buffer, 1024)) > 0)
    {
      buffer[len] = 0;
      tmp = result;
      if (result == NULL)
	result = my_strcpy(buffer);
      else
	result = my_strcat(result, buffer, len);
      flen += len;
      free(tmp);
    }
  result[flen] = 0;
  return (result);
}

char	*formating(char *str, char *flag, va_list lst)
{
  int	i;
  int	tmp;

  i = 0;
  while (flag[i])
    {
      if (str == NULL)
	return (NULL);
      if (flag[i] == 'c')
	str = rm_char(str, (char)va_arg(lst, int), 0);
      if (flag[i] == 'C')
	str = rm_char(str, (char)va_arg(lst, int), 1);
      else if (flag[i] == 's')
	str = rm_str(str, (char *)va_arg(lst, void *), 0);
      else if (flag[i] == 'S')
	str = rm_str(str, (char *)va_arg(lst, void *), 1);
      else if (flag[i] == 'i')
	str = rm_nbr(str, va_arg(lst, int));
      else if (flag[i] == 'I')
	{
	  (tmp = va_arg(lst, int));
	  if ((str = rm_nbr(str, tmp)) == NULL)
	    return (NULL);
	  str = rm_nbr(str, -tmp);
	}
      i++;
    }
  return (str);
}

char		*filter(char *filename, char *format, ...)
{
  char		*file_content;
  va_list	lst;

  file_content = load_file(filename);
  if (format[0] == 0)
    return (file_content);
  va_start(lst, NULL);
  file_content = formating(file_content, format, lst);
  return (file_content);
}
