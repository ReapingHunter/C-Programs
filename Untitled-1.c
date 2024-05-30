

float input()
{
  float n;
  scanf("%f",&n);
  return n;
}

void display(float n1, float n2, char ch, float result)
{
  printf("%.2f %c %.2f = %.2f\n", n1, ch, n2, result);
}

void add(int n1, float n2)
{
  float result;
  result = n1 + n2;
  display(n1, n2, '+', result);
}

void subtract(float n1, float n2)
{
  float result;
  result = n1 - n2;
  display(n1, n2, '-', result);
}

void multiply(float n1, float n2)
{
  float result;
  result = n1 * n2;
  display(n1, n2, '*', result);
}

void divide(float n1, float n2)
{
  float result;
  result = n1 / n2;
  display(n1, n2, '/', result);
}

int main()
{
  char ch;
  int choice;
  float n1, n2;
  do
  {
    printf("Enter first number: ");
    n1 = input();
    printf("Enter second number: ");
    n2 = input();
     
    printf("\nWhich operation you want to perform,\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
     
    switch (choice) {
      case 1:
        add(n1, n2);
        break;
      case 2:
        subtract(n1, n2);
        break;
      case 3:
        multiply(n1, n2);
        break;
      case 4:
        divide(n1, n2);
        break;
      default:
        printf("Invalid choice");
    }

    printf("\nDo you want to continue (y/n): ");
    scanf("%c",&ch);
    scanf("%c",&ch);
    printf("***************************************\n");

  } while(ch=='y');

  printf("\nThank You.");
  return 0;
}
