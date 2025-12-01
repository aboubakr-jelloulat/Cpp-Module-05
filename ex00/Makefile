NAME 		:= Bureaucrat

CXX 		:= c++

CXXFLAGS 	:= -Wall -Wextra -Werror -std=c++98

SRC		 	:= main.cpp Bureaucrat.cpp

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
	@$(call tidy_compilation,$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@)


define tidy_compilation
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


.PHONY: all clean fclean re
