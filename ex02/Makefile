CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

SRCS = main.cpp \
	   Animal.cpp \
	   Dog.cpp \
	   Cat.cpp \
	   Brain.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all