#include "proj.h"

/**
 * handle_data - this handles the character
 * @here: this is the location of the code
 * @place: the place of the character
 * @ax: this is the number of character to handle
 * Return: concatstring
 */
char *handle_data(char *here, char *place, int ax)
{
	int rip, prd;
	char *cru = here;

	rip = 0;

	while (place[rip] != '\0' && rip < ax - 1)
	{
		here[rip] = place[rip];
		rip++;
	}
	if (rip < ax)
	{
		prd = rip;

		while (prd < ax)
		{
			here[prd] = '\0';
			prd++;
		}
	}
	return (cru);
}
/**
 * plus_data - brings two character together
 * @here: the character
 * @place: this is the place character
 * @ax: this is the number of the character
 * Return: string
 */
char *plus_data(char *here, char *place, int ax)
{
	int rip, prd;
	char *cru = here;

	rip = 0;
	prd = 0;

	while (here[rip] != '\0')
		rip++;
	while (place[prd] != '\0' && prd < ax)
	{
		here[rip] = place[prd];
		rip++;
		prd++;
	}
	if (prd < ax)
		here[rip] = '\0';
	return (cru);
}
/**
 * find_data - this finds a data in the function
 * @cru: this is the string
 * @bet: this is the character
 * Return: cru
 */
char *find_data(char *cru, char bet)
{
	do {
		if (*cru == bet)
			return (cru);
	} while (*cru++ != '\0');
	return (NULL);
}
