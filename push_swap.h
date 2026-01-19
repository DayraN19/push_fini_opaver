/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastiangranier <bastiangranier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:10:08 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/19 13:09:37 by bastiangran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <math.h>

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_ctrl
{
    int         count_op;
    int         count_rra;
    int         count_rrb;
    int         count_rrr;
    int         count_pa;
    int         count_pb;
    int         count_sa;
    int         count_sb;
    int         count_ss;
    int         count_ra;
    int         count_rb;
    int         count_rr;
    int         bench;
    int         executed_strategy;
    t_strategy  strategy;
    float       count_disorder;
    int         size_a;
    int         size_b;
    t_stack_node *first;
    t_stack_node *last;
}   t_ctrl;

/* typedef struct s_ctrl {
    char    *strat;
    int     count_rra;
    int     count_rrb;
    int     count_rrr;
    int     count_pa;
    int     count_pb;
    int     count_sa;
    int     count_sb;
    int     count_ss;
    int     count_ra;
    int     count_rb;
    int     count_rr;
    int     bench;
    float   count_disorder;
    t_stack_node  *first;
    t_stack_node *last;
}   t_ctrl; */


/* ===== init ===== */
t_stack_node	*new_node(int value);
void			stack_add_back(t_stack_node **stack, t_stack_node *new);
void			init_stack_a(t_stack_node **a, char **argv);
void			index_stack(t_stack_node *a);

/* ===== stack utils ===== */
int				stack_size(t_stack_node *stack);
int				stack_sorted(t_stack_node *a);
int				is_sorted(t_stack_node *stack);
void			free_stack(t_stack_node *stack);
void			print_stack(t_stack_node *stack);
t_stack_node	*get_stack_bottom(t_stack_node *stack);
t_stack_node	*get_stack_before_bottom(t_stack_node *stack);
//bench utils
const char	    *strategy_name(int strat);
const char	    *strategy_complexity(int strat);
/* ===== operations ===== */
void	sa(t_stack_node **a, t_ctrl *c);
void	sb(t_stack_node **b, t_ctrl *c);
void	pa(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void	pb(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void	ra(t_stack_node **a, t_ctrl *c);
void	    rb(t_stack_node **b, t_ctrl *c);
void	rra(t_stack_node **a, t_ctrl *c);
void	rrb(t_stack_node **b, t_ctrl *c);
void	rrr(t_stack_node **a, t_stack_node **b, t_ctrl *c);

void			error_exit(void);
int				get_max_bits(t_stack_node *a);
void	        sort_chunks(t_stack_node **a, t_stack_node **b, int chunk, t_ctrl *c);
void	        move_min_to_top(t_stack_node **a, t_ctrl *c);
void			sort_nearly_sorted(t_stack_node **a, t_stack_node **b);
void            sort_simple(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void            sort_medium(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void            sort_complex(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void            sort_adaptive(t_stack_node **a, t_stack_node **b, t_ctrl *c);
float           compute_disorder(t_stack_node *a);
void	        dispatch_sort(t_stack_node **a, t_stack_node **b, t_ctrl *c);
void			sort_3(t_stack_node **a, t_ctrl *c);
void	        ctrl_init(t_ctrl *c, t_stack_node *a, t_stack_node *b);
void	        print_bench(t_ctrl *c);
void			select_strategy(t_ctrl *c, char **argv);


/* ===== sort utils ===== */
int	get_position(t_stack_node *stack, t_stack_node *node);
int	get_chunk_size(int size);
void	push_chunks(t_stack_node **a, t_stack_node **b, t_ctrl *c, int chunk);
t_stack_node	*find_max(t_stack_node *b);
void			push_back(t_stack_node **a, t_stack_node **b, t_ctrl *c);
int             find_first_number(int argc, char **argv);
int             is_flag(char *arg);
int				ft_sqrt(int n);
int				ft_strcmp(char *s1, char *s2);
int				count_in_range(t_stack_node *a, int min, int max);
int				get_max_index_pos(t_stack_node *b);
void			push_back_to_a(t_stack_node **a, t_stack_node **b);

#endif
