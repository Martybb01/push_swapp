/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:37:44 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 08:30:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

// void delContent(void *content)
// {
//     free(content); // Free the string content
// }

// int main()
// {
//     t_list *list = NULL;
//     char *str = ft_strdup("Hello World!");
//     t_list *node1 = ft_lstnew(str);
//     ft_lstadd_front(&list, node1);
//     ft_lstdelone(node1, delContent);
//     printf("%s\n", (char *)list->content);
// }
