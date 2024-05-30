int toBinary(double num);
int toDecimal(int num, int rem);
int main()
{
	int num = 123;
	int test = 0;
	int rem;
	int testNum;
	int k;
	for(testNum = num; testNum != 0; testNum /= 10)
	{
		rem = testNum % 10;
		if(rem > 1)
		{
			test = 1;
			break;
		}
		else
		{
			continue;
		}
	}
	if(test == 1)
	{
		num = toBinary(num);
		num = toDecimal(num, rem);
	}
	else
	{
		num = toDecimal(num, rem);
		num = toBinary(num);
	}
	return 0;
}
int toBinary(double num)
{
    int countNum = num;
    int mult = 1;
    num = 0;
    while(countNum != 0)
    {
    	if(countNum % 2 == 1)
    	{
    		num += 1;
    		num /= 10;
		}
		else
		{
			num /= 10;
		}
		mult *= 10;
		countNum /= 2;
	}
	num *= mult;
    return (int)num;
}
int toDecimal(int num, int rem)
{
	int decimal;
	int sum;
	int mult = 1;
	do
	{
		rem = num % 10;
        sum = rem * mult;
		mult *= 2;
		num /= 10;
		decimal += sum;
	}while(num != 0);
	return decimal;
}
