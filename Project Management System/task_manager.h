#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_TASKS 100
#define MAX_PROJECTS 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char due_date[11];  // Format: YYYY-MM-DD
    int priority;       // 1 = Low, 2 = Medium, 3 = High
    int completed;      // 0 = Incomplete, 1 = Completed
} Task;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Task tasks[MAX_TASKS];
    int task_count;
} Project;

// Function declarations
void create_project(Project *projects, int *project_count);
void add_task(Project *projects, int project_count);
void edit_task(Project *projects, int project_count);
void delete_task(Project *projects, int project_count);
void mark_task_completed(Project *projects, int project_count);
void generate_report(Project *projects, int project_count);
void view_projects(Project *projects, int project_count);

void save_projects_to_file(Project *projects, int project_count, const char *filename);
void load_projects_from_file(Project *projects, int *project_count, const char *filename);

void search_tasks(Project *projects, int project_count, const char *search_term);
void filter_tasks_by_status(Project *projects, int project_count, bool completed);
void sort_tasks_by_priority(Project *projects, int project_count);
void sort_tasks_by_due_date(Project *projects, int project_count);

void undo_last_action(Project *projects, int *project_count);
void redo_last_action(Project *projects, int *project_count);

bool validate_date(const char *date);
bool confirm_action(const char *message);

#endif
