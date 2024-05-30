#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int determineScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario);
int determineAltScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario);
int determineDeadEndScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario);
int determinePeaceScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario);
int scanPlayerChoice(void);
int main()
{
	int start, playerChoice, ending, scenario, peaceScenario, altScenario, deadEndScenario, tryAgain;
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
		while(altScenario==1 && deadEndScenario==0 && scenario==0 && peaceScenario==0)
	    {
	    	system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);		
    		printf("You find yourself in the master’s bedroom. It is decorated in a way that feels as if it should never have any guests, much more intruders. \nThere is a line of beds which indicates this must have been used as a dormitory. \nTo your right, there is a massive gaping hole in the room. Hints of a century-old explosion litter at your feet.");
    		printf("\n\nPress 1 to Look around.");
    		printf("\nPress 2 to Investigate the hole in the wall");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
			if(playerChoice==2)
			{
				system("cls");
				printf("You investigated the hole. It leads to the office...");
    			sleep(3);
			}
    	}
    	while(altScenario==2 && deadEndScenario==0 && scenario==0 && peaceScenario==0)
	    {
	    	system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("Your flashlight combats the overwhelming darkness in this room. The smell here is awful and rotten. \nOld hospital equipment is propped up in places they shouldn’t, some beyond repair, others in perfect condition. A laboratory.");
    		printf("\nIn the center of the room, surrounded by curtains, stands a surgical table with black stains and four cuffs. \nBeside it, a tray of scalpels - the source of the smell. There are bullets scattered on the floor. \nYou see holes in the concrete walls, gathered in manic sprays. ");
    		printf("\nThe trail leads you to a completely battered door, splinters and old gunfire introducing its wooden corpse.");
    		printf("\n\nPress 1 to Take the door.");
    		printf("\nPress 2 to Go back to the office");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You took the door. It sees you a staircase that leads to the 2nd floor.");
    			sleep(3);
			}
			else if(playerChoice==2)
			{
				system("cls");
				printf("You go back to the office...");
    			sleep(3);
			}
    	}
    	while(altScenario==3 && deadEndScenario==0 && scenario==0 && peaceScenario==0)
	    {
	    	system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You nearly trip on your own feet scrambling to get to the doorway. What you see resembles nothing of a living room, \nonly that of an empty concrete room. There is a hideous shape on the ground, \na pair of giant doors to your left, and an open doorway to your right.");
    		printf("\n\nPress 1 to Investigate a lying body");
    		printf("\nPress 2 to Go to the big door");
    		printf("\nPress 3 to Go to the small door");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You got to the small door. You sprint to the dining room.");
    			sleep(3);
			}
    	}
    	while(altScenario==4 && deadEndScenario==0 && scenario==0 && peaceScenario==0)
	    {
	    	system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You nearly fall off the stairs and land in the basement. \nThe ceiling is made of rock and your surroundings made up of cabinets and wartime equipment. \nYou can make out the shape of a person hiding under a table.");
    		sleep(3);
			printf("\nRuben is shaken and terrified out of his mind. Suddenly he sees your face - bruised, dirty, and exhausted - but it’s still you. \nNo words need to be spoken here. You share a quick embrace before facing your fears together. \nIf there is a time to escape, now would be the best time. ");
    		printf("\n\nPress 1 to Go back upstairs");
    		printf("\nPress 2 to Take the cellar door");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    	}
		while(scenario==1 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
	    {
	    	system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You dont know how long its been since hiding in the attic of an old abandoned mansion. \nDespite your years of ghost hunting experience, your hope of finally encountering true paranormal activity was close to zero. \nToday, that changes. Today you saw what true ghosts look like. \nNow you are stranded in a mansion, you and your team scattered across every corner.  \nOne minute you were together, and the next, everyone... disappeared.");
    		printf("\n\nThe night is oppressive. You hear the moans of wind and the creaking of rotten wooden floors. \nClutch your flashlight close to you; you cannot leave without it. ");
    		printf("\n\nWhat will you do?");
    		printf("\n\nPress 1 to Go Downstairs");
    		printf("\nPress 2 to Check the Closet");
    		printf("\nPress 3 to Check the Window");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You climbed downstairs...");
    	    	sleep(3);
			}
    	}
    	while(scenario==2 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You find yourself in a long dark corridor with many doors. There is a mysterious thing at the end of it. \n\nWhat is your next move?");
    		printf("\n\nPress 1 to Shine light on mysterious thing ");
    		printf("\nPress 2 to Check Masters bedroom");
    		printf("\nPress 3 to Go straight through the corridor");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You go straight. Your path leads you to the office...");
    			sleep(3);
			}
    	}
    	while(scenario==3 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("Papers are scattered everywhere. Typewriters which should have been stolen by thieves - sit alone at their desks. \nA number of fallen telephones have raised cobwebs and insects. No one has been in this room for a very long time. \nThis must have been a communications room. But for what?");
    		printf("\n\nPress 1 to Take the stairs ");
    		printf("\nPress 2 to Go to the room");
    		printf("\nPress 3 to Investigate the silhouette");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("The stairs lead you to the second floor…");
    			sleep(3);
			}
		}
		while(scenario==4 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("Something is approaching towards you in the darkness, its footsteps echoing. You hear gurgling…");
    		printf("\n\nPress 1 to Follow the Noise");
    		printf("\nPress 2 to Run");
    		printf("\nPress 3 to Fight it");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==2)
    		{
    			system("cls");
    			printf("You hear a shrill scream from behind as you race to the other side. It’s chasing you. ");
    			sleep(3);
			}
		}
		while(scenario==5 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		system("cls");
    		printf("You find yourself in another corridor. Every second you are not moving, whatever is chasing you is getting closer.");
    		printf("\n\nPress 1 to Go to the living room");
    		printf("\nPress 2 to Go to the dining room");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==3)
    		{
    			system("cls");
    			printf("You ran to the dining room.");
    			sleep(3);
			}
		}
		while(scenario==6 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);   
			altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario); 
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);			
    		system("cls");
    		printf("It looks more of a cafeteria than anything. They serve cobwebs and dust here now. \nThe place is wide and spacious - not very good for hiding. On the counter in front of you there are rusty utensils, \nincluding a knife. To your left is a narrow staircase leading to the first floor. ");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Take the knife");
    		printf("\nPress 3 to Turn back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		if(playerChoice==1)
    		{
    			system("cls");
    			printf("You scramble up the staircase.");
    			sleep(3);
			}
		}
		while(scenario==7 && altScenario==0 && deadEndScenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You’re in the entrance hall. The corridors are wide and narrow, exposing you from every direction. \nSomething is running towards you in the distance, but you cannot tell where.  A staircase leading downwards greets you from the right. \nIn front of you are a pair of giant doors. The darkness seeks to take you in.");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Take the big door");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
		}
		while(deadEndScenario==1 && altScenario==0 && scenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("The closet is empty...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    	}
    	while(deadEndScenario==2 && altScenario==0 && scenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("You saw darkness...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    	}
    	while(deadEndScenario==3 && altScenario==0 && scenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("It is a mangled shape, but you recognize it. Scattered hair over untouched floorboards, \nlying awkwardly on its side… you find the dead body of your teammate. Her face is permanently \nfixed in wide-eyed horror and a silent scream. Fingers bloodied, her neck…  she was choked by a rope - but you \ncannot find any evidence of it.");
    		printf("\n\nHer name was Lucienne. She died recently, and very close to you.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
		}
		while(deadEndScenario==4 && altScenario==0 && scenario==0 && peaceScenario==0)
    	{
    		system("cls");
    		scenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
    		altScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			deadEndScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			peaceScenario=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);
			ending=determineScenario(playerChoice, scenario, ending,  altScenario, peaceScenario, deadEndScenario);	
    		printf("As you move with curiosity, you hear something crunch under your shoe. \nYou’ve stepped on a delicate war-time portrait of a beautiful woman with black hair. \nThe glass crumbles off the picture when you read an old scribbling on the back, saying, \n\n\n“Time will tell. --Magdalene”.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
		}
    	if(ending==1 && scenario==4){
    		system("cls");
    		printf("You swing out from the side and attempt to bash it over the head with the flashlight.");
    		sleep(3);
    		printf("\nIn those moments, you saw a dead soldier, his stomach carved open, white eyes forever set on you.");
    		sleep(3);
    		printf("\nIt takes you by the neck. It will be the last thing you will ever see…");
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
			system("cls");
    		printf("You move closer. Upon shining a light, you see now it is not a shape - it is a person.");
    		sleep(3);
    		printf("\nThey lay on the ground, faced away from you and unrecognizable. You do not recognize this person at all, you realize.");
    		sleep(3);
    		printf("\nTheir limbs are unnaturally long, their breathing ragged and rapid. \n\nTheir head twists to look at you, and you see their face resembles nothing human-like.");
    		sleep(3);
    		printf("\nThe thing pounces on you with overwhelming strength. Your death is swift, but violent.");
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
			system("cls");
    		printf("Something grabs your wrist as you try to take it.");
    		sleep(3);
    		printf("\nYou look to see the thing that has been chasing you this entire time.");
    		sleep(3);
    		printf("\nA dead soldier whose stomach cavity hangs loose and exposed. It screams a guttural sound.");
    		sleep(3);
    		printf("\nThe fridge is empty. ");
    		sleep(3);
    		printf("\nThe knife is in your fist but it takes your hand and twists it - then plunges it into your neck.");
    		sleep(3);
    		printf("\nThe sensation of the blade going through your throat is instant.");
    		sleep(3);
    		printf("\nYou cannot breathe. You cannot think. You cannot do anything anymore.");
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
			system("cls");
    		printf("You turn around and see a face. It sprints towards you at full speed.");
    		sleep(3);
    		printf("\nIt is faster than you are. You cannot outrun it. ");
    		sleep(3);
    		printf("\nIt stretches its hands towards you, and the final thing you hear is the sound of its predatory scream.");
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
			system("cls");
    		printf("Perhaps you were under the impression that the ghost would have left the pursuit.");
    		sleep(3);
    		printf("\nYou and your partner take quiet steps going up. You see it waiting at the very top. It lunges at both of you.");
    		sleep(3);
    		printf("\nYou fall on your neck tumbling all the way down to the very bottom.");
    		sleep(3);
    		printf("\nAs you lay on the ground, vision slowly fading, you see Ruben lifted up to the wall, screaming and crying. ");
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
		
		if(ending==2 && altScenario==3){
			system("cls");
			printf("You go to the big door.");
			sleep(3);
			printf("\nThe ghost of this forsaken mansion was close to getting you, but not close enough.");
			sleep(3);
			printf("\nYou barge through the large doors and crash into the real world. The sun is rising.");
			sleep(3);
			printf("\nThe outside air is heavenly to breathe. You dare not look back now.");
			sleep(3);
			printf("\nYou run, and you run, and you keep on running… ");
			sleep(3);
			printf("\n\nYou are free.");
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
			system("cls");
			printf("You took the door.");
			sleep(3);
			printf("\n\nThe ghost of this forsaken mansion was close to getting you, but not close enough.");
			sleep(3);
			printf("\nYou barge through the large doors and crash into the real world. The sun is rising.");
			sleep(3);
			printf("\nThe outside air is heavenly to breathe. You dare not look back now.");
			sleep(3);
			printf("You run, and you run, and you keep on running…");
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
		if(ending==2 && altScenario==4){
			system("cls");
			printf("The exit is barred with a lock that has denied you freedom.");
			sleep(3);
			printf("\nIf you were alone, this is where you would have met your fate. But you’re not.");
			sleep(3);
			printf("\nYou and Reuben use your combined strength to break the lock by brute force.");
			sleep(3);
			printf("\nYou barge the door once, hearing the screams of multiple entities within the mansion.");
			sleep(3);
			printf("\nThen twice, awakening hundreds more.");
			sleep(3);
			printf("\nAnd finally, thrice.");
			sleep(3);
			printf("\nThe lock breaks free and the doors fly open.");
			sleep(3);
			printf("\nYou and your partner scramble to get outside and crash into the real world. ");
			sleep(3);
			printf("\nThe sun is rising. The outside air is heavenly to breathe.");
			sleep(3);
			printf("\nWe dare not look back now. You run, and you run, and you keep on running…");
			sleep(3);
			printf("\nWe are free");
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
			system("cls");
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
int scanPlayerChoice(void) 
{
	char playerChoice[60];
	scanf("%s", &playerChoice);
	if(isdigit(playerChoice[0]))
	{
		return playerChoice[0]-48;
	}
	else
	{
		return 0;
	}
}
int determineScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario)
{

		while(altScenario==1)
	    {
    		switch(playerChoice)
    		{
    			case 1:{
    				return deadEndScenario=4;
    				return altScenario=0;
    				break;
    			}
    			case 2:{
    				return scenario=3;
					return altScenario=0;	
    				break;
    			}
    			default:{
    				
    				return altScenario=1;
    				break;
    			}
    		}		
    	}
    	while(altScenario==2)
    	{
    		switch(playerChoice)
    		{
    			case 1:{
    				return scenario=4;
    				return altScenario=0;				
    				break;
    			}
    			case 2:{
    				return scenario=3;
					return altScenario=0;				
    				break;
    			}
    			default:{
    				
    				return altScenario=2;
    				break;
    			}
    		}		
    	}
    	while(altScenario==3)
    	{
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
    			case 3:{
    				return scenario=6;
    				return altScenario=0;
    				break;
    			}
    			default:{
    				
	    			return altScenario=3;
	    			break;
    			}
    		}		
    	}
    	while(altScenario==4)
    	{
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
    				
    				return altScenario=4;
    				break;
    			}
    		}		
    	}
    	while(scenario==1)
    	{
    		switch(playerChoice)
    		{
    			case 1:{
    				return scenario=2;
    				break;
    			}
    			case 2:{
    				return deadEndScenario=1;
    				return scenario=0;
    				break;
    			}
    			case 3:{
    				return deadEndScenario=2;
					return scenario=0;				
    				break;
    			}
    			default:{
    				
    				return scenario=1;
    				break;
    			}
    		}
    	}
    	while(scenario==2)
    	{
    		switch(playerChoice)
    		{
    			case 1:{
    				return deadEndScenario=3;
					return scenario=0;				
    				break;
    			}
    			case 2:{
    				return altScenario = 1;	
					return scenario=0;			
    				break;
    			}
    			case 3:{
    				return scenario=3;				
    				break;
    			}
    			default:{
    				
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
					return scenario=0;				
    				break;
    			}
    			case 3:{
    				return deadEndScenario=4;
					return scenario=0;				
    				break;
    			}
    			default:{
    				
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
					return scenario=0;				
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
					return scenario=0;				
    				break;
    			}
    			case 2:{
    				return scenario=6;				
    				break;
    			}
    			default:{
    				
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
					return scenario=0;				
    				break;
    			}
    			case 2:{
    				return ending=2;				
    				break;
    			}
    			default:{
    				
    				return scenario=7;				
    				break;
    			}
    		}
    	}
    	while(deadEndScenario==1)
    	{
    		if(playerChoice==1)
    		{
    			return scenario=1;
				return deadEndScenario=0;			
    		}
    		else
    		{
    			
    			return deadEndScenario=1;
    		}	
    	}
    	while(deadEndScenario==2)
    	{
    		if(playerChoice==1)
    		{
    			return scenario=1;
				return deadEndScenario=0;			
    		}
    		else
    		{
    			
    			return deadEndScenario=2;
    		}		
    	}
    	while(deadEndScenario==3)
    	{
    		if(playerChoice==1)
    		{
    			return scenario=2;
				return deadEndScenario=0;		
    		}
    		else
    		{
    			
    			return deadEndScenario=3;
    		}
		
    	}
    	while(deadEndScenario==4)
    	{
    		if(playerChoice==1)
    		{
    			return altScenario=1;
    			return deadEndScenario=0;
			
    		}
    		else
    		{
    			return deadEndScenario=4;
    		}
		
    	}
}
int determineAltScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario)
{
	
}
int determineDeadEndScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario)
{
	
}
int determinePeaceScenario(int playerChoice, int scenario, int ending, int altScenario, int peaceScenario, int deadEndScenario)
{
	
}
