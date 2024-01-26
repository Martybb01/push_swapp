/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:09:53 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 17:10:48 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
// int main()
// {
//     t_list *list = NULL;
//     char *str = "Hello World!";
//     char *str2 = "Spiderman";
//     t_list *node1 = ft_lstnew(str);
//     t_list *node2 = ft_lstnew(str2);
//     ft_lstadd_front(&list, node1);
//     ft_lstadd_front(&list, node2);
//     printf("%s\n", (char *)list->content);
//     printf("%s\n", (char *)list->next->content);
// }
