/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** muh library
*/

#ifndef _MY_H_
    #define _MY_H_

    #include <fcntl.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>

    #ifndef READ_SIZE
        #define READ_SIZE (1)
    #endif // READ_SIZE

    #ifndef PATH_MAX
        #define PATH_MAX (8192)
    #endif

    #define MIN(i, j) (((i) < (j)) ? (i) : (j))
    #define MAX(i, j) (((i) > (j)) ? (i) : (j))
    #define ABS(i)    (((i) > 0)   ? (i) : -(i))

typedef unsigned long long int ull_t;
typedef unsigned long int ul_t;
typedef unsigned int uint_t;
typedef long long int ll_t;
typedef long int l_t;

struct btree {
    struct btree *left;
    struct btree *right;
    struct btree *parent;
    struct btree *next;
    struct btree *root;
    void *data;
};
typedef struct btree btree_t;

typedef struct node {
    struct node *n;
    struct node *p;
    void *d;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

typedef struct file_desc_s {
    int fd;
    int ridx;
    int rbuf[READ_SIZE + 2];
    struct file_desc_s *next;
} file_desc_t;

btree_t *btree_create_node(char *);
void btree_insert_data(btree_t *, char *, int (*)());
size_t btree_level_count(btree_t const *);
void btree_destroy(btree_t *);

void btree_apply_infix(btree_t *, long long int (*)(char *));
void btree_apply_prefix(btree_t *, long long int (*)(char *));
void btree_apply_postfix(btree_t *root, long long int (*)(char *));


list_t *list_create(node_t *);
node_t *node_create(void *);
void node_rm(node_t *);
node_t *list_cut_node(list_t *, node_t *);
void *list_a_cut_node(list_t *, node_t *);

list_t *list_append(list_t *, list_t *);
list_t *list_prepend(list_t *, list_t *);
list_t *list_n_append(list_t *, node_t *);
list_t *list_n_prepend(list_t *, node_t *);

void list_rm(list_t *);
list_t *list_a_append(list_t *, void *);
list_t *list_a_prepend(list_t *, void *);

node_t *list_pop_head(list_t *);
node_t *list_pop_tail(list_t *);
void *list_pop_a_head(list_t *);
void *list_pop_a_tail(list_t *);


int my_printf(char const *, ...);

size_t my_strlen(char const *);
int my_putchar(int const);
size_t my_putstr(char const *);
size_t my_puts(char const *);
size_t my_fputstr(char *, int const);
size_t my_fputs(char *, int const);
int my_fputchar(char const, int const);
int my_vfputstr(int const, size_t const, ...);
size_t my_numlen(long long int);
size_t my_putnbr(int);
size_t my_putnbr_base(int, char const *);
long long int dysfunctional_my_getnbr(char const *);
long long int dysfunctional_getnbr_rec(char const *, long long int);
long long int my_strtoll(char *, char **);
long double my_strtold(char *, char **);
int my_atoi(char const **);
long long int my_atoll(char const *);
char *my_itoa(int);

char *my_revstr(char *);
char *my_strstr(char *, char const *);

char my_toupper(const char);
char my_tolower(const char);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);

int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, size_t);
void my_showstr(char const *);

char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, size_t const);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, size_t const);

char *my_strccat(char *, char const *, char const);
char *my_strccpy(char *, char const *, char const);

int is_in(char const, char const *);
void my_swap(int *, int *);
void bsort_int(int *, int);

int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);

int my_isdigit(char);
int my_isupper(char);
int my_islower(char);
int my_isalpha(char);
int my_isspace(char);
int my_isprintable(char);

char **str_to_tab(char * const, char const *);
char *tab_to_str(char ** const, char const *, char const *, char const *);
int show_tab(char const **, char const *);
size_t my_tablen(char **);
void free_array(char **);
char *my_strdup(char const *);
char *my_strndup(char *, size_t );
void *my_memset(char *, char, size_t);
char *my_realloc(char *, int);
void *gib(size_t);
void *regib(char *, int);
void *my_memcpy(void *, const void *, size_t);
void *my_memmove(void *, const void *, size_t);

char *my_strtok(char *, char const *);
char *my_strsep(char **p, char const *);
size_t my_strpn(char const *, char const *, bool);

char *getl(int const);
char *getd(int const, int const);

size_t err(char const *);
size_t errb(char const *);
size_t errc(char *, char const *);
size_t errm(char **, char const *);
#endif // _MY_H_
