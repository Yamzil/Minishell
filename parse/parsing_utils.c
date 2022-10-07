/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:13:52 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:15:00 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_collectword(t_tk **list, t_args **word)
{
	char	**tmp1;
	char	*tmp;

	tmp = NULL;
	tmp1 = NULL;
	while ((*list) && ((*list)->token == WORD || (*list)->token == VAR
			|| (*list)->token == SP || (*list)->token == SQUOTE))
	{
		tmp = ft_strjoin_v2(tmp, (*list)->input);
		(*list) = (*list)->next;
		if ((*list) && ((*list)->token == SP))
		{
				(*list) = (*list)->next;
			tmp1 = ft_table(tmp1, tmp);
			free (tmp);
			tmp = NULL;
		}
	}
	tmp1 = ft_table(tmp1, tmp);
	ft_addbackarg(word, ft_args_node(tmp1, COMMAND));
}

void	ft_collectpip(t_tk **list, t_args **pip)
{
	char	**tmp1;

	tmp1 = NULL;
	(*list) = (*list)->next;
	tmp1 = ft_table (NULL, NULL);
	ft_addbackarg(pip, ft_args_node(tmp1, PIPE));
}

void	ft_collectinput(t_tk **list, t_args **redirection)
{
	char	**tmp1;
	char	*tmp;

	tmp = NULL;
	tmp1 = NULL;
	(*list) = (*list)->next;
	if ((*list) && (*list)->token == SP)
		(*list) = (*list)->next;
	while ((*list) && ((*list)->token == WORD
			|| (*list)->token == VAR || (*list)->token == SQUOTE))
	{
		if ((*list)->token == SP)
			(*list) = (*list)->next;
		tmp = ft_strjoin_v2 (tmp, (*list)->input);
		(*list) = (*list)->next;
	}
	tmp1 = ft_table(tmp1, tmp);
	ft_addbackarg(redirection, ft_args_node(tmp1, IN));
}
