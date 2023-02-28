/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 20:08:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>

#include <limits.h>

#ifndef PATH_MAX
# define PATH_MAX 1024
#endif

char	*grab_cwd(void)
{
	char	*buf;
	char	*ptr;

	buf = ft_xcalloc(PATH_MAX, sizeof(char));
	ptr = getcwd(buf, PATH_MAX);
	if (ptr)
		return (ptr);
	free(buf);
	return (NULL);
}

void	bi_pwd(void)
{
	char	*cwd;

	cwd = grab_cwd();
	ft_putstr_fd(cwd, 1);
	ft_putchar_fd('\n', 1);
	free(cwd);
	add_env(ft_xstrdup("?=0"));
}
