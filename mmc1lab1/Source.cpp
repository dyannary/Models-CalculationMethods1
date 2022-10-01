#include <iostream>
#include <math.h>
#include <iomanip>
#include <windows.h>

using namespace std;

void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

double fx(double x)
{
	return log10(3 * x) + x - 2; //v21a
	//return x * x * x - 25 * x + 2; //v21b
}

void bisectionMethod()  // The Bisecton Method
{
	int a = -100, b;
	double epsilon = pow(10, -4);
	int k = 0;
	double c, d, x;
	int roots = 0;
	cout << setw(25); 
	cout << endl << "\t\t ";  setcolor(2); cout << " The Bisection Method "; setcolor(15); cout << " \t  " << endl;
	cout << "\t\t\t";
	while (roots != 1)
	{
		//if (a == 0) { a++; continue; }

		b = a + 1;
		double fx1 = fx(a);
		if (!fx1) {
			cout << "\t\t\t\t    On the interval [" << a << ", " << a + 1 << "] we found\t ";
			cout << "\t\t\t Root " << ++roots << " : " << fixed << "when x = " << a << " f(x) = " << fx1 << "\t ";
			a++;
			break;
		}
		double fx2 = fx(b);

		if ((fx1 > 0 && fx2 < 0) || (fx1 < 0 && fx2 > 0))
		{
			roots++;
			cout << "\n\t\t\t\t    On the interval [" << a << ", " << (a + 1) << "] we found: \t ";
			c = a;
			if (fx1 < 0) c = b;
			d = a + b - c;
			k = 0;

			while (abs(c - d) > epsilon)
			{
				x = c + (d - c) / 2;
				k++;
				fx1 = fx(x);
				if (fx1 == 0) break;
				if (fx1 > 0) c = x;
				else d = x;
			}
			cout << "\n\t\t\t Root " << roots << " : " << fixed << "when x = " << d << " f(x) = " << fx1  << endl;
		}
		a++;
	}
	cout << "\t\t\t";
	cout << endl;
}

void succesiveApproximations()  // The method of successive approximations
{
	double eps = pow(10, -4);
	double a = 1;
	double b = 2;
	double e, x, xnew, xprev;

	x = a - fx(a) / (fx(b) - fx(a)) * (b - a);
	if (fx(x) * fx(a) > 0)
	{
		e = b;
		xnew = a;
	}
	else
	{
		e = a;
		xnew = b;
	}
	cout << "\n\n\t\t\t";
	cout << endl << "\t\t\t\t";  setcolor(2); cout << "The Method of Successive Approximations "; setcolor(15); cout << " \t  " << endl;
	cout << "\t\t\t";


	if (fx(0) == 0)
	{
		cout << "\n\t\t\t\t x = " << fixed << 0 << setw(12) << " f(x) = " << fx(0) << " \t\t \n";
	}

	do
	{
		xprev = xnew;
		xnew = xprev - fx(xprev) / (fx(e) - fx(xprev)) * (e - xprev);
		if (xnew < 0)
			cout << "\n\t\t\t\t x = " << fixed << xnew << " f(x) = " << fx(xnew) << " \t\t ";
		else
			cout << "\n\t\t\t\t x = " << fixed << xnew << " f(x) = " << fx(xnew) << " \t\t ";
	} while (abs(xnew - xprev) > eps);


	cout << "\n\t\t\t";
	cout << endl << endl;
}

double derivative(double x)
{
	//return 3 / 3 * x * log(10); //v21a
	return 2 * x - 25; //v21b
}

void methodNewton()
{
	double a, b, x, c;

	int i, n;

	// la v21a : 1 2
	// la v21b : -5.5 -1
	a = -4.2; 
	b = 0.2; 


	n = 10;
	i = 0;
	c = a - fx(a) / (fx(b) - fx(a)) * (b - a);
	if (fx(c) * fx(a) > 0) x = a;
	else x = b;

	cout << "\n\t\t\t";
	cout << endl << "\t\t\t"; setcolor(2); cout << " \t\t\  Newton's Method "; setcolor(15); cout << " \t\t  ";
	cout << "\n\t\t\t";
	cout << endl;

	if (fx(0) == 0)
	{
		cout << left << "\t\t\t     i = " << setw(2) << i << " x = " << setw(12) << 0 << " f(x) = " << setw(12) << fx(0) << " \t \n" << endl;
	}

	while (i < n)
	{
		i = i + 1;
		x = x - fx(x) / derivative(x);

		cout << left << "\t\t\t     i = " << setw(2) << i << " x = " << setw(12) << x << " f(x) = " << setw(12) << fx(x) << " \t " << endl;
	}

	cout << "\t\t\t";
	cout << endl << endl << endl << endl;
}

int main()
{
	bisectionMethod();
	succesiveApproximations();
	methodNewton();

	return 0;
}

