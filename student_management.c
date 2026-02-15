#include <stdio.h>
//
#define MAX 50

// Structure
struct students
{
    int roll;
    float marks;
    char name[50];
};

// Gloabal Variables
int count = 0;

// Array
struct students s[MAX];

// Functions
void loadtoFile();
void addStudent();
void viewStudent();
void searchStudents();
void updateStudent();
void deleteStudent();
void savetoFile();

//============== MAIN FUNCTION ================
int main()
{
    printf("Program started\n");

    int choice;
    loadtoFile();

    do
    {
        printf("\n-----------------------------------\n");
        printf("STUDENT MANAGEMENT SYSTEM\n");
        printf("-----------------------------------\n");

        printf("\n1.Add Student:");
        printf("\n2.View All Students:");
        printf("\n3.Seach Student:");
        printf("\n4.Update Student:");
        printf("\n5.Delete Student:");
        printf("\n6.Exit:\n");
        
        printf("\nEnter Your Choice:");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            viewStudent();
            break;

        case 3:
            searchStudents();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            savetoFile();
            printf("Thankyou! Bye...");
            break;

        default:
            printf("Enter valid Choice:");
        }

    } while (choice != 6);
    return 0;
}

//============== LOAD Student Data FUNCTION ================
void loadtoFile()
{
    FILE *fptr;
    fptr = fopen("Record.txt", "r");
    if (fptr == NULL)
    {
        return;
    }

    while (fscanf(fptr, "%d %s %f",
                  &s[count].roll,
                  s[count].name,
                  &s[count].marks) != EOF)
    {
        count++;
    }
    fclose(fptr);
}
//============== SAVE Student Data FUNCTION ================

void savetoFile()
{
    FILE *fptr;
    fptr = fopen("Record.txt", "w");
    if (fptr == NULL)
    {
        printf("Unable to Save Data");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(fptr, "%d %s %f\n",
                s[i].roll,
                s[i].name,
                s[i].marks);
    }
    fclose(fptr);
}

//============== ADD Student DATA FUNCTION ================
void addStudent()
{

    if (count >= MAX)
    {
        printf("Students Lists Is Full\n");
        return;
    }
    printf("Enter Student Roll Number:\n");
    scanf("%d", &s[count].roll);

    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == s[count].roll)

        {
            printf("Roll Number Already Exist!\n");
            printf("Thankyou!\n");
            return;
        }
    }
    printf("Enter Student  Marks:\n");
    scanf("%f", &s[count].marks);

    printf("Enter Student Name:\n");
    scanf(" %[^\n]", s[count].name);
    count++;
    savetoFile();
    printf("Student Added Succesfully!\n");
}
//============== VIEW Student DATA FUNCTION ================
void viewStudent()
{
    if (count == 0)
    {
        printf("No Students Found\n");
        return;
    }
    printf("\nRoll\tName\tMarks\t");
    printf("\n-----------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("\n%d\t %s\t %f\n",
               s[i].roll,
               s[i].name,
               s[i].marks);
    }
    printf("Students Details Print Succesfully!\n");
}
//============== SEARCH Student DATA FUNCTION ================
void searchStudents()
{
    int roll, found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("%d %s %f\n",
                   s[i].roll,
                   s[i].name,
                   s[i].marks);
            found = 1;
            printf("STudent Details Is Above!\n");
        }
    }
    if (!found)
    {
        printf("Student Details Not Avaiable!");
    }
}
//============== UPDATE Student DATA FUNCTION ================
void updateStudent()
{
    int roll, choice, found = 0;
    printf("Enter Roll Number:");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("What You Wants To Update\n");
            printf("1.Roll Number\n2.Student Name\n3.Student Marks\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter New Roll Number:");
                scanf("%d", &s[i].roll);
                found = 1;
                savetoFile();
                printf("Student Details Update Successfully!\n");

                break;

            case 2:
                printf("\nEnter New  Name:");
                scanf(" %[^\n]", s[i].name);
                found = 1;
                savetoFile();

                printf("Student Details Update Successfully!\n");

                break;

            case 3:
                printf("\nEnter New Marks:");
                scanf("%f", &s[i].marks);
                found = 1;
                savetoFile();

                printf("Student Details Update Successfully!\n");

                break;

            default:
                printf("\nEnter Valid Choice!\n");
            }
        }
    }
    if (!found)
    {
        printf("Student Not Found");
    }
}
//============== DELETE Student DATA FUNCTION ================
void deleteStudent()
{
    int roll, found = 0;

    printf("Enter Roll No. For Delete Student:");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found\n");
            for (int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            count--;
            found = 1;
            savetoFile();

            printf("Student Deleted SuccessFully!\n");
        }
    }
    if (!found)
    {
        printf("Student Not Found!\n");
    }
}