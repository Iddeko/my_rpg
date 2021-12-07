/*
** EPITECH PROJECT, 2021
** header
** File description:
** header for the my lib
*/

#ifndef MY_LIB_H
    #define MY_LIB_H

    #include <stdarg.h>

    #define ABS(x) (x < 0) ? -x : x;

char *my_strdup(char const *);
char *my_strstr(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strupcase(char *);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
char my_getoperator(char const *);
char **my_strsplit(char *, char);
char *my_substr(int, int, char const *);

int my_compute_power(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_is_prime(int);
int my_showmem(char const *, int);
int my_showstr(char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strncmp(char const *, char const *, int);
int my_getnbr(char const *);
int my_char_isalpha(char const);
int my_char_isnum(char const);
int my_char_isoperator(char const);
int my_str_isoperator(char const *);
int my_strlen(char const *);
char *my_dec_to_base(long, char *);
char *my_dec_to_base_long(long long, char *);
char *my_dec_to_base_unsigned(unsigned long long, char *);

void my_swap(int *, int *);
void my_put_nbr(int);
void my_sort_int_array(int *, int);

typedef struct formats {
    char number[11];
    int is_long;
    int is_long_long;
    int is_short;
    int is_short_short;
    int is_hasht;
    int go_next;
    int to_return;
} formats;

int my_printf(char *, ...);
int write_string(va_list, formats);
int write_int(va_list, formats, char *);
int write_hex(va_list, formats, char *);
int write_hex_2(va_list, formats, char *);
int write_char(va_list, formats);
int write_binary(va_list, formats, char *);
int write_unsigned(va_list, formats, char *);
int write_pointeur(va_list, formats, char *);
int write_octal(va_list, formats, char *);
int write_unsigned_int(va_list, formats);
int write_string_formated(va_list, formats);
int write_char_none(int);
int process_char(char *, int, va_list, formats);

int print_elem_numbers(int, char *, va_list, formats);
formats print_elem_formats(int, char *, formats);
int print_elem_flags_1(int, char *, va_list, formats);
int print_elem_flags_2(int, char *, va_list, formats);

int long_or_normal(formats, int);
int short_or_normal(formats, int);
void print_spaces_minus(formats, char *);
void print_spaces(formats, char *);

formats reset_struct(formats);
formats modify_short(formats);
formats modify_long(formats);
formats modify_hashtag(formats);

#endif /* !MY_LIB_H */
