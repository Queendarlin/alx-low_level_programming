#include <stdio.h>


int main(int argc, char *argv[]) {
    int total = 0;

    if (argc == 1) {
        printf("0\n");
        return 0;
    }
	int i;
	int j;

    for (i = 1; i < argc; i++) {
        char *arg = argv[i];
        
	int num = 0;

        for (j = 0; arg[j] != '\0'; j++) {
            if (arg[j] < '0' || arg[j] > '9') {
                printf("Error\n");
                return 1;
            }
            num = num * 10 + (arg[j] - '0');
        }

        if (num > 0) {
            total += num;
        }
    }

    printf("%d\n", total);

    return 0;
}
