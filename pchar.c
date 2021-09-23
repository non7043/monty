#include "monty.h"
/**
 * pchar_monty -  prints the char at the top of the stack
 * @stack: Pointer To The head
 * @line_number: The Line Number
 * Return:Void
 */
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
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
