/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:32:15 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 23:33:04 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
			break ;
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	if (!temp)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	return (new);
}

// static void *my_toupper(void *c)
// {
//     if (ft_isalpha((size_t)c))
//     {
//         char ch = (unsigned char)c;
//         if (c >= 'a' && c <= 'z')
//             return (void *)(size_t)(c - 'a' + 'A');
//     }
//     return (c);
// }

// int main()
// {
//     t_list *list = NULL;
//     char *str = ft_strdup("Hello World!");
//     char *str2 = ft_strdup("Spiderman");
//     t_list *node1 = ft_lstnew(str);
//     t_list *node2 = ft_lstnew(str2);
//     ft_lstadd_front(&list, node1);
//     ft_lstadd_front(&list, node2);
//     t_list *new_list = ft_lstmap(list, my_toupper, free);
//     ft_lstclear(&list, free);
//     list = new_list;
//     printf("%s\n", (char *)list->content);
//     printf("%s\n", (char *)list->next->content);
// }
