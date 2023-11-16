/* stack_operations.c */
#include "monty.h"

stack_t *head = NULL;

/**
 * add_to_stack - Adds a new node at the beginning of the stack.
 * @n: The integer value to be stored in the new node.
 * Return: A pointer to the newly added node.
 */
stack_t *add_to_stack(const int n)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = head;
    new->prev = NULL;

    if (head != NULL)
        head->prev = new;

    head = new;
    return (new);
}

/**
 * print_all - Prints all elements in the stack.
 * Return: The number of printed nodes.
 */
size_t print_all(void)
{
    size_t printed = 0;
    stack_t *current = head;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
        printed++;
    }
    return (printed);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if equal, non-zero otherwise.
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * _realloc - Resizes the size of a pre-allocated pointer.
 * @ptr: The address to resize.
 * @size: The new size to allocate.
 * Return: A pointer to the newly allocated memory.
 */
void *_realloc(void *ptr, size_t size)
{
    size_t i;
    char *cpy, *temp;

    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }

    cpy = malloc(size);
    if (cpy == NULL)
        return (NULL);

    temp = ptr;
    for (i = 0; i < size; i++)
        cpy[i] = temp[i];

    free(ptr);
    return (cpy);
}

