#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct uniemplo  // Struture Used to create university student employee details //
 {
    int UID; 
    char name[100];
    int hrs; 
    int bonus_pay;
    int grant_pay, gross;
 };
   

void getDetails(struct uniemplo u1)      // Salary details of student employees //
{
printf("Employee's Unique Id is %d\n", u1.UID);
printf("Employee's  Name is %s\n", u1.name);

printf("The total of hours worked per week\n is %d\n",u1.hrs);
printf("The total general_pay pay is %d\n",u1.bonus_pay);
printf("The total grant_pay pay is %d\n",u1.grant_pay);
printf("the total gross pay is %d\n", u1.gross);
printf("\t ##################################\n");
printf("\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}


void display(struct uniemplo u1) 
{       // All student Employees details //

printf("%d \t %s \t %d \t %d \t %d \n", u1.UID, u1.name, u1.hrs, u1.bonus_pay, u1.grant_pay);
return;

}
  
int main(void)
{
    int ch,i, choice,ok,num,hrs,UID;
    char name[100];
    struct uniemplo *u1;
    printf("Enter the number of employees:");
        scanf("%d", &num);
        
        u1 = (struct uniemplo *)malloc(sizeof(struct uniemplo) * num);   // Dynamic memory allocation //
        printf("Enter your input for every employee:\n");
         for (i = 0; i < num; i++) {
                printf("Unique ID is:");
                scanf("%d", &(u1[i].UID));
                printf("Name:");
                scanf("%s", u1[i].name);
                
                printf("Total Number of hrs worked per week:");
                scanf("%d", &(u1[i].hrs));
                printf("Bonus Pay:");
                scanf("%d", &(u1[i].bonus_pay));
                printf("Grant pay:");
                scanf("%d", &(u1[i].grant_pay));
                printf("\n");
        }


while(4)
{
printf("\tBunkod @@@@@@@@@@@@@@@@ Enterprises\n\n");
printf("\n************* Gross Salary Calculator for Student Employees******** \n");
printf("\n\n______________ Choose Your Option___________\n");

 printf("1.Show All Records \n");
 printf("2.Gross Salary Calculation\n");
 printf("3. Add the new Univ Employee Record\n");
 printf("4.Exit\n");
 
printf("Enter Choice: ");
scanf("%d", &ch);
if(ch!=4){
 switch(ch)
 {
     case 1: printf("\n UID   Name \t TotalHours \tBonusPay \tGrantPay\n"); // Display All Record //
      for (i = 0; i <= num; i++){  
          display(u1[i]);
      }
     break;
     
     case 2: for(i=0;i<num;i++) // Gross Salary Calculation
     {
         u1[i].gross = u1[i].grant_pay + u1[i].bonus_pay + (u1[i].hrs*20*15);
     }
     printf("Enter Id to get details regarding gross pay");
     scanf("%d", &UID);
     for(i=0;i<num;i++){
         if(UID = u1[i].UID)
         {
            getDetails(u1[i]); 
         }
     }
     break;
     case 3: num++;   // Add new employee record //
             i = num-1;
             printf("Employee ID:");
            scanf("%d", &(u1[i].UID));
            
            printf("Employee Name:");
            scanf("%s",name);
             printf("Total Number of hrs worked per week:");
            scanf("%d", &(u1[i].hrs));
                printf("Bonus Pay:");
                scanf("%d", &(u1[i].bonus_pay));
                printf("Grant pay:");
                scanf("%d", &(u1[i].grant_pay));
                printf("\n");
        
     break;
     
     case 4: // Exit //
             break;

            default: printf("Invalid Choice");
        }
        printf("\n Do You Want To Continue(1/0):");
                scanf("%d", &choice);

                } else {
                        choice = 0;
                }

                if (!choice) {
                        break;
                }
        }
        return 0;
  }