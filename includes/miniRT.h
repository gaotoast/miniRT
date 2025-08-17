#ifndef	MINI_RT_H
# define MINI_RT_H

#include "libft.h"
#include "mlx.h"

# define WIN_WIDTH 1080
# define WIN_HEIGHT 800

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(int argc, char **argv);

#endif