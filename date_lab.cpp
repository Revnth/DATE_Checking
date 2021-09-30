#include<iostream>
using namespace std;
class Date 
{
	int d,m,y;
	public:
	void read()
	{
		cout<<"Enter Date (d/m/y)\n";
		cin>>d>>m>>y;
	}
	int check()
	{
		int f=0;
		if(y>1000&&y<4000)
		{
			if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>0&&d<=31)
			{
				cout<<"Valid\n";
				f=1;
			}		
			else if((m==4||m==6||m==9||m==11)&&d>0&&d<31)
			{
				cout<<"Valid\n";
				f=1;
			}
			
			else if(m==2)
			{
				if(y%4==0&&d>0&&d<=29)
				{
					cout<<"Valid\n";
					f=1;
				}
				else if(d>0&&d<29)
				{
					cout<<"Valid\n";
					f=1;
				}
				else
				cout<<"Not Valid\n";
			}
			
			else
			cout<<"Not Valid\n";
		}
		else
		cout<<"Not Valid\n";
		return f;
	}
	Date operator +(int n);
	void show()
	{
		cout<<d<<"/"<<m<<"/"<<y;
	}

	void next()
	{			
		if(m==1||m==3||m==5||m==7||m==8||m==10)
			{
				if(d<31)
				d++;
				else if(d==31)
				{
					m++;
					d=1;
				}
			}
			
			else if(m==4||m==6||m==9||m==11)
			{
				if(d<30)
				d++;
				else if(d==30)
				{
					m++;
					d=1;
				}
			}
			else if(m==2)
			{
				if(y%4==0)
				{
					if(d<29)
					d++;
					else if(d==29)
					{
						m++;
						d=1;
					}
				}
				else 
				{
					if(d<28)
					d++;
					else if(d==28)
					{
						m++;
						d=1;
					}
				}
			}
			else if(m==12)
			{
				if(d<31)
				d++;
				else if(d==31)
				{
					y++;
					m=1;
					d=1;
				}
			}
		
		}
};

Date Date::operator +(int n)
	{
		Date r;
		r.d=d;
		r.m=m;
		r.y=y;
		for(int i=0;i<n;i++)
		{
			r.next();
		}
		return r;
	}
int main()
{
	int f=1,n;
	Date d;
	d.read();
	f=d.check();
	if(f==1)
	{
		cout<<"Number of days to be added:";
		cin>>n;
		Date q=d+n;
		q.show();
	}
	return 0;
}
