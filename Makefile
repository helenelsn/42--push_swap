NAME = push_swap.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
SRCS = 
OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY : all re clean fclean