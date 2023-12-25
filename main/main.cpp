#include <cmath>
#include <iostream>
using namespace std;

typedef double (*fptr)(double);
typedef double (*xfptr)(double);

/* Задача 1 */
void initials(string surname = "not defined", string name = "", string last_name = "")
{
	cout << "Your name is " << surname << ' ' << name << ' ' << last_name << endl;
}

/* Задача 2 */
int FindElements(int k, ...)
{
	int count = 0, *p = &k;
	for (; k != 0; k--) {
		if (*(++p) % 2 == 0)
			count += 1;
	}
	return count;
}

/* Задача 3 */
int binSearch(int arr[], int item, int len)
{
	int mid, low = 0, high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return item;
		if (arr[mid] > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return NULL;
}

double binSearch(double arr[], double item, int len)
{
	int mid, low = 0, high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return item;
		if (arr[mid] > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return NULL;
}

char binSearch(char arr[], char item, int len)
{
	int mid, low = 0, high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return item;
		if (arr[mid] > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return NULL;
}

/* Задача 4 */
template <class Arr, class Item, class I>
Item binSearchTemplate(Arr arr, Item item, I len)
{
	int mid, low = 0, high = len - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return item;
		if (arr[mid] > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return NULL;
}

/* Задача 5 */
double func(double x)
{
	return exp(x) - exp(-x) - 2.0;
}

double diff1(double x0)
{
	return exp(x0) + exp(-x0);
}

double diff2(double x0)
{
	return exp(x0) - exp(-x0);
}

double half_division(fptr f, double a, double b)
{
	double xn = (a + b) / 2, eps = 0.000001;
	while (((*f)(xn) != 0) && (abs(a - b) > eps)){
		if (((*f)(xn) < 0 && (*f)(a) > 0) || ((*f)(xn) > 0 && (*f)(a) < 0)){
			b = xn;
		}
		else{
			a = xn;
		}
		xn = (a+b)/2;
	}
	return xn;
}

double Newton(fptr f, double a, double b)
{
	double eps = 0.000001;
	double xn, xn1;

	if ((*f)(b)*diff2(b) > 0.0)
		xn1 = b;
	else
		xn1 = a;
	xn = xn1 - ((*f)(xn1) / diff1(xn1));

	while (abs(xn - xn1) > eps) {
		xn1 = xn;
		xn = xn1 - ((*f)(xn1) / diff1(xn1));
	}
	return xn;
}

double xfunc(double x)
{
	return log(exp(-x)+2);
}

double iterations(xfptr f, double a, double b)
{
	double xn1 = b, temp, xn, eps = 0.000001;
	xn = (*f)(xn1);
	while (abs(xn - xn1) > eps) {
		xn1 = xn;
		xn = (*f)(xn1);
	}
	return xn;
}

void InitialsTests()
{
	initials("Surname", "Name", "Last name"); // Параметры заданы явно
	initials();								  // Параметры опущены
	initials("Surname", "Name");			  // Параметры заданы частично
}

void FindElementsTest()
{
	cout << FindElements(4, 1, 2, 3, 5) << endl;			 // 1
	cout << FindElements(2, 2, 4) << endl;					 // 2
	cout << FindElements(8, 1, 8, 6, 4, 2, 3, 4, 5) << endl; // 5
}

void BinSearchTest()
{
	int intarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int intitem = 3;
	int intlen = 10;
	cout << "searching for " << intitem << " in " << intarr << endl;
	cout << "Found: " << binSearch(intarr, intitem, intlen) << endl;

	double doublearr[] = {1.52, 3.0, 4.53, 8.12, 9.12, 10.10, 15.122, 15.123, 18.18, 20.20, 21.21, 25.25};
	double doubleitem = 15.123;
	int doublelen = 12;
	cout << "searching for " << doubleitem << " in " << doublearr << endl;
	cout << "Found: " << binSearch(doublearr, doubleitem, doublelen) << endl;

	char stringarr[] = "abcdefghijklmnopqrstuvwxyz";
	char charitem = 's';
	int charlen = 42;
	cout << "searching for " << charitem << " in " << stringarr << endl;
	cout << "Found: " << binSearch(stringarr, charitem, charlen) << endl;
}

void BinSearchTemplateTest()
{
	int intarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int intitem = 3;
	int intlen = 10;
	cout << "searching for " << intitem << " in " << intarr << endl;
	cout << "Found: " << binSearchTemplate(intarr, intitem, intlen) << endl;

	double doublearr[] = {1.52, 3.0, 4.53, 8.12, 9.12, 10.10, 15.122, 15.123, 18.18, 20.20, 21.21, 25.25};
	double doubleitem = 15.123;
	int doublelen = 12;
	cout << "searching for " << doubleitem << " in " << doublearr << endl;
	cout << "Found: " << binSearchTemplate(doublearr, doubleitem, doublelen) << endl;

	char stringarr[] = "abcdefghijklmnopqrstuvwxyz";
	char charitem = 's';
	int charlen = 42;
	cout << "searching for " << charitem << " in " << stringarr << endl;
	cout << "Found: " << binSearchTemplate(stringarr, charitem, charlen) << endl;
}

void FunctionsTest()
{
	cout << "Half-division:" << endl;
	cout << "X = " << half_division(func, 0.0, 1.0) << endl;
	cout << "Newton:" << endl;
	cout << "X = " << Newton(func, 0.0, 1.0) << endl;
	cout << "Iteratons:" << endl;
	cout << "X = " << iterations(xfunc, 0.0, 1.0) << endl;
}

int main()
{
	cout << "------------------------------Task1---------------------------------" << endl;
	InitialsTests();
	cout << "------------------------------Task2---------------------------------" << endl;
	FindElementsTest();
	cout << "------------------------------Task3---------------------------------" << endl;
	BinSearchTest();
	cout << "------------------------------Task4---------------------------------" << endl;
	BinSearchTemplateTest();
	cout << "------------------------------Task5---------------------------------" << endl;
	FunctionsTest();
	return 0;
}
