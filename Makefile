NAME = ./push_swap
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
INCLUDE_DIRS := includes
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))
SRC = $(call rwildcard,src,*.c)
OBJ := $(SRC:.c=.o)
RM = rm -f
MAKE = make
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc

all: libft.a $(NAME) 

libft.a:
	make -C libs/libft/
	make bonus -C libs/libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -Llibs/libft/ -lft -o $@ $(INCLUDES)


clean:
	$(MAKE) clean -C ./libs/libft
	$(RM)   $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libs/libft
		$(RM)   $(NAME)

re: fclean  all

bonus: $(NAME)

.PHONY:         all clean fclean bonus
