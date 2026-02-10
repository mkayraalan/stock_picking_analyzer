#include <limits.h>
#include "strategies.h"
#include <stdlib.h>

SingleResult strategy_single(const PricePoint* p, int n) {
    SingleResult r;
    r.buy_idx = -1;
    r.sell_idx = -1;
    r.profit = 0;

    int min_price = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < n; i++) {
        if (p[i].price < min_price) {
            min_price = p[i].price;
            min_idx = i;
        } else {
            int prof = p[i].price - min_price;
            if (prof > r.profit) {
                r.profit = prof;
                r.buy_idx = min_idx;
                r.sell_idx = i;
            }
        }
    }
    return r;
}

MultiResult strategy_multi(const PricePoint* p, int n) {
    MultiResult r;
    r.total_profit = 0;
    r.count = 0;

    r.buy_idx = malloc(sizeof(int) * n);
    r.sell_idx = malloc(sizeof(int) * n);

    int i = 0;
    while (i < n - 1) {
        // dip bul
        while (i < n - 1 && p[i + 1].price <= p[i].price)
            i++;

        if (i == n - 1) break;
        int buy = i++;

        // tepe bul
        while (i < n && p[i].price >= p[i - 1].price)
            i++;

        int sell = i - 1;

        r.buy_idx[r.count] = buy;
        r.sell_idx[r.count] = sell;
        r.total_profit += p[sell].price - p[buy].price;
        r.count++;
    }

    return r;
}