#include "monty.h"
/**
 * f_pall -Print the stack
 * @head:head of  stack
 * @counter: non used
 * Return: nothing to return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
