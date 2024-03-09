#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for storing user data
struct User {
    char username[50];
    char password[50];
    char privileges; // 0 for user, 1 for admin, 2 for patient
};
struct Room {
    int room_number;
    int is_empty;
    char patient_id;
};

struct Patient {
    int patient_id;
    char name[100];
    char status;//1 for good-state , 0 for bad-state
};

// Array of users
struct User users[10] = {
    {"ahmed", "pass1", 2},
    {"sarah", "pass2", 0},
    {"maria", "pass3", 1}
};

struct Room rooms[10] = {
        {1, 0, 1},
        {2, 1, 1},
        {3, 1, 3},
        {4, 0, 4},
        {5, 1, 5},
        {6, 0, 6},
        {7, 1, 7},
        {8, 0, 8},
        {9, 1, 9},
        {10, 0, 10}
    };

struct Patient patients[5] = {
        {1, "bassem", 1},
        {2, "Ali", 0},
        {3, "jana", 1},
        {4, "mariam", 0},
        {5, "Cherif", 1}

    };

void check_empty_rooms();
void remove_current_reservation(char patient_id);
void update_patient_data(int patient_id);
void create_new_patient();

void create_new_patient(char *name,char *status,char *patient_id){
printf("Please enter patient's name:");
scanf("%s",&name);
printf("Please enter patient's status:\n 0 for bad-state \n 1 for good-state\n");
scanf("%d",&status);
if(status == 0 || status == 1)
            {

            }
                else{printf("invalid input for patient's statues.\n");
                return;}
printf("Please enter patient's id:");
scanf("%d",&patient_id);
printf("New Patient is created successfully\n");
}

void check_empty_rooms(){
int empty_rooms = 0;
    for (int i = 0; i < 10; i++) {
        if (rooms[i].is_empty) {
            printf("Room %d is empty.\n", rooms[i].room_number);
            empty_rooms++;
        }
    }
    if (empty_rooms == 0) {
        printf("No empty rooms available.\n");
    }
}
void check_current_reservations()
{
    int reserved_rooms = 0;
    for (int i = 0; i < 10; i++) {
        if (rooms[i].is_empty==0) {
            printf("Room %d is reserved.\n", rooms[i].room_number);
            reserved_rooms++;
        }
    }
    if (reserved_rooms == 0) {
        printf("No reserved rooms available.\n");
    }
}
void remove_current_reservation(char patient_id)
{ printf("Checking all the current reserved rooms:\n");
    check_current_reservations();
    printf("Enter the patient id to remove his reserved room: ");
   if(scanf("%d", &patient_id)!=1){
        printf("invalid input for patients id, it needs to be a number");
        exit(0);
    }
else{
 for (int i = 0; i < 10; i++) {
        if (patients[i].patient_id == patient_id ) {
        if (rooms[i].is_empty == 0 ) {
            rooms[i].is_empty = 1;
            rooms[i].patient_id = 0;
            printf("Reservation removed successfully.\n");
            printf("Room %d is now empty.\n\n\n", rooms[i].room_number);
            return;
        }

    }

        printf("either patient or reservation not found.\n");
                exit(0);

    }
}

}
void update_patient_data(int patient_id)
{ char input;
char name;
char status;

    printf("Enter the patient id to update the data: ");
    if(scanf("%d", &patient_id)!=1){
        printf("invalid input for patients id, it needs to be a number");
        exit(0);
    }
    else{
    for (int i = 0; i < 5; i++) {
        if (patients[i].patient_id == patient_id) {
            printf("Updating patient %d data...\n", patient_id);
            printf("Enter the new name: ");
            scanf("%s", patients[i].name);
            printf("Enter the new status:\n 0 for bad-state \n 1 for good-state\n");
           if (scanf("%d", &patients[i].status) != 1) {
                printf("Invalid input for patient status, it needs to be a number.\n");
                exit(0);
            }

           else if (patients[i].status == 0 || patients[i].status == 1) {
                printf("Data is updated successfully. \n");
                return;
            }
            else{printf("invalid input");
            exit(0);
            }


            }
        }
    }

    printf("Patient is not found.\n To create a new patient: Insert 0\n To Exit: Insert 1.\n");
    scanf("%d",&input);
    if(input == 0 )
    {
        create_new_patient(name,status,patient_id);
    }
    else if(input == 1){
        printf("EXITING..");
        exit(0);
    }
    else{
        printf("invalid input");

    }
    }
}

int login(char *username, char *password) {
   int patient_id;
   int privilege;
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < 10; i++){
    if (strcmp(users[i].username, username) == 0) {
        if (strcmp(users[i].password, password) == 0) {
                privilege=users[i].privileges;
            printf("Login successful! Welcome, %s.\n", username);




            // Perform operations based on user privileges
            if (users[i].privileges == 1) {
                printf("-ADMIN'S operations.-\n");
                // Call the functions for an admin
                    char choice;
                    while (1) {
                       printf("1. Update Patient Data\n");
                       printf("2. Remove Current Reservation\n");
                       printf("3. Check Empty Rooms\n");
                       printf("4. Logout\n");
                       printf("5. Exit\n");
                       printf("Enter your choice: ");
                        scanf("%d", &choice);
                        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5){
                        switch (choice) {
                case 1:
                    update_patient_data( patient_id);
                    break;
                case 2:
                    remove_current_reservation( patient_id);
                    break;
                case 3:
                    check_empty_rooms();
                    break;
                case 4:
                    return;
                case 5:
                    exit(0);


            }}
                  else{
                       printf("choice not available. \n");
                       exit(0);
                      }
            }
            }

//for regular's user operations
            else  if (users[i].privileges == 0){
                printf("-REGULAR USER'S operation.-\n");
                 int choice;
        while (1) {

            printf("1. Check Empty Rooms\n");
            printf("2. Logout\n");
             printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
           if(choice == 1 || choice == 2 || choice == 3 ){
            switch (choice) {

                case 1:
                check_empty_rooms();
                break;
                case 2:
                return;
                case 3:
                exit(0);


            }
        }
        else{
              printf("choice not available");
                        exit(0);
            }
        }
            }

//for patients operation
            else  if (users[i].privileges == 2){
                printf("-PATIENT'S operation.-\n");
                int choice;
        while (1) {
            printf("1. Update Patient Data\n");
            printf("2. Remove Current Reservation\n");
            printf("3. Check Empty Rooms\n");
            printf("4. Logout\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5){
            switch (choice) {
                case 1:
                    update_patient_data( patient_id);
                    break;
                case 2:
                    remove_current_reservation( patient_id);
                    break;
                case 3:
                    check_empty_rooms();
                    break;
                case 4:
                    return;
                case 5:
                    exit(0);

         }   }
          else{
              printf("choice not available");
                        exit(0);
        }
        }
    }
        }
    }
    }

    printf("Invalid username or password.\n");
    login(username,password);

}
int main() {
    char username[50];
    char password[50];
    int privileges;
    char patient_id[50];
 int login_index = login(username,password);
    while(login_index != -1){
login(username,password);

}
}


