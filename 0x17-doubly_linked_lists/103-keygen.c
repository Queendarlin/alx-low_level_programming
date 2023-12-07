#include "lists.h"

/**
 * main - Generate a key based on a username for crackme5
 * @argc: Number of command line arguments
 * @argv: Arguments for the function
 *
 * Return: 0 on success or 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int loop_index, loop_multiplier;
	size_t username_length, sum, max_char;
	char *ch = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char generated_key[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	username_length = strlen(argv[1]);
	generated_key[0] = ch[(username_length ^ 59) & 63];
	for (loop_index = 0, sum = 0; loop_index < username_length;
			loop_index++)
		sum += argv[1][loop_index];
	generated_key[1] = ch[(sum ^ 79) & 63];
	for (loop_index = 0, loop_multiplier = 1;
			loop_index < username_length; loop_index++)
		loop_multiplier *= argv[1][loop_index];

	generated_key[2] = ch[(loop_multiplier ^ 85) & 63];

	for (max_char = argv[1][0], loop_index = 0;
			loop_index < username_length; loop_index++)
		if ((char)max_char <= argv[1][loop_index])
			max_char = argv[1][loop_index];

	srand(max_char ^ 14);
	generated_key[3] = ch[rand() & 63];
	for (sum = 0, loop_index = 0; loop_index < username_length;
			loop_index++)
		sum += argv[1][loop_index] * argv[1][loop_index];
	generated_key[4] = ch[(sum ^ 239) & 63];

	for (sum = 0, loop_index = 0; (char)loop_index < argv[1][0]; loop_index++)
		sum = rand();
	generated_key[5] = ch[(sum ^ 229) & 63];
	printf("%s\n", generated_key);
	return (0);
}
