/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:24:29 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/27 13:43:58 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_tab(long n)
{
	int		count;
	int		sign;
	char	*tab;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	count = 0;
	if (n == 0)
		count = 1;
	else
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	tab = malloc(sizeof(char) * (count + sign + 1));
	if (!(tab))
		return (NULL);
	return (tab);
}

static void	ft_rev(char *tab)
{
	int		i;
	int		j;
	char	temp;
	int		max;

	i = 0;
	j = 0;
	if (tab[i] == '-')
		i++;
	while (tab[j])
		j++;
	j--;
	max = j / 2;
	while (i <= max)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

static void	ft_fill_tab(char *tab, long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		tab[i] = '0';
		i++;
	}
	else
	{
		if (nb < 0)
		{
			tab[i] = '-';
			nb = -nb;
			i++;
		}
		while (nb > 0)
		{
			tab[i] = (nb % 10) + '0';
			nb = nb / 10;
			i++;
		}
	}
	tab[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nb;

	nb = (long)n;
	tab = ft_create_tab(nb);
	if (!tab)
		return (NULL);
	ft_fill_tab(tab, nb);
	ft_rev(tab);
	return (tab);
}
/*
** int		main()
**{
**	int i;
**	char *tab;
**
**	i = 8484;
**	tab = ft_itoa(i);
**	printf("Resultat = %s\n", tab);
**	return (0);
**}
*/
