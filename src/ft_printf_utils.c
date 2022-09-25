/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:51 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 04:58:55 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		i = ft_putstr("(null)");
	else
		while (str[++i])
			write(1, &str[i], 1);
	return (i);
}

static int	get_numdigs(unsigned int n)
{
	size_t	num;

	num = 0;
	while (n > 9)
	{
		num++;
		n /= 10;
	}
	num++;
	return (num);
}

char	*ft_itoa(long int n)
{
	int		i;
	int		is_neg;
	int		num_digs;
	char	*cad;

	i = -1;
	is_neg = (n >= 0);
	num_digs = get_numdigs(n * -(n < 0) + n * (n >= 0)) + (n < 0);
	cad = (char *)malloc((num_digs + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	if (n < 0)
	{
		cad[++i] = '-';
		n *= -1;
	}
	while (++i < num_digs)
	{
		cad[num_digs - i - is_neg] = (n % 10) + 48;
		n /= 10;
	}
	cad[i] = '\0';
	return (cad);
}
