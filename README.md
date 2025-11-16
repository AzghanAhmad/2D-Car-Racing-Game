# 2D Car Racing Game 🏎️💨

**An exciting 2D endless racing game** built in C++ using Visual Studio, featuring algorithm implementations like **Binary Search Tree for Leaderboard**, **Queue for Obstacle Management**, and **Graph for Pathfinding/Obstacles**. Includes menu system, sound effects, scoring, and collision detection.

> **Academic Project** — Data Structures & Algorithms Implementation  
> **Institution**: National University of Computer and Emerging Sciences (NUCES), Islamabad  
> **Year**: 2023

---

## 👥 Team Members

| Name             | Roll No.    |
|------------------|-------------|
| **Azghan Ahmad** | 22I-2667    |
| Arslan Shabbir   | 21I-1739    |

---

## 🚀 How to Run

This is a Visual Studio C++ project (likely using DirectX/SFML/OpenGL for graphics).

1. Open `Project_DS.sln` in Visual Studio.
2. Build the solution (Ctrl + Shift + B).
3. Run the executable (F5 or Debug > Start Debugging).

> **Controls** (from report):
> - Arrow Keys: Steer left/right, accelerate/brake
> - Enter: Select menu options
> - ESC: Pause/Exit

Scores are saved in `score.txt`.

---

## 📂 Project Structure
```
2D_Car_Racing_Game/
│
├── .vs/                        # Visual Studio cache
├── x64/                        # 64-bit build outputs
│
├── Project_DS.sln             # Visual Studio Solution file
├── Project_DS.vcxproj         # C++ Project file
├── Project_DS.vcxproj.filters # File filters
├── Project_DS.vcxproj.user    # User settings
├── score.txt                  # Leaderboard scores storage
├── Project Report.pdf         # Detailed 9-page project report
│
├── .gitignore                 # (Recommended)
└── README.md                  # This file
```

---

## 🧠 Core Features & Algorithms

| Feature/Algorithm       | Description |
|-------------------------|-------------|
| **Game Logic**          | Endless racing with collision detection, speed increase over time. |
| **Binary Search Tree (BST)** | Leaderboard: Insert/sort high scores efficiently (O(log n) search/insert). |
| **Queue (FIFO)**        | Obstacle generation: Enqueue obstacles, dequeue as they pass screen. |
| **Graph Implementation**| Obstacle paths or AI navigation (adjacency lists/matrices). |
| **Scoring System**      | Real-time score based on distance/survival time; top scores to BST. |
| **Menu & UI**           | Start, High Scores, Instructions, Exit; keyboard-navigated. |
| **Sound & Music**       | Background music, collision/engine sounds (using Windows API or libs). |
| **Controls**            | Smooth car movement, acceleration, obstacles avoidance. |

- **Gameplay**: Race infinitely, dodge obstacles, beat high scores. Game over on collision → Update leaderboard.

---

## 🎯 Sample Usage

[Menu]

- Start Game
- High Scores (BST sorted)
- Controls/Instructions
- Exit

[In-Game]

- Score: 1250
- Speed: Increasing
- Collision → Game Over → "New High Score!" → Save to score.txt

> Full details & diagrams in `Project Report.pdf` (pages 2-9).

---

## 🛠️ Setup & Requirements

### 1. Clone the Repository
```bash
git clone https://github.com/AzghanAhmad/2d-car-racing-game.git
cd 2d-car-racing-game
```

### 2. Requirements
- Visual Studio (with C++ Desktop Development workload).
- Windows OS (for DirectX/Windows.h audio/graphics).

### 3. Build & Run
- Open Project_DS.sln.
- Build (ensure x64 platform if needed).
- Run – Game launches in windowed/fullscreen mode.

Dependencies: Standard C++ libs (iostream, Windows.h, conio.h?). No external installs needed.

**Report Highlights (From PDF)**
- Introduction: 2D top-down racer with DS implementations.
- Features: Graphics, sound, responsive controls.
- Leaderboard: BST for O(log n) operations.
- Obstacles: Queue-based spawning/removal.
- Conclusion: Efficient DS usage for real-time performance.

**Development Notes**
- Main Logic: Game loop in main.cpp (not shown, but in .vcxproj sources).
- Enhancements: Add multiplayer, levels, power-ups.
- score.txt: Plain text for high scores (parsed into BST).

---

## 🤝 Contributing

- Fork the repository
- Create a feature branch (`git checkout -b feature/power-ups`)
- Commit your changes (`git commit -m 'Add power-ups'`)
- Push to the branch (`git push origin feature/power-ups`)
- Open a Pull Request

---

## ⚖️ License

MIT License – Free to use, modify, and distribute.  
See LICENSE for details.

---

## 👨‍💻 Author

Azghan Ahmad  
GitHub: @AzghanAhmad  
NUCES FAST, Islamabad  
November 17, 2025

Fun academic project demonstrating Data Structures in gaming. Play & contribute!
