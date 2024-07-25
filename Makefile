SRC = main.c time.c util_0.c util_1.c util_2.c only_one.c checker.c
PHILO = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJS = $(SRC:.c=.o)

all: $(PHILO)

$(PHILO):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(PHILO)

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(OBJS) $(PHILO)

re: fclean all

.PHONY: all clean fclean re