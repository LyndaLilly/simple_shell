#include "proj.h"

/**
 * elements - this shows the elements in the list
 * @w: this points to the head
 * Return: size
 */
size_t elements(const proj_link *w)
{
	size_t c = 0;

	while (w)
	{
		w = w->link;
		c++;
	}
	return (c);
}
/**
 * convert - converts the array to string
 * @t: this points to the head
 * Return: str
 */
char **convert(proj_link *t)
{
	proj_link *lack = t;
	size_t c = elements(t), e;
	char **surg;
	char *uses;

	if (!t || !c)
		return (NULL);
	surg = malloc(sizeof(char *) * (c + 1));
	if (!surg)
		return (NULL);
	for (c = 0; lack; lack = lack->link, c++)
	{
		uses = malloc(cut(lack->uses) + 1);
		if (!uses)
		{
			for (e = 0; e < c; e++)
				free(surg[e]);
			free(surg);
			return (NULL);
		}

		uses = run_program(uses, lack->uses);
		surg[c] = uses;
	}
	surg[c] = NULL;
	return (surg);
}
/**
 * display - this displays all the element
 * @w: this points to the header
 * Return: size
 */
size_t display(const proj_link *w)
{
	size_t c = 0;

	while (w)
	{
		print_str(fmt(w->countin, 10, 0));
		output(':');
		output(' ');
		print_str(w->uses ? w->uses : "(nil)");
		print_str("\n");
		w = w->link;
		c++;
	}
	return (c);
}
/**
 * find - finds the start node
 * @lack: this points to the head
 * @bef: this is string to prefix
 * @cru: this is the character to prefix
 * Return: null
 */
proj_link *find(proj_link *lack, char *bef, char cru)
{
	char *qui = NULL;

	while (lack)
	{
		qui = prefix_match(lack->uses, bef);
		if (qui && ((cru == -1) || (*qui == cru)))
			return (lack);
		lack = lack->link;
	}
	return (NULL);
}
/**
 * position - this fix the position of the node
 * @t: this points to the head
 * @lack: this is the node
 * Return: i or -1
 */
ssize_t position(proj_link *t, proj_link *lack)
{
	size_t c = 0;

	while (t)
	{
		if (t == lack)
			return (c);
		t = t->link;
		c++;
	}
	return (-1);
}
