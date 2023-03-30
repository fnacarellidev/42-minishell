/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:48:52 by revieira          #+#    #+#             */
/*   Updated: 2023/03/29 22:16:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	*extract_key(char *var)
{
	char	*end_var;
	char	*key;

	end_var = var;
	while (is_bash_char(*end_var))
		end_var++;
	key = ft_substr(var, 0, end_var - var);
	return (key);
}

static void	append(char **s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(*s1, s2);
	free(*s1);
	free(s2);
	*s1 = new_str;
}

void	expand_vars(char **token)
{
	int		i;
	int		j;
	char	*key;
	char	*value;
	char	*new_token;

	i = 0;
	j = 0;
	new_token = ft_calloc(sizeof(char), ft_strlen(*token) + 1);
	while ((*token)[i])
	{
		if ((*token)[i] == '$')
		{
			key = extract_key(&(*token)[i + 1]);
			value = get_key_value(g_minishell.envp, key);
			append(&new_token, ft_strdup(value));
			i += ft_strlen(key) + 1;
			j += ft_strlen(value);
			free(key);
		}
		else
			new_token[j++] = (*token)[i++];
	}
	free(*token);
	*token = new_token;
}
