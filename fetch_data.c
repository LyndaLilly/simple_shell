#include "proj.h"

/**
 * plain - this is the code_proj structure
 * @codep: this holds information
 */
void plain(code_proj *codep)
{
	codep->exec = NULL;
	codep->exec = NULL;
	codep->typed = NULL;
	codep->num_e = 0;
}
/**
 * fix - this is fix the plain structure
 * @codep: this holds information
 * @h: this is arg
 */
void fix(code_proj *codep, char **h)
{
	int c = 0;

	codep->codes = h[0];

	if (codep->exec)
	{
		codep->readings = split_data(codep->exec, " \t");
		if (!codep->readings)
		{
			codep->readings = malloc(sizeof(char *) * 2);
			if (codep->readings)
			{
				codep->readings[0] = two_(codep->exec);
				codep->readings[1] = NULL;
			}
		}
		for (c = 0; codep->readings && codep->readings[c]; c++)
			codep->num_e = c;
		substitute(codep);
		anod(codep);
	}
}
/**
 * gratis - this frees the information
 * @codep: this holds information
 * @lm: this returns true
 */
void gratis(code_proj *codep, int lm)
{
	release(codep->readings);
	codep->readings = NULL;
	codep->typed = NULL;

	if (lm)
	{
		if (!codep->project)
			free(codep->exec);
		if (codep->sur)
			lib_n(&(codep->sur));
		if (codep->bio)
			lib_n(&(codep->bio));
		if (codep->align)
			lib_n(&(codep->align));
		release(codep->environ);
		codep->environ = NULL;
		_dynops((void **)codep->project);
		if (codep->memo > 2)
			close(codep->memo);
		output(BUF_FLUSH);
	}
}
