#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compile(const char *source) {
    char command[256];
    snprintf(command, sizeof(command), "gcc -o peopleeg %s", source);
    if (system(command) == -1) {
        perror("Ошибка компиляции");
        exit(EXIT_FAILURE);
    }
    printf("Компиляция завершена. Исполняемый файл: peopleeg\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <source-file.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    compile(argv[1]);
    return EXIT_SUCCESS;
}


