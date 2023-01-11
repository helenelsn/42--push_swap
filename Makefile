NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 #attention a le tester sans -g3 pr voir si fonctionne sans!! (mais pas grave si le laisse)
RM = rm -f
SRCS = ft_atoi.c ft_push_swap.c instructions_utils.c lists_utils.c sort.c
OBJDIR = ./objs/
SRCDIR = ./srcs/
INCDIR = ./includes
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))# c que du texte bande de batards


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

test : all
	./my_tester.sh

clean:
	$(RM) -r $(OBJDIR) 
# -r bc is a directory

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean fclean