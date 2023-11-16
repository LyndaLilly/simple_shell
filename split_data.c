#include "proj.h"

/**
 * split_data - this split data
 * @uses: the data to split
 * @f: the str
 * Return: arrays to pointer
 */

char **split_data(char *uses, char *f)
{
	int a, b, c, d, e = 0;
	char **cru;

	if (uses == NULL || uses[0] == 0)
		return (NULL);
	if (!f)
		f = " ";
	for (a = 0; uses[a] != '\0'; a++)
		if (!process(uses[a], f) && (process(uses[a + 1], f) || !uses[a + 1]))
			e++;
	if (e == 0)
		return (NULL);
	cru = malloc((1 + e) * sizeof(char *));
	if (!cru)
		return (NULL);
	for (a = 0, b = 0; b < e; b++)
	{
		while (process(uses[a], f))
			a++;
		c = 0;
		while (!process(uses[a + c], f) && uses[a + c])
			c++;
		cru[b] = malloc((c + 1) * sizeof(char));
		if (!cru[b])
		{
			for (c = 0; c < b; c++)
				free(cru[c]);
			free(cru);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			cru[b][d] = uses[a++];
		cru[b][d] = 0;
	}
	cru[b] = NULL;
	return (cru);
}
/**
 * locate - this locates the string
 * @uses: this is the string to locate
 * @f: the str
 * Return: arrays to pointer
 */
char **locate(char *uses, char f)
{
	int a, b, c, d, e = 0;
	char **cru;

	if (uses == NULL || uses[0] == 0)
		return (NULL);
	for (a = 0; uses[a] != '\0'; a++)
		if ((uses[a] != f && uses[a + 1] == f) ||
				(uses[a] != f && !uses[a + 1]) || uses[a + 1] == f)
			e++;
	if (e == 0)
		return (NULL);
	cru = malloc((1 + e) * sizeof(char *));
	if (!cru)
		return (NULL);
	for (a = 0, b = 0; b < e; b++)
	{
		while (uses[a] == d && uses[a] != f)
			a++;
		c = 0;
		while (uses[a + c] != d && uses[a + c] && uses[a + c] != d)
			c++;
		cru[b] = malloc((c + 1) * sizeof(char));
		if (!cru[b])
		{
			for (c = 0; c < b; c++)
				free(cru[c]);
			free(cru);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			cru[b][d] = uses[a++];
		cru[b][d] = 0;
	}
	cru[b] = NULL;
	return (cru);
}
