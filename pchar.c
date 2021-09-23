#include "monty.h"
/**
 * pchar_monty -  prints the char at the top of the stack
 * @stack: Pointer To The head
 * @line_number: The Line Number
 * Return:Void
 */
void pchar(stack_t **head, unsigned int line_number, code_args_t token)
{

	stack_t *_head = *head;

	if (token.args)
		free(token.args);
	/*Incase there is no node to be printed*/
	if (!_head)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
	/*handle if isn't a non printable character*/
	if (_head->n < 0 || _head->n > 127)
	{

		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*if everything went well print to stdout*/
	printf("%c\n", _head->n);
}
/**
 * pchar_error - error in case of empty stack
 */
void pchar_error(void)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}
/**
 * pchar_error_2 - error in case value out of range
 */
void pchar_error_2(void)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}
