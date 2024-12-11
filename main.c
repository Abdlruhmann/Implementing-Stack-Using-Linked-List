#include <stdio.h>
#include <stdlib.h>

struct student {
    int id ;
    char name[30];
    int grade;
};
struct student fill_student() {

    struct student std1 ;
    printf("Enter id of the student: \n");
    scanf("%d", &std1.id);

    printf("Enter name of the student: \n");
    scanf("%s",std1.name);

    printf("Enter the grade of the student: \n");
    scanf("%d",&std1.grade);

    return std1;
}
void print_student(struct student std) {
    printf("Student id : %d\n", std.id);
    printf("Student name : %s\n", std.name);
    printf("Student grade : %d\n",std.grade);
}

struct Node {
    struct student data;
    struct Node * next;
};

struct Node * head;
struct Node * tail;

int push(struct student data) {
    int retval=0;
    struct Node * ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr) {
        ptr->data= data;
        ptr->next= NULL;

        retval=1;
        if(!head) {
            head=tail=ptr;
        }else {
            ptr->next=head;
            head=ptr;
         }
    }
    return retval;
}

struct student pop() {

    struct student std={ .id = -1 };
    struct Node * ptr;
    ptr = head;
    if(head != NULL) {
        if(head->next==NULL) {
            head=tail=NULL;
            std=ptr->data;
            free(ptr);
        } else {
        head=head->next;
        std=ptr->data;
        free(ptr);
        }
    }
    return std;
}
void print_stack() {
    struct Node * curr;
    curr = head;
    while(curr) {
        print_student(curr->data);
        printf("----------------------\n");
        curr = curr->next;
    }
}

void Menu(void) {
printf("\n------ Menu ------\n");
printf("1. Push.\n");
printf("2. Pop.\n");
printf("3. Print\n");
printf("3. Exit.\n");
printf("----------------------\n");
}

int main () {
    int running = 1;
    int choice;

    do {

        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    // PUSH
                    struct student std = fill_student();
                    int psuhed = push(std);
                    if(psuhed) {
                        printf("_____OUTPUT_____\n");
                        printf("Student %s psuhed Successfully into the stack!\n", std.name);
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        printf("Error While Adding new student!\n");
                        printf("________________\n");
                    }
                    break;
                }

            case 2:
                {
                    //POP
                    struct student std ;
                    std = pop();

                    if(std.id != -1) {
                        printf("_____OUTPUT_____\n");
                        printf("Student %s is poped Successfully from the stack!\n", std.name);
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        printf("Error While poping!\n");
                        printf("________________\n");
                    }
                    break;
                }

            case 3: {
                    //PRINT
                    if(!head) {
                        printf("_____OUTPUT_____\n");
                        printf("Stack Is Empty\n");
                        printf("________________\n");
                    }else {
                        printf("_____OUTPUT_____\n");
                        print_stack();
                        printf("________________\n");
                    }
                    break;
            }
            case 4 : {
                printf("Existing the program..");
                running = 0 ;
                break;
            }

            default: {
                printf("Invalid choice!");
                running=0;
            }

        }

    }while(running);
    
    return 0;
}
