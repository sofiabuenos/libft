/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:08:23 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/11/03 19:49:31 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*standard headers*/
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

/*list structure*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ---- is... family (character classification) ---- */

/*
** ft_isalpha - checks whether a character is an alphabetic letter.
** @c: the character to test, passed as an int (as with the standard isalpha).
** Return: 1 if c is a letter (a-z or A-Z), 0 otherwise.
*/
int		ft_isalpha(int c);

/*
** ft_isdigit - checks whether a character is a decimal digit.
** @c: the character to test, passed as an int.
** Return: 1 if c is between '0' and '9', 0 otherwise.
*/
int		ft_isdigit(int c);

/*
** ft_isalnum - checks whether a character is alphanumeric.
** @c: the character to test, passed as an int.
** Return: 1 if c is a letter or a digit, 0 otherwise.
*/
int		ft_isalnum(int c);

/*
** ft_isascii - checks whether a character belongs to the ASCII set.
** @c: the character to test, passed as an int.
** Return: 1 if c is between 0 and 127, 0 otherwise.
*/
int		ft_isascii(int c);

/*
** ft_isprint - checks whether a character is printable.
** @c: the character to test, passed as an int.
** Return: 1 if c is a printable character (including space), 0 otherwise.
*/
int		ft_isprint(int c);

/* ---- string functions ---- */

/*
** ft_strlen - counts the length of a null-terminated string.
** @s: the string to measure.
** Return: the number of characters before the terminating '\0'.
*/
size_t	ft_strlen(const char *s);

/*sets all bytes of a string an integer passed as parameter and returns it*/
void	*ft_memset(void *s, int c, size_t n);

/*sets all bytes of a string to zero*/
void	ft_bzero(void *s, size_t n);

/*
** ft_memcpy - copies n bytes from the memory area src to the memory area
** dest. Behavior is undefined if the two areas overlap (use ft_memmove
** for that case).
** @dest: the destination memory area.
** @src: the source memory area.
** @n: the number of bytes to copy.
** Return: a pointer to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif