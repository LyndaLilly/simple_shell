#include "proj.h"
/**
 * verify - this verifies the code
 * @codep: this holds the information
 * @bre: this is the buf
 * @qui: this shows the buf
 * Return: 0 or 1
 */
int verify(code_proj *codep, char *bre, size_t *qui)
{
	size_t b = *qui;

	if (bre[b] == '|' && bre[b + 1] == '|')
	{
		bre[b] = 0;
		b++;
		codep->proj_line = CMD_OR;
	}
	else if (bre[b] == '&' && bre[b + 1] == '&')
	{
		bre[b] = 0;
		b++;
		codep->proj_line = CMD_AND;
	}
	else if (bre[b] == ';')
	{
		bre[b] = 0;
		codep->proj_line = CMD_CHAIN;
	}
	else
		return (0);
	*qui = b;
	return (1);
}
/**
 * validate - validates the code
 * @codep: this holds information
 * @bre: this is the buf
 * @qui: this is the pointer
 * @a: this is the index
 * @stre: length of buf
 * Return: nothing
 */
void validate(code_proj *codep, char *bre, size_t *qui, size_t a, size_t stre)
{
	size_t b = *qui;

	if (codep->proj_line == CMD_AND)
	{
		if (codep->stand)
		{
			bre[a] = 0;
			b = stre;
		}
	}
	if (codep->proj_line == CMD_OR)
	{
		if (!codep->stand)
		{
			bre[a] = 0;
			b = stre;
		}
	}

	*qui = b;
}
/**
 * substitute - this substitute the code
 * @codep: this holds information
 * Return: 1 or 0
 */
int substitute(code_proj *codep)
{
	int a;
	proj_link *lack;
	char *qui;

	for (a = 0; a < 10; a++)
	{
		lack = find(codep->align, codep->readings[0], '=');
		if (!lack)
			return (0);
		free(codep->readings[0]);
		qui = find_data(lack->uses, '=');
		if (!qui)
			return (0);
		qui = two_(qui + 1);
		if (!qui)
			return (0);
		codep->readings[0] = qui;
	}
	return (1);
}
/**
 * anod - this brings another variable
 * @codep: this holds information
 * Return: 0 or 1
 */
int anod(code_proj *codep)
{
	int a = 0;
	proj_link *lack;

	for (a = 0; codep->readings[a]; a++)
	{
		if (codep->readings[a][0] != '$' || !codep->readings[a][1])
			continue;
		if (!fragment(codep->readings[a], "$?"))
		{
			modify(&(codep->readings[a]),
					two_(fmt(codep->stand, 10, 0)));
			continue;
		}
		if (!fragment(codep->readings[a], "$$"))
		{
			modify(&(codep->readings[a]),
					two_(fmt(getpid(), 10, 0)));
			continue;
		}
		lack = find(codep->sur, &codep->readings[a][1], '=');

		if (lack)
		{
			modify(&(codep->readings[a]),
					two_(find_data(lack->uses, '=') + 1));
			continue;
		}
		modify(&codep->readings[a], two_(""));
	}
	return (0);
}
/**
 * modify - this modifies the str
 * @s: the string to modify
 * @t: this is the modeifeid string
 * Return: 0 or 1
 */
int modify(char **s, char *t)
{
	free(*s);
	*s = t;
	return (1);
}
