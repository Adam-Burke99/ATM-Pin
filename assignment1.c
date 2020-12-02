/*
Programming 

Adam Burke Assignment1.c C20511903  Date: 22/11/20 
Compiled using Borland

Program for an Automated Teller Machine. Providing a list of options to the user as follows:
Enter their pin and verify that it is correct
Create a new pin.
Display the number of times the pin was entered correctly/ incorrectly 
And exit the program
*/

#include <stdio.h>
 
#define SIZE 4 //defining 'SIZE as 4'

int main()
{
    
    //Declaring Variables
    
    // varable for index, used in all 'for' loops
    int i[SIZE]; //i is the index which is used in all 'for' loops
    
    //Start of program input
    int input;                      //user input on the menu to verify which part of the program to run.
 	
 	//variables used in option '1'
 	int pin[SIZE] = {1, 2, 3, 4};   //original pin for the user 
 	int check[SIZE];                //variable which is scanned in from the user in option 1 of the program which is then checked against the variable 'pin'
     
    //variables used in option '2'                    
    int change1[SIZE];              //first varable when user is trying to change their pin
    int change2[SIZE];              //second variable when user is changing their pin
    int statement = 0;              //This is used in option 1 to verify that the user enterred the correct pin
    int reenter = 0;                // this is used to verify that the two sets of numbers enterred in option 2 match eachother

    //counter variables for all parts of the program
    int counterA = 0;               //counter for when the pin is enterred CORRECTLY.
    int counterB = 0;               // counter for when the pin is enterred INCORRECTLY
    
    printf("\nHello!\nPlease hit 'Enter' after every input for this program\n"); //Providing greeting message for user and instruction
do 
{//start of do loop for the program
        
    //giving the user their options, then requesting an input.
    
    printf("\nPlease enter your option:\n1 to check your pin.\n2 to change your pin.\n");
    printf("3 to check number of times pin was entered correctly/incorrectly.\nPress '4' to exit\n");
    
        
    scanf("%d", &input);
    getchar();

 	    
        switch(input)
        { //start switch
            case 1: // if (input == '1') checking if the pin they enter is correct.
            {
                printf("\nPlease enter your pin.\n"); //original pin: 1234
     		   
     		        for(int i = 0; i < SIZE; i ++)
                
                    { //start of for loop for user to input their pin
                 
                        scanf("%d", &check[i]);
                        getchar();
                     } // end for loop
                
                    for(int i = 0; i < SIZE; i ++)
                
                    { // start of for loop to check that the pin user entered is the same as the original pin
                     
                            if(check[i] == pin[i] && check [i] <= 9) //if statement to verify that the inputted pin is correct or incorrect
                    
                                {//start of if statement
                                
                                    statement = 1;
                        
                                } // end of if statment
                    
                            else
                                
                                {//start of else statement
                                    
                                    statement = 0;
                                }
                    }//end of for loop
                    
                    if(statement==1) //if statement to print a message to the user whether they were correct or incorrect
                        
                    { //start of if statement
                            
                        printf("\nThat is your correct pin!\n");
                            
                        counterA++; //counter incremented for times pin is enterred correctly
                            
                    } //end if statement
                    
                    else // else statment to show user they were incorrect
                  
                    {//start of else statement
                            printf("\nThe pin you enterred is incorrect\n");
                
                            counterB++;//counter incremented for times pin is enterred incorrectly
                  
                    }//end else statement
                
                break;
            } // end case '1'
 
            case 2: // if (oper == '2') Feature to change user's pin.
            
            { //start of case 2
     			
     			printf("\nPlease enter your new pin\n"); // request user to input new pin
                    
                    for(int i = 0; i < SIZE; i ++) // for loop to read the new pin into an array 
                    
                    {//start of for loop
                
                            scanf("%d", &change1[i]);
                            getchar();
                    }//end for loop
                
                //entry for confirming pin
                printf("\nPlease reenter your pin\n");
                
                for(int i = 0; i < SIZE; i ++) // for loop to reenter the new pin and verify it matches the orignal entry 
                
                { // start of for loop
                    
                        scanf("%d", &change2[i]);
                        getchar();
                    
                        if(change1[i] == change2[i] && change1[i] <= 9 && change2[i] <= 9) //if statement to verify the two new pins match
                    
                        {//start if statement
                           
                            reenter = 1; //meaning pins are correct and match
                        
                        } // end if statement
                    
                        else
                        { //start else statement
                        
                            reenter = 0; // meaning pins do not match
                        
                        } //end else statement
                }           
                    
                if(reenter == 1) //if statement for when the pins match
                
                {// start if statement
                    
                    printf("Your new pin is:\n");
                    
                     for(int i = 0; i < SIZE; i ++) // for loop to print the new pin for the user to see
                        
                        {//start for
                         
                            printf("%d", change2[i]);
                        
                        }//end for    
                         
                    for(int i = 0; i < SIZE; i ++)  // for loop to convert the pin variable to the new pin
                         
                         {//start for
                         
                            pin[i] = change2 [i];
                         
                         }//end for   
                         
                }//end if statement
                
                else //else statement if there was a problem changing the pin and printing error message
                
                { //start else statement
                
                    printf("\nError, pins do not match or an invalid number was entered. Please try again\n"); 
                    
                }//end else statement
                
                    break;
                
            }// End case 2        
            case 3: // show number of times pin was entered correctly / incorrectly
            
            {// start case 2
                
                printf("\nNumber of times pin was entered correctly: %d\n", counterA);
                
                printf("\nNumber of times pin was entered incorrectly: %d\n", counterB);
            
                break;
                
            }//end case 3
            
            case 4: //exit the program
          
            { //start case 4
                
                break;
                
            } //end case 4
            
            
            default:
            { //start default
            
                printf("\nInvalid operator. Please enter an option from the list.\n");
            
                
            } // end default
        
        }// end switch statement
        
}while(input!=4); //while loop for the do ... while function



printf("\nThank you for using this banking program!");
    
    

} // end main

 