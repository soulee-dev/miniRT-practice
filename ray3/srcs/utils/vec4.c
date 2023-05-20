/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:54:56 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 13:49:30 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

t_vec3	random_in_unit_disk(void)
{
	t_vec3	p;

	while (1)
	{
		p = vec3(random_double2(-1, 1), random_double2(-1, 1), 0);
		if (length_squared(p) >= 1)
			continue ;
		return (p);
	}
}

double	nth_vec3(t_vec3 u, int n)
{
	if (n == 0)
		return (u.x);
	else if (n == 1)
		return (u.y);
	else if (n == 2)
		return (u.z);
	return (0);
}

t_vec3	min_vec3(t_vec3 u, t_vec3 v)
{
	if (u.x > v.x)
		u.x = v.x;
	if (u.y > v.y)
		u.y = v.y;
	if (u.z > v.z)
		u.z = v.z;
	return (u);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	vec3;

	vec3.x = u.x - v.x;
	vec3.y = u.y - v.y;
	vec3.z = u.z - v.z;
	return (vec3);
}