/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:11:41 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/18 17:45:57 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vbc.h"

t_node	*create_node(char sym, void *left, void *right)
{
	t_node *node = calloc(1, sizeof(t_node));
	node->left	= left;
	node->right = right;
	node->sym = sym;
	return (node);
}

void	free_node(void *node)
{
	free(node);
}

t_node	*parse_para(char *str, size_t *idx)
{
	t_node	*node;

	/*
	do something here
	*/
}

t_node	*parse_digit(char *str, size_t *idx)
{
	t_node *node;

	if (str[*idx] && str[*idx] == '(')
	{
		node = parse_para(str, idx);
		return (node);
	}
	if (str[*idx] && isdigit(str[*idx]))
	{
		node = create_node(str[*idx], 0, 0);
		(*idx)++;
		return (node);
	}
	return (0);
}

t_node	*parse_add(char *str, size_t *idx)
{
	t_node *node;

	node = parse_mult(str, idx);
	if (str[*idx] && str[*idx] == '+')
	{
		node = create_node(str[*idx], node, 0);
		(*idx)++;
		node->right = parse_mult(str, idx);
	}
	return (node);
}

t_node	*parse_mult(char *str, size_t *idx)
{
	t_node *node;

	node = parse_digit(str, idx);
	if (str[*idx] && str[*idx] == '*')
	{
		node = create_node(str[*idx], node, 0);
		(*idx)++;
		node->right = parse_digit(str, idx);
	}
	return (node);
}


t_node *construct(char *str)
{
	size_t	idx;

	idx = 0;
	return (parse_add(str, &idx));
}

void	write_seps(size_t depth)
{
	while (depth)
	{
		printf("\t");
		depth--;
	}
	printf("|");
}

void	write_tree_idx(t_node *node, size_t depth)
{
	write_seps(depth);
	printf("%c\n", node->sym);
	if (node->left)
		write_tree_idx(node->left, depth + 1);
	if (node->right)
		write_tree_idx(node->right, depth + 1);
}

void	write_tree(t_node *node)
{
	write_tree_idx(node, 0);
}

ssize_t	walk_tree(t_node *node)
{
	if (!node)
		return (0);
	switch (node->sym)
	{
	case '*':
		return (walk_tree(node->left) * walk_tree(node->right));
	case '+':
		return (walk_tree(node->left) + walk_tree(node->right));
	case '(':
		return (walk_tree(node->left));
	default:
		return (node->sym - '0');
	}
}
