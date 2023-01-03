/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:30:17 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/01 21:16:07 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t	ft_strlen( char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	if (n == 0)
		return (0);
	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	i = 0;
	while (pt1[i] && pt2[i] && pt1[i] == pt2[i] && i < n - 1)
	{
		i++;
	}
	return (pt1[i] - pt2[i]);
}

int	is_digit(char *str)
{
	if (*str && *str == '+' )
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi( char *str)
{
	int	i;
	int	mult;
	int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

void	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}
