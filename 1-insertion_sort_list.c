#include "sort.h"

/**
 * swap_list - Swaps values of 2 given nodes in a doubly linked list
 *
 * @head: The first node to be swapped
 * @tail: The second node to be swapped
 *
 * Return: Pointer to the head node
 */
listint_t *swap_list(listint_t **head, listint_t **tail)
{
	if ((*head)->prev == NULL && (*tail)->next == NULL)
	{
		(*tail)->prev = (*head)->prev;
		(*head)->next = (*tail)->next;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		return ((*tail));
	}
	else if ((*head)->prev == NULL)
	{
		(*tail)->next->prev = *head;
		(*tail)->prev = (*head)->prev;
		(*head)->next = (*tail)->next;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		return ((*tail));
	}
	else if ((*tail)->next == NULL)
	{
		(*head)->prev->next = *tail;
		(*tail)->prev = (*head)->prev;
		(*head)->next = (*tail)->next;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		return ((*tail)->prev);
	}
	else
	{
		(*head)->prev->next = *tail;
		(*tail)->next->prev = *head;
		(*tail)->prev = (*head)->prev;
		(*head)->next = (*tail)->next;
		(*tail)->next = *head;
		(*head)->prev = *tail;
		return ((*tail)->prev);
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 * the Insertion Sort algorithm
 *
 * @list: A doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tail;

	if (list)
	{
		head = *list;
		while (head->next != NULL)
		{
			tail = head->next;
			if ((head->n > tail->n) && (head->prev == NULL))
			{
				head = swap_list(&head, &tail);
				*list = head;
				print_list(*list);
			}
			else if (head->n > tail->n)
			{
				head = swap_list(&head, &tail);
				print_list(*list);
			}
			else
			{
				head = head->next;
			}
		}
	}
}
