/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:37:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/20 15:37:54 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}

int	check_julia_input(char *argv)
{
	int	i;

	i = 0;
	check_zeros(argv);
	if (argv[i] == '-' || argv[i] == '+')
		++i;
	while (argv[i] != '.' && argv[i])
	{
		if (!ft_isdigit(argv[i]))
			exit(EXIT_FAILURE);
		++i;
	}
	if (!argv[i] && atodbl(argv) <= 2.0 && atodbl(argv) >= -2.0)
		return (1);
	while (argv[++i] && !ft_isspace(argv[i]))
		if (!ft_isdigit(argv[i]))
			exit(EXIT_FAILURE);
	while (ft_isspace(argv[i]) && argv[i])
		i++;
	if (argv[i] || atodbl(argv) > 2.0 || atodbl(argv) < -2.0)
		exit(EXIT_FAILURE);
	return (1);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
