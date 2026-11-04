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

/* ---- character conversion ---- */

/*
** ft_toupper - converts a lowercase letter to uppercase.
** @c: the character to convert, passed as an int.
** Return: the uppercase letter if c is in a-z, c unchanged otherwise.
*/
int		ft_toupper(int c);

/*
** ft_tolower - converts an uppercase letter to lowercase.
** @c: the character to convert, passed as an int.
** Return: the lowercase letter if c is in A-Z, c unchanged otherwise.
*/
int		ft_tolower(int c);

/* ---- memory functions ---- */

/*
** ft_memset - fills the first n bytes of a memory area with a given byte.
** @s: the memory area to fill.
** @c: the byte value to write (converted to unsigned char).
** @n: the number of bytes to fill.
** Return: s.
*/
void	*ft_memset(void *s, int c, size_t n);

/*
** ft_bzero - sets the first n bytes of a memory area to zero.
** @s: the memory area to clear.
** @n: the number of bytes to clear.
** Return: nothing.
*/
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

/*
** ft_memmove - copies n bytes from src to dest. Unlike ft_memcpy, the two
** areas may overlap: when dest is after src it copies from the last byte to
** the first, so no byte is overwritten before it has been read.
** @dest: the destination memory area.
** @src: the source memory area.
** @n: the number of bytes to copy.
** Return: a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
** ft_memchr - locates the first occurrence of a byte in a memory area.
** @s: the memory area to search.
** @c: the byte to look for (converted to unsigned char).
** @n: the number of bytes to examine.
** Return: a pointer to the matching byte, or NULL if it is not found.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
** ft_memcmp - compares the first n bytes of two memory areas.
** @s1: the first memory area (read as unsigned char).
** @s2: the second memory area (read as unsigned char).
** @n: the number of bytes to compare.
** Return: 0 if equal, <0 if s1 is smaller, >0 if s1 is larger.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** ft_calloc - allocates memory for count elements of size bytes each and
** sets every byte of it to zero.
** @count: the number of elements.
** @size: the size in bytes of each element.
** Return: a pointer to the allocated memory, or NULL if allocation fails.
*/
void	*ft_calloc(size_t count, size_t size);

/* ---- string functions ---- */

/*
** ft_strlen - counts the length of a null-terminated string.
** @s: the string to measure.
** Return: the number of characters before the terminating '\0'.
*/
size_t	ft_strlen(const char *s);

/*
** ft_strlcpy - copies a string into a buffer of limited size. At most
** dstsize - 1 characters are copied and dst is '\0'-terminated (unless
** dstsize is 0).
** @dst: the destination buffer.
** @src: the string to copy.
** @dstsize: the full size of the dst buffer.
** Return: the length of src. If it is >= dstsize, the copy was truncated.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** ft_strlcat - appends src to the end of dst, never letting the total
** length exceed dstsize - 1 characters.
** @dst: the destination buffer, already holding a string.
** @src: the string to append.
** @dstsize: the full size of the dst buffer.
** Return: the length it tried to create: length of dst plus length of src
** (or dstsize plus length of src, if dstsize is not larger than dst).
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** ft_strchr - locates the first occurrence of a character in a string.
** The terminating '\0' is considered part of the string.
** @s: the string to search.
** @c: the character to look for (converted to char).
** Return: a pointer to the first match, or NULL if c is not found.
*/
char	*ft_strchr(const char *s, int c);

/*
** ft_strrchr - locates the last occurrence of a character in a string.
** The terminating '\0' is considered part of the string.
** @s: the string to search.
** @c: the character to look for (converted to char).
** Return: a pointer to the last match, or NULL if c is not found.
*/
char	*ft_strrchr(const char *s, int c);

/*
** ft_strncmp - compares at most n characters of two strings, stopping at the
** first difference or at a '\0'.
** @s1: the first string (read as unsigned char).
** @s2: the second string (read as unsigned char).
** @n: the maximum number of characters to compare.
** Return: 0 if equal, <0 if s1 is smaller, >0 if s1 is larger.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** ft_strnstr - locates the first occurrence of a string within another,
** searching at most len characters.
** @haystack: the string to search in.
** @needle: the string to look for.
** @len: the maximum number of characters of haystack to examine.
** Return: haystack if needle is empty, a pointer to the start of the first
** match, or NULL if needle is not found.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
** ft_strdup - duplicates a string into newly allocated memory.
** @s1: the string to duplicate.
** Return: a pointer to the new string, or NULL if allocation fails.
*/
char	*ft_strdup(const char *s1);

/* ---- additional functions ---- */

/*
** ft_substr - extracts a substring of s, in newly allocated memory.
** @s: the string to extract from.
** @start: the index in s where the substring begins.
** @len: the maximum length of the substring.
** Return: the new string (empty if start is past the end of s), or NULL if
** s is NULL or the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
** ft_strjoin - concatenates two strings into newly allocated memory.
** @s1: the prefix string.
** @s2: the suffix string.
** Return: the new string (s1 followed by s2), or NULL if allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strtrim - removes from both ends of a string every character that
** belongs to a given set, in newly allocated memory. Characters in the
** middle of the string are never removed.
** @s1: the string to trim.
** @set: the characters to remove (their order does not matter).
** Return: the trimmed string (empty if everything is removed), or NULL if
** s1 or set is NULL or the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set);

#endif
