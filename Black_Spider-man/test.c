#include <stdlib.h>
#include <stdio.h>

typedef struct character
{
	char *name;
	struct character * next;
}character;

character *  ft_new(char * s)
{
	character * new;
	new = NULL;
	new = (character*)malloc(sizeof(character));
	new->name = s;
	new->next = NULL;
	return new;
}

character * add(character * new, char * name)
{
	if( new == NULL)
	{
		new = ft_new(name);
	}
	else {
		while (new->next != NULL)
			new = new->next;
		new = ft_new(name);
	}
	return new;

}

int main(int argc, char const *argv[])
{
	character * p1;
	p1 = NULL;
	p1 = add(p1, "Hello");
	p1 = add(p1, "BYE");
		while (p1->next)
			printf("%s \n", p1->name);
	return 0;
}
