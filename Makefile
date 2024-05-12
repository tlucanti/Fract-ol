# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 20:07:05 by kostya            #+#    #+#              #
#    Updated: 2021/12/01 13:30:07 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ compiler options ------------------------------
NAME		=	Fract-ol
CC		=	clang
CFLAGS		=	-Wall -Wextra -Werror
COPTIONS	=	-O3
# ------------------------------- linker options -------------------------------
LIBRARY		=
OBJS_DIR	=	obj
INCLUDE_DIR	=	inc
SRCS_DIR	=	src
LIBGNL		=
LIBFT		=
LIBGUI		=	../GUIlib
# ------------------------------- project sorces -------------------------------
SRCS		=	\
			error1		\
			error2		\
			error		\
			event		\
			ft_atodl	\
			ft_memcmp	\
			ft_memset	\
			julia		\
			main		\
			mandelbrot	\
			memory		\
			newton_pool	\
			options		\
			utils1		\
			utils2		\
			utils		\
			palette		\
			palette1	\
# ------------------------------------------------------------------------------
HDRS		=	\
			color		\
			error		\
			event		\
			fract_ol	\
			global		\
			memory

# ======================= UNCHANGEABLE PART OF MAKEFILE ========================
# ------------------------------------------------------------------------------
RM		=	rm -f
OBJS		=	$(addprefix ${OBJS_DIR}/,${SRCS:=.o})
DEPS		=	$(addprefix ${INCLUDE_DIR}/,${HDRS:=.h})
INCLUDE		=	-I ${INCLUDE_DIR} -I ${LIBGUI}/include
OS		=	$(shell uname -s | tr A-Z a-z)

LIBRARY		=	-lstdgui -lm `../GUIlib/guiflags.sh`

# ------------------------------------------------------------------------------
all:	${OBJS_DIR} ${NAME}

# ------------------------------------------------------------------------------
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${DEPS} Makefile
	${CC}		${CFLAGS} ${COPTIONS} -c -o $@ $< ${INCLUDE}

# ------------------------------------------------------------------------------
$(NAME):		${OBJS} ${DEPS}
	${CC}		-o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS} ${LIBRARY}


# ------------------------------------------------------------------------------
f:
	rm -f __make_all_FILE.c
	cat $(addprefix $(SRCS_DIR)/,$(SRCS:=.c)) > __make_all_FILE.c
	${CC} -o ${NAME} ${INCLUDE} -O3 -ffast-math -Wall -Wextra __make_all_FILE.c ${LIBRARY}
	rm -f __make_all_FILE.c

# ------------------------------------------------------------------------------
clean:
	${RM}		${OBJS}

# ------------------------------------------------------------------------------
fclean:			clean
	${RM}		${NAME}

# ------------------------------------------------------------------------------
${OBJS_DIR}:
	mkdir		-p ${OBJS_DIR}

# ------------------------------------------------------------------------------
re:				fclean all

# ------------------------------------------------------------------------------
.PHONY:			all f clean fclean install re
