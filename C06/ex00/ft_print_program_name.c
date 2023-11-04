/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:42 by snocita           #+#    #+#             */
/*   Updated: 2022/11/29 10:05:16 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc > 0)
	{
		while(argv[0][i] != '\0')
		{
			write(1, &argv[0][i],1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}