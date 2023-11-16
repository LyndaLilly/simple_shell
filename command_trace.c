#include "proj.h"

/**
 * cmd_trace - this finds the command trace
 * @codep: this is the information
 * Return: string
 */

char *cmd_trace(code_proj *codep)
{
	char *bre, *tref;

	tref = bring(codep, "HOME=");

	if (!tref)
		return (NULL);
	bre = malloc(sizeof(char) * (cut(tref) + cut(HIST_FILE) + 2));
	if (!bre)
		return (NULL);
	bre[0] = 0;
	run_program(bre, tref);
	combine(bre, "/");
	combine(bre, HIST_FILE);
	return (bre);
}
/**
 * text_h - this is going to create the text
 * @codep: this holds information
 * Return: 1 or -1
 */
int text_h(code_proj *codep)
{
	ssize_t prt;
	char *n = cmd_trace(codep);
	proj_link *lack = NULL;

	if (!n)
		return (-1);
	prt = open(n, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(n);
	if (prt == -1)
		return (-1);
	for (lack = codep->bio; lack; lack = lack->link)
	{
		write_to(lack->uses, prt);
		append_str('\n', prt);
	}
	append_str(BUF_FLUSH, prt);
	close(prt);
	return (1);
}
/**
 * learn_ -this learns the history
 * @codep: this holds information
 * Return: fail or success
 */
int learn_(code_proj *codep)
{
	int c, o = 0, draws = 0;
	ssize_t prt, p, q = 0;
	struct stat r;
	char *bre = NULL, *n = cmd_trace(codep);

	if (!n)
		return (0);
	prt = open(n, O_RDONLY);
	free(n);
	if (prt == -1)
		return (0);
	if (!fstat(prt, &r))
		q = r.st_size;
	if (q < 2)
		return (0);
	bre = malloc(sizeof(char) * (q + 1));
	if (!bre)
		return (0);
	p = read(prt, bre, q);
	bre[q] = 0;
	if (p <= 0)
		return (free(bre), 0);
	close(prt);
	for (c = 0; c < q; c++)
		if (bre[c] == '\n')
		{
			bre[c] = 0;
			constru(codep, bre + o, draws++);
			o = c + 1;
		}
	if (o != c)
		constru(codep, bre + o, draws++);
	free(bre);
	codep->bio_memo = draws;
	while (codep->bio_memo-- >= HIST_MAX)
		remove_n(&(codep->bio), 0);
	memo_trace(codep);
	return (codep->bio_memo);
}
/**
 * constru - constructs entry list
 * @codep: this holds information
 * @bre: this is the buffer
 * @draws: this draws the history
 * Return: 0
 */
int constru(code_proj *codep, char *bre, int draws)
{
	proj_link *lack = NULL;

	if (codep->bio)
		lack = codep->bio;
	put_n(&lack, bre, draws);

	if (!codep->bio)
		codep->bio = lack;
	return (0);
}
/**
 * memo_trace - this trace the memory history
 * @codep: holds information
 * Return: the new bio_memo
 */
int memo_trace(code_proj *codep)
{
	proj_link *lack = codep->bio;
	int c = 0;

	while (lack)
	{
		lack->countin = c++;
		lack = lack->link;
	}
	return (codep->bio_memo = c);
}
