/*
 *  delta.h
 *
 *  Copyright (c) 2007-2008 by Judd Vinet <jvinet@zeroflux.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _ALPM_DELTA_H
#define _ALPM_DELTA_H

#include <sys/types.h> /* off_t */

#include "alpm.h"

struct __pmdelta_t {
	/** filename of the 'before' file */
	char *from;
	/** md5sum of the 'before' file */
	char *from_md5;
	/** filename of the 'after' file */
	char *to;
	/** md5sum of the 'after' file */
	char *to_md5;
	/** filename of the delta patch */
	char *delta;
	/** md5sum of the delta file */
	char *delta_md5;
	/** filesize of the delta file */
	off_t delta_size;
	/** download filesize of the delta file */
	off_t download_size;
};

pmdelta_t *_alpm_delta_parse(char *line);
void _alpm_delta_free(pmdelta_t *delta);
off_t _alpm_shortest_delta_path(alpm_list_t *deltas,
		const char *to, const char *to_md5, alpm_list_t **path);

#endif /* _ALPM_DELTA_H */

/* vim: set ts=2 sw=2 noet: */
