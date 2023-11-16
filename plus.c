#include "proj.h"

/**
 * subst_vals - this is the value of the input
 * @uses: this is the characters
 * Return: void
 */
void subst_vals(char *uses)
{
	int rip = 0;

	if (!uses)
		return;
	while (uses[rip] != '\0')
	{
		swap(uses[rip]);
		rip++;
	}
}
/**
 * swap - this swaps the char
 * @dest: this is the string
 * Return: 1 or 0 on success or error
 */
int swap(char dest)
{
	static int rip;
	static char buf[WRITE_BUF_SIZE];

	if (dest == BUF_FLUSH || rip >= WRITE_BUF_SIZE)
	{
		write(2, buf, rip);
		rip = 0;
	}
	if (dest != BUF_FLUSH)
		buf[rip++] = dest;
	return (1);
}
/**
 * append_str - appends the text to the function
 * @dest: This is the string
 * @prt: this is the directory
 * Return: 1 or 0 on success or error
 */
int append_str(char dest, int prt)
{
	static int rip;
	static char buf[WRITE_BUF_SIZE];

	if (dest == BUF_FLUSH || rip >= WRITE_BUF_SIZE)
	{
		write(prt, buf, rip);
		rip = 0;
	}
	if (dest != BUF_FLUSH)
		buf[rip++] = dest;
	return (1);
}
/**
 * write_to - this writes the character
 * @uses: this is the character
 * @prt: this is the directory
 * Return: character
 */
int write_to(char *uses, int prt)
{
	int rip = 0;

	if (!uses)
		return (0);
	while (*uses)
	{
		rip += append_str(*uses++, prt);
	}
	return (rip);
}
