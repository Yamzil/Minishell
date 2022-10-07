/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:20:12 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:20:13 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_length_of_next_token(int i, char *line, t_tk **list)
{
	int	word;

	if (line[i] == '$')
		return (ft_checkdollar(i, line, list));
	else if (line[i] == '\'')
		return (ft_checksquotes(i + 1, line, list));
	else if (line[i] == '\"')
		return (ft_checkdquotes(i + 1, line, list));
	else if (line[i] == '|')
		return (ft_checkpip(i, list));
	else if (line[i] == '>' && line[i + 1] == '>')
		return (ft_checkdinput(i, list));
	else if (line[i] == '<' && line[i + 1] == '<')
		return (ft_checkdoutput(i, list));
	else if (line[i] == '>')
		return (ft_checkroutput(i, list));
	else if (line[i] == '<')
		return (ft_checkrinput(i, list));
	else if (line[i] == ' ')
		return (ft_checkspace(i, list));
	else
		word = ft_getword(line, i);
	ft_addtolist(list, ft_input(ft_substr(line, i, word - i), WORD));
	return (word);
}

t_tk	*ft_lexer(char *line)
{
	t_tk	*list;
	int		i;

	i = 0;
	line = ft_strtrim(line, " ");
	list = NULL;
	while (line[i])
		i = get_length_of_next_token(i, line, &list);
	return (list);
}
