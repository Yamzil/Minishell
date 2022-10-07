/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:19:28 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:19:30 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_checkpip(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup("|"), PIP));
	return (i + 1);
}

int	ft_checkroutput(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup(">"), ROUTPUT));
	return (i + 1);
}

int	ft_checkrinput(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup("<"), RINPUT));
	return (i + 1);
}

int	ft_checkdinput(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup(">>"), DINPUT));
	return (i + 2);
}

int	ft_checkdoutput(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup("<<"), DOUTPUT));
	return (i + 2);
}
