# Project2 - Math Quiz App

This is a CLI-based math quiz app that tests your arithmetic skills.

## Requirements
- Ask the user for the number of questions (1 to 20).
- Let the user choose the difficulty level:
  - Easy: Numbers between 1 and 9.
  - Medium: Numbers between 10 and 99.
  - Hard: Numbers between 100 and 999.
  - Mix: Random difficulty.
- Let the user choose the operation type:
  - Addition, Subtraction, Multiplication, Division, or Mix.
- Generate random questions based on the selected difficulty and operation type.
- Show the user's answer result after each question:
  - If correct, turn the screen green.
  - If incorrect, turn the screen red and show the correct answer.
- At the end of the quiz, show the final results:
  - Total number of questions.
  - Number of correct answers.
  - Number of wrong answers.
  - Whether the user passed or failed.
- Ask the user if they want to play again (Y/N).

## Project Structure
```bash
/2_MathQuizApp
│── Config.cpp      # Handles quiz settings (difficulty, operations, question count)
│── helpers.cpp     # Utility functions (random number generation, screen clearing)
│── main.cpp        # Entry point of the application
│── questions.cpp   # Logic for creating and validating questions
│── quiz.cpp        # Controls quiz flow and displays results
│── Quiz.h          # Shared structures and function declarations
│── README.md       # Project documentation
```

---

## How to Run
1. Compile the program:
   ```bash
   g++ main.cpp Config.cpp helpers.cpp questions.cpp quiz.cpp -o quiz
   ```
2. Run the compiled executable:
  ```bash
  ./quiz
  ```
