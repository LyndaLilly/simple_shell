#include "proj.h"

/**
 * main - this is the main code
 * @ready: ready code
 * @half: this is the argument
 * Return: 0 or 1
 */
int main(int ready, char **half)
{
	code_proj codep[] = { INFO_INIT };
	int prt = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (prt)
			: "r" (prt));
	if (ready == 2)
	{
		prt = open(half[1], O_RDONLY);
		if (prt == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				subst_vals(half[0]);
				subst_vals(": 0: can't open ");
				subst_vals(half[1]);
				swap('\n');
				swap(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		codep->memo = prt;
	}
	expand(codep);
	learn_(codep);
	foo(codep, half);
	return (EXIT_SUCCESS);
}
