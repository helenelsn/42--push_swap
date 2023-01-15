NAME = push_swap
BONUS_NAME = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 #attention a le tester sans -g3 pr voir si fonctionne sans!! (mais pas grave si le laisse)
RM = rm -f
SRCS = 			ft_atoi.c lists_utils.c instructions_utils.c check_args.c sort_utils.c sort_small_list.c sort.c \
				ft_push_swap.c
OBJDIR = ./objs/
SRCDIR = ./srcs/
INCDIR = ./includes
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))# c que du texte bande de batards

BONUS_SRCS = 	ft_atoi.c lists_utils.c instructions_utils.c check_args.c sort_utils.c sort_small_list.c sort.c \
			 	get_next_line.c get_next_line_utils.c checker_utils.c checker.c 
BONUS_OBJS = $(addprefix $(OBJDIR), $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) -o $@ $^ 

# make the directory an order-only prerequisite on all the targets : 
# Now the rule to create the objdir directory will be run, if needed, 
# before any ‘.o’ is built, but no ‘.o’ will be built because the objdir directory timestamp changed.

$(OBJS) : | $(OBJDIR)

$(OBJDIR) :
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ -I$(INCDIR) $<

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) -o $@ $^

$(BONUS_OBJS) : | $(OBJDIR)

test : all
	./my_tester.sh

clean:
	$(RM) -r $(OBJDIR) $(BONUS_OBJDIR)
# -r bc is a directory

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all re clean fclean