# Overview

This project is a C++ implementation of a scratch ticket lottery game inspired by The Simpsons’ Scratch ’n’ Win.

<img width="480" height="360" alt="GfkprLNWkAAtTpF" src="https://github.com/user-attachments/assets/376f6fee-7193-44c9-a225-b2a70758677b" />

It includes:

- A scratch ticket game where users reveal symbols to see if they win.
- A test harness that simulates one hundred thousand tickets, logs results to CSV, and enables analysis of fairness, win rates, payout distributions, etc.
- The potential for Excel visualizations comparing observed outcomes to theoretical probabilities and anything else that may be of interest.

# Features

- Weighted random symbol generation (🍋, 🍒, 🍇, 🔔, 💲).
- Payout logic for matching 3 symbols.
- CSV output for large-scale test runs.
- Validation of simulation results against expected probabilities.
- Excel charts with overlay lines (observed vs. theoretical).

# Project Structure
.
├── scratch_game.cpp   # Scratch ticket game
├── test_harness.cpp   # Automated simulation & CSV output
└── README.md          # Documentation

# Setup & Compilation

Compile the files using g++ (or your preferred C++ compiler):

g++ scratch_game.cpp -o scratch_game
g++ test_harness.cpp -o test_harness


Run the game:

./scratch_game


Run automated tests:

./test_harness

# Data Analysis

- Open results.csv in Excel (or another spreadsheet tool).
- Use formulas & pivot tables to calculate and visualize:

- Win frequency vs. expected probability
- Symbol distributions
- Payout frequencies
- Cumulative returns
- Etc.
