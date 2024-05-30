/***************************************************************************
 * Name:                        //Lastname, Firstname [CIS 2101 group #]   *
 * Date: March 11, 2024                                                    *
 *                                                                         *
 *                                                                         *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMPROGRAMS 4
#define YEARLEVELS 4
#define MAXSTUDS 100

//Data Structure Definition
typedef struct{
    char fName[64];
    char mi;
    char lName[32];
}studName;

typedef unsigned char personalInfo;
/*Given 8 bits: 0000 0000
 
 Bits
 8    = Status:            0 - Inactive, 1 - Active
 7    = Nationality:       0 - Filipino, 1 - Foreigner
 6    = Enrollment Status: 0 - Regular, 1 - Irregular
 5    = Gender:            0 - Male, 1 - Female
 3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
 1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH
 
 For example:
 1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
*/

typedef struct{
    char idNum[9];
    studName name;
    personalInfo info;
}student;

typedef struct{
    student studs[MAXSTUDS];
    int numStuds;
}arrListStud;



typedef struct studNode{
    student stud;
    struct studNode* next;
}studNode, *studLL;

typedef studLL studDict[YEARLEVELS];

typedef struct{
    studDict programStuds;
    int studCtr;               /* refers to the total number of students in the PROGRAM. */
}dcismNode;

typedef dcismNode dcismDict[NUMPROGRAMS];

typedef struct{
    char studID[9];
    studName sName;
}studRec;

typedef struct{
    studRec studs[MAXSTUDS];
    int count;
}sNode, *studSet;               /* array representation of a Set of studRecs */

//Function Prototypes
//-----Problem #1 Prototypes-----
arrListStud populateStudentList(void); // Reads the file containing student records and returns student 
                                       //   records to the calling function
                                       // PARTIAL CODE is provided

void generateStudentFile(void);   //Creates a file of student records
char* getProgram(personalInfo I);  //Returns the string equivalent of the program (BSCS, BSIT, BSIS, BSMATH)
                                   //  of the provided personalInfo. 
                                   
int yearLevelHash(personalInfo I);     //Returns the year level 
                                   
void displayArrListStud(arrListStud A); //Displays ID, Complete name, Program (Course) and year

//------Problem #2 Prototypes
void initDCISMDict(dcismDict D);        //Initializes the given dcismDict to be empty
void convertToDCISMDict(dcismDict D, arrListStud SL); //Inserts the LIST of students in arrListStud
                                                      //  to their proper place in the dcismDict
void displayStudLL(studLL SL) ;        // Displays the contents of a given studLL.
                                       // PARTIAL CODE is provided 

void displayDCISMDict(dcismDict D);     //Displays all the students in the dcismDict by program and year level.
                                        // PARTIAL CODE is provided;  Calls displayStudLL().

//------Problem #3 Prototypes

studSet removeInactiveStudents(dcismDict D);   //Given dcismDict D, the function deletes student records
                                               //  that have the status "inactive" and place in an array of studSets
                                               // Deleted students will be stored in proper array of studSets
															  //   based on their program (course).
															  // Array of studSets will be returned to the calling function 
															  		    
void displayStudSets(studSet* S);             // Displays the ID, Firstname and Lastname of inactive students 
                                              //    for each program.														                         
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   0)  CHANGE the name of the file to:  CIS2101_YourlastNameXX.c                  *
                                     XX is the first 2 letters of your firstname    *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/                         
int main(void)
{
   /*-------------------------------------------------------------------------
    * 	Problem #1  :: 1) Populate the list by calling populateStudentList  *
    *                   2) Calls displayArrListStud()                        *
    *------------------------------------------------------------------------*/	
   printf("\n\n\nProblem #1:: ");
   printf("\n------------\n");
    arrListStud A = populateStudentList();
   displayArrListStud(A);
    /*-------------------------------------------------------------------------
    * 	Problem #2  :: 1) Call initDCISMDict()                               *
    *                   2) Call convertToDCISMDict()                          *
    *                   3) Call displayDCISMDict()                            *
	 *-------------------------------------------------------------------------*/	    
   printf("\n\n\nProblem #2:: ");
   printf("\n------------\n");
   dcismDict B;
   initDCISMDict(B);
   convertToDCISMDict(B, A);
   displayDCISMDict(B);
    /*-------------------------------------------------------------------------
    * 	Problem #3  :: 1) Call removeInactiveStudents() passing dcismDict in *
    *                          problem #2                                     *
    *                   2) Call displayDCISMDict(D);                          *
    *                   3) Call displayStudSets(inactive);                    *
	 *-------------------------------------------------------------------------*/	  
    printf("\n\n\nProblem #3:: ");
    printf("\n------------\n");
	studSet C = removeInactiveStudents(B);
	displayDCISMDict(B);
    displayStudSets(&C);
    
    return 0;
}                                  
                                       

/*****************************************************************************************
 *  Functions for Problem # 1                                                            *
 *****************************************************************************************/      
 //-----------------------------------------------------------------------------------------
// populateStudentList(). The function will read a file containing student records and   
// returns the student records to the calling function in the form of an arrListStud..
//
// PARTIAL CODE is provide.
//-----------------------------------------------------------------------------------------
arrListStud populateStudentList(void)
{
    FILE* fp;
    student* studs;
    int dataCount;
    arrListStud A;
    int x;
    A.numStuds = 0;
    if((fp = fopen("students.bin", "rb"))== NULL){
        puts("Unsuccessful in opening students.txt");
    }else{
        fseek(fp, 0, 2);
        dataCount = (int) ftell(fp) / sizeof(student);
        studs = (student*) malloc (sizeof(student) * dataCount);
        if(studs != NULL){
            fseek(fp, 0, 0);
            fread(studs, sizeof(student), dataCount, fp);
        }
        for(x = 0; x < dataCount; x++){
        	A.studs[x] = studs[x];
        	A.numStuds++;
		}
         
         
    }
    
    return A;
}

//-----------------------------------------------------------------------------------------
// getProgram(). Return the string equivalent of the program of the provided personalInfo.
//-----------------------------------------------------------------------------------------
char* getProgram(personalInfo I)
{
  //Write your code here   
  int mask;
  int progBit = 0;
  char *program = "NONE";
  for(mask = 2; mask != 0; mask >>= 1){
  	if(I & mask){
  		progBit += mask;
	}
  }
	switch(progBit){
		case 0:
			program = "CS";
			break;
		case 1:
			program = "IT";
			break;
		case 2:
			program = "IS";
			break;
		case 3:
			program = "MATH";
			break;
			
	}
	return program;
     
     
}

//-----------------------------------------------------------------------------------------
// programHash(). Returns the integer equivalent of the bits that represent a student's program.
//-----------------------------------------------------------------------------------------
int yearLevelHash(personalInfo I)
{
     //Write your code here
     int mask;
     int yrBit = 0;
     int year = 0;
     for(mask = 8; mask != 2; mask >>= 1){
     	if(I & mask){
     		yrBit += mask;
		 }
	 }
	 switch(yrBit){
	 	case 0:
	 		year = 1;
	 		break;
	 	case 4:
	 		year = 2;
	 		break;
	 	case 8:
	 		year = 3;
	 		break;
	 	case 12:
	 		year = 4;
	 		break;
	 }
	 return year;
}



//---------------------------------------------------------------------------------------------
// displayArrListStud(). Displays the ID, Firstname, Lastname, Program (course) and year level.
//  Calls getProgram() and yearLevelHash() to determine the Program and year level.
//
//  PARTIAL CODE is provided
//-----------------------------------------------------------------------------------------
void displayArrListStud(arrListStud A)
{
   int x;
   
   printf("%-10s", "Id Number");
   printf("%-10s", "fName");
   printf("%-10s", "lName");
   printf("%-10s", "Program");      //Program and Year should be included in the display, though
   printf("%-10s", "Year");         //   it is not included in the sample display.
     
   //Write your code here.   
	for(x = 0; x < A.numStuds; x++){
		printf("\n%-10s%-10s%-10s%-10s%-10d", 
		A.studs[x].idNum,
		A.studs[x].name.fName,
		A.studs[x].name.lName,
		getProgram(A.studs[x].info),
		yearLevelHash(A.studs[x].info));
	}
    
    
    
    
}


/*****************************************************************************************
 *  Functions for Problem # 2                                                            *
 *****************************************************************************************/      
//-----------------------------------------------------------------------------------------
// programHash(). Returns the integer equivalent of the bits that represent a student's program.
//-----------------------------------------------------------------------------------------
int programHash(personalInfo I)
{
     //Write your code
       int mask;
  int progBit = 0;
  int hashNum = 0;
  for(mask = 2; mask != 0; mask >>= 1){
  	if(I & mask){
  		progBit += mask;
	}
  }
	hashNum = progBit;
	return hashNum;
}


//-----------------------------------------------------------------------------------------
// insertStudLL(). Inserts into the sorted studSet based on the student's ID number.
//  All elements in the studLL should be unique. The function will return 1 if the insert was successful and 0 if not.
//-----------------------------------------------------------------------------------------

int insertStudLL(studLL* SL, student S)
{
     //Write your code
     studLL *trav, node;
     for(trav = SL; *trav != NULL && strcmp((*trav)->stud.idNum, S.idNum) < 0; trav = &(*trav)->next){}
     if(*trav == NULL || strcmp((*trav)->stud.idNum, S.idNum) != 0){
     	node = (studLL)malloc(sizeof(struct studNode));
     	if(node != NULL){
     		node->stud = S;
     		node->next = *trav;
     		*trav = node;
		 }
	 }
	 return (strcmp((*trav)->stud.idNum, S.idNum) != 0 || node != NULL)? 1 : 0;
}

//-----------------------------------------------------------------------------------------
// displayStudLL(). The function will display the contents of a given studLL.
//-----------------------------------------------------------------------------------------
void displayStudLL(studLL SL)
{   studLL temp;
    if(SL != NULL){
        printf("\nYear %d\n\n", yearLevelHash(SL->stud.info));        //Complete the code and Uncomment
        printf("%-10s", "Id Number");
        printf("%-10s", "fName");
        printf("%-10s", "lName");
        printf("%-10s", "Program");
        printf("%-10s", "Year");
        printf("%-10s", "Gender");
        printf("%-15s", "Enrollment");
        printf("%-15s", "Nationality");
        printf("%-10s\n", "Status");
        
        //Write your code here
        for(temp = SL; temp != NULL; temp = temp->next){
        	printf("\n%-10s%-10s%-10s%-10s%-10d%-10s%-15s%-15s%-10s",
					temp->stud.idNum,
					temp->stud.name.fName,
					temp->stud.name.lName,
					getProgram(temp->stud.info),
					yearLevelHash(temp->stud.info),
					(temp->stud.info & 16)? "Female" : "Male",
					(temp->stud.info & 32)? "Irregular" : "Regular",
					(temp->stud.info & 64)? "Foreigner" : "Filipino",
					(temp->stud.info & 128)? "Active" : "Inactive");
		}
    }
}

//-----------------------------------------------------------------------------------------
// initDCISMDict(). The function will initialize the given  dcismDict to be empty
//-----------------------------------------------------------------------------------------
void initDCISMDict(dcismDict D)
{
     //Write your code here
     int x, y;
     for(x = 0; x < NUMPROGRAMS; x++){
     	D[x].studCtr = 0;
     	for(y = 0; y < YEARLEVELS; y++){
     		D[x].programStuds[y] = NULL;
		 }
	 }
}


//-----------------------------------------------------------------------------------------
// convertToDCISMDict(). The function will go through list of students and insert them to their proper place in the dcismDict.
//-----------------------------------------------------------------------------------------
void convertToDCISMDict(dcismDict D, arrListStud SL)
{
     //Write your code here
     int progHash;
     int yearHash;
     int x;
     for(x = 0; x < SL.numStuds; x++){
     	progHash = programHash(SL.studs[x].info);
     	yearHash = yearLevelHash(SL.studs[x].info) - 1;
     	if(insertStudLL(&D[progHash].programStuds[yearHash], SL.studs[x])){
     		D[progHash].studCtr++;
		}
	 }
}



//-----------------------------------------------------------------------------------------
// displayDCISMDict(). The function will display all the students in the dcismDict by program and year level.
//-----------------------------------------------------------------------------------------
void displayDCISMDict(dcismDict D)
{
    int i, j;
    studLL temp;
    for(i = 0; i < NUMPROGRAMS; i++){
    	printf("\n---------------------------------------------------------------------------------------------------------------\n%s %d Students\n",getProgram(i), D[i].studCtr);  //Complete code and uncomment
		for(j = 0; j < YEARLEVELS; j++){
            displayStudLL(D[i].programStuds[j]);
       	}
        
    }
}

/*****************************************************************************************
 *  Functions for Problem # 3                                                            *
 *****************************************************************************************/      
//-----------------------------------------------------------------------------------------
// initStudSet(). The functions initialize an empty array of studSets that can accommodate the total number of programs.
//-----------------------------------------------------------------------------------------
studSet initStudSet(void)
{
     studSet S;
     S = (studSet)malloc(sizeof(sNode));
     if(S != NULL){
     	S->count = 0;
	 }
     return S;
}


//-----------------------------------------------------------------------------------------
// insertStudSet(). The function will insert the studRec into the studSet. Student will be inserted at the end of the set.
//-----------------------------------------------------------------------------------------
void insertStudSet(studSet S, studRec sRecord)
{
    //Write your code here
    int x;
    if(S->count < MAXSTUDS){
    	for(x = 0; x < S->count && strcmp(S->studs[x].studID, sRecord.studID) != 0; x++){}
    	if(x == S->count){
    		S->studs[S->count++] = sRecord;
		}
	}
}


//-----------------------------------------------------------------------------------------
// removeInactiveStudents(). The function will delete all student records that have the status "inactive".
// Deleted records will be stored in an array of studSets, such that each deleted student will be stored
// in its proper index in the array of studSets based on their program. Return the array of studSets to the calling function.
//-----------------------------------------------------------------------------------------
studSet removeInactiveStudents(dcismDict D)
{
     //Write your code here
     int x, y;
     studLL *trav, node;
     studSet S = initStudSet();
     studRec R;
     for(x = 0; x < NUMPROGRAMS; x++){
     	for(y = 0; y < YEARLEVELS; y++){
     		for(trav = &D[x].programStuds[y]; *trav != NULL;){
     			if(!((*trav)->stud.info & 128)){
     				node = *trav;
     				*trav = (*trav)->next;
     				strcpy(R.studID, node->stud.idNum);
     				R.sName = node->stud.name;
     				insertStudSet(S, R);
     				free(node);
				} else{
					trav = &(*trav)->next;
				}
			 }
		 }
	 }
     return S;
}

 
 
/**********************************************************************************
 *  Displays the ID, Firstname and Lastname of inactive students for each program. *
 **********************************************************************************/
void displayStudSets(studSet* S)
{
     //Write your code 
     int x;
     printf("\n\nInactive Students");
     printf("\n========================================");
     printf("\n%-15s%-15s%-15s", "ID", "Firstname", "Lastname");
     for(x = 0; x < (*S)->count; x++){
     	printf("\n%-15s%-15s%-15s", (*S)->studs[x].studID, (*S)->studs[x].sName.fName, (*S)->studs[x].sName.lName);
	 }
}


