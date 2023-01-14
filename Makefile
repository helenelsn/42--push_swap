NAME = push_swap
BONUS_NAME = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 #attention a le tester sans -g3 pr voir si fonctionne sans!! (mais pas grave si le laisse)
RM = rm -f
SRCS = ft_atoi.c lists_utils.c instructions_utils.c check_args.c sort_utils.c sort_small_list.c sort.c ft_push_swap.c
BONUS_SRCS = checker.c
OBJDIR = ./objs/
SRCDIR = ./srcs/
INCDIR = ./includes
BONUS_OBJDIR = ./bonus/objs
BONUS_SRCDIR = ./bonus/srcs
BONUS_INCDIR = ./bonus/includes
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))# c que du texte bande de batards
BONUS_OBJS = $(addprefix $(BONUS_OBJDIR), $(BONUS_SRCS:.c=.c))

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

$(BONUS_OBJS) : | $(BONUS_OBJDIR)

$(BONUS_OBJDIR) :
	mkdir $(BONUS_OBJDIR)

$(BONUS_OBJDIR)%.o: $(BONUS_SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ -I$(BONUS_INCDIR) $<

test : all
	./my_tester.sh

clean:
	$(RM) -r $(OBJDIR) $(BONUS_OBJDIR)
# -r bc is a directory

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all re clean fclean