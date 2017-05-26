#include<iostream>		
#include<cstdlib>
#include<climits>

#define MAX 1000000000000000000

using namespace std;

enum Month {Jan=0, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} ;
enum Day {Mon=0, Tue, Wed, Thu, Fri, Sat, Sun} ;

class month
{
	public :
		Day d;
} ;

class Year
{
	public :
		long long N;
		month m[12];
		bool leap;
} ;

void Ask(long long&,int&);
void Calc_first_day(long long,int&);
Year Make(long long,int);
void Show(Year,int);

int main()
{
	long long n;
	Year y;
	int m0, d1=0 ;
	Ask(n,m0) ;
	Calc_first_day(n,d1) ;
	y = Make(n,d1) ;
	Show(y,m0);	
	cin.get();
	cin.get();
}

void Ask(long long &n1,int &m1)
{
	system("cls");
	cout<<"CALENDAR"<<endl<<endl;
	cout<<"Enter the year 1-"<<MAX<<endl ;
	cin>>n1;
	while (n1>MAX || n1<1)
	{
		cout<<"Year can only be between 1 and "<<MAX<<endl;
		cout<<"Try again"<<endl;
		cin>>n1;
	}
	cout<<"Enter month (1 for January, 2 for February, 3 for March, and so on)"<<endl ;
	cin>>m1 ;
	while ( m1<1 || m1>12 )
	{
		cout<<"Month can be between 1 and 12 only"<<endl<<"Try again"<<endl ;
		cin>>m1 ;
	}
	m1-- ;
}

void Calc_first_day(long long n1, int &dd)
{
	dd = ( dd + (n1-1)%7 + ((n1-1)/4)%7 - ((n1-1)/100)%7 + ((n1-1)/400)%7 )%7 ;
}
	
Year Make(long long n1, int f1)
{
	int NO_OF_DAYS[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	int d1 = f1;
	Year y1;
	y1.N = n1;
	y1.leap = false ;
	
	if ( (n1%4)==0 )		y1.leap = true ;
	if ( (n1%100)==0 )		y1.leap = false ;
	if ( (n1%400)==0 )		y1.leap = true ;
	
	if (y1.leap)
		NO_OF_DAYS[1] = 29 ;
	y1.m[0].d = Day(f1) ;
	for (int j=1; j<12; j++)
	{
		f1 = (d1+(NO_OF_DAYS[j-1]%7))%7 ;
		y1.m[j].d = Day(f1) ;
		d1 = y1.m[j].d ;
	}
	return y1 ;
}

void Show(Year y1, int mon)
{
	system("cls");
	int no_of_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	int i,pos ;
	cout<<"\t\t"<<y1.N<<" - " ;
	switch (mon)
	{
		case 0: cout<<"January"; break;
		case 1: cout<<"February"; break;
		case 2: cout<<"March"; break;
		case 3: cout<<"April"; break;
		case 4: cout<<"May"; break;
		case 5: cout<<"June"; break;
		case 6: cout<<"July"; break;
		case 7: cout<<"August"; break;
		case 8: cout<<"September"; break;
		case 9: cout<<"October"; break;
		case 10: cout<<"November"; break;
		case 11: cout<<"December"; break;
	}
	cout<<endl<<endl<<"Mon     Tue     Wed     Thu     Fri     Sat     Sun"<<endl;
	cout<<" ";
	pos = 0;
	for (i=0; i<y1.m[mon].d; i++)
	{
		if (pos>6)
		{
			cout<<endl;
			pos=0 ;
		}
		cout<<"        " ;
		pos++;
	}
	if ( y1.leap == true)   no_of_days[1] = 29;
	else						 no_of_days[1] = 28;
	for (i=1; i<=no_of_days[mon]; i++)
	{
		cout<<i ;
		if (pos<6)
		{
			if (i<10)	cout<<"       " ;
			else		cout<<"      " ;
		
			pos++ ;
		}
		else
		{
			cout<<endl<<" " ;
			pos = 0 ;
		}
	}
}
