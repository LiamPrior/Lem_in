/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:19:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/12 12:13:20 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		x;
	
	x = 0;
	i = ft_strlen(str);
	rev = (char *)malloc(sizeof(char) * (i + 1));
	while (--i > -1)
		rev[x++] = str[i];
	rev[x] = '\0';
	free(str);
	return (rev);
}
