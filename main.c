
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 50

void create_file()
{
    char filename[MAX_FILENAME_LEN];
    FILE *fp;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    
    printf("File created successfully.\n");
    fclose(fp);
}

void write_file()
{
    char filename[MAX_FILENAME_LEN];
    FILE *fp;
    char data[1000];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("Enter data to write to file:\n");
    scanf("%s", data);
    
    fprintf(fp, "%s", data);
    printf("Data written to file successfully.\n");
    fclose(fp);
}

void read_file()
{
    char filename[MAX_FILENAME_LEN];
    FILE *fp;
    char ch;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("File content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
}

void delete_file()
{
    char filename[MAX_FILENAME_LEN];
    int status;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    status = remove(filename);
    if (status == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file!\n");
    }
}

void modify_file()
{
    char filename[MAX_FILENAME_LEN];
    FILE *fp;
    char data[1000];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("Enter data to append to file:\n");
    scanf("%s", data);
    
    fprintf(fp, "%s", data);
    printf("Data appended to file successfully.\n");
    fclose(fp);
}

int main()
{
    int choice;
    
    printf("File management system\n");
    printf("=======================\n");
    printf("1. Create file\n");
    printf("2. Write to file\n");
    printf("3. Read file\n");
    printf("4. Delete file\n");
    printf("5. Modify file\n");
    printf("6. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                write_file();
                break;
            case 3:
                read_file();
                break;
            case 4:
                delete_file();
                break;
            case 5:
                modify_file();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}

