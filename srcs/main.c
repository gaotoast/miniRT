/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:13 by stakada           #+#    #+#             */
/*   Updated: 2026/02/15 03:25:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_ctx	*ctx;

	if (check_args(argc, argv) < 0)
		return (1);
	ctx = init_ctx(argv[1]);
	if (!ctx)
		return (1);
	if (run_mlx(ctx) < 0)
	{
		free_ctx(ctx);
		return (1);
	}
	return (0);
}
