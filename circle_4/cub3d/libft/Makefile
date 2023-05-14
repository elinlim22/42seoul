# ---- NAME ---- #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAG = ruc
RM = rm -f

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Mandatory ---- #

sources1 :=

# libft
sources1 += ft_isalpha.c
sources1 += ft_isdigit.c
sources1 += ft_isalnum.c
sources1 += ft_isascii.c
sources1 += ft_isprint.c
sources1 += ft_strlen.c
sources1 += ft_memset.c
sources1 += ft_bzero.c
sources1 += ft_memcpy.c
sources1 += ft_memmove.c
sources1 += ft_strlcpy.c
sources1 += ft_strlcat.c
sources1 += ft_toupper.c
sources1 += ft_tolower.c
sources1 += ft_strchr.c
sources1 += ft_strrchr.c
sources1 += ft_strncmp.c
sources1 += ft_memchr.c
sources1 += ft_memcmp.c
sources1 += ft_strnstr.c
sources1 += ft_atoi.c
sources1 += ft_calloc.c
sources1 += ft_strdup.c
sources1 += ft_substr.c
sources1 += ft_strjoin.c
sources1 += ft_strtrim.c
sources1 += ft_split.c
sources1 += ft_itoa.c
sources1 += ft_strmapi.c
sources1 += ft_striteri.c
sources1 += ft_putchar_fd.c
sources1 += ft_putstr_fd.c
sources1 += ft_putendl_fd.c
sources1 += ft_putnbr_fd.c

# libft_bonus
sources1 += ft_lstnew_bonus.c
sources1 += ft_lstadd_front_bonus.c
sources1 += ft_lstsize_bonus.c
sources1 += ft_lstlast_bonus.c
sources1 += ft_lstadd_back_bonus.c
sources1 += ft_lstdelone_bonus.c
sources1 += ft_lstclear_bonus.c
sources1 += ft_lstiter_bonus.c
sources1 += ft_lstmap_bonus.c

# ft_printf
sources1 += ./ft_printf/_c_s_per.c
sources1 += ./ft_printf/_d_i_u_x_X_p.c
sources1 += ./ft_printf/ft_printf.c
sources1 += ./ft_printf/ft_putnbr_printf.c
sources1 += ./ft_printf/ft_strjoinchr.c

# get_next_line
sources1 += ./get_next_line/get_next_line.c
sources1 += ./get_next_line/get_next_line_utils.c

# push_swap
sources1 += ./push_swap/ft_stack_add.c
sources1 += ./push_swap/ft_stackclear.c
sources1 += ./push_swap/ft_stacknew.c
sources1 += ./push_swap/ft_stackpop.c
sources1 += ./push_swap/ft_stackpush.c
sources1 += ./push_swap/ft_stacksize.c
sources1 += ./push_swap/ft_stackswap.c

# garbage_collector
sources1 += ./gc/garbage_collector.c
sources1 += ./gc/primary.c
sources1 += ./gc/mem_list.c

# ---- Bonus ---- #

sources2 :=

sources2 +=

# ---- Elements ---- #

all_sources = $(sources1) $(sources2)

objects1 = $(sources1:.c=.o)
objects2 = $(sources2:.c=.o)
all_objects = $(objects1) $(objects2)

define objects_goal
$(call $(if $(filter bonus, $(MAKECMDGOALS)), all_objects, objects1))
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

# ---- Command ---- #

.PHONY : clean fclean re all bonus

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(objects_goal)
	@$(AR) $(ARFLAG) $(NAME) $(objects_goal)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

clean :
	@$(RM) $(all_objects)
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)
