/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:25:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/05 20:26:18 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*get_name(char *line)
{
	int i;
	int iname;
	char	*str;
	i = 0;
	iname = 0;
	str = ft_strnew(MAX_NAME_LEN);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		str[iname++] = line[i++];
	return (str);
}

void	get_ants(t_file *file)
{
	int	i;
	
	i = 0;
	if (file->line[i] > 57 || file->line[i] < 48)
		error();
	file->ants = ft_atoi(file->line);
	while (file->line[i] < 58 && file->line[i] > 47)
		i++;
	while (file->line[i] == '\t' || file->line[i] == ' ')
		i++;
	if (file->line[i] != '\0')
	{
		error();
	}
}

void   comment_command(t_file *file)
{
	int i;
	
	i = 0;
		printf("%s[%s]%s\n", RED, file->line, NORMAL);
	while (file->line[i] != '#' && file->line[i] != '\0')
		i++;
	if (file->line[i] == '\0')
		return ;
	if (file->line[i + 1] != '#')
	{
		//		if (file->line[i] == '#') printf("comment removed\n");
		file->line[i] = '\0';
	}
	else
	{
		printf("%s\n", &(file->line[i]));
		if (file->end == NULL && ft_strncmp(&(file->line[i]), "##end", 5) == 0 && gnl(file))
		{
						printf("ENDING\n");
			file->end = get_name(file->line);
		}
		else if (file->start == NULL && ft_strncmp(&(file->line[i]), "##start", 7) == 0 && gnl(file))
		{
						printf("STARTING\n");
			file->start = get_name(file->line);
		}
		else
		{
			printf("here dfdfgg\n");
			error();
		}
	}
	if (ft_strcmp(file->line, "\0") == 0)
	{
		gnl(file);
		comment_command(file);
	}
}

void    parse(t_file *file)
{
	if (gnl(file) == 0)
		error();
	
	get_ants(file);
	printf("ants: %d\n", file->ants);
	printf("%s[%s]%s\n", CYAN, file->line, NORMAL);
	rooms(file);
	if (file->ants < 0 || file->start == NULL || file->end == NULL)
		error();
	printf("AFTER PARSING ROOMS\n");
	connect(file);
	
	
	int		i = 0;
	t_room	*ptr;

//	while (i < file->nb_rooms)
//	{
//		ptr = ROOMS[i];
//		while (ptr != NULL)
//		{
//			printf("%s %d -> ", ptr->name, ptr->weight);
//			ptr = ptr->next;
//		}
//		printf("null\n");
//		i++;
//	}
//	printf("%s", NORMAL);
}
