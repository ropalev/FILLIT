/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:12:06 by lvania            #+#    #+#             */
/*   Updated: 2019/09/26 15:12:53 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int num)
{
	int		i;

	i = 1;
	if (num <= 0)
		return (0);
	while (i * i < num)
	{
		i++;
	}
	return (i);
}
