/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:31:12 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/30 17:44:40 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>

typedef char				*t_str;
typedef const char			*t_const_str;

typedef unsigned char		t_u8;
typedef char				t_i8;
typedef unsigned short		t_u16;
typedef short				t_i16;
typedef int					t_i32;
typedef unsigned int		t_u32;
typedef unsigned long long	t_u64;
typedef long long			t_i64;
typedef ssize_t				t_isize;
typedef size_t				t_usize;

typedef float				t_f32;
typedef double				t_f64;

typedef int					t_file;
typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

typedef bool				t_error;
# define ERROR true
# define NO_ERROR false

#endif
