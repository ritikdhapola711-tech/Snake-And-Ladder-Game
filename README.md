# Snake-And-Ladder-Game
It is a command-line console based game implemented in C++ featuring two local multiplayer feature. The game utilizes a 2D array to map the board and random number generation for dice mechanics. It includes automatic logic for detecting snakes and ladders to update player positions instantly.
# Snake and Ladder Game - C++

## 📌 Project Overview
This is a console-based Snake and Ladder game implemented in C++.
The board is dynamically generated using a 10x10 matrix with zig-zag numbering logic.

## 🧠 Game Logic Explanation

1. Board Generation:
   - A 10x10 matrix is used.
   - Numbers are filled in zig-zag pattern.
   - Bottom row starts from 1 to 10.

2. Dice Logic:
   - Implemented using <random> library.
   - Uniform distribution between 1 to 6.

3. Player Movement:
   - Players move according to dice value.
   - If position exceeds 100, move is cancelled.

4. Snakes and Ladders:
   - Arrays store start and end positions.
   - movePlayer() checks and updates player position.

5. Winner Detection:
   - First player to reach exactly 100 wins.

## 🛠 Concepts Used
- 2D Arrays
- References
- Random Number Generation
- Functions
- Game Loop Logic

## 🚀 Future Improvements
- Convert into OOP structure
- Add multiple players
- Add colored output
