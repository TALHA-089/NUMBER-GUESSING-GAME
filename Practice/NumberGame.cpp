#include<iostream>
#include<string>
#include<math.h>
#include<limits>
using namespace std;
bool isPrime( int n)
{
	if (n <= 1)
	{
		return false; 
	}

	int sqrtN = sqrt(n); 

	for (int i = 2; i <= sqrtN; i++)
	{
		if (n % i == 0) 
		{
			return false; 
		}
	}

	return true; 
}
bool isValidInput()
{
	if (cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		return false;
	}
	return true;
}
int main()
{
	char choice,hint,count=1;
	cout << "\nNUMBER GUESSING GAME.";
	cout << "\n\nMAIN MENU\n\n1.START (S)\n\n2.QUIT (Q)";
	cout << "\n\nEnter your choice: ";
	cin >> choice;
	while(choice == 'S' || choice == 's')
	{
		int n,guess,lives=7;
		srand(time(0));
		n = rand() % 100+1;
		do {
			cout << "\n\nYou have " << lives << " lives left";
			cout << "\n\nEnter Your Guess: ";
			cin >> guess;
			if(isValidInput())
			{
			if (guess == n)
			{
				cout << "\n\nYou Win!!!";
				break;
			}
			else
			{
				cout << "\n\nWrong Guess!!!";
				lives--;
				cout << "\n\nDO YOU WANT A HINT (Y)? ";
				cin >> hint;
				if (hint == 'Y' || hint == 'y')
				{
					if (count <= 3)
					{
						if (count == 1)
						{
							if (isPrime(n))
							{
								cout << "\n\n1.It is a Prime Number";
							}
							else
							{
								cout << "\n\n1.It is a Composite Number";
							}
							count++;
						}
						else if (count == 2)
						{
							if (n % 2 == 0)
							{
								cout << "\n\n2.It is an Even Number";
							}
							else
							{
								cout << "\n\n2.It is an Odd Number";
							}
							count++;
						}
						else if (count == 3)
						{
							int k = n - 10;
							int l = n + 10;
							cout << "\nThe Number is between " << k << " and " << l;
						}
					}
					else
					{
						cout << "\n\nNo More hints left";
					}

				}
				if (lives == 0)
				{
					cout << "\n\nYou Lost!!!";
					break;
				}
			}
			}
			else
			{
				cout << "\n\nEnter a Numeric Value";
				lives--;
			}

		}while(lives!=0);
		cout << "\n\nEnter (S) if you want to Continue Playing ?";
		cin >> choice;
	}
	cout << "\n\nGOODBYE";
	cout << endl << endl;
	system("pause");
	return 0;
}
