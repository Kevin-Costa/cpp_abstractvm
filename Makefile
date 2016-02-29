##
## Makefile for Makefile in /home/plasko_a/projet/cplusplus/cpp_abstractvm
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Thu Feb 26 12:42:14 2015 Antoine Plaskowski
## Last update Fri Feb 27 16:18:47 2015 Antoine Plaskowski
##

NAME			=	avm

CPP			=	g++

RM			=	rm -f

DEPEND			=	makedepend

CPPFLAGS		=	-Wall -Wextra
CPPFLAGS		+=	-I include/

LDFLAGS			=

COLOR			=	no

DEBUG			=	no

DFLAGS			=	-Yinclude/ -w80

ifeq ($(CPP), clang++)
CPPFLAGS		+=	-Weverything -Wno-padded
endif

ifneq ($(COLOR), no)
CPPFLAGS		+=	-fdiagnostics-color
endif

ifneq ($(DEBUG), no)
CPPFLAGS		+=	-g
endif

ifeq ($(DEBUG), no)
LDFLAGS			+=	-s
endif

SRC			=

include				source.mk

OBJ			=	$(SRC:.cpp=.o)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CPP) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

%.o			:	%.cpp
				$(CPP) -c $< -o $@ $(CPPFLAGS)

depend			:
				$(DEPEND) $(SRC) $(DFLAGS)

.PHONY			:	all clean fclean re
# DO NOT DELETE

source/main.o: include/parser.hpp include/ioperand.hpp include/lexer.hpp
source/parser.o: include/parser.hpp include/ioperand.hpp include/lexer.hpp
source/parser.o: include/managerOperand.hpp
source/lexer.o: include/lexer.hpp
source/instruction.o: include/instruction.hpp include/ioperand.hpp
source/ioperand.o: include/ioperand.hpp
source/value.o: include/instruction.hpp include/ioperand.hpp
source/value.o: include/operand.hpp include/exception.hpp
source/managerOperand.o: include/operand.hpp include/ioperand.hpp
source/managerOperand.o: include/exception.hpp include/managerOperand.hpp
