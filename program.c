#include "proj.h"
/**
 * run_program - this runs a program
 * @here: this is the dest of the code
 * @place: this is where the code is
 * Return: pointer
 */
char *run_program(char *here, char *place)
{
	int c = 0;

	if (here == place || place == 0)
		return (here);
	while (place[c])
	{
		here[c] = place[c];
		c++;
	}
	here[c] = 0;
	return (here);
}
/**
 * two_ -this makes the string two
 * @uses: this is the string
 * Return: pointer
 */
char *two_(const char *uses)
{
	int strit = 0;
	char *qui;

	if (uses == NULL)
		return (NULL);
	while (*uses++)
		strit++;
	qui = malloc(sizeof(char) * (strit + 1));
	if (!qui)
		return (NULL);
	for (strit++; strit--;)
		qui[strit] = *--uses;
	return (qui);
}
/**
 * print_str - this is going to print the string
 * @uses: this is the str to be printed
 * Return: void
 */
void print_str(char *uses)
{
	int c = 0;

	if (!uses)
		return;
	while (uses[c] != '\0')
	{
		output(uses[c]);
		c++;
	}
}
/**
 * output - this outputs the text
 * @texts: Tthis is the text to output
 * Return: 1 or 0.
 */
int output(char texts)
{
	static int c;
	static char bre[WRITE_BUF_SIZE];

	if (texts == BUF_FLUSH || c >= WRITE_BUF_SIZE)
	{
		write(1, bre, c);
		c = 0;
	}
	if (texts != BUF_FLUSH)
		bre[c++] = texts;
	return (1);
}
