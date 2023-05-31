/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/22 15:31:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// @brief Test if `c` is uppercase or lowercase
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isalpha(int c);

// @brief Test if `c` is a number (0-9)
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isdigit(int c);

// @brief tests for which ft_isalpha or ft_isdigit is true
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isalnum(int c);

// @brief tests for an ASCII character
// @param c character to test
// @return zero if the tests false and non-zero if the tests true.
int		ft_isascii(int c);

// @brief tests for any printing character, including space (‘ ’).
// @param c character to test as an unsigned char
// @return zero if the tests false and non-zero if the tests true.
int		ft_isprint(int c);

// computes the length of the string s
// @param s input string
// @return number of characters that precede the terminating NULL character
size_t	ft_strlen(const char *s);

// @brief writes len bytes of value c (converted to an unsigned char) 
// @brief to the string b.
// @param b destination
// @param c byte
// @param len lenght
// @return first argument (b)
void	*ft_memset(void *b, int c, size_t len);

// @brief writes n zeroed bytes to the string s.
// @param s destination
// @param n lenght
void	ft_bzero(void *s, size_t n);

// @brief copies n bytes from memory area src to memory area dst.
// @brief If dst and src overlap, behavior is undefined.
// @param dst destination
// @param src source
// @param n length
// @return original value of dst.
void	*ft_memcpy(void *dst, const void *src, size_t n);

// @brief copies len bytes from memory area src to memory area dst.
// @brief The two strings may overlap.
// @param dst destination
// @param src source
// @param len length
// @return original value of dst.
void	*ft_memmove(void *dst, const void *src, size_t len);

// @brief copies dstsize bytes from memory area src to memory area dst
// @brief without overflow and guarantee NUL-termination.
// @param dst destination
// @param src source
// @param dstsize destination available size
// @return length of src
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// @brief concatenate strings without overflow and guarantee NUL-termination.
// @param dst destination
// @param src source
// @param dstsize destination available size
// @return initial length of dst plus the length of src.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// @brief converts a lower-case letter to the corresponding upper-case letter.
// @param c charactere to convert.
// @return the corresponding upper-case letter if there is one; otherwise 'c'
int		ft_toupper(int c);

// @brief converts a upper-case letter to the corresponding lower-case letter.
// @param c charactere to convert.
// @return the corresponding lower-case letter if there is one; otherwise 'c'
int		ft_tolower(int c);

// @brief locates the first occurrence of c (converted to a char) in
// @brief the string pointed to by s
// @param s the string to search in.
// @param c charactere to locate.
// @return a pointer to the located character, or
// @return NULL if the character does not appear in the string.
char	*ft_strchr(const char *s, int c);

// @brief locates the las occurrence of c (converted to a char) in
// @brief the string pointed to by s
// @param s the string to search in.
// @param c charactere to locate.
// @return a pointer to the located character, or
// @return NULL if the character does not appear in the string.
char	*ft_strrchr(const char *s, int c);

// @brief lexicographically compare the null-terminated strings s1 and s2.
// @brief compares not more than n characters
// @param s1 first string to compare
// @param s2 second string to compare
// @param n limit
// @return integer greater than, equal to, or less than 0
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// @brief locates the first occurrence of 
// @brief c (converted to an unsigned char) in string s.
// @param s the string to search in.
// @param c byte to locate.
// @param n lenght
// @return a pointer to the byte located, 
// @return or NULL if no such byte exists within n bytes.
void	*ft_memchr(const void *s, int c, size_t n);

// @brief compares byte string s1 against byte string s2.
// @brief Both strings are assumed to be n bytes long.
// @param s1 first string to compare
// @param s2 second string to compare
// @param n strings lenght
// @return returns zero if the two strings are identical, 
// @return otherwise returns the difference between the 
// @return first two differing bytes
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// @brief locates the first occurrence of the 
// @brief null-termi-nated string needle in the string 
// @brief haystack, where not more than len char-acters are searched. 
// @brief Characters that appear after a `\0' character are not searched.
// @param haystack str to search in
// @param needle str to search
// @param len len of haystack to search in
// @return If needle is an empty string, haystack is returned.
// @return if needle occurs nowhere in haystack, NULL is returned
// @return otherwise a pointer to the first character of the first 
// @return occurrence of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// @brief converts the initial portion of the string pointed to by str to 
// @brief int representation.
// @param str string to convert
// @return int representation
int		ft_atoi(const char *str);

// @brief contiguously allocates enough space for count objects 
// @brief that are size bytes of memory each and returns a pointer 
// @brief to the allocated memory. The allocated memory is filled 
// @brief with bytes of value zero.
// @param count number of object to allocate
// @param size size of each object
// @return pointer to the allocated memory
void	*ft_calloc(size_t count, size_t size);

// @brief allocates sufficient memory for a copy of the 
// @brief string s1, does the copy, and returns a pointer to it.
// @param s1 string to copy
// @return pointer to the copied string
char	*ft_strdup(const char *s1);

// @brief Allocates with malloc and returns a substring from the string ’s’. 
// @brief The substring begins at index ’start’ and is of maximum size ’len’.
// @param s The string from which to create the substring.
// @param start The start index of the substring in the string ’s’.
// @param len The maximum length of the substring.
// @return The substring. 
// @return NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
// @param s1 The prefix string.
// @param s2 The suffix string.
// @return The new string.
// @return NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2);

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
// @param s1 The string to be trimmed.
// @param set The reference set of characters to trim.
// @return The trimmed string.
// @return NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

// @brief Allocates (with malloc(3)) and returns an array
// @brief of strings obtained by splitting ’s’ using the
// @brief character ’c’ as a delimiter.  The array must end
// @brief with a NULL pointer.
// @param s The string to be split.
// @param c The delimiter character.
// @return The array of new strings resulting from the split.
// @return NULL if the allocation fails.
char	**ft_split(char const *s, char c);

// @brief Allocates (with malloc(3)) and returns a string
// @brief representing the integer received as an argument. 
// @param n the integer to convert.
// @return The string representing the integer.
// @return NULL if the allocation fails.
char	*ft_itoa(int n);

// @brief Applies the function ’f’ to each character of the 
// @brief string ’s’, and passing its index as first argument 
// @brief to create a new string (with malloc(3)) resulting 
// @brief from successive applications of ’f’.
// @param s The string on which to iterate. 
// @param f The function to apply to each character.
// @return The string created from the successive applications 
// @return of ’f’. 
// @return Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// @brief Applies the function ’f’ on each character of
// @brief the string passed as argument, passing its index
// @brief as first argument.  Each character is passed by
// @brief address to ’f’ to be modified if necessary.
// @param s The string on which to iterate.
// @param f The function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// @brief Outputs the character ’c’ to the given file
// @brief descriptor.
// @param c The character to output.
// @param fd The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd);

// @brief Outputs the string ’s’ to the given file
// @brief descriptor.
// @param s The string to output.
// @param fd The file descriptor on which to write.
void	ft_putstr_fd(char *s, int fd);

// @brief Outputs the string ’s’ to the given file descriptor
// @brief followed by a newline.
// @param s The string to output.
// @param fd The file descriptor on which to write.
void	ft_putendl_fd(char *s, int fd);

// @brief Outputs the integer ’n’ to the given file
// @brief descriptor.
// @param n The integer to output.
// @param fd The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd);

#endif