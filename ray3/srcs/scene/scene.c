/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:29:13 by soulee            #+#    #+#             */
/*   Updated: 2023/05/24 21:08:07 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera	camera(t_canvas *canvas, t_point3 lookfrom, \
	t_point3 lookat, double vfov)
{
	t_camera	cam;
	double		theta;
	double		h;
	double		viewport_height;
	double		viewport_width;

	theta = degrees_to_radians(vfov);
	h = tan(theta / 2.0);
	viewport_height = 2.0 * h;
	viewport_width = canvas->aspect_ratio * viewport_height;
	cam.w = unit_vector(sub_vec3(lookfrom, lookat));
	cam.u = unit_vector(cross(vec3(0, 1, 0), cam.w));
	cam.v = cross(cam.w, cam.u);
	cam.orig = lookfrom;
	cam.horizontal = mul_n_vec3(cam.u, viewport_width);
	cam.vertical = mul_n_vec3(cam.v, viewport_height);
	cam.lower_left_corner = sub_vec3(cam.orig, \
		add_vec3(add_vec3(div_n_vec3(cam.horizontal, 2), \
			div_n_vec3(cam.vertical, 2)), cam.w));
	return (cam);
}
