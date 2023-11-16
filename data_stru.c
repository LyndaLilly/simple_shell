#include "proj.h"

/**
 * data_stru - this is the data structure
 * @t: this indicates the head
 * @uses: this is the string
 * @countin: this is the number of lack
 * Return: len
 */
proj_link *data_stru(proj_link **t, const char *uses, int countin)
{
	proj_link *u;

	if (!t)
		return (NULL);
	u = malloc(sizeof(proj_link));
	if (!t)
		return (NULL);
	set((void *)u, 0, sizeof(proj_link));
	u->countin = countin;
	if (uses)
	{
		u->uses = two_(uses);
		if (!u->uses)
		{
			free(u);
			return (NULL);
		}
	}
	u->link = *t;
	*t = u;
	return (u);
}
/**
 * put_n - this puts a lack to the list
 * @t: this is pointer to head
 * @uses: this is the string
 * @countin: this is the number of lack
 * Return: len
 */
proj_link *put_n(proj_link **t, const char *uses, int countin)
{
	proj_link *v, *lack;

	if (!t)
		return (NULL);
	lack = *t;
	v = malloc(sizeof(proj_link));
	if (!v)
		return (NULL);
	set((void *)v, 0, sizeof(proj_link));
	v->countin = countin;
	if (uses)
	{
		v->uses = two_(uses);
		if (!v->uses)
		{
			free(v);
			return (NULL);
		}
	}
	if (lack)
	{
		while (lack->link)
			lack = lack->link;
		lack->link = v;
	}
	else
		*t = v;
	return (v);

}
/**
 * out - this brings out the outer element
 * @w: this is the width
 * Return: size
 */
size_t out(const proj_link *w)
{
	size_t c = 0;

	while (w)
	{
		print_str(w->uses ? w->uses : "(nil)");
		print_str("\n");
		w = w->link;
		c++;
	}
	return (c);
}
/**
 * remove_n - this removes the lack
 * @t: this points the header
 * @x: this is the index
 * Return: 1 or 0
 */
int remove_n(proj_link **t, unsigned int x)
{
	proj_link *lack, *a;
	unsigned int c = 0;

	if (!t || !*t)
		return (0);
	if (!x)
	{
		lack = *t;
		*t = (*t)->link;
		free(lack->uses);
		free(lack);
		return (1);
	}
	lack = *t;

	while (lack)
	{
		if (c == x)
		{
			a->link = lack->link;
			free(lack->uses);
			free(lack);
			return (1);
		}
		c++;
		a = lack;
		lack = lack->link;
	}
	return (0);
}
/**
 * lib_n - this liberates the node
 * @b: this points to the head
 * Return: nothing
 */
void lib_n(proj_link **b)
{
	proj_link *lack, *y, *t;

	if (!b || !*b)
		return;
	t = *b;
	lack = t;

	while (lack)
	{
		y = lack->link;
		free(lack->uses);
		free(lack);
		lack = y;
	}
	*b = NULL;
}
