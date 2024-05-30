int findElem(int A[], int N, int X);




int main()
{
	int N;
	int A[2] = {1,2};
    int X;
    X = 2;
    findElem(A, N, X);
}


int findElem(int A[], int N, int X)
{
    for(N = 0; N<1; N++)
    {
    	if(A[N] == 2)
        {
            X = 1;
            break;
        }
        else
        {
            X = 0;
        }
	}
    return X;
}
