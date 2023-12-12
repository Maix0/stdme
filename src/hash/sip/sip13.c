/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sip13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:32:28 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/11 15:38:13 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hash/sip.h"
#include "me/hash/sip/sip_utils.h"
#include "me/mem/mem_alloc.h"

t_hasher	hasher_sip13_new(void)
{
	t_hasher	out;
	t_sip13		*inner;

	inner = mem_alloc(sizeof(t_sip13));
	inner->state = create_state_with_key(0, 0);
	out.hasher = inner;
	out.hash_bytes = (t_hash_bytes)sip13_write_bytes;
	out.finish = (t_hash_finish)sip13_finish;
	return (out);
}