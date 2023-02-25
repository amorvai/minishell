/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:05:02 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 15:44:43 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h" // should be removed later (ft_ calloc in extract_redirection; bc it doesnt belong here but that part needs to be rewritten anyways)

// t_redirection	*extract_redirection(t_token *temp_lst)
// {
// 	t_redirection	*new_redir;
//
// 	new_redir = ft_calloc(1, sizeof(t_redirection));
// 	new_redir->redir_type = temp_lst->token;
// 	new_redir->file	= expand_token(temp_lst->next->word);
// 	return (new_redir);
// }

// int	get_redirections(t_token **token_lst, t_simp_com *curr_command)
// {
// 	t_token			*temp_lst;
// 	t_redirection	*new_redir;
//
// 	temp_lst = *token_lst;
// 	// if (token_lst && temp_lst && temp_lst->token == PIPE)
// 	// 	return (1); // syntax error near '|'
// 	while (token_lst && temp_lst && temp_lst->token != PIPE)
// 	{
// 		if (temp_lst->token > 1)
// 		{
// 			if (!temp_lst->next || temp_lst->next->token != WORD)
// 				return (1); // syntax error near 'enum e_token'
// 			new_redir = extract_redirection(temp_lst);
// 			if (temp_lst->token % 2)
// 				redir_add_back(&curr_command->redirect_input, new_redir);
// 			else
// 				redir_add_back(&curr_command->redirect_output, new_redir);
// 			token_delete(token_lst, temp_lst->next);
// 			token_delete(token_lst, temp_lst);
// 			temp_lst = *token_lst;
// 			// token_lst_print(temp_lst);
// 			continue ;
// 		}
// 		temp_lst = temp_lst->next;
// 	}
// 	// if (token_lst && temp_lst && temp_lst->token == PIPE && !temp_lst->next)
// 	// 	return (1); // syntax error near '|'
// 	return (0);
// }

// int	get_rest(t_token **token_lst, t_simp_com *curr_command)
// {
// 	t_token	*temp_lst;
// 	int		i;
//
// 	temp_lst = *token_lst;
// 	i = 0;
// 	while (token_lst && temp_lst && temp_lst->token != PIPE)
// 	{
// 		temp_lst = temp_lst->next;
// 		i++;
// 	}
// 	curr_command->command = ft_calloc(i + 1, sizeof(char *));
// 	i = 0;
// 	// print_commands(curr_command);
// 	while (token_lst && (*token_lst) && (*token_lst)->token != PIPE)
// 	{
// 		// printf("str: %s\n", (*token_lst)->word);
// 		curr_command->command[i] = expand_token((*token_lst)->word);
// 		token_delete(token_lst, *token_lst);
// 		i++;
// 	}
// 	if (token_lst && (*token_lst) && (*token_lst)->token == PIPE)
// 		token_delete(token_lst, *token_lst);
// 	return (0);
// }

// t_simp_com	*get_simp_command(t_token **token_lst)
// {
// 	t_simp_com	*curr_command;
//
// 	curr_command = ft_calloc(1, sizeof(t_simp_com));
// 	if (get_redirections(token_lst, curr_command))
// 		return (NULL);
// 	if (get_rest(token_lst, curr_command))
// 		return (NULL);
// 	return (curr_command);
// }

// t_simp_com	*parse_for_commands(t_token **token_lst)
// {
// 	t_simp_com	*head_command;
// 	t_simp_com	*curr_command;
//
// 	head_command = NULL;
// 	while (*token_lst)
// 	{
// 		curr_command = get_simp_command(token_lst);
// 		if (!curr_command)
// 		{
// 			command_lst_clear(&head_command);
// 			return (NULL);
// 		}
// 		command_lst_add_back(&head_command, curr_command);
// 	}
// 	return (head_command);
// }

// some alternative code
// int	extract_redirections(t_token **it, t_simp_com *command)
// {
// 	while (*it && (*it)->token != PIPE)
// 	{
// 		if (is_redirection((*it)->token))
// 		{
// 			if ((*it)->next == NULL)
// 				return (1); // syntax error near 'newline'
// 			if ((*it)->next->token != WORD)
// 				return (1); // syntax error near '[(*it)->next->token]' // kann man auch wieder zusammenfassen
// 			t_redirection *new_redirection = (t_redirection *)malloc(sizeof(t_redirection));
// 			if (is_redirection_input((*it)->token)) 
// 				token_list_push_back(command->redirect_input, new_redirection);
// 			else
// 				token_list_push_back(command->redirect_output, new_redirection);
// 			new_redirection->redir_type = (*it)->token;
// 			new_redirection->file = expand_token((*it)->next->word);
// 		}
// 		*it = (*it)->next;
// 	}
// 	if (*it && (*it)->token == PIPE && !(*it)->next)
// 		return (1); // syntax error near 'newline'
// 	if (*it && (*it)->token == PIPE)
// 		*it = (*it)->next;
// 	return (0);
// }
