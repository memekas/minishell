# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 03:51:55 by sbearded          #+#    #+#              #
#    Updated: 2019/04/26 23:13:21 by sbearded         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minishell

INC = includes

HEADER = $(INC)/minishell.h

LIBFT_PATH = 	libft
LIB_HEAD = 		$(LIBFT_PATH)/includes
LIBFT = 		$(LIBFT_PATH)/libft.a

WFLAGS = -Wall -Wextra -Werror

COMP = 			gcc -g -I $(INC) -I $(LIB_HEAD) -c -o

OBJ_DIR = obj/

MS_SRC_DIR = srcs/minishell/
PR_SRC_DIR = srcs/print/
WK_SRC_DIR = srcs/work/
FR_SRC_DIR = srcs/free/
MC_SRC_DIR = srcs/mini_commands/

MS_SRC = 	minishell.c

PR_SRC = 	print_prompt.c \
			error.c

WK_SRC = 	wait_input.c \
			commands.c \
			ft_strsplit_multiple.c \
			get_commands.c \
			get_expansion.c \
			get_env.c \
			ft_strinsert.c \
			dollar.c \
			tilde.c

FR_SRC = 	

MC_SRC = 	mini_cd.c \
			mini_echo.c \
			mini_env.c \
			mini_setenv.c \
			mini_unsetenv.c \
			mini_exit.c

MS_SRC_PATH = $(MS_SRC:%=$(MS_SRC_DIR)%)
PR_SRC_PATH = $(PR_SRC:%=$(PR_SRC_DIR)%)
WK_SRC_PATH = $(WK_SRC:%=$(WK_SRC_DIR)%)
FR_SRC_PATH = $(FR_SRC:%=$(FR_SRC_DIR)%)
MC_SRC_PATH = $(MC_SRC:%=$(MC_SRC_DIR)%)

SRC = $(MS_SRC_PATH) $(PR_SRC_PATH) $(WK_SRC_PATH) $(FR_SRC_PATH) $(MC_SRC_PATH)

MS_OBJ = $(MS_SRC:%.c=%.o)
PR_OBJ = $(PR_SRC:%.c=%.o)
WK_OBJ = $(WK_SRC:%.c=%.o)
FR_OBJ = $(FR_SRC:%.c=%.o)
MC_OBJ = $(MC_SRC:%.c=%.o)

MS_OBJ_PATH = $(addprefix $(OBJ_DIR), $(MS_OBJ))
PR_OBJ_PATH = $(addprefix $(OBJ_DIR), $(PR_OBJ))
WK_OBJ_PATH = $(addprefix $(OBJ_DIR), $(WK_OBJ))
FR_OBJ_PATH = $(addprefix $(OBJ_DIR), $(FR_OBJ))
MC_OBJ_PATH = $(addprefix $(OBJ_DIR), $(MC_OBJ))

OBJ = $(MS_OBJ_PATH) $(PR_OBJ_PATH) $(WK_OBJ_PATH) $(FR_OBJ_PATH) $(MC_OBJ_PATH)

all:		$(OBJ_DIR) $(NAME)

$(OBJ_DIR):	
			@mkdir -p $(OBJ_DIR)

$(NAME):	do_libft $(OBJ)
			@gcc -g $(MS_OBJ_PATH) $(PR_OBJ_PATH) $(WK_OBJ_PATH) $(FR_OBJ_PATH) $(MC_OBJ_PATH)\
			$(LIBFT) \
			-o $(NAME) -I $(INC) -I $(LIBFT_PATH)

$(MS_OBJ_PATH):	$(MS_SRC_PATH) $(HEADER)
				@$(MAKE) $(MS_OBJ)

$(PR_OBJ_PATH):	$(PR_SRC_PATH) $(HEADER)
				@$(MAKE) $(PR_OBJ)

$(WK_OBJ_PATH):	$(WK_SRC_PATH) $(HEADER)
				@$(MAKE) $(WK_OBJ)

$(FR_OBJ_PATH):	$(FR_SRC_PATH) $(HEADER)
				@$(MAKE) $(FR_OBJ)

$(MC_OBJ_PATH):	$(MC_SRC_PATH) $(HEADER)
				@$(MAKE) $(MC_OBJ)

$(MS_OBJ):		
				@$(COMP) $(OBJ_DIR)$@ $(MS_SRC_DIR)$(@:%.o=%.c)

$(PR_OBJ):		
				@$(COMP) $(OBJ_DIR)$@ $(PR_SRC_DIR)$(@:%.o=%.c)

$(WK_OBJ):		
				@$(COMP) $(OBJ_DIR)$@ $(WK_SRC_DIR)$(@:%.o=%.c)

$(FR_OBJ):		
				@$(COMP) $(OBJ_DIR)$@ $(FR_SRC_DIR)$(@:%.o=%.c)

$(MC_OBJ):		
				@$(COMP) $(OBJ_DIR)$@ $(MC_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT_PATH)

clean:
				@/bin/rm -rf $(OBJ_DIR)
				@make -C $(LIBFT_PATH) clean

fclean: 		clean
				@/bin/rm -f $(NAME)
				@make -C $(LIBFT_PATH) fclean

re: 			fclean all
