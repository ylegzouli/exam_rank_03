#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_zone
{
	float	width;
	float	height;
	char	back;
}				t_zone;

typedef struct	s_draw
{
	char	type;
	float	x;
	float	y;
	float	wi;
	float	he;
	char	c;
}				t_draw;

//______________________________________________________________________//

void		parsing(FILE *file, t_zone *zone, char **draw)
{
	if (fscanf(file, "%d %d %c\n",  %zone->width, &zone->height, &zone->back) != 3)
		return (ERROR);
	if 
	
}

//______________________________________________________________________//

int			main(int ac, char **av)
{
	FILE 	*file;
	t_zone	zone;
	char 	*draw;

	if (!(file = fopen(av[1], "r")))
		return (ERROR);
	parsing(file, zone, draw);

}
