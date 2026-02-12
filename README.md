# Stock Picking Analyzer (C) + Signal Plotter (Python)

A command-line stock analysis tool written in C.

This project:
- Reads historical price data from CSV
- Implements two trading strategies:
  - Single trade (best buy + sell)
  - Multi trade (capture multiple uptrends)
- Supports transaction fees
- Exports buy/sell signals
- Plots results using Python

---

## Features

- Modular C project structure
- CSV file parsing
- Dynamic memory management (malloc / realloc / free)
- CLI argument parsing
- Transaction cost modeling
- ROI calculation
- Signal export
- Visualization with Python (matplotlib)

## Multi Strategy

- ./analyzer data/volatile.csv --strategy=multi --fee=0
- ./analyzer data/volatile.csv --strategy=multi --fee=2

## Single Strategy

- ./analyzer data/volatile.csv --strategy=single --fee=0
- /analyzer data/volatile.csv --strategy=single --fee=2