PHILO = philo
SRC = main.c time.c util_0.c util_1.c util_2.c only_one.c checker.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(PHILO)
$(PHILO):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(PHILO)

clean:
	@$(RM) $(OBJS)
fclean:
	@$(RM) $(OBJS) $(PHILO)

re: fclean all

.PHONY: all clean fclean re