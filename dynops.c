#include "proj.h"
/**
 * _dynops- this realease the pointers
 * @arch: this is going addess pointer
 * Return: 0 or 1
 */
int _dynops(void **arch)
{
	if (arch && *arch)
	{
		free(*arch);
		*arch = NULL;
		return (1);
	}
	return (0);
}
