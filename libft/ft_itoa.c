/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:36:35 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/21 18:44:30 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len_n;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (0);
	str[len_n] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (i < len_n--)
	{
		str[len_n] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
