
#ifndef VBC_H
#define VBC_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

typedef struct s_node t_node;
struct s_node
{
	char sym;
	t_node	*left;
	t_node	*right;
};

t_node	*create_node(char sym, void *left, void *right);
void	free_node(void *node);

int		validate_str(char *str);
void	write_tree(t_node *node);
t_node	*construct(char *str);

ssize_t	walk_tree(t_node *node);

t_node	*parse_para(char *str, size_t *idx);
t_node	*parse_digit(char *str, size_t *idx);
t_node	*parse_add(char *str, size_t *idx);
t_node	*parse_mult(char *str, size_t *idx);

#endif

