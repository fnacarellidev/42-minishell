/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:48:52 by revieira          #+#    #+#             */
/*   Updated: 2023/04/02 01:06:41 by revieira         ###   ########.fr       */
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

int	is_valid_var(char *str)
{
	if (*str == '$' && (ft_isalpha(*(str + 1)) || *(str + 1) == '_'))
		return (1);
	return (0);
}

int	check_quoted(char c)
{
	static int status_quote;

	if (status_quote == c)
	{
		status_quote = 0;
		return (0);
	}
	if (!status_quote)
		status_quote = c;
	if (status_quote == SINGLE_QUOTE)
		return (1);
	else
		return (-1);
}

void	expand_vars(char **token)
{
	int		i;
	char	*key;
	char	*value;
	char	*new_token;

	i = 0;
	new_token = ft_strdup("");
	while ((*token)[i])
	{
		if (check_quoted((*token)[i]) == 1 || !is_valid_var(&(*token)[i]))
			append(&new_token, ft_strndup(&(*token)[i++], 1));
		else
		{
			key = extract_key(&(*token)[i + 1]);
			value = get_key_value(g_minishell.envp, key);
			append(&new_token, ft_strdup(value));
			i += ft_strlen(key) + 1;
			free(key);
		}
	}
	free(*token);
	*token = new_token;
}
