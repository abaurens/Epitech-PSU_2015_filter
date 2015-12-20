/*
** filter.h for filter in /home/bauren_a/Work/tek-1/PSU_year_filter
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Tue Dec 15 15:56:00 2015 Arthur
** Last update Sun Dec 20 03:16:22 2015 Arthur
*/

#ifndef FILTER_H_
# define FILTER_H_

char	*filter(char *filename, char *format, ...);

int	str_len(char *str);
char	*my_strcat(char *str1, char *str2, int  len2);
int	char_is_in_str(char c, char *str);
char	*my_strcpy(char *str);

int	getnbr(const char *str);
char	*itoa(int nb);
int	is_digit(char c);

int	char_equals(char c1, char c2, int case_sensi);
char	*rm_nbr(char *str, int nb);
char	*rm_str(char *str, const char *to_rm, int case_sensi);
char	*rm_char(char *str, char c, int case_sensi);

#endif /* !FILTER_H_ */
