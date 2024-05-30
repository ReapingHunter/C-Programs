#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int start=1, playerChoice=0, ending=0, scenario=0, tryAgain=0; 
	
    while(start == 1){
    	while(scenario==0)
    	{
    		printf("                                               Haunted Mansion"); /*Title menu*/
            printf("\n\n\n                       In the 1990s, you are an amateur ghost hunter working with a team.");
            printf("\n                        You receive a call to investigate an old mansion where the owner");
            printf("\n                         has reported supernatural happenings and is clearly disturbed.");
            printf("\n                          As per their wishes, you set up and begin the investigation.");
            printf("\n                     Everything goes wrong when you lose your way and your team went missing.");
            printf("\n                 You must find your team and survive on your own in a large, puzzle-like mansion.");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                           Press 1 to start game: ");
            printf("\n                                           Press any key to exit: ");
            printf("\n\n                                            Enter Choice here: ");
            playerChoice=scanPlayerChoice();
            switch(playerChoice)
            {
            	case 1:{
            		scenario=1;
					break;
				}
				default:{
					return 0;
					break;
				}
			}
		}
    	while(scenario==1); //Scenario 1
    	{
    		system("cls");
    		printf("You dont know how long its been since hiding in the attic of an old abandoned mansion. \nDespite your years of ghost hunting experience, your hope of finally encountering true paranormal activity was close to zero. \nToday, that changes. Today you saw what true ghosts look like. \nNow you are stranded in a mansion, you and your team scattered across every corner.  \nOne minute you were together, and the next, everyone... disappeared.");
    		printf("\n\nThe night is oppressive. You hear the moans of wind and the creaking of rotten wooden floors. \nClutch your flashlight close to you; you cannot leave without it. ");
    		printf("\n\nWhat will you do?");
    		printf("\n\nPress 1 to Go Downstairs");
    		printf("\nPress 2 to Check the Closet");
    		printf("\nPress 3 to Check the Window");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=2;
					break;
				}
				case 2:{
					scenario=8;
					break;
				}
				case 3:{
					scenario=9;
					break;
				}
				default:{
					scenario=1;
					break;
				}
			}	
		}
		while(scenario==2); //Scenario 2
    	{
    		system("cls");
    		printf("You find yourself in a long dark corridor with many doors. There is a mysterious thing at the end of it. \n\nWhat is your next move?");
    		printf("\n\nPress 1 to Shine light on mysterious thing ");
    		printf("\nPress 2 to Check Masters bedroom");
    		printf("\nPress 3 to Go straight through the corridor");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=10;
					break;
				}
				case 2:{
					scenario=11;
					break;
				}
				case 3:{
					scenario=3;
					break;
				}
				default:{
					scenario=2;
					break;
				}
			}
		}
		while(scenario==3); //Scenario 3
    	{
    		system("cls");
    		printf("You are in the office. Papers are scattered everywhere. Typewriters which should have been stolen by thieves - sit alone at their desks. \nA number of fallen telephones have raised cobwebs and insects. No one has been in this room for a very long time. \nThis must have been a communications room. But for what? An open door greets you to your left. \nYou see a silhouette under one of the desks, and a staircase that leads downwards.");
    		printf("\n\nPress 1 to Take the stairs ");
    		printf("\nPress 2 to Go to the room");
    		printf("\nPress 3 to Investigate the silhouette");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=4;
					break;
				}
				case 2:{
					scenario=13;
					break;
				}
				case 3:{
					scenario=14;
					break;
				}
				default:{
					scenario=3;
					break;
				}
			}
		}
		while(scenario==4); //Scenario 4
    	{
    		system("cls");	
    		printf("Something is approaching towards you in the darkness, its footsteps echoing. You hear gurgling...");
    		printf("\n\nPress 1 to Follow the Noise");
    		printf("\nPress 2 to Run");
    		printf("\nPress 3 to Fight it");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=17;
					break;
				}
				case 2:{
					scenario=5;
					break;
				}
				case 3:{
					scenario=29;
					break;
				}
				default:{
					scenario=4;
					break;
				}
			}
		}
		while(scenario==5); //Scenario 5
    	{
    		system("cls");
    		printf("You find yourself in another corridor. Every second you are not moving, whatever is chasing you is getting closer.");
    		printf("\n\nPress 1 to Go to the living room");
    		printf("\nPress 2 to Go to the dining room");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=15;
					break;
				}
				case 2:{
					scenario=6;
					break;
				}
				default:{
					scenario=5;
					break;
				}
			}
		}
		while(scenario==6); //Scenario 6
    	{
    		system("cls");
    		printf("It looks more of a cafeteria than anything. They serve cobwebs and dust here now. \nThe place is wide and spacious - not very good for hiding. On the counter in front of you there are rusty utensils, \nincluding a knife. To your left is a narrow staircase leading to the first floor. ");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Take the knife");
    		printf("\nPress 3 to Turn back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=7;
					break;
				}
				case 2:{
					scenario=33;
					break;
				}
				case 3:{
					scenario=34;
					break;
				}
				default:{
					scenario=6;
					break;
				}
			}
		}
		while(scenario==7); //Scenario 7
    	{
    		system("cls");	
    		printf("You’re in the entrance hall. The corridors are wide and narrow, exposing you from every direction. \nSomething is running towards you in the distance, but you cannot tell where.  A staircase leading downwards greets you from the right. \nIn front of you are a pair of giant doors. The darkness seeks to take you in.");
    		printf("\n\nPress 1 to Take the staircase");
    		printf("\nPress 2 to Take the big door");
    		printf("\n\nEnter your Choice here: ");
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=16;
					break;
				}
				case 2:{
					scenario=36;
					break;
				}
				default:{
					scenario=7;
					break;
				}
			}
		}
		while(scenario==8); //Dead End Scenario 1
    	{
    		system("cls");
    		printf("The closet is empty...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=1;
					break;
				}
				default:{
					scenario=8;
					break;
				}
			}
		}
		while(scenario==9); //Dead End Scenario 2
    	{
    		system("cls");	
    		printf("You saw darkness...");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=1;
					break;
				}
				default:{
					scenario=9;
					break;
				}
			}
		}
		while(scenario==10); //Dead End Scenario 3
    	{
    		system("cls");
    		printf("It is a mangled shape, but you recognize it. Scattered hair over untouched floorboards, \nlying awkwardly on its side… you find the dead body of your teammate. Her face is permanently \nfixed in wide-eyed horror and a silent scream. Fingers bloodied, her neck…  she was choked by a rope - but you \ncannot find any evidence of it.");
    		printf("\n\nHer name was Lucienne. She died recently, and very close to you.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=2;
					break;
				}
				default:{
					scenario=10;
					break;
				}
			}
		}
		while(scenario==11); //Alternate Scenario 1
    	{
    		system("cls");
    		printf("You find yourself in the master’s bedroom. It is decorated in a way that feels as if it should never have any guests, much more intruders. \nThere is a line of beds which indicates this must have been used as a dormitory. \nTo your right, there is a massive gaping hole in the room. Hints of a century-old explosion litter at your feet.");
    		printf("\n\nPress 1 to Look around.");
    		printf("\nPress 2 to Investigate the hole in the wall");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=12;
					break;
				}
				case 2:{
					scenario=3;
					break;
				}
				default:{
					scenario=11;
					break;
				}
			}
		}
		while(scenario==12); //Dead End Scenario 4
    	{
    		system("cls");
    		printf("As you move with curiosity, you hear something crunch under your shoe. \nYou’ve stepped on a delicate war-time portrait of a beautiful woman with black hair. \nThe glass crumbles off the picture when you read an old scribbling on the back, saying, \n\n“Time will tell. -Magdalene”.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=11;
					break;
				}
				default:{
					scenario=12;
					break;
				}
			}
		}
		while(scenario==13); //Alternate Scenario 2
    	{
    		system("cls");
    		printf("Your flashlight combats the overwhelming darkness in this room. The smell here is awful and rotten. \nOld hospital equipment is propped up in places they shouldn’t, some beyond repair, others in perfect condition. A laboratory.");
    		printf("\n\nIn the center of the room, surrounded by curtains, stands a surgical table with black stains and four cuffs. \nBeside it, a tray of scalpels - the source of the smell. There are bullets scattered on the floor. \nYou see holes in the concrete walls, gathered in manic sprays.");
    		printf("\n\nPress 1 Go through the door.");
    		printf("\nPress 2 Go back to the office.");
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=4;
					break;
				}
				case 2:{
					scenario=3;
					break;
				}
				default:{
					scenario=13;
					break;
				}
			}
		}
		while(scenario==14); //Dead End Scenario 5
    	{
    		system("cls");
    		printf("A face meets you. It does not move, however. It is still… and dead. \nCalvin’s youth is gone forever, his body slumped under a desk, with eyes open \nslightly and cheeks wet with fresh tears. There is an infection that has emerged from his neck, \nappearing in white bubbles under his skin. Rigor mortis clenches a paper in his cold hand.");
    		printf("It reads: “Subject 2092 exhibits signs of delirium with an onset of nausea. \nOne week of exposure to the gas has displayed optimum results for the pathogen. \nWe have scheduled an open dissection on [REDACTED]. Anesthetics are prohibited, \nout of concern it may tamper with final results.");
    		printf("\n\nPress 1 to Go back...");
    		printf("\n\nEnter Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=3;
					break;
				}
				default:{
					scenario=14;
					break;
				}
			}
		}
		while(scenario==15); //Alternate Scenario 3
    	{
    		system("cls");	
    		printf("You nearly trip on your own feet scrambling to get to the doorway. What you see resembles nothing of a living room, \nonly that of an empty concrete room. There is a hideous shape on the ground, \na pair of giant doors to your left, and an open doorway to your right.");
    		printf("\n\nPress 1 to Investigate a lying body");
    		printf("\nPress 2 to Go to the big door");
    		printf("\nPress 3 to Go to the small door");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=31;
					break;
				}
				case 2:{
					scenario=32;
					break;
				}
				case 3:{
					scenario=6;
					break;
				}
				default:{
					scenario=15;
					break;
				}
			}
		}
		while(scenario==16); //Alternate Scenario 4
    	{
    		system("cls");
    		printf("You nearly fall off the stairs and land in the basement. \nThe ceiling is made of rock and your surroundings made up of cabinets and wartime equipment. \nYou can make out the shape of a person hiding under a table.");
    		sleep(3);
			printf("\nRuben is shaken and terrified out of his mind. Suddenly he sees your face - bruised, dirty, and exhausted - but it’s still you. \nNo words need to be spoken here. You share a quick embrace before facing your fears together. \nIf there is a time to escape, now would be the best time. ");
    		printf("\n\nPress 1 to Go back upstairs");
    		printf("\nPress 2 to Take the cellar door");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=35;
					break;
				}
				case 2:{
					scenario=36;
					break;
				}
				default:{
					scenario=16;
					break;
				}
			}
		}
		while(scenario==17); //17-28 lead to peace route. Peace Scenario 1
    	{
    		system("cls");
    		printf("The very reason why you’re in this mess in the first place is that you decided to become a ghost hunter. \nYou can’t pass up on a lifetime opportunity. Now is the best time to see what you can do.");
    		printf("\n\nPress 1 Read your notes");
    		printf("\nPress 2 to Examine Player Equipment");
    		printf("\nPress 3 to Secure a Safe Area");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=18;
					break;
				}
				case 2:{
					scenario=19;
					break;
				}
				case 3:{
					scenario=20;
					break;
				}
				default:{
					scenario=17;
					break;
				}
			}
		}
		while(scenario==18); //read your notes / Dead End Scenario 6
    	{
    		system("cls");
    		printf("“Step 1. Secure a safe area by creating a protection circle. \nStep 2. Establish communication and identify the entity.	\nStep 3. Obtain paranormal evidence and exit the territory ASAP. \nStep 4. Do not engage with the entity if it is tampering with Equipment or displaying hostility, as well as any unwarranted behaviour.”");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=17;
					break;
				}
				default:{
					scenario=18;
					break;
				}
			}
		}
		while(scenario==19); //examine player equipment / Dead End Scenario 7
    	{
    		system("cls");
    		printf("You check in your inventory and find: \n(1) Flashlight, (1) Purified Salt, (1) Spirit Box, (1) Camera");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=17;
					break;
				}
				default:{
					scenario=19;
					break;
				}
			}
		}
		while(scenario==20); //secure a safe area / Peace Scenario 2
    	{
    		system("cls");
    		printf("Out of all of the rooms you have encountered so far, the Master’s Bedroom seems the safest.");
    		printf("\nYou carefully make a tense trip all the way back to the top floor. \nOnce there, you quietly close the door behind you and begin setting up a protection circle on the floor, made up of purified salt. \nThe howling of wind is your only company. You are alone, for now.");
    		printf("\n\nYou have used up (1) Purified Salt.");
    		printf("\n\nPress 1 to Use a spirit box");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=21;
					break;
				}
				default:{
					scenario=20;
					break;
				}
			}
		}
		while(scenario==21); //use a spirit box / Peace Scenario 3
    	{
    		system("cls");
    		printf("You stand in the center of the protection circle, with a spirit box in hand. \nWhen it’s switched on, the device gives out an ear-splitting experience; the rapid scanning \nof radio channels \ndelivers a loud white noise that echoes in the room. ");
    		printf("Any entity in your presence will now be able to communicate with you.");
    		printf("\n\nPress 1 to say Hello");
    		printf("\n\nPress 2 to say Is anyone here with me?");
    		printf("\n\nPress 3 to say Would anyone like to talk to me?");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=22;
					break;
				}
				case 2:{
					scenario=23;
					break;
				}
				case 3:{
					scenario=24;
					break;
				}
				default:{
					scenario=21;
					break;
				}
			}
    		
		}
		while(scenario==22); //HELLO / Dead End Scenario 8
    	{
    		system("cls");
    		printf("HELLO");
    		printf("No response...");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=21;
					break;
				}
				default:{
					scenario=22;
					break;
				}
			}
    		
		}
		while(scenario==23); //Is anyone here with me / Dead End Scenario 9
    	{
    		system("cls");
    		printf("Is anyone here with me?");
    		printf("\nNo response...");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=21;
					break;
				}
				default:{
					scenario=23;
					break;
				}
			}
		}
		while(scenario==24); // Would anyone like to talk to me? / Peace Scenario 4
    	{
    		system("cls");
    		printf("Would anyone like to talk to me?");
    		printf("It takes a few minutes for a sign.");
    		printf("... hel-llo?");
    		printf("The voice seems to sound feminine - it’s hard to tell under the limits of the spirit box.");
    		printf("\n\nPress 1 to say Can you tell me your name?");
    		printf("\nPress 2 to say Can you give me a sign?");
    		printf("\nPress 3 to say I want to help you. Can you please tell me how? What do you want? What do you need?");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=25;
					break;
				}
				case 2:{
					scenario=26;
					break;
				}
				case 3:{
					scenario=28;
					break;
				}
				default:{
					scenario=24;
					break;
				}
			}
		}
		while(scenario==25); //name of ghost / Dead End Scenario 10
    	{
    		system("cls");
    		printf("Can you tell me your name?");
    		printf("\nCait...lyn.");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=27;
					break;
				}
				default:{
					scenario=25;
					break;
				}
			}
		}
		while(scenario==26); //Sign / Dead End Scenario 11
    	{
    		system("cls");
    		printf("Can you give me a sign?");
    		printf("\n...not-strong.., --enough.");
    		printf("\n\nPress 1 to Go back");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=27;
					break;
				}
				default:{
					scenario=26;
					break;
				}
			}
		}
		while(scenario==27); //after pressing 1 and 2 on scenario 24 afterwards
    	{
    		system("cls");
    		printf("The voice seems to sound feminine - it’s hard to tell under the limits of the spirit box.");
    		printf("\n\nPress 1 to say Can you tell me your name?");
    		printf("\nPress 2 to say Can you give me a sign?");
    		printf("\nPress 3 to say I want to help you. Can you please tell me how? What do you want? What do you need?");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=25;
					break;
				}
				case 2:{
					scenario=26;
					break;
				}
				case 3:{
					scenario=28;
					break;
				}
				default:{
					scenario=27;
					break;
				}
			}
		}
		while(scenario==28); //After pressing 3 on scenario 24 or 27
    	{
    		system("cls");
    		printf("I want to help you. Can you please tell me how? What do you want? What do you need?");
    		printf("\n\n.. you.. hear me?” There is hope tinged in these words.");
    		printf("\n\n--justice. bring us---justice. ----experiments---the scientists---give us justice…");
    		printf("--help. --help. please…---help.");
    		printf("After a if, no other voice comes through the spirit box. The entities have said their peace. \nYou pull out your camera and snap a picture of the entire set-up. It’s not much, \nbut it will do. It’s time to go.");
    		printf("\n\nPress 1 to Exit the mansion");
    		printf("\n\nEnter your Choice here: ");
    		playerChoice=scanPlayerChoice();
    		switch(playerChoice)
    		{
    			case 1:{
    				scenario=30;
					break;
				}
				default:{
					scenario=28;
					break;
				}
			}
		}
		while(scenario==29); //Bad Ending 1
    	{
    		system("cls");
    		printf("You swing out from the side and attempt to bash it over the head with the flashlight.");
    		sleep(3);
    		printf("\nIn those moments, you saw a dead soldier, his stomach carved open, white eyes forever set on you.");
    		sleep(3);
    		printf("\nIt takes you by the neck. It will be the last thing you will ever see…");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==30); //PEACEFUL ENDING
    	{
    		system("cls");
    		printf("Your leave is a peaceful one. Perhaps the entities understood that you were the messenger to their cause.");
    		sleep(3);
    		printf("\nIn those last moments of leaving the mansion, fear did not cling to your senses, but that of melancholiness.");
    		sleep(3);
    		printf("\nAs you exit the way you first entered, the sunrise greets you in the outside world..");
    		sleep(3);
    		printf("\n\nPEACEFUL ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==31); //Bad Ending 2
    	{
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
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==32); //ESCAPE ENDING 1
    	{
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
			printf("You are free...");
			sleep(3);
			printf("\n\nESCAPE ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==33); //Bad Ending 3
    	{
    		system("cls");
    		printf("Something grabs your wrist as you try to take it.");
    		sleep(3);
    		printf("\nYou look to see the thing that has been chasing you this entire time.");
    		sleep(3);
    		printf("\nA dead soldier whose stomach cavity hangs loose and exposed. It screams a guttural sound.");
    		sleep(3);
    		printf("\nThe knife is in your fist but it takes your hand and twists it - then plunges it into your neck.");
    		sleep(3);
    		printf("\nThe sensation of the blade going through your throat is instant.");
    		sleep(3);
    		printf("\nYou cannot breathe. You cannot think. You cannot do anything anymore.");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==34); //Bad Ending 4
    	{
    		system("cls");
    		printf("You turn around and see a face. It sprints towards you at full speed.");
    		sleep(3);
    		printf("\nIt is faster than you are. You cannot outrun it. ");
    		sleep(3);
    		printf("\nIt stretches its hands towards you, and the final thing you hear is the sound of its predatory scream.");
    		sleep(3);
    		printf("\n\nBAD ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==35); //Bad Ending 5
    	{
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
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==36); //ESCAPE ENDING 2
    	{
    		system("cls");
    		printf("You took the door.");
			sleep(3);
			printf("\n\nThe ghost in this forsaken mansion was close to getting you, but not close enough.");
			sleep(3);
			printf("\nYou barge through the large doors and crash into the real world. The sun is rising.");
			sleep(3);
			printf("\nThe outside air is heavenly to breathe. You dare not look back now.");
			sleep(3);
			printf("You run, and you run, and you keep on running…");
			sleep(3);
			printf("\n\nESCAPE ENDING");
    		printf("\n\nPress 1 to try again");
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
		while(scenario==37);
    	{
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
    		printf("\nPress any key to exit");
    		printf("\n\nEnter Choice here: ");
    		scanf("%d",&tryAgain);
    		if(tryAgain==1)
    		{
    			scenario=0;
    			ending=0;
    			tryAgain=0;
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}
int scanPlayerChoice(void) //Prevents the input from registering whenever a character is entered...
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
