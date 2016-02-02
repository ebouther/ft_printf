/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:43:31 by rporcon           #+#    #+#             */
/*   Updated: 2016/02/02 12:56:32 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_res_length(long long n, int base_length)
{
	int		i;

	if (n == 0)
		return (1);
	i = (n < 0 ? 1 : 0);
	while (n != 0)
	{
		n /= base_length;
		i++;
	}
	return (i);
}

static long	ft_real_value(long long inp)
{
	if (inp < 0)
		return (-inp);
	return (inp);
}

static int	ft_get_res_length_un(unsigned long long n, int base_length)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base_length;
		i++;
	}
	return (i);
}

char		*ft_lltoa(long long n, char *base)
{
	int		base_length;
	int		res_length;
	char	*res;
	int		i;
	int		limit;

	base_length = ft_strlen(base);
	if (base_length < 2)
		return (NULL);
	res_length = ft_get_res_length(n, base_length);
	if (!(res = (char*)malloc(sizeof(char) * (res_length + 1))))
		return (NULL);
	res[res_length] = '\0';
	limit = 0;
	if (n < 0)
		res = ft_toa_bis(&limit, res);
	i = res_length - 1;
	while (i >= limit)
	{
		res[i] = base[ft_real_value(n % base_length)];
		n /= base_length;
		i--;
	}
	return (res);
}

char		*ft_llntoa(unsigned long long n, char *base)
{
	int		base_length;
	int		res_length;
	char	*res;
	int		i;

	base_length = ft_strlen(base);
	if (base_length < 2)
		return (NULL);
	res_length = ft_get_res_length_un(n, base_length);
	if (!(res = (char*)malloc(sizeof(char) * (res_length + 1))))
		return (NULL);
	res[res_length] = '\0';
	i = res_length - 1;
	while (i >= 0)
	{
		res[i] = base[n % base_length];
		n /= base_length;
		i--;
	}
	return (res);
}
