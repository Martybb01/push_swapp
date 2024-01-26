/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:31:58 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 17:50:21 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
// int main()
// {
//     t_list *list = NULL;
//     char *str = "Hello World!";
//     char *str2 = "Spiderman";
//     t_list *node1 = ft_lstnew(str);
//     t_list *node2 = ft_lstnew(str2);
//     ft_lstadd_back(&list, node1);
//     ft_lstadd_back(&list, node2);
//     printf("%s\n", (char *)list->content);
//     printf("%s\n", (char *)list->next->content);
// }
