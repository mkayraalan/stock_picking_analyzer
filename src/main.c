#include <stdio.h>
#include <stdlib.h>
#include "csv.h"
#include "strategies.h"

int main(void) {
    PricePoint* prices = NULL;
    int n = 0;

    if (read_prices_csv("data/sample.csv", &prices, &n) != 0 || n <= 0) {
        printf("Failed to read CSV\n");
        return 1;
    }

    SingleResult r = strategy_single(prices, n);

    printf("Strategy: single\n");
    printf("Profit: %d\n", r.profit);

    if (r.buy_idx != -1) {
    int buy_price = prices[r.buy_idx].price;
    int sell_price = prices[r.sell_idx].price;

    printf("Buy : %s @ %d\n", prices[r.buy_idx].date, buy_price);
    printf("Sell: %s @ %d\n", prices[r.sell_idx].date, sell_price);

    if (buy_price > 0) {
        double pct = (double)r.profit / (double)buy_price * 100.0;
        printf("Profit %%: %.2f%%\n", pct);
    }
} else {
    printf("No profitable trade found.\n");
}
    
   MultiResult m = strategy_multi(prices, n);

printf("\nStrategy: multi\n");
printf("Total Profit: %d\n", m.total_profit);

for (int i = 0; i < m.count; i++) {
    int b = m.buy_idx[i];
    int s = m.sell_idx[i];
    printf("Trade %d: Buy %s @ %d | Sell %s @ %d\n",
           i + 1,
           prices[b].date, prices[b].price,
           prices[s].date, prices[s].price);
}

free(m.buy_idx);
free(m.sell_idx); // memory leak'i önlemek için 

int invested = 0;
for (int i = 0; i < m.count; i++) {
    invested += prices[m.buy_idx[i]].price;
}

if (invested > 0) {
    double profit_pct = (double)m.total_profit / (double)invested * 100.0;
    printf("Total Profit %% (on total buys): %.2f%%\n", profit_pct);
}
}