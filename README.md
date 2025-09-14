# Overview

This project is a C++ implementation of a scratch ticket lottery game inspired by The Simpsons’ (my favorite show) Scratch ’n’ Win.

<img width="343" height="230" alt="Scratch_n_Win" src="https://github.com/user-attachments/assets/9980ea2b-2612-4541-b259-40c2cf152450" />


It includes:

- A scratch ticket game where users reveal symbols to see if they win.
- A test harness that simulates one hundred thousand tickets, logs results to CSV, and enables analysis of fairness, win rates, payout distributions, etc.
- The potential for Excel visualizations comparing observed outcomes to theoretical probabilities and anything else that may be of interest.

<img width="150" height="500" alt="image" src="https://github.com/user-attachments/assets/e377a2bc-aa3d-4bd8-8804-25b7a0399afe" />


# Features

- Weighted random symbol generation (🍋, 🍒, 🍇, 🔔, 💲).
- Payout logic for matching 3 symbols.
- CSV output for large-scale test runs.
- Validation of simulation results against expected probabilities.
- Excel charts with overlay lines (observed vs. theoretical).

# Project Structure
```
.
├── scratch_game.cpp   # Scratch ticket game
├── test_harness.cpp   # Automated simulation & CSV output
└── README.md          # Documentation
```

# Setup & Compilation

Compile the files using g++ (or your preferred C++ compiler):

```
g++ scratch_game.cpp -o scratch_game
g++ test_harness.cpp -o test_harness
```

Run the game:

```
./scratch_game
```

Run automated tests:

```
./test_harness
```

# Data Analysis

- Open results.csv in Excel (or another spreadsheet tool).
- Use formulas & pivot tables to calculate and visualize:

- Win frequency vs. expected probability
- Symbol distributions
- Payout frequencies
- Cumulative returns
- Etc.

<img width="403" height="329" alt="image" src="https://github.com/user-attachments/assets/51b297a3-76af-49fe-abd3-f119c69ce7e9" />

<img width="759" height="825" alt="image" src="https://github.com/user-attachments/assets/809c9a6f-742f-4406-9aa7-8d961e437d87" />

<img width="2122" height="1003" alt="Picture1" src="https://github.com/user-attachments/assets/9f946cd0-3474-4cf3-810c-53a2c2d6c68f" />

<img width="2112" height="1003" alt="Picture2" src="https://github.com/user-attachments/assets/4d7536f5-8c40-47d9-b91d-218399c2d515" />

<img width="1947" height="1035" alt="Picture3" src="https://github.com/user-attachments/assets/212350f7-7f8f-4d31-b7f0-7316432bd84f" />

<img width="2053" height="999" alt="Picture4" src="https://github.com/user-attachments/assets/d1fd5b12-fb82-491c-896b-e107928dfbf7" />

<img width="2002" height="1155" alt="Picture5" src="https://github.com/user-attachments/assets/dbe86479-9cd3-4d58-9fe4-bc57b87a881b" />

<img width="2007" height="1109" alt="Picture6" src="https://github.com/user-attachments/assets/e35dda58-d986-4eaa-9c98-30f32275cb92" />

<img width="1915" height="1100" alt="Picture7" src="https://github.com/user-attachments/assets/5af9aaad-0bb8-4263-a562-c90417ee83cb" />












