#ifndef _MONTY_
#define _MONTY_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define TRUE 1
#define FALSE 0


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum Date_Format_Modes - The data format modes for this program.
 * @DF_LIFO: The data format code for a LIFO structure (like a stack)
 * @DF_FIFO: The data format code for a FIFO structure (like a queue)
 */
enum Date_Format_Modes
{
	/* The data format code for a LIFO structure (like a stack) */
	DF_LIFO,
	/* The data format code for a FIFO structure (like a queue) */
	DF_FIFO
};


void clean_mem(void);
void exit_(int status);
void _execute(char *line, int line_num, stack_t **stack_values);
instruction_t *get_handlers(void);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int n);
int _pop(stack_t **stack);
void enqueue(stack_t **stack, int n);
stack_t *get_top_element(stack_t **stack);
stack_t *get_bottom_element(stack_t **stack);
char **read_file(char *path, int *lines_count);
char *read_word(char *str, int *offset);
char is_whitespace(char c);
char is_ascii_char(int c);
char *get_data_mode(void);
char **get_lines(void);
char is_integer(char *str);
char **str_split(char *str, char c, int *len_out, char can_free);
char *str_cat(char *left, char *right, char can_free);
int str_len(const char *str);
void malloc_failure(char failed);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void mem_set(char *str, int n, char c);

#endif
