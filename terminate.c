#include "proj.h"

/**
 * terminate - removes the code
 * @codep: this is the code for argument
 * Return: 0 or 1
 */
int terminate(code_proj *codep)
{
	int termi;

	if (codep->readings[1])
	{
		termi = strint(codep->readings[1]);
		if (termi == -1)
		{
			codep->stand = 2;
			show(codep, "Illegal number: ");
			subst_vals(codep->readings[1]);
			swap('\n');
			return (1);
		}
		codep->mist = strint(codep->readings[1]);
		return (-2);
	}
	codep->mist = -1;
	return (-2);
}
/**
 * navigate - navigates the next dir
 * @codep: code that has useful argument info
 * Return: 0
 */
int navigate(code_proj *codep)
{
	char *pres, *tref, buffer[1024];
	int refes;

	pres = getcwd(buffer, 1024);

	if (!pres)
		print_str("TODO: >>getcwd failure emsg here<<\n");
	if (!codep->readings[1])
	{
		tref = bring(codep, "HOME=");
		if (!tref)
			refes = chdir((tref = bring(codep, "PWD=")) ? tref : "/");
		else
			refes = chdir(tref);
	}
	else if (fragment(codep->readings[1], "-") == 0)
	{
		if (!bring(codep, "OLDPWD="))
		{
			print_str(pres);
			output('\n');
			return (1);
		}
		print_str(bring(codep, "OLDPWD=")), output('\n');
		refes =
			chdir((tref = bring(codep, "OLDPWD=")) ? tref : "/");
	}
	else
		refes = chdir(codep->readings[1]);
	if (refes == -1)
	{
		show(codep, "can't cd to ");
		subst_vals(codep->readings[1]), swap('\n');
	}
	else
	{
		views(codep, "OLDPWD", bring(codep, "PWD="));
		views(codep, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * assist - helps to change cd
 * @codep: this has useful arguments
 * Return: 0
 */
int assist(code_proj *codep)
{
	char **character;

	character = codep->readings;
	print_str("help call works. Function not yet implemented \n");

	if (0)
		print_str(*character);
	return (0);
}
