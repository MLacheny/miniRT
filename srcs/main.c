#include "minirt.h"

int main()
{
	void *mlx =  mlx_init();
	void *window = mlx_new_window(mlx, 400, 400, "test");
	while(1);
	mlx_destroy_window(mlx, window);
	return (0);
}
