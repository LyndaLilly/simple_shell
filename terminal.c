#include "proj.h"
/**
 * foo - this si the hshs
 * @codep: this is the information
 * @half: this is the average
 * Return: 1 or 0
 */
int foo(code_proj *codep, char **half)
{
	ssize_t cri = 0;
	int gip = 0;

	while (cri != -1 && gip != -2)
	{
		plain(codep);
		if (_check(codep))
			print_str("$ ");
		swap(BUF_FLUSH);
		cri = capture(codep);
		if (cri != -1)
		{
			fix(codep, half);
			gip = setup_program(codep);
			if (gip == -1)
				show_prompt(codep);
		}
		else if (_check(codep))
			output('\n');
		gratis(codep, 0);
	}
	text_h(codep);
	gratis(codep, 1);
	if (!_check(codep) && codep->stand)
		exit(codep->stand);
	if (gip == -2)
	{
		if (codep->mist == -1)
			exit(codep->stand);
		exit(codep->mist);
	}
	return (gip);
}
/**
 * setup_program - this setup a program
 * @codep: this holds information
 * Return: 0 or 1
 */
int setup_program(code_proj *codep)
{
	int c, a = -1;
	core_repo b[] = {
		{"exit", terminate},
		{"sur", circles},
		{"help", assist},
		{"bio", loged},
		{"views", n_sur},
		{"relive", not_b},
		{"cd", navigate},
		{"align", customize},
		{NULL, NULL}
	};
	for (c = 0; b[c].variant; c++)
		if (fragment(codep->readings[0], b[c].variant) == 0)
		{
			codep->narrates++;
			a = b[c].routine(codep);
			break;
		}
	return (a);
}
/**
 * show_prompt - shows the prompt command
 * @codep: this shows the information
 * Return: nothing
 */
void show_prompt(code_proj *codep)
{
	char *typed = NULL;
	int c, d;

	codep->typed = codep->readings[0];
	if (codep->red_code == 1)
	{
		codep->narrates++;
		codep->red_code = 0;
	}
	for (c = 0, d = 0; codep->exec[c]; c++)
		if (!process(codep->exec[c], " \t\n"))
			d++;
	if (!d)
		return;
	typed = locate_dir(codep, bring(codep, "PATH="), codep->readings[0]);
	if (typed)
	{
		codep->typed = typed;
		exec_task(codep);
	}
	else
	{
		if ((_check(codep) || bring(codep, "PATH=")
					|| codep->readings[0][0] == '/') && input(codep, codep->readings[0]))

			exec_task(codep);
		else if (*(codep->exec) != '\n')
		{
			codep->stand = 127;
			show(codep, "not found\n");
		}
	}
}
/**
 * exec_task - this executes the task
 * @codep: this holds information
 * Return: nothing
 */
void exec_task(code_proj *codep)
{
	pid_t f_b;

	f_b = fork();

	if (f_b == -1)
	{
		perror("Error:");
		return;
	}
	if (f_b == 0)
	{
		if (execve(codep->typed, codep->readings, catch_r(codep)) == -1)
		{
			gratis(codep, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(codep->stand));
		if (WIFEXITED(codep->stand))
		{
			codep->stand = WEXITSTATUS(codep->stand);
			if (codep->stand == 126)
				show(codep, "Permission denied\n");
		}
	}
}
