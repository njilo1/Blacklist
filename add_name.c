#include <stdio.h>

void add_name(FILE* file, char* name) {
    fprintf(file, "%s\n", name); // Ajoute le nom dans le fichier
}
