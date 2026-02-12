/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:42:02 by stakada           #+#    #+#             */
/*   Updated: 2026/02/12 17:09:45 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/* General errors */
# define ERR_MSG_USAGE "Usage: %s scene_file.rt"
# define ERR_MSG_EXT "File must have a %s extension"
# define ERR_MSG_FILE "File not found or cannot be accessed"

/* Format errors */
# define ERR_MSG_LINE "Invalid line: whitespace only"
# define ERR_MSG_IDENT "Invalid identifier: %s"
# define ERR_MSG_DUP_IDENT "Duplicated identifier: %s"
# define ERR_MSG_ELEM_COUNT "%s: Invalid element count"
# define ERR_MSG_ELEM_FORMAT "%s: Invalid element format"

/* Value errors */
# define ERR_MSG_ELEM_VALUE "%s: Element has invalid value"

/* Scene errors */
# define ERR_MSG_MISSING_AMBIENT "Missing ambient lighting (A)"
# define ERR_MSG_MISSING_CAMERA "Missing camera (C)"
# define ERR_MSG_MISSING_LIGHT "Missing light (L)"
# define ERR_MSG_NO_OBJECTS "Scene must contain at least one object"

/* System/Runtime errors */
# define ERR_MSG_MALLOC "Memory allocation failed"

#endif