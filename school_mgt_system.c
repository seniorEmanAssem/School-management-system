#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   
#include <string.h>
#include <ctype.h> /*check isalpha()*/

 
 
 typedef struct date{
	 
    int yyyy;
    int mm;
    int dd;
	
}StuDate_of_birth;

typedef struct student{

	char stu_name[20];
	char fath_name[20];
	char address[100];
	int id,phoneNum,year,day,mons;
	float gpa;
	StuDate_of_birth date;
	
	struct student *next;
	
	
}Student_info;

 Student_info *head;

/*prototyping*/
void welcome_screen();
void main_menu();
//void create_new_student(int id,int phoneNum,char stu_name[],char fath_name[],char address[]);
void create_new_student(int id,int phoneNum,float gpa,char* stu_name,char* fath_name,char* address,int day,int year,int mons);
void Delete_student();
void student_list();
int check_name(char name[]);
void edit_student(int id);
void rank();
void student_score();



void main(void){

	welcome_screen();

}


void welcome_screen(){
	
	printf("\n\t\t******************************************************\n");
	printf("\n\t\t======================================================\n");
	printf("\n\t\t--------Welcome to School Management System-----------\n");
	printf("\n\t\t======================================================\n");
	printf("\n\t\t******************************************************\n");
	printf("\n\t\t Enter any key to continue....");
    getch();
    main_menu();
}
void main_menu(){

	head = NULL;
	int choice=0;
    char stu_name[20];
    char fath_name[20];
	char address[100];
    int id,phoneNum,year,day,mons;
	float gpa;
	
    do{
	printf("\n\n\t\t---------------------Main Menu------------------------\n");
	printf("\n\t\t1-Add new student\n");
	printf("\n\t\t2-Rank\n");
	printf("\n\t\t3-Delete an exixting student\n");
	printf("\n\t\t4-Edit particular student \n");
	printf("\n\t\t5-Student list \n");
	printf("\n\t\t6-student score \n");
	printf("\n\t\t7-Exit\n\n");
	printf("\n\t\tEnter your choice please: ");
	scanf("%d",&choice);
	
	switch(choice){

		case 1:
		  
		    printf("\t\t\t\tEnter id: ");
            scanf("%d", &id);
			printf("\t\t\t\tEnter phone number: ");
            scanf("%d",& phoneNum);
			printf("\t\t\t\tEnter gpa: ");
            scanf("%f",& gpa);
			printf("\t\t\t\tEnter student name: ");
            scanf("%s", stu_name);
			printf("\t\t\t\tEnter father name: ");
            scanf("%s", fath_name);
            printf("\t\t\t\tEnter address: ");
            //scanf("%s", address);
            scanf("\n");
			scanf("%[^\n]%*c",address);
			printf("\t\t\t\tEnter the birth-data (day mons year):\n");
            scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&day,&mons,&year);
			
			
		    //create_new_student(id,phoneNum,gpa,stu_name);
		    create_new_student(id,phoneNum,gpa,stu_name,fath_name,address,day,year,mons);
		    break;
			
		case 2:
            rank();	
	    break;
			
		case 3:
		    printf("\t\t\t\tEnter id number to delete: ");
            scanf("%d", &id);
		    Delete_student(id);
		    break;
			
		case 4:
		    printf("\t\t\t\tEnter id: ");
            scanf("%d", &id);
            edit_student(id);
		    break;
			
		case 5:
			student_list();

		    break;
			
		case 6:
           student_score();
		    break;
			
		case 7:
            exit(1);
		    break;
			
		default:	
		    printf("\n\t\t---------------Invalid input!! try again-----------------\n");
	    }
		
		
    }while(choice  != 0);
		
	
}



int check_name(char name[]){
	
	int i,name_len=0;
	int validName=1;
	
	name_len=strlen(name);

	for(i=0;i<name_len;i++){
	     if(!((name[i]>=65 && name[i]<=90 )||(name[i]>=97 && name[i]<=122))&&(name[i] != '\n')&&(name[i] !=32))
		 {
			validName=0;
			break;
			 
		}
	
	}
	
	if(validName==0)
	printf("please enter a valid name\n\n");
	
	return validName;
	
	
	
	
}

void create_new_student(int id,int phoneNum,float gpa,char* stu_name,char* fath_name,char* address,int day,int year,int mons){
	
//void create_new_student(int id,int phoneNum,float gpa,char* stu_name){
	
	Student_info *new_stu=(Student_info *)malloc(sizeof(Student_info));
	new_stu->id=id;
	new_stu->phoneNum=phoneNum;
	new_stu->gpa=gpa;
    new_stu->day=day;
    new_stu->mons=mons;
    new_stu->year=year;
    
    strcpy(new_stu->stu_name,stu_name);
    strcpy(new_stu->fath_name,fath_name);
    strcpy(new_stu->address,address);

	//new_stu->stu_name=stu_name;
	//new_stu->fath_name=fath_name;
	//new_stu->address=address;
	
	new_stu->next=NULL;
	
	
	if(head == NULL){
		head=new_stu;
	}
	else{
		new_stu->next=head;
		new_stu->id=id;
	    new_stu->phoneNum=phoneNum;
		new_stu->gpa=gpa;
		new_stu->day=day;
		new_stu->mons=mons;
		new_stu->year=year;

        strcpy(new_stu->stu_name,stu_name);
        strcpy(new_stu->fath_name,fath_name);
        strcpy(new_stu->address,address);
		
		
		

	    //new_stu->stu_name=stu_name;
	    //new_stu->fath_name=fath_name;
	    //new_stu->address=address;
		head=new_stu;

	}


} 
	

void student_list(){

    Student_info * temp = head;

	printf("\n\n\tID\tNAME\t\t\tGPA\t\tPHONE\t\tBIRTH-DATE\tADDRESS\n");

    while(temp!=NULL){
        
		
		
		//printf("\n\t\t\t\t%d\t\t%s %s\t\t%f\t%d\t\t%d/%d/%d\t\t%s\n",temp->id,temp->stu_name,temp->fath_name,temp->gpa,temp->phoneNum,temp->day,temp->mons,temp->year,temp->address);


        printf("\n\t%d", temp->id);
        printf("\t%s %s", temp->stu_name,temp->fath_name);
        printf("\t\t%f", temp->gpa);
	    printf("\t%d",temp->phoneNum);
	    printf("\t\t%d/%d/%d",temp->day,temp->mons,temp->year);
		printf("\t%s", temp->address);
		
        temp = temp->next;
        
    }
    
}


void Delete_student(int id){
	
    Student_info *temp1 = head;
	Student_info *temp2 = head; 
	
	while(temp1 != NULL){
		
		if(temp1->id==id){
			
			printf("\t\t\t\tRecord with id => %d Founded !!!\n", id);
			
			if(temp1 == temp2){
				
				head = head -> next;
				free(temp1);
			}
			else{
				
				temp2->next = temp1->next;
				free(temp1); 
			}
			
			printf("\t\t\t\tStudent Successfully Deleted !!!\n");
			
			return;
			
		}
		temp2 = temp1;
		temp1 = temp1->next;
		
	}
	printf("\t\t\t\tStudent with id => %d is not found !!!\n", id);
	
}

void edit_student(int id){
	


    int edit_choice=0;
    Student_info *temp = head;
	
    while( temp != NULL){
      
        if(temp->id == id){

			printf("\t\t\tRecord with id => %d Founded !!!\n", id);
			
			
	        printf("\n\n\t\tWhich data you want to change? \n");
	        printf("\n\t\t1-All\n");
	        printf("\n\t\t2-phone\n");
	        printf("\n\t\t3-gpa\n");
	        printf("\n\t\t4-Name\n");
		    printf("\n\t\t5-address\n");
            printf("\n\t\t6-birth_date\n");
	        printf("\n\t\t7-Exit\n\n");
	        printf("\n\t\tEnter your choice please: ");
	        scanf("%d",&edit_choice);
				
	        switch(edit_choice){

		        case 1:
		            
		        	printf("\t\t\tEnter new phone number: ");
                    scanf("%d",&temp->phoneNum);
				    printf("\t\t\t\tEnter new GPA : ");
				    scanf("%f",&temp->gpa);
			        printf("\t\t\t\tEnter new student name: ");
                    scanf("%s",temp->stu_name);
			        printf("\t\t\t\tEnter new father name: ");
                    scanf("%s",temp->fath_name);
                    printf("\t\t\t\tEnter new address: ");
                    scanf("\n");
			        scanf("%[^\n]%*c",temp->address);
			        printf("\t\t\t\tEnter new birth-data (day mons year):\n");
                    scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&temp->day,&temp->mons,&temp->year);
					
			        printf("\t\t\tUpdation Successful!!!\n");
			        student_list();
		            break;
		       	
		        case 2:
		            printf("Enter new phone number: ");
                    scanf("%d",&temp->phoneNum);
		        	printf("Updation Successful!!!\n");
		        	student_list();
		            break;
		        	
		        case 3:
                    printf("Enter new GPA : ");
				    scanf("%F",&temp->gpa);
					printf("\t\t\tUpdation Successful!!!\n");
					student_list();		
		        	
		        case 4:
                    printf("\t\t\t\tEnter new student name: ");
                    scanf("%s",temp->stu_name);
			        printf("\t\t\t\tEnter new father name: ");
                    scanf("%s",temp->fath_name);
                    printf("\t\t\t\tEnter new address: ");
					
                    printf("Updation Successful!!!\n");
		        	student_list();
		            break;
		        	
		        case 5:
                    printf("\t\t\t\tEnter new address: ");
                    scanf("\n");
			        scanf("%[^\n]%*c",temp->address);
					
					printf("Updation Successful!!!\n");
		        	student_list();
					break;
					
			    case 6:
                    printf("\t\t\t\tEnter new birth-data (day mons year):\n");
                    scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&temp->day,&temp->mons,&temp->year);
					
					printf("Updation Successful!!!\n");
		        	student_list();
					break;
					
		        case 7:
                    exit(1);
		            break;	
		        default:	
		            printf("\n\t\t---------------Invalid input!! try again-----------------\n");
			}
		return;
		} 
		
		temp = temp->next;
    }
    printf("\t\t\tStudent with id=> %d is not found !!!\n", id);

}

void rank(){
	
	
	
    Student_info * currnode; 
    Student_info * nextnode;
    int temp_id,temp_phone,temp_year,temp_mons,temp_day;
	float temp_gpa;
	char temp_name[50],temp_fath[50],temp_address[100];
	
    if(head==NULL)
     {
         printf("No data found in the list\n");
     }
     else
     {
         currnode=head;
         while(currnode!=NULL)
         {
             nextnode=currnode->next;
             while(nextnode!=NULL)
             {
                 if(currnode->gpa < nextnode->gpa)
                 {
					 
                    temp_id = currnode->id;
                    currnode->id=nextnode->id;
                    nextnode->id=temp_id;
					
					temp_phone = currnode->phoneNum;
                    currnode->phoneNum=nextnode->phoneNum;
                    nextnode->phoneNum=temp_phone;
					
					temp_gpa = currnode->gpa;	
                    currnode->gpa=nextnode->gpa;
                    nextnode->gpa=temp_gpa;
					
					temp_day = currnode->day;	
                    currnode->day=nextnode->day;
                    nextnode->day=temp_day;
					
					temp_year = currnode->year;	
                    currnode->year=nextnode->year;
                    nextnode->year=temp_year;
					
					
					temp_mons = currnode->mons;	
                    currnode->mons=nextnode->mons;
                    nextnode->mons=temp_mons;
					
	                strcpy(temp_name,currnode->stu_name);
					strcpy(currnode->stu_name,nextnode->stu_name);
					strcpy(nextnode->stu_name,temp_name);
					 
					 
					 strcpy(temp_fath,currnode->fath_name);
					strcpy(currnode->fath_name,nextnode->fath_name);
					strcpy(nextnode->fath_name,temp_fath);
					
					strcpy(temp_address,currnode->address);
					strcpy(currnode->address,nextnode->address);
					strcpy(nextnode->address,temp_address);
					 
                 }
                 nextnode=nextnode->next;

             } 
             currnode=currnode->next;
			 
         }
		 	 student_list();

     }
	 

}

void student_score(){

	Student_info *temp = head;
	
   for(int i=0; temp != NULL ;i++){
		
		printf("\t\t\tid=>%d\n",temp->id);
		printf("\t\t\t\tEnter new GPA : ");
	    scanf("%f",&temp->gpa);
		temp = temp->next;
		}
		
}
	
	

