#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int isExecutable(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (dot && !strcmp(dot, ".exe")) {
        return 1; 
    }
    return 0;
}

int isBatchFile(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (dot && !strcmp(dot, ".bat")) {
        return 1; 
    }
    return 0;
}

void searchFiles(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Erro ao abrir o diretório. Verifique se o diretório está correto.\n");
        return;
    }

    printf("Caminho do diretório recebido: %s\n", path);

    while ((entry = readdir(dir)) != NULL) {
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        if (stat(filepath, &fileStat) == -1) {
            printf("Erro ao acessar informações do arquivo: %s\n", entry->d_name);
            continue;
        }

        if (S_ISREG(fileStat.st_mode)) { 
            if (isExecutable(entry->d_name) || isBatchFile(entry->d_name)) {
                printf("Arquivo encontrado: %s\n", filepath);
            }
        } else if (S_ISDIR(fileStat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            searchFiles(filepath); 
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <caminho_do_diretorio>\n", argv[0]);
        return 1;
    }

    printf("Buscando por arquivos .exe e .bat em %s...\n", argv[1]);
    searchFiles(argv[1]);

    return 0;
}

