#include "push_swap.h"

int is_flag(char *arg)
{
    return (!ft_strcmp(arg, "--bench")
        || !ft_strcmp(arg, "--simple")
        || !ft_strcmp(arg, "--medium")
        || !ft_strcmp(arg, "--complex")
        || !ft_strcmp(arg, "--adaptive"));
}
int find_first_number(int argc, char **argv)
{
    int i = 1;

    while (i < argc && is_flag(argv[i]))
        i++;
    return (i);
}
