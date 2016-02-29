##
## source.mk for source in /home/plasko_a/projet/cplusplus/cpp_abstractvm
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Thu Feb 26 12:42:06 2015 Antoine Plaskowski
## Last update Sun Mar  1 14:02:58 2015 Antoine Plaskowski
##

PATH_SRC	=	source/

SRC		+=	$(PATH_SRC)main.cpp
SRC		+=	$(PATH_SRC)parser.cpp
SRC		+=	$(PATH_SRC)lexer.cpp
SRC		+=	$(PATH_SRC)instruction.cpp
SRC		+=	$(PATH_SRC)ioperand.cpp
SRC		+=	$(PATH_SRC)operand.cpp
SRC		+=	$(PATH_SRC)managerOperand.cpp
SRC		+=	$(PATH_SRC)exception.cpp
SRC		+=	$(PATH_SRC)vm.cpp
