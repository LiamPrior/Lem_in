/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:24:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/12 12:13:29 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_wstrlen(wchar_t *ws)
{
	int	len;
	
	len = 0;
	while (ws[len])
	{
		if (ws[len] > 0xFF)
			return (-1);
		len++;
	}
	return (len);
}
