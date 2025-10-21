/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:13 by stakada           #+#    #+#             */
/*   Updated: 2025/10/20 12:39:10 by stakada          ###   ########.fr       */
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
	run_mlx(ctx);
	return (0);
}
