/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:25:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/12 14:34:54 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_init(t_file *file)
{
	file->ants = -1;
	file->map = NULL;
	file->line = NULL;
	file->nb_rooms = 0;
	file->rooms = (t_room **)malloc(sizeof(t_room *) * MAX_ROOMS_NB);
	file->start = NULL;
	file->nb_paths = 0;
	file->paths = (char **)malloc(sizeof(char *) * MAX_PATHS_NB);
	file->end = NULL;
	file->offset = 0;
}

int		main(void)
{
	t_file	file;

	ft_init(&file);
	file.map = readandstore();
	ft_parse(&file);
	sleep(10);
	ft_solve(&file);
	free_file(&file);
	return (0);
}
