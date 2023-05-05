/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/06 02:07:27 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// ### memo
// 1st arg : number of philosophers
// 2nd arg : time to die
// 3rd arg : time to eat
// 4th arg : time to sleep
// 5th arg : [number_of_times_each_philosopher_must_eat]

int	main(int argc, char **argv)
{
	if (!is_validate_arg(argc, argv))
	{
		printf("ERROR: Invalid arguments.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
