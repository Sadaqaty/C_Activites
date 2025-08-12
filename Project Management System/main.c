#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"

int main() {
    Project projects[MAX_PROJECTS];
    int project_count = 0;
    int choice;
    char search_term[MAX_NAME_LENGTH];
    char filename[] = "projects.dat";

    load_projects_from_file(projects, &project_count, filename);

    while (1) {
        printf("\nTask and Project Management Tool\n");
        printf("1. Create a new project\n");
        printf("2. Add a task\n");
        printf("3. Edit a task\n");
        printf("4. Delete a task\n");
        printf("5. Mark task as completed\n");
        printf("6. Generate project report\n");
        printf("7. View all projects\n");
        printf("8. Search tasks by name\n");
        printf("9. Filter tasks by status\n");
        printf("10. Sort tasks by priority\n");
        printf("11. Sort tasks by due date\n");
        printf("12. Undo last action\n");
        printf("13. Redo last action\n");
        printf("14. Save projects to file\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                create_project(projects, &project_count);
                break;
            case 2:
                add_task(projects, project_count);
                break;
            case 3:
                edit_task(projects, project_count);
                break;
            case 4:
                delete_task(projects, project_count);
                break;
            case 5:
                mark_task_completed(projects, project_count);
                break;
            case 6:
                generate_report(projects, project_count);
                break;
            case 7:
                view_projects(projects, project_count);
                break;
            case 8:
                printf("Enter the search term: ");
                fgets(search_term, MAX_NAME_LENGTH, stdin);
                search_term[strcspn(search_term, "\n")] = '\0'; // Remove newline
                search_tasks(projects, project_count, search_term);
                break;
            case 9:
                printf("Filter by status (1: Completed, 0: Pending): ");
                int status;
                scanf("%d", &status);
                getchar(); // Clear newline from buffer
                filter_tasks_by_status(projects, project_count, status);
                break;
            case 10:
                sort_tasks_by_priority(projects, project_count);
                break;
            case 11:
                sort_tasks_by_due_date(projects, project_count);
                break;
            case 12:
                undo_last_action(projects, &project_count);
                break;
            case 13:
                redo_last_action(projects, &project_count);
                break;
            case 14:
                save_projects_to_file(projects, project_count, filename);
                break;
            case 15:
                save_projects_to_file(projects, project_count, filename);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Error: Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
