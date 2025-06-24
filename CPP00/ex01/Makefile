NAME = phonebook
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = src/main.cpp \
		src/Contact.cpp \
		src/input.cpp \
		src/PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./inc

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS) -I$(INCLUDE)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $< -I$(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
