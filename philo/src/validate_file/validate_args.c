/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:41:05 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/06 01:44:33 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static bool	is_validate_digit(char *argv_str);
static bool	is_validate_argc_5(int argc, char **argv);
static bool	is_validate_argc_6(int argc, char **argv);

bool	is_validate_arg(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (ERROR);
	i = 1;
	while (i < argc)
	{
		if (!is_validate_digit(argv[i]))
			return (ERROR);
		i++;
	}
	if (argc == 5)
		return (is_validate_argc_5(argc, argv));
	if (argc == 6)
		return (is_validate_argc_6(argc, argv));
	return (NOT_ERROR);
}

static bool	is_validate_digit(char *argv_str)
{
	size_t	i;

	i = 0;
	while (argv_str[i])
	{
		if (!ft_isdigit(argv_str[i]))
			return (ERROR);
		i++;
	}
	return (NOT_ERROR);
}

static bool	is_validate_argc_5(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 1)
			return (ERROR);
		i++;
	}
	return (NOT_ERROR);
}

static bool	is_validate_argc_6(int argc, char **argv)
{
	if (!is_validate_argc_5((argc - 1), argv))
		return (ERROR);
	if (ft_atoi(argv[5]) < 1)
		return (ERROR);
	return (NOT_ERROR);
}
