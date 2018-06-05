/** \copyright The MIT License */

#define RRC_EXPORTS
#include "pt.h"

#include <stdlib.h>
#include <stdarg.h>

RRC_API point_t
new_point(const size_t dimension, ...)
{
	point_t point = malloc(sizeof(struct point_t));
	if (!point)
		return NULL;

	point->dimension = dimension;
	if (!dimension) {
		point->vector = NULL;
		return point;
	}

	point->vector = calloc(dimension, sizeof(graduation_t));
	if (!point->vector) {
		free(point);
		return NULL;
	}

	va_list va;
	va_start(va, dimension);
	for (size_t i = 0; i < dimension; ++i)
		point->vector[i] = va_arg(va, int);
	va_end(va);
	return point;
}

RRC_API void
delete_point(point_t *const pointp)
{
	if (!*pointp)
		return;
	if ((*pointp)->vector)
		free((*pointp)->vector);
	free(*pointp);
	*pointp = NULL;
}

RRC_API length_t
point_axis_distance(point_t const A, point_t const B, const size_t axis)
{
	graduation_t alen = A->dimension < axis ? 0 : A->vector[axis];
	graduation_t blen = B->dimension < axis ? 0 : B->vector[axis];
	return alen < blen ? blen - alen : alen - blen;
}
