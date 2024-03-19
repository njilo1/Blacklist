#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes des fonctions
void add_name(FILE* file, char* name);
int find_name(FILE* file, char* name);
void delete_name(FILE* file, char* name);

int main() {
    FILE* etudiants_file = fopen("etudiants.txt", "a+"); // Ouvre le fichier en mode ajout/lecture

    if (etudiants_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    char name[100];
    int choice;

    do {
        printf("1. Ajouter un nouveau nom\n");
        printf("2. Rechercher un étudiant\n");
        printf("3. Supprimer un étudiant\n");
        printf("4. Quitter (tapez 'exi')\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez le nom à ajouter : ");
                scanf("%s", name);
                add_name(etudiants_file, name);
                break;
            case 2:
                printf("Entrez le nom à rechercher : ");
                scanf("%s", name);
                if (find_name(etudiants_file, name))
                    printf("Le nom a été trouvé.\n");
                else
                    printf("Le nom n'a pas été trouvé.\n");
                break;
            case 3:
                printf("Entrez le nom à supprimer : ");
                scanf("%s", name);
                delete_name(etudiants_file, name);
                break;
            case 4:
                printf("Au revoir !\n");
                fclose(etudiants_file); // Ferme le fichier
                return 0; // Quitte le programme
            default:
                printf("Choix invalide.\n");
        }
    } while (strcmp(name, "exi") != 0);

    fclose(etudiants_file); // Ferme le fichier
    return 0;
}

void add_name(FILE* file, char* name) {
    fprintf(file, "%s\n", name); // Ajoute le nom dans le fichier
}

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
