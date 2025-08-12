#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task_manager.h"

// Utility functions for string trimming
void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Date validation
bool validate_date(const char *date) {
    if (strlen(date) != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    return true;
}

// Confirmation prompt
bool confirm_action(const char *message) {
    char response[3];
    printf("%s (y/n): ", message);
    fgets(response, 3, stdin);
    trim_newline(response);
    return strcmp(response, "y") == 0;
}

// Create a new project
void create_project(Project *projects, int *project_count) {
    if (*project_count >= MAX_PROJECTS) {
        printf("Error: Project limit reached.\n");
        return;
    }

    printf("Enter the project name: ");
    fgets(projects[*project_count].name, MAX_NAME_LENGTH, stdin);
    trim_newline(projects[*project_count].name);
    projects[*project_count].task_count = 0;
    (*project_count)++;
    printf("Project '%s' created successfully!\n", projects[*project_count - 1].name);
}

// Add a task to a project
void add_task(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available. Please create a project first.\n");
        return;
    }

    int project_index;
    printf("Select a project by number:\n");
    for (int i = 0; i < project_count; i++) {
        printf("%d. %s\n", i + 1, projects[i].name);
    }
    scanf("%d", &project_index);
    getchar(); // Clear newline from buffer
    project_index--;

    if (project_index >= 0 && project_index < project_count) {
        if (projects[project_index].task_count < MAX_TASKS) {
            Task *task = &projects[project_index].tasks[projects[project_index].task_count];
            printf("Enter task name: ");
            fgets(task->name, MAX_NAME_LENGTH, stdin);
            trim_newline(task->name);

            do {
                printf("Enter due date (YYYY-MM-DD): ");
                fgets(task->due_date, 11, stdin);
                trim_newline(task->due_date);
            } while (!validate_date(task->due_date));

            printf("Enter priority (1 = Low, 2 = Medium, 3 = High): ");
            scanf("%d", &task->priority);
            getchar(); // Clear newline from buffer
            task->completed = 0;
            projects[project_index].task_count++;
            printf("Task added successfully!\n");
        } else {
            printf("Error: Task limit reached for this project.\n");
        }
    } else {
        printf("Error: Invalid project selection.\n");
    }
}

// Edit a task in a project
void edit_task(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available. Please create a project first.\n");
        return;
    }

    int project_index;
    printf("Select a project by number:\n");
    for (int i = 0; i < project_count; i++) {
        printf("%d. %s\n", i + 1, projects[i].name);
    }
    scanf("%d", &project_index);
    getchar(); // Clear newline from buffer
    project_index--;

    if (project_index >= 0 && project_index < project_count) {
        if (projects[project_index].task_count > 0) {
            printf("Select a task to edit by number:\n");
            for (int i = 0; i < projects[project_index].task_count; i++) {
                printf("%d. %s (Due: %s, Priority: %d)\n", i + 1, projects[project_index].tasks[i].name, projects[project_index].tasks[i].due_date, projects[project_index].tasks[i].priority);
            }
            int task_index;
            scanf("%d", &task_index);
            getchar(); // Clear newline from buffer
            task_index--;

            if (task_index >= 0 && task_index < projects[project_index].task_count) {
                Task *task = &projects[project_index].tasks[task_index];
                printf("Editing task: %s\n", task->name);
                printf("Enter new task name: ");
                fgets(task->name, MAX_NAME_LENGTH, stdin);
                trim_newline(task->name);

                do {
                    printf("Enter new due date (YYYY-MM-DD): ");
                    fgets(task->due_date, 11, stdin);
                    trim_newline(task->due_date);
                } while (!validate_date(task->due_date));

                printf("Enter new priority (1 = Low, 2 = Medium, 3 = High): ");
                scanf("%d", &task->priority);
                getchar(); // Clear newline from buffer
                printf("Task edited successfully!\n");
            } else {
                printf("Error: Invalid task selection.\n");
            }
        } else {
            printf("Error: No tasks available to edit in this project.\n");
        }
    } else {
        printf("Error: Invalid project selection.\n");
    }
}

// Delete a task from a project
void delete_task(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available. Please create a project first.\n");
        return;
    }

    int project_index;
    printf("Select a project by number:\n");
    for (int i = 0; i < project_count; i++) {
        printf("%d. %s\n", i + 1, projects[i].name);
    }
    scanf("%d", &project_index);
    getchar(); // Clear newline from buffer
    project_index--;

    if (project_index >= 0 && project_index < project_count) {
        if (projects[project_index].task_count > 0) {
            printf("Select a task to delete by number:\n");
            for (int i = 0; i < projects[project_index].task_count; i++) {
                printf("%d. %s (Due: %s, Priority: %d)\n", i + 1, projects[project_index].tasks[i].name, projects[project_index].tasks[i].due_date, projects[project_index].tasks[i].priority);
            }
            int task_index;
            scanf("%d", &task_index);
            getchar(); // Clear newline from buffer
            task_index--;

            if (task_index >= 0 && task_index < projects[project_index].task_count) {
                if (confirm_action("Are you sure you want to delete this task?")) {
                    for (int i = task_index; i < projects[project_index].task_count - 1; i++) {
                        projects[project_index].tasks[i] = projects[project_index].tasks[i + 1];
                    }
                    projects[project_index].task_count--;
                    printf("Task deleted successfully!\n");
                } else {
                    printf("Task deletion canceled.\n");
                }
            } else {
                printf("Error: Invalid task selection.\n");
            }
        } else {
            printf("Error: No tasks available to delete in this project.\n");
        }
    } else {
        printf("Error: Invalid project selection.\n");
    }
}

// Mark a task as completed
void mark_task_completed(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available. Please create a project first.\n");
        return;
    }

    int project_index;
    printf("Select a project by number:\n");
    for (int i = 0; i < project_count; i++) {
        printf("%d. %s\n", i + 1, projects[i].name);
    }
    scanf("%d", &project_index);
    getchar(); // Clear newline from buffer
    project_index--;

    if (project_index >= 0 && project_index < project_count) {
        if (projects[project_index].task_count > 0) {
            printf("Select a task to mark as completed by number:\n");
            for (int i = 0; i < projects[project_index].task_count; i++) {
                printf("%d. %s (Due: %s, Priority: %d)\n", i + 1, projects[project_index].tasks[i].name, projects[project_index].tasks[i].due_date, projects[project_index].tasks[i].priority);
            }
            int task_index;
            scanf("%d", &task_index);
            getchar(); // Clear newline from buffer
            task_index--;

            if (task_index >= 0 && task_index < projects[project_index].task_count) {
                Task *task = &projects[project_index].tasks[task_index];
                task->completed = 1;
                printf("Task '%s' marked as completed!\n", task->name);
            } else {
                printf("Error: Invalid task selection.\n");
            }
        } else {
            printf("Error: No tasks available to mark as completed in this project.\n");
        }
    } else {
        printf("Error: Invalid project selection.\n");
    }
}

// Generate a project report
void generate_report(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available.\n");
        return;
    }

    for (int i = 0; i < project_count; i++) {
        printf("\nProject: %s\n", projects[i].name);
        printf("Total tasks: %d\n", projects[i].task_count);
        int completed_tasks = 0;
        for (int j = 0; j < projects[i].task_count; j++) {
            if (projects[i].tasks[j].completed) {
                completed_tasks++;
            }
        }
        printf("Completed tasks: %d\n", completed_tasks);
        printf("Pending tasks: %d\n", projects[i].task_count - completed_tasks);
    }
}

// View all projects and tasks
void view_projects(Project *projects, int project_count) {
    if (project_count == 0) {
        printf("Error: No projects available.\n");
        return;
    }

    for (int i = 0; i < project_count; i++) {
        printf("\nProject: %s\n", projects[i].name);
        for (int j = 0; j < projects[i].task_count; j++) {
            printf("Task: %s (Due: %s, Priority: %d, Completed: %s)\n", projects[i].tasks[j].name, projects[i].tasks[j].due_date, projects[i].tasks[j].priority, projects[i].tasks[j].completed ? "Yes" : "No");
        }
    }
}

// Save projects to a file
void save_projects_to_file(Project *projects, int project_count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fwrite(&project_count, sizeof(int), 1, file);
    fwrite(projects, sizeof(Project), project_count, file);
    fclose(file);
    printf("Projects saved to file successfully!\n");
}

// Load projects from a file
void load_projects_from_file(Project *projects, int *project_count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    fread(project_count, sizeof(int), 1, file);
    fread(projects, sizeof(Project), *project_count, file);
    fclose(file);
    printf("Projects loaded from file successfully!\n");
}

// Search tasks by name
void search_tasks(Project *projects, int project_count, const char *search_term) {
    printf("Search results for '%s':\n", search_term);
    for (int i = 0; i < project_count; i++) {
        for (int j = 0; j < projects[i].task_count; j++) {
            if (strstr(projects[i].tasks[j].name, search_term)) {
                printf("Project: %s, Task: %s (Due: %s, Priority: %d)\n", projects[i].name, projects[i].tasks[j].name, projects[i].tasks[j].due_date, projects[i].tasks[j].priority);
            }
        }
    }
}

// Filter tasks by status
void filter_tasks_by_status(Project *projects, int project_count, bool completed) {
    printf("%s tasks:\n", completed ? "Completed" : "Pending");
    for (int i = 0; i < project_count; i++) {
        for (int j = 0; j < projects[i].task_count; j++) {
            if (projects[i].tasks[j].completed == completed) {
                printf("Project: %s, Task: %s (Due: %s, Priority: %d)\n", projects[i].name, projects[i].tasks[j].name, projects[i].tasks[j].due_date, projects[i].tasks[j].priority);
            }
        }
    }
}

// Sort tasks by priority
void sort_tasks_by_priority(Project *projects, int project_count) {
    for (int i = 0; i < project_count; i++) {
        for (int j = 0; j < projects[i].task_count - 1; j++) {
            for (int k = 0; k < projects[i].task_count - j - 1; k++) {
                if (projects[i].tasks[k].priority < projects[i].tasks[k + 1].priority) {
                    Task temp = projects[i].tasks[k];
                    projects[i].tasks[k] = projects[i].tasks[k + 1];
                    projects[i].tasks[k + 1] = temp;
                }
            }
        }
    }
    printf("Tasks sorted by priority!\n");
}

// Sort tasks by due date
void sort_tasks_by_due_date(Project *projects, int project_count) {
    for (int i = 0; i < project_count; i++) {
        for (int j = 0; j < projects[i].task_count - 1; j++) {
            for (int k = 0; k < projects[i].task_count - j - 1; k++) {
                if (strcmp(projects[i].tasks[k].due_date, projects[i].tasks[k + 1].due_date) > 0) {
                    Task temp = projects[i].tasks[k];
                    projects[i].tasks[k] = projects[i].tasks[k + 1];
                    projects[i].tasks[k + 1] = temp;
                }
            }
        }
    }
    printf("Tasks sorted by due date!\n");
}

// Undo last action (Simplified example, implement according to your undo/redo strategy)
void undo_last_action(Project *projects, int *project_count) {
    printf("Undo feature is not yet implemented.\n");
}

// Redo last action (Simplified example, implement according to your undo/redo strategy)
void redo_last_action(Project *projects, int *project_count) {
    printf("Redo feature is not yet implemented.\n");
}
