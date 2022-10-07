/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:50 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:55:49 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	checker_key(char *var)
{
	int	lenght;

	lenght = ft_strlen(var);
	if (var[lenght - 1] == '+' && ft_isalpha(var[lenght - 2]) == 1)
		lenght--;
	while ((lenght - 1) >= 0)
	{
		if (ft_isalpha(var[lenght - 1]) == 0)
			return (0);
		lenght--;
	}
	return (1);
}

static int	checker_value(char *var)
{
	int	i;

	i = -1;
	while (var[++i])
	{
		if (var[i] == '+')
			continue ;
	}
	return (1);
}

static int	check_var_existance(t_env *envar, char *name, char *value)
{
	t_env	*tmp;
	int		length;

	tmp = envar;
	while (tmp)
	{
		length = ft_strlen(tmp->key);
		if (ft_strncmp(tmp->key, name, length) == 0)
		{
			if (name[length] != '+')
				tmp->value = value;
			else if (name[length] == '+')
				tmp->value = ft_strjoin(tmp->value, value);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	add_var(t_args *line, t_env **envar)
{	
	int	i;

	i = 0;
	while (line->arg[++i])
	{
		if (!(*envar))
		{
			*envar = create_var_list(&line->arg[1]);
			(*envar)->next = NULL;
		}
		else if ((checker_key(var_name(line->arg[i])) == 1) && \
				(checker_value(var_value(line->arg[i])) == 1))
		{
			if (!check_var_existance(*envar, var_name(line->arg[i]), \
						var_value(line->arg[i])))
				add_node_at_end(envar, var_name(line->arg[i]), \
						var_value(line->arg[i]));
		}
		else
			print_msg(line->arg[i]);
	}
}

void	ft_export(t_args *line, t_env **envar)
{
	if (!line->arg[1])
		sort_and_print(envar);
	else
		add_var(line, envar);
}
