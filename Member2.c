/**********************************************************************
* Group No. : F                                                       *
* Member No : 2                                                       *
* Name : Marlex Lance A. Manalili                                     *
*                                                                     *
* Module Description: This module consists of the ff. functions:      *
* a) LCD()                                                            *
* b) GCF()                                                            *
*                                                                     *
***********************************************************************/
int GCF(int x, int y)
{
	int GCF;
	int lesserNum;
	int count;
	lesserNum = (x<y)? x : y;
	for(count = 1; count <= lesserNum; count++)
	{
		if(x % count == 0 && y % count == 0)
		{
		    GCF = count;
		}
	}
	return GCF;
}
int LCD(int x, int y)
{
	int LCD;
	int fact;
	LCD = (x>y)? x : y;
	for(fact = 1; fact != 0; LCD++)
	{
		if(LCD % x == 0 && LCD % y == 0)
		{
			fact = 0;
			return LCD;
		}
	}
}
