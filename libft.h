/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:08:23 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/16 22:04:55 by sobueno          ###   ########.fr       */
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
# include <stdint.h>

/*list structure*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** Layout of this header: first by subject part (Part 1, Part 2, Part 3),
** then by family (for Part 1, the libc header the function comes from), and
** alphabetically inside each family.
*/

/* ======================== PART 1: libc functions ======================== */

/* ---- character tests and conversion (ctype.h) ---- */

/*
** ft_isalnum - checks whether a character is alphanumeric.
** @c: the character to test, passed as an int.
** Return: 1 if c is a letter or a digit, 0 otherwise.
*/
int				ft_isalnum(int c);

/*
** ft_isalpha - checks whether a character is an alphabetic letter.
** @c: the character to test, passed as an int (as with the standard isalpha).
** Return: 1 if c is a letter (a-z or A-Z), 0 otherwise.
*/
int				ft_isalpha(int c);

/*
** ft_isascii - checks whether a character belongs to the ASCII set.
** @c: the character to test, passed as an int.
** Return: 1 if c is between 0 and 127, 0 otherwise.
*/
int				ft_isascii(int c);

/*
** ft_isdigit - checks whether a character is a decimal digit.
** @c: the character to test, passed as an int.
** Return: 1 if c is between '0' and '9', 0 otherwise.
*/
int				ft_isdigit(int c);

/*
** ft_isprint - checks whether a character is printable.
** @c: the character to test, passed as an int.
** Return: 1 if c is a printable character (including space), 0 otherwise.
*/
int				ft_isprint(int c);

/*
** ft_tolower - converts an uppercase letter to lowercase.
** @c: the character to convert, passed as an int.
** Return: the lowercase letter if c is in A-Z, c unchanged otherwise.
*/
int				ft_tolower(int c);

/*
** ft_toupper - converts a lowercase letter to uppercase.
** @c: the character to convert, passed as an int.
** Return: the uppercase letter if c is in a-z, c unchanged otherwise.
*/
int				ft_toupper(int c);

/* ---- memory (string.h) ---- */

/*
** ft_bzero - sets the first n bytes of a memory area to zero.
** @s: the memory area to clear.
** @n: the number of bytes to clear.
** Return: nothing.
*/
void			ft_bzero(void *s, size_t n);

/*
** ft_memchr - locates the first occurrence of a byte in a memory area.
** @s: the memory area to search.
** @c: the byte to look for (converted to unsigned char).
** @n: the number of bytes to examine.
** Return: a pointer to the matching byte, or NULL if it is not found.
*/
void			*ft_memchr(const void *s, int c, size_t n);

/*
** ft_memcmp - compares the first n bytes of two memory areas.
** @s1: the first memory area (read as unsigned char).
** @s2: the second memory area (read as unsigned char).
** @n: the number of bytes to compare.
** Return: 0 if equal, <0 if s1 is smaller, >0 if s1 is larger.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** ft_memcpy - copies n bytes from the memory area src to the memory area
** dest. Behavior is undefined if the two areas overlap (use ft_memmove
** for that case).
** @dest: the destination memory area.
** @src: the source memory area.
** @n: the number of bytes to copy.
** Return: a pointer to dest.
*/
void			*ft_memcpy(void *dest, const void *src, size_t n);

/*
** ft_memmove - copies n bytes from src to dest. Unlike ft_memcpy, the two
** areas may overlap: when dest is after src it copies from the last byte to
** the first, so no byte is overwritten before it has been read.
** @dest: the destination memory area.
** @src: the source memory area.
** @n: the number of bytes to copy.
** Return: a pointer to dest.
*/
void			*ft_memmove(void *dest, const void *src, size_t n);

/*
** ft_memset - fills the first n bytes of a memory area with a given byte.
** @s: the memory area to fill.
** @c: the byte value to write (converted to unsigned char).
** @n: the number of bytes to fill.
** Return: s.
*/
void			*ft_memset(void *s, int c, size_t n);

/* ---- strings (string.h) ---- */

/*
** ft_strchr - locates the first occurrence of a character in a string.
** The terminating '\0' is considered part of the string.
** @s: the string to search.
** @c: the character to look for (converted to char).
** Return: a pointer to the first match, or NULL if c is not found.
*/
char			*ft_strchr(const char *s, int c);

/*
** ft_strdup - duplicates a string into newly allocated memory.
** @s1: the string to duplicate.
** Return: a pointer to the new string, or NULL if allocation fails.
*/
char			*ft_strdup(const char *s1);

/*
** ft_strlcat - appends src to the end of dst, never letting the total
** length exceed dstsize - 1 characters.
** @dst: the destination buffer, already holding a string.
** @src: the string to append.
** @dstsize: the full size of the dst buffer.
** Return: the length it tried to create: length of dst plus length of src
** (or dstsize plus length of src, if dstsize is not larger than dst).
*/
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** ft_strlcpy - copies a string into a buffer of limited size. At most
** dstsize - 1 characters are copied and dst is '\0'-terminated (unless
** dstsize is 0).
** @dst: the destination buffer.
** @src: the string to copy.
** @dstsize: the full size of the dst buffer.
** Return: the length of src. If it is >= dstsize, the copy was truncated.
*/
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** ft_strlen - counts the length of a null-terminated string.
** @s: the string to measure.
** Return: the number of characters before the terminating '\0'.
*/
size_t			ft_strlen(const char *s);

/*
** ft_strncmp - compares at most n characters of two strings, stopping at the
** first difference or at a '\0'.
** @s1: the first string (read as unsigned char).
** @s2: the second string (read as unsigned char).
** @n: the maximum number of characters to compare.
** Return: 0 if equal, <0 if s1 is smaller, >0 if s1 is larger.
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** ft_strnstr - locates the first occurrence of a string within another,
** searching at most len characters.
** @haystack: the string to search in.
** @needle: the string to look for.
** @len: the maximum number of characters of haystack to examine.
** Return: haystack if needle is empty, a pointer to the start of the first
** match, or NULL if needle is not found.
*/
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

/*
** ft_strrchr - locates the last occurrence of a character in a string.
** The terminating '\0' is considered part of the string.
** @s: the string to search.
** @c: the character to look for (converted to char).
** Return: a pointer to the last match, or NULL if c is not found.
*/
char			*ft_strrchr(const char *s, int c);

/* ---- number conversion and allocation (stdlib.h) ---- */

/*
** ft_atoi - converts the beginning of a string to an int. Skips leading
** whitespace, accepts one optional '+' or '-' sign, then reads decimal
** digits up to the first character that is not a digit.
** @str: the string to convert.
** Return: the converted value (0 if there are no digits).
*/
int				ft_atoi(const char *str);

/*
** ft_calloc - allocates memory for count elements of size bytes each and
** sets every byte of it to zero.
** @count: the number of elements.
** @size: the size in bytes of each element.
** Return: a pointer to the allocated memory, or NULL if allocation fails.
*/
void			*ft_calloc(size_t count, size_t size);

/* ==================== PART 2: additional functions ==================== */

/* ---- building new strings (allocate memory) ---- */

/*
** ft_itoa - converts an integer to its decimal representation, in newly
** allocated memory. Negative numbers get a leading '-'.
** @n: the integer to convert.
** Return: the new string, or NULL if the allocation fails.
*/
char			*ft_itoa(int n);

/*
** ft_split - splits a string into words, using a character as delimiter.
** Consecutive delimiters, and delimiters at either end, produce no empty
** words. Every word and the array itself are newly allocated.
** @s: the string to split.
** @c: the delimiter character.
** Return: a NULL-terminated array of words, or NULL if s is NULL or any
** allocation fails (in which case nothing is left allocated).
*/
char			**ft_split(char const *s, char c);

/*
** ft_strjoin - concatenates two strings into newly allocated memory.
** @s1: the prefix string.
** @s2: the suffix string.
** Return: the new string (s1 followed by s2), or NULL if allocation fails.
*/
char			*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strmapi - applies f to each character of s, in order, and builds a new
** string from the results. f receives the index of the character and the
** character itself; s is left unchanged.
** @s: the string to iterate over.
** @f: the function to apply to each character.
** Return: the new string, or NULL if the allocation fails.
*/
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** ft_strtrim - removes from both ends of a string every character that
** belongs to a given set, in newly allocated memory. Characters in the
** middle of the string are never removed.
** @s1: the string to trim.
** @set: the characters to remove (their order does not matter).
** Return: the trimmed string (empty if everything is removed), or NULL if
** s1 or set is NULL or the allocation fails.
*/
char			*ft_strtrim(char const *s1, char const *set);

/*
** ft_substr - extracts a substring of s, in newly allocated memory.
** @s: the string to extract from.
** @start: the index in s where the substring begins.
** @len: the maximum length of the substring.
** Return: the new string (empty if start is past the end of s), or NULL if
** s is NULL or the allocation fails.
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);

/* ---- iterating over a string ---- */

/*
** ft_striteri - applies f to each character of s, in order. f receives the
** index of the character and its address, so it can modify s in place.
** @s: the string to iterate over (it must be modifiable).
** @f: the function to apply to each character.
** Return: nothing.
*/
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ---- writing to a file descriptor ---- */

/*
** ft_putchar_fd - writes a character to a file descriptor.
** @c: the character to write.
** @fd: the file descriptor to write to.
** Return: nothing.
*/
void			ft_putchar_fd(char c, int fd);

/*
** ft_putendl_fd - writes a string to a file descriptor, followed by a
** newline.
** @s: the string to write.
** @fd: the file descriptor to write to.
** Return: nothing.
*/
void			ft_putendl_fd(char *s, int fd);

/*
** ft_putnbr_fd - writes an integer, in decimal, to a file descriptor.
** @n: the integer to write.
** @fd: the file descriptor to write to.
** Return: nothing.
*/
void			ft_putnbr_fd(int n, int fd);

/*
** ft_putstr_fd - writes a string to a file descriptor.
** @s: the string to write.
** @fd: the file descriptor to write to.
** Return: nothing.
*/
void			ft_putstr_fd(char *s, int fd);

/* ======================== PART 3: linked lists ======================== */

/* ---- list functions (the t_list node is declared at the top) ---- */

/*
** ft_lstadd_back - adds a node at the end of a list. If the list is empty,
** the new node becomes its first node.
** @lst: the address of the pointer to the first node of the list.
** @new: the node to add.
** Return: nothing.
*/
void			ft_lstadd_back(t_list **lst, t_list *new);

/*
** ft_lstadd_front - adds a node at the beginning of a list.
** @lst: the address of the pointer to the first node of the list.
** @new: the node to add.
** Return: nothing.
*/
void			ft_lstadd_front(t_list **lst, t_list *new);

/*
** ft_lstclear - frees every node of a list from the given node onwards,
** using del on each content, then sets the list pointer to NULL.
** @lst: the address of the pointer to the first node to free.
** @del: the function used to free each node's content.
** Return: nothing.
*/
void			ft_lstclear(t_list **lst, void (*del)(void *));

/*
** ft_lstdelone - frees one node: its content with the given function, then
** the node itself. The next node is NOT freed or touched.
** @lst: the node to free.
** @del: the function used to free the node's content.
** Return: nothing.
*/
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/*
** ft_lstiter - applies a function to the content of each node of a list,
** from the given node to the end. The list itself is not modified.
** @lst: the first node to visit.
** @f: the function applied to the content of each node.
** Return: nothing.
*/
void			ft_lstiter(t_list *lst, void (*f)(void *));

/*
** ft_lstlast - finds the last node of a list.
** @lst: the first node of the list.
** Return: the last node, or NULL if the list is empty.
*/
t_list			*ft_lstlast(t_list *lst);

/*
** ft_lstmap - builds a new list by applying a function to the content of each
** node of a list. The original list is not modified. If an allocation fails,
** everything created so far is freed with del.
** @lst: the first node of the list to map.
** @f: the function applied to each content; returns the new content.
** @del: the function used to free a new content if something fails.
** Return: the new list, or NULL if lst or f is NULL or an allocation fails.
*/
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** ft_lstnew - creates a new node holding the given content. Only the pointer
** is stored: the content itself is not copied.
** @content: the content to store in the node.
** Return: the new node (its next is NULL), or NULL if the allocation fails.
*/
t_list			*ft_lstnew(void *content);

/*
** ft_lstsize - counts the nodes of a list.
** @lst: the first node of the list.
** Return: the number of nodes (0 for an empty list).
*/
unsigned int	ft_lstsize(t_list *lst);

#endif
