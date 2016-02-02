/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:12:25 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/02 11:13:23 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_switch(int *i, int *n, char **str, t_conv *conv)
{
	while ((*str)[*i + *n] == '#' ||
			(*str)[*i + *n] == '0' ||
			(*str)[*i + *n] == '-' ||
			(*str)[*i + *n] == ' ' ||
			(*str)[*i + *n] == '+')
	{
		if (((*i + *n) < conv->precision_pos && conv->precision_pos != -1)
				|| conv->precision_pos == -1)
		{
			if (ft_strchr(conv->flag, (*str)[*i + *n]) == NULL)
				conv->flag = ft_strjoin(conv->flag,
						ft_char_to_str((*str)[*i + *n]));
			if (conv->flag_pos == -1)
				conv->flag_pos = *i + *n;
		}
		(*n)++;
	}
}

char			*ft_get_flags(char *str, t_conv *conv, t_env *e)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	ret = ft_get_precision(str, conv, e);
	while (str[i] && str[i] != '%')
	{
		n = 0;
		if (str[i + n] == '#' ||
				str[i + n] == '0' ||
				str[i + n] == '-' ||
				str[i + n] == ' ' ||
				str[i + n] == '+')
		{
			ft_flag_switch(&i, &n, &str, conv);
			break ;
		}
		i++;
	}
	return (ret);
}