#include <stdio.h>
int determineScenario(int playerChoice, int scenario, int ending, int error, int altScenario, int peaceScenario, int deadEndScenario);
int errorTrap(int error, int playerChoice);
int main()
{
	int start=0, playerChoice, ending=0, error=0, scenario=0, peaceScenario=0, altScenario=0, deadEndScenario, tryAgain;
	printf("                                               Haunted Mansion");
    printf("\n\n\n                       In the 1990s, you are an amateur ghost hunter working with a team.");
    printf("\n                        You receive a call to investigate an old mansion where the owner");
    printf("\n                         has reported supernatural happenings and is clearly disturbed.");
    printf("\n                          As per their wishes, you set up and begin the investigation.");
    printf("\n                     Everything goes wrong when you lose your way and your team went missing.");
    printf("\n                 You must find your team and survive on your own in a large, puzzle-like mansion.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                           Press 1 to start game: ");
    printf("\n                                         Press any number to exit: ");
    printf("\n\n                                            Enter Choice here: ");
    scanf("%d",&start);
	while(start == 1){
		scenario=1;
		while(altScenario==1)
	    {
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		error=errorTrap(error, playerChoice);
    		system("cls");
    		printf("You are in the master’s bedroom with a hole in the wall. What is your next move?");
    		printf("\n\nPress 1 to Go back to the corridor");
    		printf("\nPress 2 to Investigate the hole in the wall");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You go back to the corridor...");
    			sleep(3);
			}
			else if(playerChoice==2)
			{
				system("cls");
				printf("You investigated the hole. It leads to the office...");
    			sleep(3);
			}
    	}
    	while(altScenario==2)
	    {
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		error=errorTrap(error, playerChoice);
    		printf("You find yourself in the nursery. You found another door. What is your next move?");
    		printf("\n\nPress 1 to Take the door.");
    		printf("\nPress 2 to Go back to the office");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You took the door. You saw a staircase that leads to the 2nd floor.");
    			sleep(3);
			}
			else if(playerChoice==2)
			{
				system("cls");
				printf("You go back to the office...");
    			sleep(3);
			}
    	}
    	while(altScenario==3)
	    {
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		error=errorTrap(error, playerChoice);
    		printf("You go to the living room. You see a lying shadow, a big door, and a small door. What is your next move?");
    		printf("\n\nPress 1 to Investigate a lying body");
    		printf("\nPress 2 to Go to the big door");
    		printf("\nPress 3 to Go to the small door");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You got to the small door. It connects to the dining room.");
    			sleep(3);
			}
    	}
    	while(altScenario==4)
	    {
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		error=errorTrap(error, playerChoice);
    		printf("You are in the master’s bedroom with a hole in the wall. What is your next move?");
    		printf("\n\nPress 1 to Go back to the corridor");
    		printf("\nPress 2 to Investigate the hole in the wall");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    	}
		while(scenario==1)
	    {
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		error=errorTrap(error, playerChoice);
    		printf("You are in the attic of the abandoned mansion. What is your first move?");
    		printf("\n\nPress 1 to Go Downstairs");
    		printf("\nPress 2 to Check the Closet");
    		printf("\nPress 3 to Check the Window");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You climbed downstairs...");
    	    	sleep(3);
			}
    	}
    	while(scenario==2)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You find yourself in a corridor with a mysterious thing and a room to master's bedroom. What is your next move?");
    		printf("\n\nPress 1 to Investigate mysterious thing ");
    		printf("\nPress 2 to Check Masters bedroom");
    		printf("\nPress 3 to Go straight through the corridor");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You go straight. Your path leads you to the office...");
    			sleep(3);
			}
    	}
    	while(scenario==3)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You are in the office. It is connected to another room. You see a silhouette under the desk. There is a stair that leads downwards. What is your next move?");
    		printf("\n\nPress 1 to Take the stairs ");
    		printf("\nPress 2 to Go to the room");
    		printf("\nPress 3 to Investigate the silhouette");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You took the stairs to the 2nd floor...");
    			sleep(3);
			}
		}
		while(scenario==4)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You are on the 2nd floor. You encountered a ghost. She looks disturbed. What is your next move?");
    		printf("\n\nPress 1 to Talk to the ghost");
    		printf("\nPress 2 to Get past through her");
    		printf("\nPress 3 to Attack the ghost");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==2)
    		{
    			system("cls");
    			printf("You got past her. The ghost becomes hostile.");
    			sleep(3);
			}
		}
		while(scenario==5)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		system("cls");
    		printf("After you get past her, you find yourself in another corridor. What is your next move?");
    		printf("\n\nPress 1 to Go to the living room");
    		printf("\nPress 2 to Go to the bathroom");
    		printf("\nPress 3 to Go to the dining room");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You go to the dining room.");
    			sleep(3);
			}
		}
		while(scenario==6)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		system("cls");
    		printf("You are in the dining room. You saw a staircase that leads to the 1st floor, a room that leads to the kitchen. What is your choice?");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Go to the kitchen");
    		printf("\nPress 3 to Turn back");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You took the staircase.");
    			sleep(3);
			}
		}
		while(scenario==7)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You find yourself in the entrance hall. You saw another staircase that leads downwards, a big door and a dead body. What will you do?");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Take the big door");
    		printf("\nPress 3 to Investigate the dead body");
    		printf("\n\nEnter your Choice here: ");
    		scanf("%d",&playerChoice);
		}
		while(deadEndScenario==1)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("The closet is empty...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
    	}
    	while(deadEndScenario==2)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You saw darkness...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
    	}
    	while(deadEndScenario==3)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You found the dead body of your teammate.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
		}
		while(deadEndScenario==4)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You found the dead body of your teammate.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
		}
		while(deadEndScenario==5)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You go to the bathroom. You saw nothing worthwhile.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
		}
		while(deadEndScenario==6)
    	{
    		scenario=determineScenario(playerChoice, scenario, ending, error, altScenario, peaceScenario, deadEndScenario);
    		errorTrap(error, playerChoice);
    		printf("You investigated the dead body. It is the dead body of one of your teammates.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&playerChoice);
		}
    	if(ending==1 && scenario==4){
    		printf("You tried to attack the ghost.");
    		sleep(3);
    		printf("\n\nThe ghost retaliates and kills you.");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==1 && scenario==5){
    		printf("You investigated a lying body. It is a dead body of your teammate.");
    		sleep(3);
    		printf("\n\nThe ghost catches up and kills you from behind.");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==1 && scenario==6 && playerChoice==2){
    		printf("You go to the kitchen. ");
    		sleep(3);
    		printf("You feel hungry. ");
    		sleep(3);
    		printf("You check the fridge to see if there is any food. ");
    		sleep(3);
    		printf("\nThe fridge is empty. ");
    		sleep(3);
    		printf("You decided to go back to the dining room, still feeling hungry. ");
    		sleep(3);
    		printf("Upon turning back, you see the ghost from before near your face. ");
    		sleep(3);
    		printf("She ends your life for feeling rejected before. ");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==1 && scenario==6 && playerChoice==3){
    		printf("You decided to go back to the corridor. ");
    		sleep(3);
    		printf("\n\nUpon turning back, you see the ghost from before near your face. ");
    		sleep(3);
    		printf("She ends your life for feeling rejected before. ");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==1 && scenario==7 && altScenario==4){
    		printf("You decided to go back upstairs. ");
    		sleep(3);
    		printf("\n\nUpon turning back, you see the ghost from before near your face.");
    		sleep(3);
    		printf("\n\nShe ends your life along with your partner.");
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		
		if(ending==2 && scenario==5){
			printf("You go to the big door.");
			sleep(3);
			printf("\n\nYou found yourself outside the mansion.");
			sleep(3);
			printf("\n\nYou have successfully escaped the mansion... Alone.");
			sleep(3);
			printf("\n\nESCAPE ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==2 && scenario==7){
			printf("You took the door.");
			sleep(3);
			printf("\n\nYou found yourself outside the mansion.");
			sleep(3);
			printf("\n\nYou have successfully escaped the mansion... with your partner.");
			sleep(3);
			printf("\n\nESCAPE ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}
		if(ending==3){
			printf("The ghost, freed from guilt, thanks you.");
			sleep(3);
			printf("\n\nThe ghosts have risen to heaven.");
			sleep(3);
			printf("\n\nAfter you saw them, you looked deeped into the mansion for survivors. At the basement, you saw your partner and a door. You took the door with your partner.");
			sleep(3);
			printf("\n\nYou have successfully escaped the mansion... with your partner.");
			sleep(3);
			printf("PEACEFUL ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any number to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			start=1;
			}
		}	
	}
    return 0;
}
int errorTrap(int error, int playerChoice)
{
	error=0;
	if(error==1)
	{
		system("cls");
		
	}
}
int determineScenario(int playerChoice, int scenario, int ending, int error, int altScenario, int peaceScenario, int deadEndScenario)
{
	error=errorTrap(error, playerChoice);
	while(altScenario==1 && scenario==2)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return scenario=2;
				altScenario=0;
				
				break;
			}
			case 2:{
				return scenario=3;
				
				break;
			}
			default:{
				error=1;
				return altScenario=1;
				break;
			}
		}		
	}
	while(altScenario==2 && scenario==3)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return scenario=4;
				altScenario=0;
				
				break;
			}
			case 2:{
				return scenario=3;
				
				break;
			}
			default:{
				error=1;
				return altScenario=2;
				break;
			}
		}		
	}
	while(altScenario==3 && scenario==5)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return ending=1;
				
				break;
			}
			case 2:{
				return ending=2;
				
				break;
			}
			default:{
				error=1;
				return altScenario=3;
				break;
			}
		}		
	}
	while(altScenario==4 && scenario==7)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return ending=1;
				
				break;
			}
			case 2:{
				return ending=2;
				
				break;
			}
			default:{
				error=1;
				return altScenario=4;
				break;
			}
		}		
	}
	while(scenario==1)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return scenario=2;
				break;
			}
			case 2:{
				return deadEndScenario=1;
				break;
			}
			case 3:{
				return deadEndScenario=2;
				
				break;
			}
			default:{
				return error=1;
				return scenario=1;
				break;
			}
		}
	}
	while(scenario==2)
	{
		system("cls");
		switch(playerChoice)
		{
			case 1:{
				return deadEndScenario=3;
				
				break;
			}
			case 2:{
				return altScenario = 1;
				
				break;
			}
			case 3:{
				scenario=3;
				
				break;
			}
			default:{
				return error=1;
				return scenario=2;
				
				break;
			}
		}
	}
	while(scenario==3)
	{
		switch(playerChoice)
		{
			case 1:{
				return scenario=4;
				
				break;
			}
			case 2:{
				return altScenario = 2;
				
				break;
			}
			case 3:{
				deadEndScenario=4;
				
				break;
			}
			default:{
				return error=1;
				return scenario=3;
				
				break;
			}
		}
	}
	while(scenario==4)
	{
		switch(playerChoice)
		{
			case 1:{
				return peaceScenario=1;
				
				break;
			}
			case 2:{
				return scenario=5;
				
				break;
			}
			case 3:{
				return ending=1;
				
				break;
			}
			default:{
				return error=1;
				return scenario=4;
				
				break;
			}
		}
	}
	while(scenario==5)
	{
		switch(playerChoice)
		{
			case 1:{
				return altScenario=3;
				
				break;
			}
			case 2:{
				return deadEndScenario=5;
				
				break;
			}
			case 3:{
				return scenario=6;
				
				break;
			}
			default:{
				return error=1;
				return scenario=5;
				
				break;
			}
		}
	}
	while(scenario==6)
	{
		switch(playerChoice)
		{
			case 1:{
				return scenario=7;
				
				break;
			}
			case 2:{
				return ending=1;
				
				break;
			}
			case 3:{
				return ending=1;
				
				break;
			}
			default:{
				return error=1;
				return scenario=6;
				
				break;
			}
		}
	}
	while(scenario==7)
	{
		switch(playerChoice)
		{
			case 1:{
				return altScenario=4;
				
				break;
			}
			case 2:{
				return ending=2;
				
				break;
			}
			case 3:{
				return deadEndScenario=6;
				
				break;
			}
			default:{
				return error=1;
				return scenario=7;
				
				break;
			}
		}
	}
	while(deadEndScenario==1)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=1;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=1;
		}	
	}
	while(deadEndScenario==2)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=1;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=2;
		}
		
	}
	while(deadEndScenario==3)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=2;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=3;
		}
		
	}
	while(deadEndScenario==4)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=3;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=4;
		}
		
	}
	while(deadEndScenario==5)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=5;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=5;
		}
		
	}
	while(deadEndScenario==6)
	{
		system("cls");
		if(playerChoice==1)
		{
			return scenario=7;
			
		}
		else
		{
			return error=1;
			return deadEndScenario=6;
		}
		
	}
}


