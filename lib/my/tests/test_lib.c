/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** test_lib
*/

#include <criterion/criterion.h>

#include "my.h"

Test(my_char_isalpha, basic)
{
    char cha = 's';

    cr_assert_eq(my_char_isalpha(cha), 1);
}

Test(my_char_isalpha, basic_2)
{
    char cha = 'z';

    cr_assert_eq(my_char_isalpha(cha), 1);
}


Test(my_char_isalpha, wrong)
{
    char cha = '%';

    cr_assert_eq(my_char_isalpha(cha), 0);
}

Test(my_char_isalpha, wrong_2)
{
    char cha = '-';

    cr_assert_eq(my_char_isalpha(cha), 0);
}

Test(my_char_isnum, wrong)
{
    char cha = '-';

    cr_assert_eq(my_char_isnum(cha), 0);
}

Test(my_char_isnum, wrong_2)
{
    char cha = 'a';

    cr_assert_eq(my_char_isnum(cha), 0);
}

Test(my_char_isnum, basic)
{
    char cha = '1';

    cr_assert_eq(my_char_isnum(cha), 1);
}

Test(my_char_isnum, basic_2)
{
    char cha = '9';

    cr_assert_eq(my_char_isnum(cha), 1);
}

Test(my_char_isoperator, basic)
{
    char cha = '*';

    cr_assert_eq(my_char_isoperator(cha), 1);
}

Test(my_char_isoperator, basic_2)
{
    char cha = '+';

    cr_assert_eq(my_char_isoperator(cha), 1);
}

Test(my_char_isoperator, wrong)
{
    char cha = '1';

    cr_assert_eq(my_char_isoperator(cha), 0);
}

Test(my_char_isoperator, wrong_2)
{
    char cha = 'a';

    cr_assert_eq(my_char_isoperator(cha), 0);
}

Test(my_compute_power, 1)
{
    cr_assert_eq(my_compute_power(1,1), 1);
}

Test(my_compute_power, 2)
{
    cr_assert_eq(my_compute_power(2,1), 2);
}

Test(my_compute_power, 16)
{
    cr_assert_eq(my_compute_power(4,2), 16);
}


Test(my_compute_power, 0)
{
    cr_assert_eq(my_compute_power(4,0), 1);
}

Test(my_compute_power, minus1)
{
    cr_assert_eq(my_compute_power(4,-1), 0);
}

Test(my_compute_square_root, 2)
{
    cr_assert_eq(my_compute_square_root(4), 2);
}

Test(my_compute_square_root, 4)
{
    cr_assert_eq(my_compute_square_root(16), 4);
}

Test(my_getnbr, 4)
{
    char *str = "4";

    cr_assert_eq(my_getnbr(str), 4);
}

Test(my_getnbr, 8)
{
    char *str = "8k,";

    cr_assert_eq(my_getnbr(str), 8);
}

Test(my_getnbr, 227782788)
{
    char *str = "227782788yuhue";

    cr_assert_eq(my_getnbr(str), 227782788);
}

Test(my_getnbr, 22778278)
{
    char *str = "-22778278yuhue";
    int i = -22778278;

    cr_assert_eq(my_getnbr(str), i);
}

Test(my_getnbr, multiple_minus)
{
    char *str = "-++--++-227yuhue";
    int i = 227;

    cr_assert_eq(my_getnbr(str), i);
}

Test(my_getnbr, multiple_minus_2)
{
    char *str = "-++--++--227yuhue";
    int i = -227;

    cr_assert_eq(my_getnbr(str), i);
}

Test(my_strdup, basic)
{
    char *str = "crab";
    char *str_dup = my_strdup(str);

    cr_assert_str_eq(str, str_dup);
}

Test(my_strdup, basic2)
{
    char *str = "crab\ntest\\j";
    char *str_dup = my_strdup(str);

    cr_assert_str_eq(str, str_dup);
}

Test(my_substr, basic)
{
    char *str = "crab\ntest\\j";
    char *sub_str = my_substr(1,2,str);

    cr_assert_str_eq("r", sub_str);
}

Test(my_substr, basic2)
{
    char *str = "crab\ntest\\j";
    char *new_line = "\n";
    char *sub_str = my_substr(4,5,str);

    cr_assert_str_eq(new_line, sub_str);
}

/*
Test(my_strsplit, basic)
{
    char *str = "Je suis une phrase";
    char *my_str_array[4] = {"Je", "suis", "une", "phrase"};
    char **str_array = my_strsplit(str, ' ');

    cr_assert_str_eq(str_array[0], my_str_array[0]);
    cr_assert_str_eq(str_array[1], my_str_array[1]);
    cr_assert_str_eq(str_array[2], my_str_array[2]);
    cr_assert_str_eq(str_array[3], my_str_array[3]);
}

Test(my_strsplit, basic_2)
{
    char *str = "Je\nsuis\nun\ntableau";
    char *my_str_array[4] = {"Je", "suis", "un", "tableau"};
    char **str_array = my_strsplit(str, '\n');

    cr_assert_str_eq(str_array[0], my_str_array[0]);
    cr_assert_str_eq(str_array[1], my_str_array[1]);
    cr_assert_str_eq(str_array[2], my_str_array[2]);
    cr_assert_str_eq(str_array[3], my_str_array[3]);
}

Test(my_strsplit, basic_3)
{
    char *str = "Je\nsuis\nun\ntableau\nlong\n";
    char *my_str_array[6] = {"Je", "suis", "un", "tableau", "long", ""};
    char **str_array = my_strsplit(str, '\n');

    cr_assert_str_eq(str_array[0], my_str_array[0]);
    cr_assert_str_eq(str_array[1], my_str_array[1]);
    cr_assert_str_eq(str_array[2], my_str_array[2]);
    cr_assert_str_eq(str_array[3], my_str_array[3]);
    cr_assert_str_eq(str_array[4], my_str_array[4]);
    cr_assert_str_eq(str_array[5], my_str_array[5]);
}

Test(my_strsplit, short_one)
{
    char *str = "Je";
    char *my_str_array[5] = {"Je"};
    char **str_array = my_strsplit(str, '\n');

    cr_assert_str_eq(str_array[0], my_str_array[0]);
}
 */
