/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:19:50 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/12 12:13:24 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strstr(char *str, char *to_find)
{
	int		begin;
	int		i;
	int		j;

	i = 0;
	begin = 0;
	while (str[i])
	{
		j = 0;
		begin = i;
		while (str[i] && str[i++] == to_find[j++])
			;
		if (to_find[j] == '\0')
			return (1);
		if (str[i] == '\0')
			return (0);
		i = begin + 1;
	}
	return (0);
}
