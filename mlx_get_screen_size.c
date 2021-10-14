#ifdef __APPLE__

void    mlx_get_screen_size(__attribute__((unused))void *mlx, int *width, int *height)	
{
	*width = 5120;
	*height = 2880;
}
		
#endif
