//Nguyen Ngo Huy DHTI15A5HN
//bai1tuan2
#include<iostream>  
#include<iomanip>
#include<cstdio>
#include<string.h>

using namespace std;
struct NS
{
	int ngay,thang,nam;
	NS()
	{
		(ngay,thang,nam)=0;
	}	
	~NS()
	{
		;
	}
};
class KH
{
	private:
		char ho_ten[30];
		NS ns;
		char cmt[10];
		char ho_khau[50];
	public:
	friend ostream& operator << (ostream&,KH);
	friend istream& operator >> (istream&,KH&);
	void nhap_ds(KH a[],int &n);
	void xuat_ds(KH a[],int n);
	bool operator > (KH a);
	void sap_xep(KH a[],int &n);
	void thang_12(KH a[],int n);		
};
ostream& operator << (ostream& out,KH a)
{
	out<<"|"<<setw(20)<<a.ho_ten
	   <<"|  "<<setw(2)<<a.ns.ngay<<"/"<<setw(2)<<a.ns.thang<<"/"<<setw(4)<<a.ns.nam<<"   "
	   <<"|"<<setw(15)<<a.cmt
	   <<"|"<<setw(20)<<a.ho_khau
	   <<"|"<<endl;
	   
	return out;   
}
istream& operator >> (istream& in,KH &a)
{
	fflush(stdin);
	cout<<"nhap ho va ten: ";
	in.getline(a.ho_ten,30);
	
	cout<<"\tnhap ngay thang nam sinh\n";
	cout<<"nhap ngay: ";
	in>>a.ns.ngay;
	while(a.ns.ngay < 1 || a.ns.ngay > 31)
	{
		cout<<"nhap lai ngay: ";
		cin>>a.ns.ngay;
	}
	cout<<"nhap thang: ";
	in>>a.ns.thang;
	while(a.ns.ngay < 31 && (a.ns.thang == 2 || a.ns.thang == 4 || a.ns.thang == 6 || a.ns.thang == 9 || a.ns.thang == 11))
	{
		cout<<"nhap lai thang: ";
		cin>>a.ns.thang;
	}
	while(a.ns.ngay>29 && a.ns.thang ==2)
	{
		cout<<"nhap lai thang: ";
		cin>>a.ns.thang;
	}
	cout<<"nhap nam: ";
	in>>a.ns.nam;
	while(a.ns.ngay==29 && a.ns.thang==2 && ( a.ns.nam % 4 !=0 || a.ns.nam % 400 ==0))
	{
		cout<<"nhap lai nam: ";
		cin>>a.ns.nam;	
	}
	in.ignore();
	cout<<"nhap chung minh thu: ";
	in.getline(a.cmt,10);
	
	cout<<"nhap ho khau: ";
	in.getline(a.ho_khau,50); 
	cout<<endl;
	
	return in;
}
void KH ::nhap_ds(KH a[],int &n)
{
	cout<<"\n\t\t\tNHAP DANH SACH "<<n<<" KHACH HANG\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n\t\t\tNHAP KHACH HANG THU "<<i+1<<endl;
		cin>>a[i];
	}	
}
void tieu_de()
{
	cout<<"| STT |       ho ten      |   ngay sinh   |     so cmt    |       ho khau      |\n";
}
void KH ::xuat_ds(KH a[],int n)
{
	cout<<"\n\t\t\tXUAT DANH SACH "<<n<<" KHACH HANG\n";
	for(int i=0;i<n;i++)
	{
		cout<<"|"<<setw(4)<<i+1<<" ";
		cout<<a[i];		
	}
}
bool KH:: operator > (KH a)
{
	if(strcmp(this->ho_ten,a.ho_ten)==1)
		return true;
	return false;	
}
void KH ::sap_xep(KH a[],int &n)
{
	cout<<"\n\t\t\tDANH SACH DA DUOC SAP XEP THEO TEN TU A-Z\n";
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		if(a[i]> a[j])
		{
			KH tg=a[i];
			a[i]=a[j];
			a[j]=tg;
		}
}
void KH ::thang_12(KH a[],int n)
{
	cout<<"\n\t\t\tXUAT CAC KHACH HANG CO THANG SINH BANG 12\n";
	int check =0;
	for(int i=0;i<n;i++)
		if(a[i].ns.thang==12)
		{
			++check;
			if(check == 1)
				tieu_de();
			cout<<"|"<<setw(4)<<check<<" ";
			cout<<a[i];
		}
	if(check ==0)
		cout<<"\n\t\t\tKHONG CO KHACH HANG NAO CO THANG SINH BANG 12\n";	
}
int main()
{
	int n;
	cout<<"nhap so luong khach hang co trong danh sach: ";
	cin>>n;
	while(n<1)
	{
		cout<<"hay nhap lai so luong khach hang co trong danh sach: ";
		cin>>n;
	}
	KH a[n];
	a[n].nhap_ds(a,n);
	a[n].xuat_ds(a,n);
	a[n].sap_xep(a,n);
	a[n].xuat_ds(a,n);
	a[n].thang_12(a,n);
	return 0;
}
