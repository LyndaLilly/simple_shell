#include "proj.h"

/**
 * bring - this is the brings in the inputs
 * @codep: this contains potential information
 * @nome: this defines the name
 * Return: names
 */
char *bring(code_proj *codep, const char *nome)
{
	proj_link *lack = codep->sur;
	char *prep;

	while (lack)
	{
		prep = prefix_match(lack->uses, nome);
		if (prep && *prep)
			return (prep);
		lack = lack->link;
	}
	return (NULL);
}
/**
 * circles - represents a close space
 * @codep: this contains potential information
 * Return: 0
 */
int circles(code_proj *codep)
{
	out(codep->sur);
	return (0);
}
/**
 * n_sur -  this is the number of surrounding
 * @codep: this contains potential information
 * Return: 0
 */
int n_sur(code_proj *codep)
{
	if (codep->num_e != 3)
	{
		subst_vals("Incorrect number of arguements\n");
		return (1);
	}
	if (views(codep, codep->readings[1], codep->readings[2]))
		return (0);
	return (1);
}
/**
 * not_b - this cancels number of environment
 * @codep: this contains the potential arguments
 * Return: 0
 */
int not_b(code_proj *codep)
{
	int ex;

	if (codep->num_e == 1)
	{
		subst_vals("Too few arguements.\n");
		return (1);
	}
	for (ex = 1; ex <= codep->num_e; ex++)
		relive(codep, codep->readings[ex]);
	return (0);
}
/**
 * expand - this makes the code bigger
 * @codep: this contains the potential argument
 * Return: Always 0
 */
int expand(code_proj *codep)
{
	proj_link *lack = NULL;
	size_t ex;

	for (ex = 0; environ[ex]; ex++)
		put_n(&lack, environ[ex], 0);
	codep->sur = lack;
	return (0);
}
