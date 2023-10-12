#include "variadic_functions.h"

/**
 * print_all - Function to print anything
 * @format: A list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int index = 0, sup;
	char *string;
	va_list vr_str;

	va_start(vr_str, format);
	while (format != NULL && format[index] != '\0')
	{
		switch (format[index])
		{
			case 'c':
				printf("%c", va_arg(vr_str, int));
				sup = 0;
				break;
			case 'i':
				printf("%d", va_arg(vr_str, int));
				sup = 0;
				break;
			case 'f':
				printf("%f", va_arg(vr_str, double));
				sup = 0;
				break;
			case 's':
				string = va_arg(vr_str, char*);
				if (string == NULL)
					string = "(nil)";
				printf("%s", string);
				sup = 0;
				break;
			default:
				sup = 1;
				break;
		}
		if (format[index + 1] != '\0' && sup == 0)
			printf(", ");
		index++;
	}
	printf("\n");
	va_end(vr_str);
}
