/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinationTest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:50:54 by awilliam          #+#    #+#             */
/*   Updated: 2022/11/20 12:16:15 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*convert_input(char	*input);
int		make_grid(char *input);
void	ft_print_grid(char	*grid[]);
int		check_solution(char	*grid[], char	*input);

int	main(int argc, char	*argv[])
{
	char	*converted;

	if (argc != 2)
	{
		write (1, "Enter integers from 1 - 4 separated by spaces\n", 45);
		return (0);
	}
	converted = convert_input(argv[1]);
	if (!converted)
	{
		write (1, "INVALID: Please check your input\n", 33);
		return (0);
	}
	make_grid (converted);
}

int	make_grid(char *input)
{
	char	**grid;
	int		i;
	int		j;
	int		k;
	int		l;
	char	*combination_array[] = {
		"1234", "1243", "1324", "1342",
		"1423", "1432", "2134", "2143",
		"2314", "2341", "2413", "2431",
		"3124", "3142", "3214", "3241",
		"3412", "3421", "4123", "4132",
		"4213", "4231", "4312", "4321"
	};

	grid = malloc(50);
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < 24)
	{
		grid[0] = combination_array[i];
		if (check_solution(grid, input))
			break;
		while (j < 24)
		{
			grid[1] = combination_array[j];
			while (k < 24)
			{
				grid[2] = combination_array[k];
				while (l < 24)
				{
					grid[3] = combination_array[l];
					if (check_solution(grid, input))
						break;
					l++;
				}
				if (check_solution(grid, input))
					break;
				l = 0;
				k++;
			}
			if (check_solution(grid, input))
				break;
			k = 0;
			j++;
		}
		if (check_solution(grid, input))
			break;
		j = 0;
		i++;
	}
	if (check_solution(grid, input))
	{
		ft_print_grid(grid);
	}
	else
		write(1, "No possible solutions found\n", 28);
	return (0);
}
