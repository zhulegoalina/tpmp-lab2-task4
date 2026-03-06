#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

#define MAX_LINE 256

void read_file(const char *filename, Country **countries, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        *count = 0;
        return;
    }

    char line[MAX_LINE];
    int capacity = 10;
    *countries = malloc(capacity * sizeof(Country));
    *count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (*count >= capacity) {
            capacity *= 2;
            *countries = realloc(*countries, capacity * sizeof(Country));
        }

        Country *c = &(*countries)[*count];
        char *token = strtok(line, ";");
        if (token) strcpy(c->country, token);
        token = strtok(NULL, ";");
        if (token) strcpy(c->capital, token);
        token = strtok(NULL, ";");
        if (token) strcpy(c->language, token);
        token = strtok(NULL, ";");
        if (token) c->population = atoi(token);
        token = strtok(NULL, ";");
        if (token) c->area = atof(token);
        token = strtok(NULL, ";");
        if (token) strcpy(c->currency, token);
        token = strtok(NULL, ";");
        if (token) strcpy(c->government, token);
        token = strtok(NULL, ";");
        if (token) strcpy(c->leader, token);
        token = strtok(NULL, ";");
        if (token) {
            token[strcspn(token, "\n")] = 0;
            strcpy(c->continent, token);
        }
        (*count)++;
    }
    fclose(file);
}

void filter_europe(Country *countries, int count, Country **result, int *result_count) {
    *result = malloc(count * sizeof(Country));
    *result_count = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(countries[i].continent, "Европа") == 0 && countries[i].population > 8000000) {
            (*result)[*result_count] = countries[i];
            (*result_count)++;
        }
    }
}

void write_file(const char *filename, Country *countries, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Ошибка открытия файла для записи");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s;%d;%.2f;%s;%s;%s;%s\n",
                countries[i].country,
                countries[i].capital,
                countries[i].language,
                countries[i].population,
                countries[i].area,
                countries[i].currency,
                countries[i].government,
                countries[i].leader,
                countries[i].continent);
    }
    fclose(file);
}

void print_countries(Country *countries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-15s | %-12s | %-10s | %10d | %8.2f | %-8s | %-10s | %-15s | %-8s\n",
               countries[i].country,
               countries[i].capital,
               countries[i].language,
               countries[i].population,
               countries[i].area,
               countries[i].currency,
               countries[i].government,
               countries[i].leader,
               countries[i].continent);
    }
}
