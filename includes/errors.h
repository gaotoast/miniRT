/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:42:02 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 16:56:30 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MSG_USAGE "Usage: %s scene_file.rt"
# define ERR_MSG_EXT "File must have a %s extension"
# define ERR_MSG_FILE "File not found or cannot be accessed"

# define ERR_MSG_IDENT "Invalid identifier: %s"
# define ERR_MSG_DUP_IDENT "Duplicated identifier: %s"
# define ERR_MSG_ELEM_COUNT "Count of elements is invalid"
# define ERR_MSG_RATIO "%s: Invalid ratio"
# define ERR_MSG_COLORS "%s: Invalid colors"
# define ERR_MSG_VEC_FORMAT "%s: Invalid vector format"
# define ERR_MSG_NUM_FORMAT "%s: Invalid number format"
# define ERR_MSG_RANGE "%s: Value out of range"
# define ERR_MSG_NORM_VEC "%s: Vector must be normalized"

# define ERR_MSG_MISSING_AMBIENT "Missing ambient lighting (A) declaration"
# define ERR_MSG_MISSING_CAMERA "Missing camera (C) declaration"
# define ERR_MSG_MISSING_LIGHT "Missing light (L) declaration"
# define ERR_MSG_NO_OBJECTS "Scene must contain at least one object"

#endif