#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "csv.h"

typedef struct {
    int buy_idx;
    int sell_idx;
    int profit;
} SingleResult;

typedef struct {
    int* buy_idx;
    int* sell_idx;
    int count;
    int total_profit;
} MultiResult;

SingleResult strategy_single(const PricePoint* p, int n, int fee);
MultiResult strategy_multi(const PricePoint* p, int n, int fee);

#endif