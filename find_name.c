#include <stdio.h>
int find_name(FILE* file, char* name) {
    char buffer[100];
    rewind(file); // Rembobine le fichier
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strlen(buffer) - 1] = '\0'; // Supprime le saut de ligne
        if (strcmp(buffer, name) == 0)
            return 1; // Le nom a été trouvé
    }
    return 0; // Le nom n'a pas été trouvé
}