#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int,int);
void mainMenu();
void acer_lab_1();
void acer_lab_2();
void mac_lab();
void reports();
void terminate();

struct info{
    char subject[50];
    char section[50];
    char teacher[50];
    char date[50];
    char time[50];
};
int main()
{

    system("cls");

    int choice, status = 1;
    char buffer;

    gotoxy(40,7);
    printf("---Laboratory Scheduling System---");

    gotoxy(1,18);
    printf("Made by Group 8");
    gotoxy(1,20);
    printf("Team Leader: Ilaida, Romille");
    gotoxy(1,22);
    printf("Members: Torre, John Lloyd");
    gotoxy(10,23);
    printf("Ong, Noriel Edward");
    gotoxy(10,24);
    printf("Lim, Jald");
    gotoxy(10,25);
    printf("Aranas, Jon Mark");
    gotoxy(43,9);
    printf("Press any key to continue...");
    getch();

    gets(buffer);
    mainMenu();
    return 0;
}

void mainMenu(){
    char choice[40];

    system("cls");
        gotoxy(15,5);
        printf("---Main Menu---");
        gotoxy(15,7);
        printf("[A] Acer 1");
        gotoxy(15,8);
        printf("[B] Acer 2");
        gotoxy(15,9);
        printf("[C] Mac Lab");
        gotoxy(15,10);
        printf("[D] Reports");
        gotoxy(15,11);
        printf("[E] Exit");

        gotoxy(15,13);
        printf("Select Laboratory: ");
        scanf("%s", choice);

        if(strcmp(strupr(choice), "A") == 0){
            acer_lab_1();
        }else if(strcmp(strupr(choice), "B") == 0){
            acer_lab_2();
        }else if(strcmp(strupr(choice), "C") == 0){
            mac_lab();
        }else if(strcmp(strupr(choice), "D") == 0){
            reports();
        }else if(strcmp(strupr(choice), "E") == 0){
            terminate();
        }else{
            gotoxy(15,14);
            printf("Invalid Input. Try Again.");
            getch();
            mainMenu();
        }
}
void gotoxy(int x,int y){
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void acer_lab_1(){
    system("cls");


    gotoxy(15,5);
    printf("---Acer Laboratory 1---");

    FILE *fpointer;
    fpointer = fopen("Acer_Lab_1.txt", "a+");
    fclose(fpointer);

    struct info lab1;

    char *days[6] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char *time[4] = {"7:00am-10:00am", "10:20am-12:00pm", "1:30pm-4:30pm", "4:50pm-7:50pm"};
    int numbers[3] = {1,2,3};
    int date, times, status = 1, counter = 1;
    char choice, date_check[50], time_check[50], input_1[20], input_2[20];

    gotoxy(15,7);
    printf("[1] %s", days[0]);
    gotoxy(15,8);
    printf("[2] %s", days[1]);
    gotoxy(15,9);
    printf("[3] %s", days[2]);
    gotoxy(15,10);
    printf("[4] %s", days[3]);
    gotoxy(15,11);
    printf("[5] %s", days[4]);
    gotoxy(15,12);
    printf("[6] %s", days[5]);

    gotoxy(15,14);
    printf("Select day: ");
    scanf("%s", input_1);

    if(strcmp(input_1, "1") != 0 && strcmp(input_1, "2") != 0 && strcmp(input_1, "3") != 0 && strcmp(input_1, "4") != 0 && strcmp(input_1, "5") != 0 && strcmp(input_1, "6") != 0){
        gotoxy(15,16);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_1, "1") == 0){
            date = 1;
        }else if(strcmp(input_1, "2") == 0){
            date = 2;
        }else if(strcmp(input_1, "3") == 0){
            date = 3;
        }else if(strcmp(input_1, "4") == 0){
            date = 4;
        }else if(strcmp(input_1, "5") == 0){
            date = 5;
        }else if(strcmp(input_1, "6") == 0){
            date = 6;
        }

    }

    gotoxy(15,15);
    printf("Day: %s", days[date-1]);

    gotoxy(15,17);
    printf("[1] %s", time[0]);
    gotoxy(15,18);
    printf("[2] %s", time[1]);
    gotoxy(15,19);
    printf("[3] %s", time[2]);
    gotoxy(15,20);
    printf("[4] %s", time[3]);

    gotoxy(15,22);
    printf("Select time: ");
    scanf("%s", input_2);

    if(strcmp(input_2, "1") != 0 && strcmp(input_2, "2") != 0 && strcmp(input_2, "3") != 0 && strcmp(input_2, "4") != 0){
        gotoxy(15,24);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_2, "1") == 0){
            times = 1;
        }else if(strcmp(input_2, "2") == 0){
            times = 2;
        }else if(strcmp(input_2, "3") == 0){
            times = 3;
        }else if(strcmp(input_2, "4") == 0){
            times = 4;
        }
    }

    gotoxy(15,23);
    printf("Time: %s", time[times-1]);

    fpointer = fopen("Acer_Lab_1.txt", "r");

    while(fscanf(fpointer, "%s\t%s", date_check, time_check) != EOF){
        if(strcmp(date_check, days[date-1]) == 0 && strcmp(time_check, time[times-1]) == 0){
            gotoxy(15,25);
            printf("Error! Schedule is already occupied. Please try again.");
            getch();
            mainMenu();
        }
    }

    fclose(fpointer);

    gotoxy(15,25);
    printf("Input Subject: ");
    scanf(" %[^\n]", lab1.subject);
    gotoxy(15,26);
    printf("Input Section: ");
    scanf(" %[^\n]", lab1.section);
    gotoxy(15,27);
    printf("Input Teacher: ");
    scanf(" %[^\n]", lab1.teacher);

    strcpy(lab1.date, days[date-1]);
    strcpy(lab1.time, time[times-1]);

    gotoxy(15,29);
    printf("--------------------------------------------------------------------------------------------------");

    gotoxy(15,31);
    printf("Summary:");
    gotoxy(15,33);
    printf("Acer 1 / %s / %s / %s / %s / %s", lab1.date, lab1.time, lab1.subject, lab1.section, lab1.teacher);

    fpointer = fopen("Acer_Lab_1.txt", "a+");

    if(fpointer == NULL){
        gotoxy(15,35);
        printf("Error! File is missing?!");
    }

    fprintf(fpointer, "%s\t%s\t%s\t%s\t%s\n", lab1.date, lab1.time, lab1.subject, lab1.section, lab1.teacher);
    fclose(fpointer);



    while(status == 1){
        gotoxy(15,35);
        printf("Do you want to input again (Y/N)?: ");
        scanf(" %c", &choice);

        if(toupper(choice) == 'Y'){
            mainMenu();
        }else if(toupper(choice) == 'N'){
            terminate();
            break;
        }else{
            gotoxy(15,37);
            printf("Invalid Response. Try Again.");
            getch();
            system("cls");
            continue;
        }
    }
}

void acer_lab_2(){
    system("cls");


    gotoxy(15,5);
    printf("---Acer Laboratory 2---");

    FILE *fpointer;
    fpointer = fopen("Acer_Lab_2.txt", "a+");
    fclose(fpointer);

    struct info lab2;

    char *days[6] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char *time[4] = {"7:00am-10:00am", "10:20am-12:00pm", "1:30pm-4:30pm", "4:50pm-7:50pm"};
    int date, times, status = 1, counter = 1;
    char choice, date_check[50], time_check[50], input_1[20], input_2[20];

    gotoxy(15,7);
    printf("[1] %s", days[0]);
    gotoxy(15,8);
    printf("[2] %s", days[1]);
    gotoxy(15,9);
    printf("[3] %s", days[2]);
    gotoxy(15,10);
    printf("[4] %s", days[3]);
    gotoxy(15,11);
    printf("[5] %s", days[4]);
    gotoxy(15,12);
    printf("[6] %s", days[5]);

    gotoxy(15,14);
    printf("Select day: ");
    scanf("%s", input_1);

    if(strcmp(input_1, "1") != 0 && strcmp(input_1, "2") != 0 && strcmp(input_1, "3") != 0 && strcmp(input_1, "4") != 0 && strcmp(input_1, "5") != 0 && strcmp(input_1, "6") != 0){
        gotoxy(15,16);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_1, "1") == 0){
            date = 1;
        }else if(strcmp(input_1, "2") == 0){
            date = 2;
        }else if(strcmp(input_1, "3") == 0){
            date = 3;
        }else if(strcmp(input_1, "4") == 0){
            date = 4;
        }else if(strcmp(input_1, "5") == 0){
            date = 5;
        }else if(strcmp(input_1, "6") == 0){
            date = 6;
        }
    }

    gotoxy(15,15);
    printf("Day: %s", days[date-1]);

    gotoxy(15,17);
    printf("[1] %s", time[0]);
    gotoxy(15,18);
    printf("[2] %s", time[1]);
    gotoxy(15,19);
    printf("[3] %s", time[2]);
    gotoxy(15,20);
    printf("[4] %s", time[3]);

    gotoxy(15,22);
    printf("Select time: ");
    scanf("%s", input_2);

    if(strcmp(input_2, "1") != 0 && strcmp(input_2, "2") != 0 && strcmp(input_2, "3") != 0 && strcmp(input_2, "4") != 0){
        gotoxy(15,24);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_2, "1") == 0){
            times = 1;
        }else if(strcmp(input_2, "2") == 0){
            times = 2;
        }else if(strcmp(input_2, "3") == 0){
            times = 3;
        }else if(strcmp(input_2, "4") == 0){
            times = 4;
        }
    }

    gotoxy(15,23);
    printf("Time: %s", time[times-1]);

    fpointer = fopen("Acer_Lab_2.txt", "r");

    while(fscanf(fpointer, "%s\t%s", date_check, time_check) != EOF){
        if(strcmp(date_check, days[date-1]) == 0 && strcmp(time_check, time[times-1]) == 0){
            gotoxy(15,25);
            printf("Error! Schedule is already occupied. Please try again.");
            getch();
            mainMenu();
        }
    }

    fclose(fpointer);

    gotoxy(15,25);
    printf("Input Subject: ");
    scanf(" %[^\n]", lab2.subject);
    gotoxy(15,26);
    printf("Input Section: ");
    scanf(" %[^\n]", lab2.section);
    gotoxy(15,27);
    printf("Input Teacher: ");
    scanf(" %[^\n]", lab2.teacher);

    strcpy(lab2.date, days[date-1]);
    strcpy(lab2.time, time[times-1]);

    gotoxy(15,29);
    printf("--------------------------------------------------------------------------------------------------");

    gotoxy(15,31);
    printf("Summary:");
    gotoxy(15,33);
    printf("Acer 2 / %s / %s / %s / %s / %s", lab2.date, lab2.time, lab2.subject, lab2.section, lab2.teacher);

    fpointer = fopen("Acer_Lab_2.txt", "a+");

    if(fpointer == NULL){
        gotoxy(15,35);
        printf("Error! File is missing?!");
    }

    fprintf(fpointer, "%s\t%s\t%s\t%s\t%s\n", lab2.date, lab2.time, lab2.subject, lab2.section, lab2.teacher);
    fclose(fpointer);



    while(status == 1){
        gotoxy(15,35);
        printf("Do you want to input again (Y/N)?: ");
        scanf(" %c", &choice);

        if(toupper(choice) == 'Y'){
            mainMenu();
        }else if(toupper(choice) == 'N'){
            terminate();
            break;
        }else{
            gotoxy(15,37);
            printf("Invalid Response. Try Again.");
            getch();
            system("cls");
            continue;
        }
    }
}

void mac_lab(){
    system("cls");


    gotoxy(15,5);
    printf("---Mac Laboratory---");

    FILE *fpointer;
    fpointer = fopen("Mac_Lab.txt", "a+");
    fclose(fpointer);

    struct info mac_lab;

    char *days[6] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char *time[4] = {"7:00am-10:00am", "10:20am-12:00pm", "1:30pm-4:30pm", "4:50pm-7:50pm"};
    int date, times, status = 1, counter = 1;
    char choice, date_check[50], time_check[50], input_1[20], input_2[20];

    gotoxy(15,7);
    printf("[1] %s", days[0]);
    gotoxy(15,8);
    printf("[2] %s", days[1]);
    gotoxy(15,9);
    printf("[3] %s", days[2]);
    gotoxy(15,10);
    printf("[4] %s", days[3]);
    gotoxy(15,11);
    printf("[5] %s", days[4]);
    gotoxy(15,12);
    printf("[6] %s", days[5]);

    gotoxy(15,14);
    printf("Select day: ");
    scanf("%s", input_1);

    if(strcmp(input_1, "1") != 0 && strcmp(input_1, "2") != 0 && strcmp(input_1, "3") != 0 && strcmp(input_1, "4") != 0 && strcmp(input_1, "5") != 0 && strcmp(input_1, "6") != 0){
        gotoxy(15,16);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_1, "1") == 0){
            date = 1;
        }else if(strcmp(input_1, "2") == 0){
            date = 2;
        }else if(strcmp(input_1, "3") == 0){
            date = 3;
        }else if(strcmp(input_1, "4") == 0){
            date = 4;
        }else if(strcmp(input_1, "5") == 0){
            date = 5;
        }else if(strcmp(input_1, "6") == 0){
            date = 6;
        }
    }

    gotoxy(15,15);
    printf("Day: %s", days[date-1]);

    gotoxy(15,17);
    printf("[1] %s", time[0]);
    gotoxy(15,18);
    printf("[2] %s", time[1]);
    gotoxy(15,19);
    printf("[3] %s", time[2]);
    gotoxy(15,20);
    printf("[4] %s", time[3]);

    gotoxy(15,22);
    printf("Select time: ");
    scanf("%s", input_2);

    if(strcmp(input_2, "1") != 0 && strcmp(input_2, "2") != 0 && strcmp(input_2, "3") != 0 && strcmp(input_2, "4") != 0){
        gotoxy(15,24);
        printf("Invalid input. Please try again.");
        getch();
        acer_lab_1();
    }else{
        if(strcmp(input_2, "1") == 0){
            times = 1;
        }else if(strcmp(input_2, "2") == 0){
            times = 2;
        }else if(strcmp(input_2, "3") == 0){
            times = 3;
        }else if(strcmp(input_2, "4") == 0){
            times = 4;
        }
    }

    gotoxy(15,23);
    printf("Time: %s", time[times-1]);

    fpointer = fopen("Mac_Lab.txt", "r");

    while(fscanf(fpointer, "%s\t%s", date_check, time_check) != EOF){
        if(strcmp(date_check, days[date-1]) == 0 && strcmp(time_check, time[times-1]) == 0){
            gotoxy(15,25);
            printf("Error! Schedule is already occupied. Please try again.");
            getch();
            mainMenu();
        }
    }

    fclose(fpointer);

    gotoxy(15,25);
    printf("Input Subject: ");
    scanf(" %[^\n]", mac_lab.subject);
    gotoxy(15,26);
    printf("Input Section: ");
    scanf(" %[^\n]", mac_lab.section);
    gotoxy(15,27);
    printf("Input Teacher: ");
    scanf(" %[^\n]", mac_lab.teacher);

    strcpy(mac_lab.date, days[date-1]);
    strcpy(mac_lab.time, time[times-1]);

    gotoxy(15,29);
    printf("--------------------------------------------------------------------------------------------------");

    gotoxy(15,31);
    printf("Summary:");
    gotoxy(15,33);
    printf("Acer 1 / %s / %s / %s / %s / %s", mac_lab.date, mac_lab.time, mac_lab.subject, mac_lab.section, mac_lab.teacher);

    fpointer = fopen("Mac_Lab.txt", "a+");

    if(fpointer == NULL){
        gotoxy(15,35);
        printf("Error! File is missing?!");
    }

    fprintf(fpointer, "%s\t%s\t%s\t%s\t%s\n", mac_lab.date, mac_lab.time, mac_lab.subject, mac_lab.section, mac_lab.teacher);
    fclose(fpointer);



    while(status == 1){
        gotoxy(15,35);
        printf("Do you want to input again (Y/N)?: ");
        scanf(" %c", &choice);

        if(toupper(choice) == 'Y'){
            mainMenu();
        }else if(toupper(choice) == 'N'){
            terminate();
            break;
        }else{
            gotoxy(15,37);
            printf("Invalid Response. Try Again.");
            getch();
            system("cls");
            continue;
        }
    }
}

void reports(){
    system("cls");

    char choice[20], line[500];
    int y = 18, counter = 0, x = 15;

    gotoxy(15,5);
    printf("---Reports---");

    gotoxy(15,7);
    printf("[A] Acer 1");
    gotoxy(15,8);
    printf("[B] Acer 2");
    gotoxy(15,9);
    printf("[C] Mac Lab");

    gotoxy(15,11);
    printf("Select your Lab: ");
    scanf("%s", choice);

    FILE *fpointer;

    if(strcmp(strupr(choice), "A") == 0){
        fpointer = fopen("Acer_Lab_1.txt","r");

        gotoxy(15,13);
        printf("---Acer Lab 1 Schedule---");

        gotoxy(15,15);
        printf("Day");
        gotoxy(35,15);
        printf("Time");
        gotoxy(55,15);
        printf("Subject");
        gotoxy(75,15);
        printf("Section");
        gotoxy(95,15);
        printf("Teacher");
        gotoxy(15,16);
        printf("-----------------------------------------------------------------------------------------------------");
        gotoxy(15,y);
        while(fscanf(fpointer, "%[^\t\n]", line) == 1){
            printf("%-20s", line);
            if(fgetc(fpointer) == '\n'){
                y++;
                gotoxy(15,y);
            }
        }

        gotoxy(15,y+4);
        printf("Press any key to continue...");
        getch();
        mainMenu();
    }else if(strcmp(strupr(choice), "B") == 0){
        fpointer = fopen("Acer_Lab_2.txt","r");

        gotoxy(15,13);
        printf("---Acer Lab 2 Schedule---");

        gotoxy(15,15);
        printf("Day");
        gotoxy(35,15);
        printf("Time");
        gotoxy(55,15);
        printf("Subject");
        gotoxy(75,15);
        printf("Section");
        gotoxy(95,15);
        printf("Teacher");
        gotoxy(15,16);
        printf("-----------------------------------------------------------------------------------------------------");
        gotoxy(15,y);
        while(fscanf(fpointer, "%[^\t\n]", line) == 1){
            printf("%-20s", line);
            if(fgetc(fpointer) == '\n'){
                y++;
                gotoxy(15,y);
            }
        }

        gotoxy(15,y+4);
        printf("Press any key to continue...");
        getch();
        mainMenu();
    }else if(strcmp(strupr(choice), "C") == 0){
        fpointer = fopen("Mac_Lab.txt","r");

        gotoxy(15,13);
        printf("---Mac Lab Schedule---");

        gotoxy(15,15);
        printf("Day");
        gotoxy(35,15);
        printf("Time");
        gotoxy(55,15);
        printf("Subject");
        gotoxy(75,15);
        printf("Section");
        gotoxy(95,15);
        printf("Teacher");
        gotoxy(15,16);
        printf("-----------------------------------------------------------------------------------------------------");
        gotoxy(15,y);
        while(fscanf(fpointer, "%[^\t\n]", line) == 1){
            printf("%-20s", line);
            if(fgetc(fpointer) == '\n'){
                y++;
                gotoxy(15,y);
            }
        }

        gotoxy(15,y+4);
        printf("Press any key to continue...");
        getch();
        mainMenu();
    }else{
        gotoxy(15,13);
        printf("Invalid input. Please try again.");
        getch();
        reports();
    }

}

void terminate(){
    system("cls");

    int choice, status = 1;
    char buffer;

    gotoxy(40,7);
    printf("---Laboratory Scheduling System---");

    gotoxy(1,18);
    printf("Made by Group 8");
    gotoxy(1,20);
    printf("Team Leader: Ilaida, Romille");
    gotoxy(1,22);
    printf("Members: Torre, John Lloyd");
    gotoxy(10,23);
    printf("Ong, Noriel Edward");
    gotoxy(10,24);
    printf("Lim, Jald");
    gotoxy(10,25);
    printf("Aranas, Jon Mark");
    gotoxy(41,9);
    printf("Thank you for using our program!");
    gotoxy(10,26);

    exit(0);
}
