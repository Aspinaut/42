#include "../includes/ft_printf.h"

static void ft_init_vartab(t_var *vartab)
{
//   vartab->args = 0;
  vartab->len_to_print = 0;
//   return (vartab);
}

int test(const char *s, ...)
{
    // basic use of va_args
    // va_list args;

    // va_start(args, s);
    // printf("INT : %d\n", va_arg(args, int));
    // printf("CHAR : %c\n", va_arg(args, int));
    // printf("STR : %s\n", va_arg(args, char *));
    // va_end(args);

    // use of va_args with tab
    va_list args;
    t_var *tab;
    
    tab = (t_var *)malloc(sizeof(t_var));
    ft_init_vartab(tab);
    va_start(tab->args, s);
    printf("INT : %d\n", va_arg(tab->args, int));
    printf("CHAR : %c\n", va_arg(tab->args, int));
    printf("STR : %s\n", va_arg(tab->args, char *));
    va_end(tab->args);
    return (0);
}

int main()
{
    test("salut", 10, 'a', "coucou");
    return (0);
}