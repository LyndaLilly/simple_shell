#include "proj.h"

/**
 * strint - this is the string integer
 * @pres: this is the character
 * Return: 0 or 1
 */
int strint(char *pres)
{
	int abx = 0;
	unsigned long int done = 0;

	if (*pres == '+')
		pres++;
	for (abx = 0;  pres[abx] != '\0'; abx++)
	{
		if (pres[abx] >= '0' && pres[abx] <= '9')
		{
			done *= 10;
			done += (pres[abx] - '0');
			if (done > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (done);
}
/**
 * show - shows the error
 * @codep: this holds information
 * @seen: this is the character error
 * Return: 0 or 1
 */
void show(code_proj *codep, char *seen)
{
	subst_vals(codep->codes);
	subst_vals(": ");
	disp(codep->narrates, STDERR_FILENO);
	subst_vals(": ");
	subst_vals(codep->readings[0]);
	subst_vals(": ");
	subst_vals(seen);
}

/**
 * disp - this is disputes the decimal num
 * @inside: the inner function
 * @prt: this is the description of file
 * Return: num
 */
int disp(int inside, int prt)
{
	int (*output)(char) = output;
	int abx, num = 0;
	unsigned int _abs_, face;

	if (prt == STDERR_FILENO)
		output = swap;
	if (inside < 0)
	{
		_abs_ = -inside;
		output('-');
		num++;
	}
	else
		_abs_ = inside;
	face = _abs_;
	for (abx = 1000000000; abx > 1; abx /= 10)
	{
		if (_abs_ / abx)
		{
			output('0' + face / abx);
			num++;
		}
		face %= abx;
	}
	output('0' + face);
	num++;
	return (num);
}
/**
 * fmt - this is the format of the function
 * @ques: this is the num que
 * @rumb: this is the end of the func
 * @bear: this is the bearing
 * Return: character
 */
char *fmt(long int ques, int rumb, int bear)
{
	static char *array;
	static char buffer[50];
	char look = 0;
	char *arch;
	unsigned long ax = ques;

	if (!(bear & CONVERT_UNSIGNED) && ques < 0)
	{
		ax = -ques;
		look = '-';
	}
	array = (bear & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	arch = &buffer[49];
	*arch = '\0';
	do {
		*--arch = array[ax % rumb];
		ax /= rumb;
	} while (ax != 0);
	if (look)
		*--arch = look;
	return (arch);
}
/**
 * strip - this removes the code from its position
 * @bre: the code to remove
 * Return: 0;
 */
void strip(char *bre)
{
	int abx;

	for (abx = 0; bre[abx] != '\0'; abx++)
		if (bre[abx] == '#' && (!abx || bre[abx - 1] == ' '))
		{
			bre[abx] = '\0';
			break;
		}
}
