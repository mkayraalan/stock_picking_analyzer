#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

int read_prices_csv(const char* path, PricePoint** out, int* out_count) {
    FILE* f = fopen(path, "r");
    if (!f) return 1;

    char line[128];
    int cap = 16;
    int n = 0;

    PricePoint* arr = (PricePoint*)malloc(sizeof(PricePoint) * cap);
    if (!arr) {
        fclose(f);
        return 2;
    }

    // header'ı atla
    if (!fgets(line, sizeof(line), f)) {
        fclose(f);
        free(arr);
        return 3;
    }

    while (fgets(line, sizeof(line), f)) {
        // newline temizle
        line[strcspn(line, "\r\n")] = '\0';

        // boş satır geç
        if (line[0] == '\0') continue;

        if (n >= cap) {
            cap *= 2;
            PricePoint* tmp = (PricePoint*)realloc(arr, sizeof(PricePoint) * cap);
            if (!tmp) {
                fclose(f);
                free(arr);
                return 4;
            }
            arr = tmp;
        }

        char* date = strtok(line, ",");
        char* price = strtok(NULL, ",");

        if (!date || !price) continue;

        // date: 10 char kopyala
        strncpy(arr[n].date, date, 10);
        arr[n].date[10] = '\0';

        arr[n].price = atoi(price);
        n++;
    }

    fclose(f);
    *out = arr;
    *out_count = n;
    return 0;
}