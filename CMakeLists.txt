cmake_minimum_required(VERSION 3.20)
project(Fract_ol)

# get more information (what commands are runing)
# set(CMAKE_VERBOSE_MAKEFILE ON)

# compile flags
# set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
# (to speed up project)
set(CMAKE_C_FLAGS "-O0")# -ffast-math")

set(CMAKE_C_STANDARD 99)

add_executable(Fract_ol
        error1.c
        error2.c
        error.c
        event.c
        ft_atodl.c
        ft_memcmp.c
        ft_memset.c
        julia.c
        main.c
        mandelbrot.c
        memory.c
        newton_pool.c
        options.c
        utils1.c
        utils2.c
        utils.c
        palette.c
        palette1.c
        color.h
        error.h
        event.h
        fract_ol.h
        global.h
        memory.h
        time.h
        )
#link_directories(/usr/local/lib/)
target_link_libraries(Fract_ol 
#        Xext
#        X11             # for mlx
#        m               # math library
#        pthread         # for multithreading
#        /media/kostya/Data/CLion/Fract-ol/mlxlinux/libmlx.a

        mlx -framework OpenGL -framework AppKit z
        )