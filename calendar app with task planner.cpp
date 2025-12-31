#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100

typedef struct {
    int day, month, year;
    char task[MAX_LEN];
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

/* ---------- FUNCTION DECLARATIONS ---------- */
int isLeapYear(int year);
int daysInMonth(int month, int year);
int firstDayOfMonth(int month, int year);
void showCalendar(int month, int year);

void addTask();
void viewTasksByDate();
void deleteTask();
void loadTasks();
void saveTasks();
void menu();

/* ---------- MAIN ---------- */
int main() {
    loadTasks();
    menu();
    saveTasks();
    return 0;
}

/* ---------- MENU ---------- */
void menu() {
    int choice, month, year;

    do {
        printf("\n===== CALENDAR TASK PLANNER =====\n");
        printf("1. Show Calendar\n");
        printf("2. Add Task\n");
        printf("3. View Tasks by Date\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter month and year (MM YYYY): ");
                scanf("%d %d", &month, &year);
                showCalendar(month, year);
                break;
            case 2:
                addTask();
                break;
            case 3:
                viewTasksByDate();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
}

/* ---------- CALENDAR LOGIC ---------- */
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    return 31;
}

/* Simple known reference: 01/01/1900 = Monday */
int firstDayOfMonth(int month, int year) {
    int day = 1;
    int totalDays = 0;

    for (int y = 1900; y < year; y++)
        totalDays += isLeapYear(y) ? 366 : 365;

    for (int m = 1; m < month; m++)
        totalDays += daysInMonth(m, year);

    return (totalDays + day) % 7; // 0 = Sunday
}

void showCalendar(int month, int year) {
    int startDay = firstDayOfMonth(month, year);
    int totalDays = daysInMonth(month, year);

    printf("\n\n   Calendar %02d / %d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < startDay; i++)
        printf("    ");

    for (int day = 1; day <= totalDays; day++) {
        printf("%3d ", day);
        if ((day + startDay) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

/* ---------- TASK FUNCTIONS ---------- */
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list full!\n");
        return;
    }

    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d",
          &tasks[taskCount].day,
          &tasks[taskCount].month,
          &tasks[taskCount].year);

    getchar(); // clear newline

    printf("Enter task description: ");
    fgets(tasks[taskCount].task, MAX_LEN, stdin);
    tasks[taskCount].task[strcspn(tasks[taskCount].task, "\n")] = 0;

    taskCount++;
    saveTasks();
    printf("Task added successfully!\n");
}

void viewTasksByDate() {
    int d, m, y, found = 0;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &d, &m, &y);

    printf("\nTasks on %02d-%02d-%04d:\n", d, m, y);
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].day == d &&
            tasks[i].month == m &&
            tasks[i].year == y) {
            printf("- %s\n", tasks[i].task);
            found = 1;
        }
    }

    if (!found)
        printf("No tasks found.\n");
}

void deleteTask() {
    int index;

    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("\nALL TASKS:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %02d-%02d-%04d : %s\n",
               i + 1,
               tasks[i].day,
               tasks[i].month,
               tasks[i].year,
               tasks[i].task);
    }

    printf("Enter task number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = index - 1; i < taskCount - 1; i++)
        tasks[i] = tasks[i + 1];

    taskCount--;
    saveTasks();
    printf("Task deleted successfully!\n");
}

/* ---------- FILE HANDLING ---------- */
void loadTasks() {
    FILE *fp = fopen("tasks.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%d %d %d %[^\n]",
                  &tasks[taskCount].day,
                  &tasks[taskCount].month,
                  &tasks[taskCount].year,
                  tasks[taskCount].task) != EOF) {
        taskCount++;
    }
    fclose(fp);
}

void saveTasks() {
    FILE *fp = fopen("tasks.txt", "w");
    if (fp == NULL) return;

    for (int i = 0; i < taskCount; i++) {
        fprintf(fp, "%d %d %d %s\n",
                tasks[i].day,
                tasks[i].month,
                tasks[i].year,
                tasks[i].task);
    }
    fclose(fp);
}

