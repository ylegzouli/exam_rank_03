#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int         ft_error(char *s);
int         ft_strlen(char *str);
int         get_zone(FILE *file, t_zone *zone, char **draw);


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

int			ft_error(char *s)
{
    if (s)
        write(1, s, ft_strlen(s));
    return(1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//______________________________________________________________________//

int			get_zone(FILE *file, t_zone *zone, char **draw)
{
	int		i;

	if (fscanf(file, "%d %d %c\n",  &zone->width, &zone->height, &zone->back) != 3)
		return (0);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
        return (NULL);
    if (!(*draw = (char *)malloc(sizeof(char) * (zone->height * zone->width))))
        return (NULL);
    i = 0;
    while (i < zone->height * zone->width)
        (*draw)[i++] = zone->back;	
	return (1);
}

int			draw_form(FILE *file, t_zone *zone, char **draw)
{
	int		ret;
	
	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", )
	return (1);
}


//______________________________________________________________________//

int			main(int ac, char **av)
{
	FILE 	*file;
	t_zone	zone;
	char 	*draw;

	if (!(file = fopen(av[1], "r")))
		return (ft_error("ERROR");
	if (!(get_zone(file, zone, draw)))
		return (ft_error("ERROR");
	

}
