#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Title Deed structure
typedef struct {
	int id;
	char name[20];
	char color[20];
	double amount[9]; 			// rent lot but empty, 1, 2, 3, 4, hotel, mortgage, house cost, hotel cost (house cost * 5) 
	int houseCount;				// will be used only if players owns already the property
	int hotelCount;				// will be used only if players owns already the property
	int mortgage;				// will be used only if players owns already the property and value is 1 - under mortgage, 0 - not in mortgage 
} TitleDeed;

typedef struct {
	char cardType[20];
	char cardDescription[100];
} Card, Cards[16];

// Used to store Title Deeds in a linkled list 
typedef struct prop {
	TitleDeed lot;
	struct prop *next;
} Prop, *PropLList, *SortedPropLList;

// Used to store Title Deeds in an array list 
typedef struct {
	TitleDeed *lot;
	int count;
	int max;
} PropAList, SortedPropAList;

// Player structure
typedef struct {
	int id;
	SortedPropLList owned;		// initially empty but insertSorted when adding ownership to a title deed based on id
	int moneyCount[7];			// 2pcs-$500, 2pcs-$100, 2pcs-$50, 6pcs-$20, 5pcs-$10, 5pcs-$5, 5pcs-$1
	double totalMoney;			// $1500
	int position;				// current position in board starts at 0
} Player;

// GameBoard structure
typedef struct {
	PropLList ownedBank;		// the collection of title deeds not yet owned by a player
	int boardLot[40];			// compromises the lot area
	int moneyCount[7];			// 30pcs-$500, 30pcs-$100, 30pcs-$50, 30pcs-$20, 30pcs-$10, 30pcs-$5, 30pcs-$1
	double totalMoney;			// $20580
	Player players[8];			// players of the game
	int playerCount;			// current count of players
	int houseCount;				// 32 houses
	int hotelCount;				// 12 hotels
	Cards chance;				// chance cards
	int currChanceTop;			// initially starts at 0 then moves once the player lands a chance lot
	Cards communityChest;		// commmunity chest cards
	int currCommunityChestTop;	// initially starts at 0 then moves once the player lands a community chest lot
	int dice[2];				// will contain the dice values (0 for the dice 1 and 1 for dice 2)
} GameBoard;

//	> 0 special(-1 community chest, -2 chance, -3 free parking, -4 income tax, -5 jail, -6 electric company, -7 water works, -8 road 1, -9 road 2, -10 road 3, -11 road 4, -12)
//  0 owned by bank, id of the player if lot is owned by a player
//  initial value of board lot 0, *0, -1, *0, -4, -8, !0, -2, !0, !0, -5, *0, -6, *0, *0, -9, !0, -1, !0, !0, -3, *0, -2, *0, *0, -10, !0, !0, -7, !0, -12, *0, *0, -1, *0, -11, -2, !0, -4, !0

// must implement

bool acquireProperty(GameBoard * board, int player_id, int property_id);

// place the other function prototypes needed

GameBoard G;
FILE *fp;
void initGameBoard(GameBoard *board);
bool addPlayer(GameBoard *board, int player_id);
void initOwnedBank(GameBoard *G, TitleDeed T);
PropAList readTitleDeed(FILE *filename, PropAList titles);
void insertOwnedBank(PropLList *L, TitleDeed T);
void deleteOwnedBank(PropLList *L, TitleDeed T);
void insertSorted(SortedPropLList *L, TitleDeed T);
void displayPropLList(PropLList L);
void displaySortedPropLList(SortedPropLList L);

int main(int argc, char *argv[]) {
	initGameBoard(&G);
	addPlayer(&G, 20103264);
	addPlayer(&G, 1);
	addPlayer(&G, 2);
	acquireProperty(&G, 20103264, 6);
	acquireProperty(&G, 20103264, 18);
	acquireProperty(&G, 20103264, 29);
	acquireProperty(&G, 20103264, 8);
	acquireProperty(&G, 20103264, 6);
	acquireProperty(&G, 20103264, 6);
	acquireProperty(&G, 20103264, 6);
	acquireProperty(&G, 20103264, 6);
	acquireProperty(&G, 1, 6);
	acquireProperty(&G, 1, 9);
	acquireProperty(&G, 1, 19);
	acquireProperty(&G, 1, 19);
	acquireProperty(&G, 1, 26);
	acquireProperty(&G, 1, 26);
	acquireProperty(&G, 2, 9);
	acquireProperty(&G, 2, 13);
	acquireProperty(&G, 2, 14);
	acquireProperty(&G, 2, 39);
	acquireProperty(&G, 2, 39);
	acquireProperty(&G, 2, 24);
	acquireProperty(&G, 20103264, 39);
	displayPropLList(G.ownedBank);
	printf("%lf\n",G.players[0].totalMoney);
	printf("%lf\n",G.players[1].totalMoney);
	printf("%lf\n",G.players[2].totalMoney);
	return 0;
}

PropAList readTitleDeed(FILE *filename, PropAList titles) {
	// To do code logic for readTitles from file.
	int i;
	filename = fopen("titledeed.cis","rb");
	titles.lot = (TitleDeed*)malloc(sizeof(TitleDeed)*22);
	for(i = 0; i < 22; i++){
		fread(&titles.lot[i], sizeof(TitleDeed),1, filename);
	}
	return titles;
}

void initGameBoard(GameBoard *board){
	int i;
	int road = -8;
	PropAList titles = readTitleDeed(fp, titles);
	for(i = 0; i < 40; i++) {
		board->boardLot[i] = 0;
	}
	board->boardLot[20] = -3;
	board->boardLot[4] = -4;
	board->boardLot[10] = -5;
	board->boardLot[12] = -6;
	board->boardLot[28] = -7;
	board->boardLot[30] = -12;
	for(i = 0; i < 40; i++){
		if(i == 5 || i == 15 || i == 25){
			board->boardLot[i] = road--;
		}
		else if(i == 2 || i == 17 || i == 33){
			board->boardLot[i] = -1;
		}
		else if(i == 7 || i == 36){
			board->boardLot[i] = -2;
		}	
	}
	board->moneyCount[0] = 500 * 30;
	board->moneyCount[1] = 100 * 30;
	board->moneyCount[2] = 50 * 30;
	board->moneyCount[3] = 20 * 30;
	board->moneyCount[4] = 10 * 30;
	board->moneyCount[5] = 5 * 30;
	board->moneyCount[6] = 1 * 30;
	board->houseCount = 32;
	board->hotelCount = 12;
	for(i = 0; i < 22; i++) {
		insertOwnedBank(&(board->ownedBank), titles.lot[i]);
	}
	board->playerCount = 0;
	board->totalMoney = 20580;
	board->currCommunityChestTop = 0;
}

bool addPlayer(GameBoard *board, int player_id) {
	if(board->playerCount < 8) {
		board->moneyCount[0] -= 500 * 2;
		board->moneyCount[1] -= 100 * 2;
		board->moneyCount[2] -= 50 * 2;
		board->moneyCount[3] -= 20 * 6;
		board->moneyCount[4] -= 10 * 5;
		board->moneyCount[5] -= 5 * 5;
		board->moneyCount[6] -= 1 * 5;
		
		board->players[board->playerCount].moneyCount[0] = 500 * 2;
		board->players[board->playerCount].moneyCount[1] = 100 * 2;
		board->players[board->playerCount].moneyCount[2] = 50 * 2;
		board->players[board->playerCount].moneyCount[3] = 20 * 6;
		board->players[board->playerCount].moneyCount[4] = 10 * 5;
		board->players[board->playerCount].moneyCount[5] = 5 * 5;
		board->players[board->playerCount].moneyCount[6] = 1 * 5;
		board->players[board->playerCount].position = 0;
		board->players[board->playerCount].totalMoney = 1500;
		board->players[board->playerCount].owned = NULL;
		board->players[board->playerCount++].id = player_id;
	}
		
}

bool acquireProperty(GameBoard *board, int player_id, int property_id) {
	int x;
	int y;
	int found = 0;
	PropLList scan;
	SortedPropLList scan2;
	SortedPropLList scan3;
	for(x = 0; x < board->playerCount && board->players[x].id != player_id; x++){}
	if(x != board->playerCount) {
		// Breaks if property is owned by bank
		for(scan = board->ownedBank; scan != NULL && scan->lot.id != property_id; scan = scan->next){} 
		
		// Breaks if property is owned by player with given id
		for(scan2 = board->players[x].owned; scan2 != NULL && scan2->lot.id != property_id; scan2 = scan2->next){} 
		
		if(scan != NULL) {
			if(board->players[x].totalMoney >= scan->lot.amount[0]) {
				insertSorted(&(board->players[x].owned), scan->lot);
				deleteOwnedBank(&(board->ownedBank), scan->lot);
				board->players[x].totalMoney -= scan->lot.amount[0];
				board->totalMoney += scan->lot.amount[0];
				scan->lot.houseCount = 0;
				scan->lot.hotelCount = 0;
				scan->lot.mortgage =  0;
			}
		} else if(scan2 != NULL) {
			if(scan2->lot.houseCount < 4 && board->players[x].totalMoney >= scan2->lot.amount[7] && scan2->lot.hotelCount != 1) {
				scan2->lot.houseCount += 1;
				board->houseCount -= 1;
				board->players[x].totalMoney -= scan2->lot.amount[7];
				board->totalMoney += scan2->lot.amount[7];
			} else if(scan2->lot.houseCount == 4 && board->players[x].totalMoney >= scan2->lot.amount[8] && scan2->lot.hotelCount != 1) {
				scan2->lot.houseCount = 0;
				scan2->lot.hotelCount = 1;
				board->hotelCount -= 1;
				board->players[x].totalMoney -= scan2->lot.amount[8];
				board->totalMoney += scan2->lot.amount[8];
			}
		} else {
			for(y = 0; y < board->playerCount && found != 1; y++) {
				for(scan3 = board->players[y].owned; scan3 != NULL && scan3->lot.id != property_id; scan3 = scan3->next){}
				found = (scan3 != NULL)? 1 : 0;
			}
			if(found) {
				if(scan3->lot.houseCount == 0 && scan3->lot.hotelCount == 0 && board->players[x].totalMoney >= scan3->lot.amount[0] * 3) {
					insertSorted(&(board->players[x].owned), scan3->lot);
					board->players[x].totalMoney -= scan3->lot.amount[0] * 3;
					board->totalMoney += scan3->lot.amount[0] * 3;
				} else if(scan3->lot.houseCount > 0 && board->players[x].totalMoney >= scan3->lot.amount[scan3->lot.houseCount] * 3) {
					insertSorted(&(board->players[x].owned), scan3->lot);
					board->players[x].totalMoney -= scan3->lot.amount[scan3->lot.houseCount] * 3;
					board->totalMoney += scan3->lot.amount[scan3->lot.houseCount] * 3;
				} else if(scan3->lot.hotelCount == 1 && board->players[x].totalMoney >= scan3->lot.amount[5] * 3) {
					insertSorted(&(board->players[x].owned), scan3->lot);
					board->players[x].totalMoney -= scan3->lot.amount[5] * 3;
					board->totalMoney += scan3->lot.amount[5] * 3;
				}
			}
		}
	}
	
}

void insertOwnedBank(PropLList *L, TitleDeed T) {
	PropLList *current, node;
	node = (PropLList)malloc(sizeof(struct prop));
	for(current = L; *current != NULL; current = &(*current)->next){}
	node->lot = T;
	node->next = *current;
	*current = node;
	
}

void deleteOwnedBank(PropLList *L, TitleDeed T) {
	PropLList *current, node;
	for(current = L; *current != NULL && (*current)->lot.id != T.id; current = &(*current)->next){}
	node = *current;
	*current = (*current)->next;
	free(node);
}

void insertSorted(SortedPropLList *L, TitleDeed T) {
	SortedPropLList *current, node;
	node = (SortedPropLList)malloc(sizeof(struct prop));
	for(current = L; *current != NULL && (*current)->lot.id < T.id; current = &(*current)->next){}
	node->lot = T;
	node->next = *current;
	*current = node;
}

void displayPropLList(PropLList L) {
	PropLList current;
	for(current = L; current != NULL; current = current->next) {
		printf("%2d - %30s - %15s\n", current->lot.id, current->lot.name, current->lot.color);
	}
	
}

void displaySortedPropLList(SortedPropLList L) {
	SortedPropLList current;
	for(current = L; current != NULL; current = current->next) {
		printf("%2d - %30s - %15s\n", current->lot.id, current->lot.name, current->lot.color);
	}
	
}



