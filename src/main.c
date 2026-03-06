#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"

int main() {
    Country *countries = NULL;
    Country *europe_countries = NULL;
    int count = 0, europe_count = 0;

    printf("=== Задание 4: Государства ===\n");
    printf("Вариант 37: страны Европы с населением > 8 млн\n\n");

    // Чтение из файла
    read_file("data/input.txt", &countries, &count);
    if (count == 0) {
        printf("Ошибка: нет данных или файл не найден\n");
        return 1;
    }

    printf("Всего стран: %d\n\n", count);
    printf("Все страны:\n");
    print_countries(countries, count);

    // Фильтрация
    filter_europe(countries, count, &europe_countries, &europe_count);

    printf("\n=== Результат: страны Европы с населением > 8 млн ===\n");
    printf("Найдено: %d\n\n", europe_count);
    print_countries(europe_countries, europe_count);

    // Запись в файл
    write_file("data/output.txt", europe_countries, europe_count);
    printf("\nРезультат сохранен в data/output.txt\n");

    // Очистка памяти
    free(countries);
    free(europe_countries);

    return 0;
}
