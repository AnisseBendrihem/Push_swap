/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:32:44 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 19:12:16 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Libc & Allocation */
# include <assert.h>       // assert()
# include <ctype.h>        // isdigit, isalpha, toupper, etc.
# include <dirent.h>       // opendir, readdir, closedir
# include <errno.h>        // errno, perror
# include <fcntl.h>        // open, O_RDONLY, O_CREAT, etc.
# include <float.h>        // FLT_MAX, DBL_EPSILON
# include <grp.h>          // getgrgid
# include <limits.h>       // INT_MAX, LONG_MIN, etc.
# include <locale.h>       // setlocale
# include <math.h>         // sin, cos, pow, sqrt
# include <pwd.h>          // getpwuid
# include <signal.h>       // signal, sigaction, kill, SIGUSR1, etc.
# include <stdarg.h>       // va_list, va_start, va_arg, va_end
# include <stdbool.h>      // bool, true, false
# include <stddef.h>       // size_t, NULL, offsetof, ptrdiff_t
# include <stddef.h>       // Encore size_t etc. (doublé volontairement)
# include <stdint.h>       // int64_t, uint32_t, etc.
# include <stdio.h>        // printf, fprintf, sprintf, perror, FILE*, stdin
# include <stdlib.h>       // malloc, free, exit, atoi, calloc, realloc, getenv
# include <string.h>       // strlen, strcmp, strcpy, strerror
# include <sys/mman.h>     // mmap, munmap (bonus/minishell)
# include <sys/resource.h> // getrusage
# include <sys/stat.h>     // struct stat, fstat
# include <sys/time.h>     // gettimeofday, struct timeval
# include <sys/types.h>    // pid_t, size_t, etc.
# include <sys/uio.h>      // readv, writev
# include <sys/wait.h>     // wait, waitpid, WIFEXITED
# include <time.h>         // time, clock, nanosleep
# include <unistd.h>       // write, read, close, access, dup, fork, pipe

/* ************************************************************************** */
/*                          Structure de Liste Chaînée                        */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/*                              Fonctions de Tests                            */
/* ************************************************************************** */

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/* ************************************************************************** */
/*                         Fonctions de Conversion                            */
/* ************************************************************************** */

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);

/* ************************************************************************** */
/*                      Fonctions de Manipulation Mémoire                     */
/* ************************************************************************** */

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);

/* ************************************************************************** */
/*                     Fonctions de Manipulation de Chaines                   */
/* ************************************************************************** */

int					ft_strlen(char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strdup(char *src);
char				*ft_strndup(char *src, size_t n);

char				*ft_strchr(char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, char *little, size_t len);
char				**ft_split(const char *s, char c);
char				*ft_substr(char *s, int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s1, char *set);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ************************************************************************** */
/*                     Fonctions d'Affichage sur Fichier                      */
/* ************************************************************************** */

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                          Fonctions de Listes Chaînées (Bonus)              */
/* ************************************************************************** */

/* Création et Manipulation des Maillons */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);

/* Suppression et Nettoyage */
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ************************************************************************** */
/*                             ft_printf - Affichage                          */
/* ************************************************************************** */

int					ft_printf(const char *str, ...);
int					ft_convertf(char mod, va_list args);
int					ft_put_unsigned_nbrf(int n);
int					ft_puthexaf(unsigned long nb, int is_mod);
int					ft_putnbrf(int n);
int					ft_putstrf(char *str);
int					ft_putcharf(char c);

/* ************************************************************************** */
/*                           get_next_line - Lecture                          */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
int					lenof_newline(char *str);
char				*extract_line(char **static_recip, char **read_recip);
char				*next_and_free(char **static_recip, int bytes_read);
int					init_var(int fd, char **final_line, char **read_recip,
						ssize_t *bytes_read);

#endif
