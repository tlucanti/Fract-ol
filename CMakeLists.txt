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
        error.c
        error.h

        event.c
        event.h

        memory.c
        memory.h

        main.c
        ft_atodl.c
        utils.c
        fract-ol.h
        global.h
        color.h
)
link_directories(/usr/local/lib/)
target_link_libraries(Fract_ol
        Xext
        X11    # for mlx
        m               # math library
        pthread         # for multithreading
        /media/kostya/Data/CLion/Fract-ol/mlxlinux/libmlx.a
        )