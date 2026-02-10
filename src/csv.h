#ifndef CSV_H
#define CSV_H

typedef struct {
    char date[11]; // YYYY-MM-DD
    int price;
} PricePoint;

int read_prices_csv(const char* path, PricePoint** out, int* out_count);

#endif
