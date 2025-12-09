NAME 		:= intern

CXX 		:= c++

CXXFLAGS 	:= -Wall -Wextra -Werror -std=c++98

SRC		 	:= AForm.cpp  Bureaucrat.cpp  main.cpp  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp Intern.cpp

OBJDIR 		:= build

OBJ 		:= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))



all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo Created executable :  $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re : fclean all


DEPENDS := $(patsubst %.o,%.d,$(OBJ))

-include $(DEPENDS)

$(OBJDIR)/%.o : %.cpp Makefile | $(OBJDIR)
	@mkdir -p $(@D)
	@$(call foo,$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@)


define foo
	@printf "%s\e[K\n" "$(1)"
	@$(1)
	@printf "\e[A\e[K"
endef



ifdef OPT
CXXFLAGS += -O3 -march=native
endif

ifdef SAN
CXXFLAGS += -fsanitize=address
endif

# Passing -O3 to the compiler tells it to optimize the code very hard.
# Passing -march=native to the compiler tells it to make optimizations based on your specific CPU.


execute: all clean
	./$(NAME)


perf : all
	perf stat ./$(NAME)

report:
	perf report

htop:
	htop

glances:
	glances

valgrind:
	valgrind --leak-check=full ./$(NAME)


.PHONY: all clean fclean re
