// Nguyen Ngo Huy DHTI15A5HN
//bai3tuan2
#include<iostream>

using namespace std;
class DaThuc3
{
	private:
		int a,b,c,d;
	public:
		DaThuc3()
		{
			(a,b,c,d)=0; 
		}		
		~DaThuc3()
		{
			;
		} 
		friend ostream& operator << (ostream&,DaThuc3);
		friend istream& operator >> (istream&,DaThuc3&);
		void tong(DaThuc3 a,DaThuc3 b); 
}; 
ostream& operator << (ostream& out,DaThuc3 x)
{
	out<<"\n\t\t\tDA THUC CO DANG: "<<x.a<<"x3 + "<<x.b<<"x2 + "<<x.c<<"x + "<<x.d<<endl; 
}
istream& operator >> (istream& in,DaThuc3 &x)
{
	cout<<"nhap bac 3: ";
	in>>x.a;
	cout<<"nhap bac 2: ";
	in>>x.b;
	cout<<"nhap bac 1: ";
	in>>x.c;
	cout<<"nhap ba 0: ";
	cin>>x.d;
	cout<<endl; 
}
void DaThuc3::tong(DaThuc3 u,DaThuc3 v)
{
	DaThuc3 sum;
	sum.a=u.a+v.a;
	sum.b=u.b+v.b;
	sum.c=u.c+v.c;
	sum.d=u.d+v.d; 
	cout<<"\n\t\tTONG CUA HAI DA THUC BAC 3 LA: "<<sum<<endl; 
} 
int main()
{
	DaThuc3 a,b;
	cout<<"\n\t\tNHAP DA THUC THU NHAT\n";
	cin>>a;
	cout<<"\n\t\tNHAP DA THUC THU HAI\n";
	cin>>b;
	cout<<"\n\t\tXUAT DA THUC THU NHAT\n";
	cout<<a;
	cout<<"\n\t\tXUAT DA THUC THU HAI\n"; 
	cout<<b;
	a.tong(a,b); 
	return 0;
}
