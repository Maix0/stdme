/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:16:17 by maiboyer          #+#    #+#             */
/*   Updated: 2023/12/06 16:16:53 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "me/hashmap/generic/template.h"
#include "me/mem/calloc.h"
#include "me/mem/malloc.h"
#include "me/mem/memcpy.h"
#include "me/types.h"
#include <stdlib.h>

static void	find_possible_entry(t_entry **entry, t_entry **prev, t_hashmap *hmap,
		C_KEYTYPE__ *key)
{
	while (*entry != NULL)
	{
		if (hmap->cfunc(&(*entry)->kv.key, key))
		{
			*prev = *entry;
			break ;
		}
		*entry = (*entry)->next;
	}
}

void	insert_hashmap(t_hashmap *hmap, C_KEYTYPE__ key, C_VALTYPE__ value)
{
	size_t	hashed_key;
	t_entry	*prev;
	t_entry	*entry;

	hashed_key = hmap->hfunc(&key);
	prev = NULL;
	entry = hmap->buckets[hashed_key % hmap->num_buckets];
	find_possible_entry(&entry, &prev, hmap, &key);
	if (entry == NULL)
	{
		entry = malloc(sizeof(t_entry));
		entry->hash_id = hashed_key;
		entry->kv.key = key;
		entry->kv.val = value;
		entry->next = NULL;
		if (prev == NULL)
			hmap->buckets[hashed_key] = entry;
		else
			prev->next = entry;
	}
	else
		entry->kv.val = value;
}

C_VALTYPE__	*get_hashmap(t_hashmap *hmap, C_KEYTYPE__ *key)
{
	size_t	hashed_key;
	t_entry	*entry;

	hashed_key = hmap->hfunc(key);
	entry = hmap->buckets[hashed_key];
	while (entry != NULL)
	{
		if (hmap->cfunc(&entry->kv.key, key))
			return (&entry->kv.val);
		entry = entry->next;
	}
	return (NULL);
}

void	remove_hashmap(t_hashmap *hmap, C_KEYTYPE__ *key)
{
	size_t	hashed_key;
	t_entry	*prev;
	t_entry	*entry;

	hashed_key = hmap->hfunc(key);
	prev = NULL;
	entry = hmap->buckets[hashed_key % hmap->num_buckets];
	find_possible_entry(&entry, &prev, hmap, key);
	if (entry == NULL)
		return ;
	if (prev == NULL)
		hmap->buckets[hashed_key] = entry->next;
	else
		prev->next = entry->next;
	free(entry);
	hmap->buckets[hashed_key] = NULL;
}

#undef C_KEYTYPE__
#undef C_VALTYPE__
