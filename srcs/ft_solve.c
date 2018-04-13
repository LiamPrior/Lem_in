/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:09:14 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/12 12:18:05 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		multi_path(t_file *file, t_room *ptr)
{
	int		cur;
	int		weight;
	char	*name;

	cur = 0;
	name = ft_strnew(1);
	name = ft_strjoin(name, " ");
	name = ft_strjoin(name, ptr->name);
	name = ft_strjoin(name, " ");
	while (cur < file->nb_paths)
	{
		if (ft_strcmp(ALL_PATHS[cur], "\0") && ft_strstr(ALL_PATHS[cur], name))
		{
			weight = ft_atoi(ALL_PATHS[cur]);
			if (find_room(file, file->end)->weight >= weight)
				return (-1);
			else
			{
				free(ALL_PATHS[cur]);
				ALL_PATHS[cur] = ft_strnew(1);
			}
		}
		cur++;
	}
	return (0);
}

void	save_path(t_file *file)
{
	t_room	*ptr;
	char	*path;
	char	*weight;

	path = ft_strnew(1);
	ptr = find_room(file, file->start);
	weight = ft_itoa(find_room(file, file->end)->weight);
	path = ft_strjoin(path, weight);
	free(weight);
	path = ft_strjoin(path, ":");
	while (ptr && ft_strcmp(ptr->name, file->end) != 0)
	{
		if (multi_path(file, ptr) == -1)
			return ;
		path = ft_strjoin(path, ptr->name);
		path = ft_strjoin(path, " ");
		ptr = find_room(file, (ROOMS[ptr->path])->name);
	}
	path = ft_strjoin(path, ptr->name);
	ALL_PATHS[file->nb_paths++] = path;
}

int		find_path(t_file *file, t_room *ptr, int w)
{
	t_room *head;

	head = ptr;
	if (head)
	{
		head->open = false;
		head->weight = w;
	}
	while (ptr)
	{
		while (ptr && find_room(file, ptr->name)->open == false)
			ptr = ptr->next;
		if (ptr && ft_strcmp(ptr->name, file->end) == 0)
		{
			head->path = room_pos(file, ptr->name);
			find_room(file, file->end)->weight = w + 1;
			save_path(file);
			ptr = ptr->next;
		}
		else if (ptr)
		{
			head->path = room_pos(file, ptr->name);
			find_path(file, ROOMS[room_pos(file, ptr->name)], 1 + w);
			ptr = ptr->next;
		}
	}
	if (head)
		head->open = true;
	return (file->nb_paths);
}

void	ft_solve(t_file *file)
{
	t_room	*curr;

	if ((curr = find_room(file, file->start)) == NULL)
		error(6);
	if (find_path(file, curr, 0) == 0)
		error(5);
	print_path(file);
}