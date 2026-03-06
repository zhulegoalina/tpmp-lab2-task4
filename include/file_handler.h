#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

typedef struct {
    char country[50];
    char capital[50];
    char language[30];
    int population;
    float area;
    char currency[20];
    char government[30];
    char leader[50];
    char continent[20];
} Country;

void read_file(const char *filename, Country **countries, int *count);
void filter_europe(Country *countries, int count, Country **result, int *result_count);
void write_file(const char *filename, Country *countries, int count);
void print_countries(Country *countries, int count);

#endif
