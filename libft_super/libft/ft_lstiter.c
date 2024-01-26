/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:31:31 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 18:48:44 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// static void printContent(void *content)
// {
//     printf("%s\n", (char *)content);
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
//     ft_lstiter(list, printContent);
// }
