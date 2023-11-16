#include "proj.h"
/**
 * set - sets the memory
 * @cru: this points to memo
 * @t: this is the type byte
 * @r: this si the num of bytes
 * Return: cru
 */
char *set(char *cru, char t, unsigned int r)
{
	unsigned int c;

	for (c = 0; c < r; c++)
		cru[c] = t;
	return (cru);
}
/**
 * release - this releases the bytes
 * @q: this the char
 */
void release(char **q)
{
	char **u = q;

	if (!q)
		return;
	while (*q)
		free(*q++);
	free(u);
}
/**
 * resize - this resize the memo
 * @arch: this is the pointer
 * @x: this is the pre bytes
 * @w: this is the curr bytes
 * Return: pointer
 */
void *resize(void *arch, unsigned int x, unsigned int w)
{
	char *v;

	if (!arch)
		return (malloc(w));
	if (!w)
		return (free(arch), NULL);
	if (w == x)
		return (arch);
	v = malloc(w);
	if (!v)
		return (NULL);
	x = x < w ? x : w;
	while (x--)
		v[x] = ((char *)arch)[x];
	free(arch);
		return (v);
}
