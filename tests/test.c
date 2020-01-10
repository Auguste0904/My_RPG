/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_rpg.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* Test(test_init, lunch_game, .init = redirect_all_stdout)
{
    game_t game;
    char **av = malloc(sizeof(char *) * 2);

    av[0] = my_strdup("my_rpg");
    av[1] = my_strdup(NULL);
    cr_expect_eq(main_menu(&game), 0);
} */

Test(test, help, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = my_strdup("my_rpg");
    av[1] = my_strdup("-h");
    av[2] = my_strdup(NULL);
    cr_expect_eq(display_help(), 0);
}

Test(test2, arg, .init = redirect_all_stdout)
{
    int ac = 2;

    cr_expect_neq(ac, 84);
}

Test(test3, env, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 4);
    char **env = NULL;

    av[0] = my_strdup("env");
    av[1] = my_strdup("-i");
    av[2] = my_strdup("./my_rpg");
    av[3] = my_strdup(NULL);
    cr_expect_eq(error_gestion(env), 84);
}