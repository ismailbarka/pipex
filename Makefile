
SRCS = 	check_error.c\
		ft_check_file_access.c\
		ft_cmnds.c\
		ft_split.c\
		ft_split_two.c\
		ft_strjoin.c\
		paths.c\
		pipex.c\
		ft_split_one_bonus.c\

SRCSB = check_error_bonus.c\
		check_here_doc_bonus.c\
		ft_check_file_access_bonus.c\
		ft_cmnds_here_doc_bonus.c\
		ft_cmnds_multiple_pipes_bonus.c\
		ft_cmnds_multiple_pipes_one_bonus.c\
		ft_read_bonus.c\
		ft_split_bonus.c\
		ft_split_one_bonus.c\
		ft_split_two_bonus.c\
		ft_strjoin_bonus.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		paths_bonus.c\
		pipex_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(SRCS) -o $(NAME)

bonus: $(OBJSB)
	cc $(CFLAGS) $(SRCSB) -o $(NAME_BONUS)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all