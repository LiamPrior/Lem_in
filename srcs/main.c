/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:25:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/05 20:50:07 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	init(t_file *file)
{
	file->ants = -1;
	file->map = NULL;
	file->line = NULL;
	file->nb_rooms = 0;
	file->rooms = (t_room **)malloc(sizeof(t_room *) * MAX_ROOMS_NB);
	ft_bzero(file->rooms, MAX_ROOMS_NB);
	file->start = NULL;
	file->nb_paths = 0;
	file->paths = (char **)malloc(sizeof(char *) * MAX_PATHS_NB);
	ft_bzero(ROOMS, MAX_PATHS_NB);
	file->end = NULL;
	file->offset = 0;
}

int     main(int ac, char **av)
{
    t_file file;
	
	init(&file);
	// printf("HERE\n");
	file.map = readandstore();
    parse(&file);
	// printf("after parising:\nstart: [%s]\nend: [%s]\n", file.start, file.end);
	// solve(&file);
	// free_file(&file);
	return (0);
}
