#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


     
      //VARIABLES
      struct person 
      {
        char name[100];
        char addr[100];
        char ID[100];
        long ph_no;
        long lan_no;
      } p[50];
      

  
      //FUNCTIONS (declaration)
      
      void Initialize(); //Function to initialize data
      void Input(); //Function to read the data input by the user
      int Search(); //Function to search if the entered contact exists
      void Display(); //Function to display details of entered contact 
      void DisplayAll(); //Function to display all contacts in the directory
      void Modify();   //Function to modify details of entered contact



//INITIALIZING 'i' to 0
int i=0;
//MAIN FUNCTION

void main()
{
     Initialize();

     int choice, ch;
  
    do
    {system("clear"); 
     
     printf("\n\t\t\tTELEPHONE DIRECTORY");
     
     printf("\n\nChoose from the following options: ");
     printf("\n1. New entry.");
     printf("\n2. Display contact details. ");
     printf("\n3. Display all contacts. ");
     printf("\n4. Modify contact. ");
     printf("\n5. Close directory.");
     printf("\n\nEnter your choice: ");
       scanf("%d",&choice);
     switch(choice)
    {
	case 1: Input();
		break;
	case 2: Display();
		break;
	case 3: DisplayAll();
		break;
	case 4: Modify();
                break;	
        case 5: exit(0);
		
	default: printf("\nSorry! This option is unavailable!");
		break;
     }

     choice:                                        //LABEL FOR GOTO STATEMENT
     printf("\n\n\nPress 1 to return to main directory.");
     printf("\nPress 2 to close directory.");
       scanf("%d",&ch);

     if (ch==2)
	  exit(0);
     else if(ch!=1)
         {
          printf("\nInvalid choice! Enter again.");
          goto choice;                            //GOTO STATEMENT
	      }
    
    }
    while(ch==1);
	  //END OF DO-WHILE LOOP
    
  }	
   
 //END OF MAIN   

//////////////////////////////////////////////////////////////////////////////
//                 FUNCTION TO INITIALIZE ALL DATA ITEMS                    //
//////////////////////////////////////////////////////////////////////////////

void Initialize()
{
  
   int j;
  for (j=0;j<50;++j)
  { 
      p[j].ph_no=0;
      p[j].lan_no=0;
      strcpy(p[j].ID,"NULL");
      strcpy(p[j].name,"NULL");
      strcpy(p[j].addr,"NULL");
   }
}

/////////////////////////////////////////////////////////////////////////////
//		    FUNCTION TO INPUT CONTACT AND DETAILS                  //
/////////////////////////////////////////////////////////////////////////////

    void  Input()
    {
        
       int ch,choice,count;
       long int num;

       do
       {	 
         system("clear");
	 printf("\n\nEnter the contact details: ");
	   printf("\n\nName:");
	     scanf("%s",p[i].name);
           pnum:                            //LABEL 
	   printf("\nPhone number: ");
	     scanf("%ld",&p[i].ph_no);

	   //TO CHECK IF PHONE NUMBER IS VALID(10 DIGITS LONG)
           num=p[i].ph_no;
           count=0;
           while(num!=0)
           {
             num/=10;
             ++count;
           }
           
           if(count!=10)
           {
             printf("\nINVALID NUMBER.\nEnter again.");
             goto pnum;
           }
           
          
           opt:
	   printf("\nDo you wish to enter more details?\nPress 1 for Yes\nPress 2 for No\n");
	     scanf("%d",&ch);
	 
              if(ch==1)
	      {
		printf("\nChoose from the following: ");
		printf("\n1. Landline. ");
		printf("\n2. Address. ");
		printf("\n3. Email id. ");
	        printf("\n4. Go back.");
		printf("\n\nEnter your choice: ");
		  scanf("%d",&choice);
		switch(choice)
		{
		  case 1: printf("Landline: ");
			    scanf("%ld",&p[i].lan_no);
			
			  break;
		  case 2: printf("Address: ");
			    scanf("%s",p[i].addr);
			
			  break;
		  case 3: printf("Email Id: ");
			    scanf("%s",p[i].ID);
				
			  break;
			
		  case 4:  goto opt1;
			   break;

		  default: printf("\nInvalid choice! ");
			   break;
		}
		 //END OF SWITCH
                 goto opt;                       //GOTO STATEMENT, CONTROL IS PASSED TO opt
		
	       }
		//END OF IF STATEMENT
          
         opt1:                              
	printf("\nDo you want to enter more contacts?\nPress 1 for Yes\nPress 2 for No\n");
	  scanf("%d",&ch);
        
	++i;
      }
	 while(ch==1);
	 
		//END OF OUTER DO WHILE LOOP
	
	return ;
    }
     //END OF FUNCTION

///////////////////////////////////////////////////////////////////////////////////
//		     FUNCTION TO SEARCH FOR ENTERED CONTACT			 //
///////////////////////////////////////////////////////////////////////////////////

int Search()
{
       char cont_name[50]; //Name to be searched
       int flag,j;
           
	

          printf("\n\nEnter the contact name:");
	   scanf("%s",cont_name);
          
	 for (j=0; j<i;++j)
	 {
	     flag=strcmp(p[j].name,cont_name);
	     if(flag==0)
	      return j;   //RETURN j IF NAME IS FOUND IN DIRECTORY
	 }
	
        return -1;        //RETURN -1 IF NAME IS NOT FOUND
}
   //END OF FUNCTION

///////////////////////////////////////////////////////////////////////////////////
//		     FUNCTION TO DISPLAY DETAILS OF CONTACT			 //
///////////////////////////////////////////////////////////////////////////////////
    void Display()
    {
       
       int k,a,ch;

       srch:                     //LABEL FOR GOTO FUNCTION 
       system("clear");
       k=Search();               //CALLING SEARCH() TO CHECK IF NAME EXISTS IN DIRECTORY
       
       if(k==-1)
	{
          printf("\nContact not found.");
          goto srch_cont;	//GOTO STATEMENT FOR SEARCHING AGAIN, CONTROL IS PASSED TO srch_cont
        }
       
       else
       {
          printf("\nThe contact details are: ");
          printf("\nNAME: %s",p[k].name);
          printf("\nNUMBER: %ld",p[k].ph_no);
       
          if (p[k].lan_no)
	    printf("\nLANDLINE: %ld",p[k].lan_no);
      
           a=strcmp(p[k].addr,"NULL");
	   if(a!=0)
	     printf("\nADDRESS: %s",p[k].addr);
	   
         
           a=strcmp(p[k].ID,"NULL");
          if(a!=0)
            printf("\nEMAIL ID: %s",p[k].ID);


      
       }

       srch_cont:					//LABEL FOR CONTINUING SEARCH
       printf("\nDo you want to search for more contacts?\nPress 1 for Yes\nPress 2 for No\n");
          scanf("%d",&ch);
       if(ch==1)
          goto srch;					//GOTO STATEMENT, CONTROL IS PASSED TO srch
       else 
          return ;
}
   //END OF FUNCTION

///////////////////////////////////////////////////////////////////////////////////
//		           FUNCTION TO DISPLAY ALL CONTACTS			 //
///////////////////////////////////////////////////////////////////////////////////

void DisplayAll()
{
  
	
	int j,k,a;
	char temp[50], str[50][50];         
	for (j=0;j<i;++j)
	    strcpy(str[j],p[j].name);
		       //Copying Names to string "str"
	
        //Loop to arrange Names in alphabetical order
	for(j=1; j<i; j++)
	{
	   for(k=1; k<i; k++)
	   {
	     a=strcmp(str[k-1], str[k]);
	     if (a>0)
	     {
		strcpy(temp, str[k-1]);
		strcpy(str[k-1], str[k]);
		strcpy(str[k],temp);
	      }
	    }
	 }
	  //END OF LOOP
	

       //LOOP TO DISPLAY ALL CONTACTS
       system("clear");
       for(j=0;j<i;++j)
       {
       for(k=0; k<i; k++)
       {
       a=strcmp(str[j],p[k].name);
       if(a==0)  
       {
          printf("\nNAME: %s",p[k].name);
          printf("\nNUMBER: %ld",p[k].ph_no);
       
          if (p[k].lan_no)
	    printf("\nLANDLINE: %ld",p[k].lan_no);
      
           a=strcmp(p[k].addr,"NULL");
           if(a!=0)
              printf("\nADDRESS: %s",p[k].addr);
 	           
         a=strcmp(p[k].ID,"NULL");
          if(a!=0)
           printf("\nEMAIL ID: %s",p[k].ID);
	   
          printf("\n\n");
        }
           //END OF IF STATEMENT
        }
          // END OF INNER FOR LOOP
 
      }
       //END OF OUTER FOR LOOP

}
    //END OF FUNCTION

////////////////////////////////////////////////////////////////////////////////////
//		            FUNCTION TO MODIFY CONTACTS				  //
////////////////////////////////////////////////////////////////////////////////////

 void Modify()
 {
    
      int k,a,choice, ch;

      srch:                     //LABEL FOR GOTO FUNCTION 
      system("clear");
      k=Search();               //CALLING SEARCH() TO CHECK IF NAME EXISTS IN DIRECTORY
       
      if(k==-1)
      {
          printf("\nContact not found.");
          goto srch_cont;	//GOTO STATEMENT FOR SEARCHING AGAIN, CONTROL IS PASSED TO srch_cont
      }
       
     else
     {
      opt:
      system("clear");
      printf("\n\n Choose from the following options: ");
      printf("\n1. Display current contact details. ");
      printf("\n2. Edit phone number. ");
      printf("\n3. Edit landline number. ");
      printf("\n4. Edit address. ");
      printf("\n5. Edit email id. ");
      printf("\n6. Go to main directory. ");
      printf("\n Enter your choice: ");
          scanf("%d",&choice);

      switch(choice)
      {
        case 1:  printf("\nThe contact details are: ");
 
                 printf("\nNAME: %s",p[k].name);
                 printf("\nNUMBER: %ld",p[k].ph_no);
                 if (p[k].lan_no)
	           printf("\nLANDLINE: %ld",p[k].lan_no);
                 a=strcmp(p[k].addr,"NULL");
                  if(a!=0)
                    printf("\nADDRESS: %s",p[k].addr);
                
                 a=strcmp(p[k].ID,"NULL");
                  if(a!=0)
                    printf("\nEMAIL ID: %s",p[k].ID);
                 
		
		break;

       case 2: printf("\nEnter the new phone number:");
		 scanf("%ld",&p[k].ph_no);
		
	       break;
      
       case 3: printf("Enter the new landline number: ");
		scanf("%ld",&p[k].lan_no);
		break;
       case 4: printf("\nEnter the new address: ");
		scanf("%s",p[k].addr);
		
	       break;
      
       case 5: printf("\nEnter new email id: ");
		 scanf("%s",p[k].ID);
     		
	       break;
       case 6: return;
       default: printf("\nInvalid choice!");
	      
      }
         //END OF SWITCH STATEMENT
     printf("\nDo you want to edit more details?\nPress 1 for Yes\nPress 2 for No\n");
         scanf("%d",&ch);
     if(ch==1)
     goto opt;

     }//END OF ELSE STATEMENT 

     srch_cont:					//LABEL FOR CONTINUING SEARCH
       printf("\nDo you want to edit more contacts?\nPress 1 for Yes\nPress 2 for No\n");
          scanf("%d",&ch);
       if(ch==1)
          goto srch;					//GOTO STATEMENT, CONTROL IS PASSED TO srch
       else 
          return ;
 }
     
    //END OF FUNCTION

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF PROGRAM                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////
