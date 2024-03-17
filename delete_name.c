#include<stdio.h>

void delete_name(FILE* file, char* name) {
    FILE* temp_file = fopen("temp.txt", "w"); // Fichier temporaire
    char buffer[100];
    rewind(file);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strlen(buffer) - 1] = '\0';
        if (strcmp(buffer, name) != 0)
            fprintf(temp_file, "%s\n", buffer); // Copie tous les noms sauf celui à supprimer
    }
    fclose(temp_file);
    remove("etudiants.txt"); // Supprime l'ancien fichier
    rename("temp.txt", "etudiants.txt"); // Renomme le fichier temporaire
    printf("Étudiant supprimé avec succès !\n");
}