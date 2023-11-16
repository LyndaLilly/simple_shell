#include "proj.h"

/**
 * catch_r - this catches the string
 * @codep: this holds information
 * Return: 0
 */
char **catch_r(code_proj *codep)
{
	if (!codep->environ || codep->loc_sur)
	{
		codep->environ = convert(codep->sur);
		codep->loc_sur = 0;
	}
	return (codep->environ);
}
/**
 * relive - this removes the loc_sur
 * @codep: this contains information
 * @f: the variable property
 * Return: 1 or 0
 */
int relive(code_proj *codep, char *f)
{
	proj_link *lack = codep->sur;
	size_t c = 0;
	char *qui;

	if (!lack || !f)
		return (0);
	while (lack)
	{
		qui = prefix_match(lack->uses, f);
		if (qui && *qui == '=')
		{
			codep->loc_sur = remove_n(&(codep->sur), c);
			c = 0;
			lack = codep->sur;
			continue;
		}
		lack = lack->link;
		c++;
	}
	return (codep->loc_sur);
}
/**
 * views - this sets view for new sur
 * @codep: this contains information
 * @f: this is the character variable
 * @g: this is the string
 * Return: 0
 */
int views(code_proj *codep, char *f, char *g)
{
	char *bre = NULL;
	proj_link *lack;
	char *qui;

	if (!f || !g)
		return (0);
	bre = malloc(cut(f) + cut(g) + 2);
	if (!bre)
		return (1);
	run_program(bre, f);
	combine(bre, "=");
	combine(bre, g);
	lack = codep->sur;
	while (lack)
	{
		qui = prefix_match(lack->uses, f);
		if (qui && *qui == '=')
		{
			free(lack->uses);
			lack->uses = bre;
			codep->loc_sur = 1;
			return (0);
		}
		lack = lack->link;
	}
	put_n(&(codep->sur), bre, 0);
	free(bre);
	codep->loc_sur = 1;
	return (0);
}
