📅 Calendar Task Planner in C

A simple console-based Calendar Task Planner written in C that allows users to view calendars, add tasks, view tasks by date, and delete tasks with persistent storage using files.

🚀 Features

📆 Display monthly calendar for any given month and year

➕ Add tasks for specific dates

🔍 View tasks by date

❌ Delete existing tasks

💾 Save and load tasks using file handling (tasks.txt)

🧠 Leap year and correct day calculation

📂 Persistent data storage

🛠️ Technologies Used

Programming Language: C

File Handling: stdio.h

String Handling: string.h

Data Structures: struct

Arrays

📂 File Structure
calendar-task-planner/
│
├── main.c        # Source code
├── tasks.txt     # Auto-created file to store tasks
└── README.md     # Project documentation

▶️ How to Compile and Run
1️⃣ Compile

Using GCC:

gcc main.c -o planner

2️⃣ Run
./planner

📋 Menu Options
===== CALENDAR TASK PLANNER =====
1. Show Calendar
2. Add Task
3. View Tasks by Date
4. Delete Task
5. Exit

🧪 Example Usage

Add tasks like:

25 01 2026
Biology Exam


View tasks by entering a date

Tasks are automatically saved and loaded from tasks.txt

📌 Important Notes

Maximum tasks supported: 100

Maximum task description length: 100 characters

The program automatically creates tasks.txt if it does not exist

Date validation is basic (can be improved)

🔧 Possible Improvements

Input validation for dates

Highlight dates with tasks in calendar

Sorting tasks by date

Support for multiple tasks per day (already partially supported)

Better UI (colors, formatting)

Porting to GUI version in future

👨‍💻 Author

Bhanubhakta Acharya
Tech enthusiast & aspiring researcher
Planning to contribute to Nepal through education and research 🇳🇵

📜 License

This project is open-source and free to use for learning and educational purposes.
