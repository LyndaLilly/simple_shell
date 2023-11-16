#include "proj.h"

/**
 * allowed - this allows the func
 * @codep: this holds information
 * @bre: this is the buffer
 * @stre: this is the len
 * Return: bytes
 */
ssize_t allowed(code_proj *codep, char **bre, size_t *stre)
{
	ssize_t cri = 0;
	size_t wit = 0;

	if (!*stre)
	{
		free(*bre);
		*bre = NULL;
		signal(SIGINT, interrupt);
#if USE_GETLINE
		cri = getline(bre, &wit, stdin);
#else
		cri = pre_read(codep, bre, &wit);
#endif
		if (cri > 0)
		{
			if ((*bre)[cri - 1] == '\n')
			{
				(*bre)[cri - 1] = '\0';
				cri--;
			}
			codep->red_code = 1;
			strip(*bre);
			constru(codep, *bre, codep->bio_memo++);
			/* if (find_data(*bre, ';')) is this a command chain? */
			{
				*stre = cri;
				codep->project = bre;
			}
		}
	}
		return (cri);
}

/**
 * capture - this captures the code new line
 * @codep: this holds information
 * Return: bytes
 */

ssize_t capture(code_proj *codep)
{
	static char *bre; /* the ';' command chain buffer */
	static size_t c, e, stre;
	ssize_t cri = 0;
	char **rm = &(codep->exec), *qui;

	output(BUF_FLUSH);

	cri = allowed(codep, &bre, &stre);

	if (cri == -1) /* EOF */
		return (-1);
	if (stre)
	{
		e = c;
		qui = bre + c;
		validate(codep, bre, &e, c, stre);
		while (e < stre)
		{
			if (verify(codep, bre, &e))
				break;
			e++;
		}
		c = e + 1;
		if (c >= stre)
		{
			c = stre = 0; /* reset posi and strit */
			codep->proj_line = CMD_NORM;
		}
		*rm = qui;
		return (cut(qui));
	}
	*rm = bre;
	return (cri);
}

/**
 * study_line - this is studies the line buffer
 * @codep: this holds information
 * @bre: this is the buf
 * @c: this is the char size
 * Return: cri
 */
ssize_t study_line(code_proj *codep, char *bre, size_t *c)
{
	ssize_t cri = 0;

	if (*c)
		return (0);
	cri = read(codep->memo, bre, READ_BUF_SIZE);
	if (cri >= 0)
		*c = cri;
	return (cri);
}
/**
 * pre_read - this reads the line of the buffer
 * @codep: this holds information
 * @arch: this is the pointer
 * @strit: this is the size
 * Return: cru
 */
int pre_read(code_proj *codep, char **arch, size_t *strit)
{
	static char bre[READ_BUF_SIZE];
	static size_t c, stre;
	size_t d;
	ssize_t cri = 0, cru = 0;
	char *qui = NULL, *a = NULL, *dest;

	qui = *arch;

	if (qui && strit)
		cru = *strit;
	if (c == stre)
		c = stre = 0;
	cri = study_line(codep, bre, &stre);
	if (cri == -1 || (cri == 0 && stre == 0))
		return (-1);
	dest = find_data(bre + c, '\n');
	d = dest ? 1 + (unsigned int)(dest - bre) : stre;
	a = resize(qui, cru, cru ? cru + d : d + 1);
	if (!a) /* MALLOC FAILURE! */
		return (qui ? free(qui), -1 : -1);
	if (cru)
		plus_data(a, bre + c, d - c);
	else
		handle_data(a, bre + c, d - c + 1);
	cru += d - c;
	c = d;
	qui = a;
	if (strit)
		*strit = cru;
	*arch = qui;
	return (cru);
}
/**
 * interrupt - this handles the control
 * @pens: this is responsible for signal
 * Return: nothing
 */
void interrupt(__attribute__((unused))int pens)
{
	print_str("\n");
	print_str("$ ");
	output(BUF_FLUSH);
}
