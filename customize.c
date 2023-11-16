#include "proj.h"

/**
 * loged - handles the function for displaying information
 * @codep: thi contains potential info
 * Return: 0
 */
int loged(code_proj *codep)
{
	display(codep->bio);
	return (0);
}
/**
 * re_learn - reset the function
 * @codep: information
 * @uses: the characters
 * Return: 0 or 1
 */
int re_learn(code_proj *codep, char *uses)
{
	char *prep, drp;
	int gip;

	prep = find_data(uses, '=');
	if (!prep)
		return (1);
	drp = *prep;
	*prep = 0;
	gip = remove_n(&(codep->align),
			position(codep->align, find(codep->align, uses, -1)));
	*prep = drp;
	return (gip);
}
/**
 * learned - this is the set function
 * @codep: holds information
 * @uses: this is the character
 * Return: 0 or 1
 */
int learned(code_proj *codep, char *uses)
{
	char *prep;

	prep = find_data(uses, '=');

	if (!prep)
		return (1);
	if (!*++prep)
		return (re_learn(codep, uses));
	re_learn(codep, uses);
	return (put_n(&(codep->align), uses, 0) == NULL);
}
/**
 * studied - this brings out all the alias code
 * @lack: this is the node
 * Return: 0  or 1
 */
int studied(proj_link *lack)
{
	char *prep = NULL, *bru = NULL;

	if (lack)
	{
		prep = find_data(lack->uses, '=');
		for (bru = lack->uses; bru <= prep; bru++)
			output(*bru);
		output('\'');
		print_str(prep + 1);
		print_str("'\n");
		return (0);
	}
	return (1);
}
/**
 * customize - this customize the core functions
 * @codep: this holds information
 *  Return: 0
 */
int customize(code_proj *codep)
{
	int rip = 0;
	char *prep = NULL;
	proj_link *lack = NULL;

	if (codep->num_e == 1)
	{
		lack = codep->align;
		while (lack)
		{
			studied(lack);
			lack = lack->link;
		}
		return (0);
	}
	for (rip = 1; codep->readings[rip]; rip++)
	{
		prep = find_data(codep->readings[rip], '=');
		if (prep)
			learned(codep, codep->readings[rip]);
		else
			studied(find(codep->align, codep->readings[rip], '='));
	}
	return (0);
}
