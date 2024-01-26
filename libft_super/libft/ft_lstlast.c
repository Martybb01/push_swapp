/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:20:41 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 17:30:21 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
//     printf("%s\n", (char *)ft_lstlast(list)->content);
// }
