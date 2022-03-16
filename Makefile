NAME		= clusterfuck.exe
OBJ			= main cf_gravity cf_rotate cf_win
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I headers/
HEXLOC		= bestagon
HEXLIB		= $(addsuffix /hexlib.a, ${HEXLOC})
CFLAGS		= -Wall -Werror -Wextra -g

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				@$(CC) -c $(CFLAGS) $(HEADER) -o $@ $<

clean:
				@${RM} ${OBJS}
				$(info ************  clusterfuck Clean)

fclean:		clean
				@${RM} ${NAME}
				$(info ************  clusterfuck Removed)
				@${MAKE} fclean -C ${HEXLOC} --no-print-directory

re:			fclean all

${NAME}:	${OBJS}
				@${MAKE} -C ${HEXLOC} --no-print-directory
				@${CC} -o $@ $^ ${HEXLIB}
				$(info ************  clusterfuck Ready!)

.PHONY: all clean fclean re libft