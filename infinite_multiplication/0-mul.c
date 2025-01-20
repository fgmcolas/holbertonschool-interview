#include "holberton.h"

/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *error = "Error\n";
	int i;

	if (argc != 3 || !is_a_number(argv[1]) || !is_a_number(argv[2]))
	{
		for (i = 0; error[i] != '\0'; i++)
			_putchar(error[i]);
		exit(98);
	}
	multiply(argv[1], argv[2]);
	return (0);
}

/**
 * multiply - Fills an array with the multiplication num_1 times i
 * Arguments
 * @num_1:	string representing the 1st number in 10 base
 * @num_2:  string representing the 2nd number in 10 base
 * Returns - The multiplication
 */

void multiply(char *num_1, char *num_2)
{
	char mul[10][MAX1], answer[MAX1][MAX2];
	int tag, i, j, len_1, len_2, res, value, pos_1, pos_2, row, z;

	len_1 = str_len(num_1);
	len_2 = str_len(num_2);
	for (i = 0; i < 10; i++)
		for (j = 0; j < MAX1; j++)
			mul[i][j] = '.';

	for (i = 0; i < MAX1; i++)
		for (j = 0; j < MAX2; j++)
			answer[i][j] = '.';

	for (tag = 0, i = 0; i < 10; i++)
	{
		for (j = 0; j <= len_1; j++)
		{
			pos_1 = len_1 - j - 1;
			if (pos_1 >= 0)
			{
				res = ((num_1[pos_1] - 48) * i) + tag;
				value = res % 10;
				mul[i][j] = (value + '0');
				tag = res / 10;
			}
			else
			{
				mul[i][j] = (tag != 0) ? tag + 48 : '.';
				tag = 0;
			}
		}
	}

	for (j = 0; j < len_2; j++)
	{
		pos_2 = len_2 - j - 1;
		row = num_2[pos_2] - 48;
		for (z = 0; z < len_1 + 1; z++)
			answer[j][z + j] = mul[row][z];
	}
	sum_and_print(answer, len_1, len_2);
}

/**
 * is_a_number - Indicates if a string represents a number in 10 base
 * Arguments
 * @a_str: string representing a number in 10 base
 * Return: 1 if true, 0 if not.
 */
int is_a_number(char *a_str)
{
	if (*a_str == '\0')
		return (_FALSE_);
	while (*a_str != '\0')
	{
		if (*a_str < '0' || *a_str > '9')
			return (_FALSE_);
		a_str++;
	}
	return (_TRUE_);
}

/**
 * sum_and_print - Generates the sumation and print the results
 * Arguments
 * @a:	matrix with multiplitation tables
 * @len_1: len of string 1
 * @len_2: len os string 2
 * Return: noting.
 */
void sum_and_print(char a[MAX1][MAX2], int len_1, int len_2)
{
	int tag = 0, i, j, sum, value, total_len;
	char total[MAX2 + 1] = {0};
	char *ar;

	total_len = len_1 + len_2;
	for (j = 0; j < total_len; j++)
	{
		sum = 0;
		for (i = 0; i < len_2; i++)
			sum += (a[i][j] >= '0' && a[i][j] <= '9') ? a[i][j] - '0' : 0;
		value = (sum + tag) % 10;
		total[j] = (value + '0');
		tag = (sum + tag) / 10;
	}
	if (tag > 0)
		total[j++] = tag + '0';
	total[j] = '\0';

	for (i = 0; total[total_len - i - 1] == '0' && total_len - i - 1 > 0; i++)
		;
	ar = &total[total_len - i - 1];
	while (*ar)
		_putchar(*ar--);
	_putchar('\n');
}

/**
 * str_len - Calculates the lenght of a string
 * Arguments
 * @a:	matrix with multiplitation tables
 * Return: The lengnth of a.
 */
int str_len(char *a)
{
	int i;

	for (i = 0; a[i] != '\0'; i++)
		;
	return (i);
}
