/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:44 by soulee            #+#    #+#             */
/*   Updated: 2023/05/20 14:12:33 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "render.h"

int	main(void)
{
	t_canvas	canv;
	t_camera	cam;
	void		*mlx;
	void		*mlx_win;
	t_sphere	sp;

	sp = sphere(point3(0, 0, -5), 2);
	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, canv.width, canv.height, "Ray3");
	render(&canv, &cam, mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
