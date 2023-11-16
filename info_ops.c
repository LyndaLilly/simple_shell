#include "proj.h"

/**
 * _check - checks for correct shell code
 * @codep: this is the code project
 * Return: 1 or 0
 */
int _check(code_proj *codep)
{
	return (isatty(STDIN_FILENO) && codep->memo <= 2);
}
/**
 * process - this is the process of character
 * @kp: this is the character
 * @rut: this is the string
 * Return: 0 or 1
 */
int process(char kp, char *rut)
{
	while (*rut)
		if (*rut++ == kp)
			return (1);
	return (0);
}
/**
 * handleInfo - handles the info char
 * @kp: character to handle
 * Return: 1 0r 0
 */
int handleInfo(int kp)
{
	if ((kp >= 'a' && kp <= 'z') || (kp >= 'A' && kp <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * infoops - handles information operation
 * @pres: the prescribed char to handle
 * Return: 0 or -1
 */
int infoops(char *pres)
{
	int abx, bet = 1, bear = 0, see;
	unsigned int done = 0;

	for (abx = 0; pres[abx] != '\0' && bear != 2; abx++)
	{
		if (pres[abx] == '-')
			bet *= -1;

		if (pres[abx] >= '0' && pres[abx] <= '9')
		{
			bear = 1;
			done *= 10;
			done += (pres[abx] - '0');
		}
		else if (bear == 1)
			bear = 2;
	}
	if (bet == -1)
		see = -done;
	else
		see = done;
	return (see);
}
