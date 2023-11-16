#include "proj.h"

/**
 * input -this is the input file
 * @codep: this holds information
 * @ways: this is the way of the file
 * Return: 0 or 1
 */
int input(code_proj *codep, char *ways)
{
	struct stat r;
	(void)codep;

	if (!ways || stat(ways, &r))
		return (0);
	if (r.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * foo_bar - this makes the char two
 * @f: the this is the char path
 * @g: begins the i
 * @m: ends the i
 * Return: pointer
 */
char *foo_bar(char *f, int g, int m)
{
	static char bre[1024];
	int c = 0, d = 0;

	for (d = 0, c = g; c < m; c++)
		if (f[c] != ':')
			bre[d++] = f[c];
	bre[d] = 0;
	return (bre);
}
/**
 * locate_dir - this locates the dir
 * @codep: this holds information
 * @f: this is the string
 * @n: this is the command
 * Return: f
 */
char *locate_dir(code_proj *codep, char *f, char *n)
{
	int c = 0, k = 0;
	char *typed;

	if (!f)
		return (NULL);
	if ((cut(n) > 2) && prefix_match(n, "./"))
	{
		if (input(codep, n))
			return (n);
	}
	while (1)
	{
		if (!f[c] || f[c] == ':')
		{
			typed = foo_bar(f, k, c);
			if (!*typed)
				combine(typed, n);
			else
			{
				combine(typed, "/");
				combine(typed, n);
			}
			if (input(codep, typed))
				return (typed);
			if (!f[c])
				break;
			k = c;
		}
		c++;
	}
	return (NULL);
}
