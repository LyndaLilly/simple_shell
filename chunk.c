#include "proj.h"

/**
 * cut - this cuts the len of the string
 * @cru: this is the string to cut
 * Return: len of str
 */
int cut(char *cru)
{
	int c = 0;

	if (!cru)
		return (0);
	while (*cru++)
		c++;
	return (c);
}
/**
 * fragment - this compares strings
 * @mt: this is the first str
 * @mx: this is the 2nd str
 * Return: 1 or -1
 */
int fragment(char *mt, char *mx)
{
	while (*mt && *mx)
	{
		if (*mt != *mx)
			return (*mt - *mx);
		mt++;
		mx++;
	}
	if (*mt == *mx)
		return (0);
	else
		return (*mt < *mx ? -1 : 1);
}
/**
 * prefix_match - thid prfix the match string
 * @g: this si the string to match
 * @f: this is the sub-str to match
 * Return: string
 */
char *prefix_match(const char *g, const char *f)
{
	while (*f)
		if (*f++ != *g++)
			return (NULL);
	return ((char *)g);
}
/**
 * combine - combines string
 * @here: the destination buffer
 * @place: the source buffer
 * Return: buf
 */
char *combine(char *here, char *place)
{
	char *gip = here;

	while (*here)
		here++;
	while (*place)
		*here++ = *place++;
	*here = *place;
	return (gip);
}
