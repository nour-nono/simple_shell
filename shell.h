#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>
extern char **environ;

/*is_file*/
void is_file(char *program_name, char *filename);

/*is_interactive*/
void is_interactive(char *program_name);

/*is_non_interactive*/
void is_non_interactive(char *program_name);

/*token*/
unsigned int is_delim(char c, char *delimiters);
char *_strtok(char *str, char *delimiters);
char **make_arr_of_str(char *str, char *delimiters);
void remove_comment(char *str);

/*string_funcs*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
int _atoi(char *s);

/*env_funcs*/
int search_for_env(const char *name);
char *_get_env(const char *name);
int _set_env(char **arr, int overwrite);
int _unset_env(char *key);

/*exec_commands*/
char *search_for_command_in_paths(char *command);
void exec_command(char *command, char **command_and_argu, int *status);

/*free_array*/
void free_array(char **arr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*implemented funcs*/
void remove_comment(char *str);
void print_env(void);
void is_exit(char **arr, int status, int i, char *program_name);

/*get_line*/
ssize_t get_line(char **lineptr, size_t *n, int fd, int flag1);

/*show_error*/
int _pow(int a, int b);
void int_to_string(char *arr, int zz);
void show_error(char *program_name, int i, char *command, char *err);

/*replace_var*/
char **replace_var(char **arr, int status);
char *change_to_status(char *arr_str, int status);
char *change_to_pid(char *arr_str);
char *change_to_env_var(char *arr_str);

/*search_in_implemented_functions*/
int search_in_implemented(char **arr, int *status, int i, char *program_name);

#endif

