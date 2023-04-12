/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 17:43:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

char	**get_subtokens(char *token, int idx)
{
	int		i;
	char	**subtokens;
	char	quoted;

	i = 0;
	if (*token == '\0')
		return (ft_calloc(idx + 1, sizeof(char *)));
	quoted = 0;
	if (is_quote(token[i]))
		quoted = token[i++];
	while (token[i] && ((quoted && quoted != token[i]) || !is_quote(token[i])))
		i++;
	if (quoted && is_quote(token[i]))
		i++;
	subtokens = get_subtokens(token + i, idx + 1);
	subtokens[idx] = ft_substr(token, 0, i);
	return (subtokens);
}

char	*concat_subtokens(char **subtokens)
{
	int		i;
	char	*expanded_token;

	i = 0;
	expanded_token = ft_strdup("");
	while (subtokens[i])
	{
		append(&expanded_token, subtokens[i]);
		i++;
	}
	return (expanded_token);
}

static char	*extract_key(char *var)
{
	char	*end_var;
	char	*key;

	end_var = var;
	if (var[0] == '?')
		return (ft_strdup("?"));
	while (is_bash_char(*end_var))
		end_var++;
	key = ft_substr(var, 0, end_var - var);
	return (key);
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
		if (is_valid_var(&(*token)[i]))
		{
			key = extract_key(&(*token)[i + 1]);
			value = get_key_value(g_minishell.envp, key);
			if ((*token)[i + 1] == '?')
				append(&new_token, value);
			else
				append(&new_token, ft_strdup(value));
			i += ft_strlen(key) + 1;
			free(key);
		}
		else
			append(&new_token, ft_strndup(&(*token)[i++], 1));
	}
	free(*token);
	*token = new_token;
}

void	expand_token(char **token)
{
	int		i;
	char	**subtokens;

	i = 0;
	subtokens = get_subtokens(*token, 0);
	while (subtokens[i])
	{
		if (subtokens[i][0] != SINGLE_QUOTE && ft_strchr(subtokens[i], '$'))
			expand_vars(subtokens + i);
		i++;
	}
	free(*token);
	*token = concat_subtokens(subtokens);
	free(subtokens);
}
