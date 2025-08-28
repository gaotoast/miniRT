/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:26:43 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:04:51 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// TODO: delete debug statement
t_ctx	*init(char *filename)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)ft_calloc(1, sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->scene = parse_scene(filename);
	if (!ctx->scene)
	{
		free(ctx);
		return (NULL);
	}
	debug_scene(ctx->scene);
	return (ctx);
}
