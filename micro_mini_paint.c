#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int         get_zone(FILE *file, t_zone *zone, char **draw);
int			get_form(FILE *file, t_zone *zone, char **draw);
void		ft_print(char *draw);

int			draw_form(t_zone *zone, char **draw, t_draw *info);
int			is_in_rec();
//int		is_in_cir();

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

//typedef struct	s_draw
//{
//	char	type;

//}					t_draw;

//______________________________________________________________________//

int			get_zone(FILE *file, t_zone *zone, char **draw)
{
	int		i;

	i = 0;
	if (fscanf(file, "%d %d %c\n",  &zone->width, &zone->height, &zone->back) != 3)
		return (0);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
        return (0);
	if (!(*draw = (char *)malloc(sizeof(char) * (zone->height * zone->width))))
        return (0);
	while (i < zone->height * zone->width)
	{	
		(*draw)[i] = zone->back;
		i++;
	}
	return (1);
}

int			get_form(FILE *file, t_zone *zone, char **draw)
{
	int		ret;
	t_draw	info;
	
//	while ((ret = fscanf(file, "%c %f %f %f %c\n", &info->type, &info->x, &info->y, &info->wi, &info->he, &info->c) == 5))
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &info->type, &info->x, &info->y, &info->wi, &info->he, &info->c) == 6))
	{

		draw_form(zone, draw, info);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void		ft_print(char *draw)
{

}

//______________________________________________________________________//

int			draw_form(t_zone *zone, char **draw, t_draw *info)
{
	
}

int			is_in_rec()
{
}

//int			is_in_cir()
//{
//}

//______________________________________________________________________//

int			main(int ac, char **av)
{
	FILE 	*file;
	t_zone	zone;
	char 	*draw;

	if (ac != 2)
	{
		write(1, "ERROR_1\n", 6);
		return (0);
	}
	if (!(file = fopen(av[1], "r")))
	{
		write(1, "ERROR_2\n", 6);
		return (0);
	}
	if (!(get_zone(file, zone, draw)))
	{
		write(1, "ERROR_2\n", 6);
		return (0);
	}
	if (!(get_form()))
	{
		write(1, "ERROR_2\n", 6);
		return (0);
	}
	ft_print(draw);
	return (0);
}
