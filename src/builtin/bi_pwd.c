/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 11:28:54 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>

#include <limits.h>

#ifndef PATH_MAX
# define PATH_MAX 1024
#endif

char	*grab_cwd()
{
	char	buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
		return (buf);
	return (NULL);
}

void bi_pwd()
{
	ft_putstr_fd(grab_cwd(), 1);
	ft_putchar_fd('\n', 1);
}
