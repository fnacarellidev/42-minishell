#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	t_node	*a;
	t_node	*b;

	a = malloc(sizeof(t_node));
	b = malloc(sizeof(t_node));
	a->next = b;
	b->next = NULL;

	a->data = strdup("Fabin");
	b->data = strdup("Reinan");

	printf("%s\n", a->data);
	printf("%s\n", b->data);

	ft_free_list(&a);
}
