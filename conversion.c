/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:08:31 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/02 15:43:48 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_conversion(char *str, t_conv *conv, t_env *e)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	tmp = NULL;	
	ret = NULL;	
	while (str[i] && str[i] != '%')
	{
		if (ft_strchr("sSpdDioOuUxXcC", str[i]) != NULL)
		{
			conv->conversion = str[i];
			conv->conversion_pos = i;
			break ;
		}
		i++;
	}
	if (conv->conversion == 0)
		return (NULL);
	else if (conv->conversion == 'c')
		ret = ft_char_to_str((char)va_arg(*(e->ap), int));
	else if (conv->conversion == 's')
	{
		if ((ret = ft_strdup((char *)va_arg(*(e->ap), char *))) == NULL)
		{
			ft_memdel((void **)&ret);
			ret = ft_strdup("(null)");
		}
	}
	else if (conv->conversion == 'd' || conv->conversion == 'i')
		ret = ft_itoa((int)va_arg(*(e->ap), int));
	else if (conv->conversion == 'u')
		ret = ft_itoa((int)va_arg(*(e->ap), unsigned int));
	else if (conv->conversion == 'x')
		ret = ft_itoa_base((unsigned int)va_arg(*(e->ap),
					unsigned int), 16);
	else if (conv->conversion == 'p')
	{
		if ((ret = ft_llntoa_base((unsigned long)va_arg(*(e->ap), void *), (char *)"0123456789abcdef")) == NULL)
		{
			ft_memdel((void **)&ret);
			ret = ft_strdup("(null)");
		}
		else
			ret = ft_strjoin_free(ft_strdup("0x"), ret);
	}
	return (ret);
}
