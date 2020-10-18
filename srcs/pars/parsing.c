#include "minirt.h"

int	is_dot(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			return (i + 1);
	}
	return (-1);
}

int valid_ext(char *str)
{
	int i;
	int is_ext;

	if (!str[0])
		return (1);
	i = 0;
	while ((is_ext = is_dot(str + i)) != -1)
		i += is_ext;
	if (!ft_strncmp("rt", str + i, 3))
		return (1);
	return (0);
}

int	handle_err(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" : wrong number of arguments\n", 2);
		return (-1);
	}
	if (!valid_ext(argv[1]))
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" : invalid scene description file\n", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd(argv[0], 2);
		perror(" : ");
		return (-1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int 	fd;
	t_scene	scene;

	if ((fd = handle_err(argc, argv)) == -1)
		return (1);
	if (!fill_scene(&scene, fd))
		return (1);
	return (0);
}
