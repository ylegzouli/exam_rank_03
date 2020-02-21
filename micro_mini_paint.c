#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_zone
{
	int		width;
	int		height;
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
//	float	x;
//	float	y;
//	float	rad;
//	char	c;
//}					t_draw;

int         get_zone(FILE *file, t_zone *zone, char **draw);
int         get_form(FILE *file, t_zone *zone, char **draw);
void		draw_form(t_zone *zone, char **draw, t_draw *info);
int         is_in_rec(float x, float y, t_draw *info);
//int       is_in_cir(float x, float y, t_draw *info);
void        ft_print(char *draw, t_zone *zone);

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
	
//	while ((ret = fscanf(file, "%c %f %f %f %c\n", &info.type, &info.x, &info.y, &info.rad, &info.c) == 5))
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &info.type, &info.x, &info.y, &info.wi, &info.he, &info.c) == 6))
	{
//		if (info.rad <= 0.000000000 || (info.type != 'c' && info.type != 'C'))
		if (info.wi <= 0.000000000 || info.he <= 0.000000000 || (info.type != 'r' && info.type != 'R'))
			return (0);
		draw_form(zone, draw, &info);
	}
	if (ret != 0)
		return (0);
	return (1);
}

void		ft_print(char *draw, t_zone *zone)
{
	int		y;

	y = 0;
	while (y < zone->height)
	{
		write(1, draw + (y * zone->width), zone->width);
		write(1, "\n", 1);
		y++;
	}
}

//______________________________________________________________________//

void		draw_form(t_zone *zone, char **draw, t_draw *info)
{
	int		x;
	int		y;
	int		in;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
//			in = is_in_cer((float)x, (float)y, info);
			in = is_in_rec((float)x, (float)y, info);
//			if ((info->type == 'c' && in == 2) || (info->type == 'C' && in))
			if ((info->type == 'r' && in == 2) || (info->type == 'R' && in))
				(*draw)[(y * zone->width) + x] = info->c;
			x++;
		}
		y++;
	}
}

int			is_in_rec(float x, float y, t_draw *info)
{
	if (x < info->x || info->x + info->wi < x ||
		y < info->y || info->y + info->he < y)
		return (0);
	if (x - info->x < 1.00000000 || info->x + info->wi - x < 1.00000000 ||
		y - info->y < 1.00000000 || info->y + info->he - y < 1.00000000)
		return (2);
	return (1);
}

//int			is_in_cir(float x, float y, t_draw *info)
//{
//	float	dist;

//	dist = sqrt(powf(x - info->x, 2.) + powf(y - info->y, 2.));
//	if (dist < info->rad)
//	{
//		if (info->rad - dist < 1.00000000)
//			return (2);
//		return (1);
//	}
//	return (0);
//}

//______________________________________________________________________//

int			main(int ac, char **av)
{
	FILE 	*file;
	t_zone	zone;
	char 	*draw;

	if (ac != 2)
	{
		write(1, "ERROR_1\n", 8);
		return (0);
	}
	if (!(file = fopen(av[1], "r")))
	{
		write(1, "ERROR_2\n", 8);
		return (0);
	}
	if (!(get_zone(file, &zone, &draw)))
	{
		write(1, "ERROR_3\n", 8);
		return (0);
	}
	if (!(get_form(file, &zone, &draw)))
	{
		write(1, "ERROR_4\n", 8);
		return (0);
	}
	ft_print(draw, &zone);
	fclose(file);
	free(draw);
	return (0);
}
