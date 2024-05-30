int findElem(int A[], int N, int X)
{
int ndx, j;
j = 0;
for(ndx = 0; ndx < N; ndx++)
{
if(A[ndx] == X)
 {
 j++;
 }
}

return j;
}
