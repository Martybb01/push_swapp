/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:30:41 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 18:41:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
// static void delContent(void *content)
// {
//     free(content); // Free the string content
// }

// int main()
// {
//     t_list *list = NULL;
//     char *str = ft_strdup("Hello World!");
//     char *str2 = ft_strdup("Spiderman");
//     t_list *node1 = ft_lstnew(str);
//     t_list *node2 = ft_lstnew(str2);
//     ft_lstadd_back(&list, node1);
//     ft_lstadd_back(&list, node2);
//     ft_lstclear(&list, delContent);
//     if (!list)
//         printf("List is empty\n");
//     else
//         printf("List is not empty\n");
// }
