/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/21 11:39:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define	MAX_LONG	9223372036854775807

typedef struct s_stack
{
	int	nb;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_addnew(int nb);
void	stack_addback(t_stack **alst, t_stack *new);

// t_list	*ft_lstlast(t_list *lst);
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
// void	ft_lstadd_front(t_list **lst, t_list *new);
// void	ft_lstadd_back(t_list **alst, t_list *new);
// void	ft_lstclear(t_list **lst, void (*del)(void*));
// void	ft_lstdelone(t_list *lst, void (*del)(void*));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// int			ft_lstsize(t_list *lst);

int	ft_putstr_fd(char const *s, int fd);
long	ft_atol(const char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif
