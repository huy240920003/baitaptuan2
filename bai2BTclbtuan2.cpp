
// Nguyen Ngo Huy DHTI15A5HN
// bai2tuan2
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>

using namespace std;
class GV
{
	private:
		char ho_ten[30];
		int tuoi;
		char bang_cap[15];
		char chuyen_nganh [20];
		float bac_luong; 
		double lcb; 
	public:
		GV()
		{
			strcpy(ho_ten,"");
			tuoi=0;
			strcpy(bang_cap,"");
			strcpy(bang_cap,"");
			bac_luong=0; 
			lcb=0; 
		} 
		~GV()
		{
			;
		} 
		friend ostream& operator << (ostream&,GV);
		friend istream& operator >> (istream&,GV&);
		void nhap_ds(GV a[],int &n);
		void xuat_ds(GV a[],int n);
		void tinh_lcb(GV a[],int &n);		 
		void luong_nho(GV a[],int n);
		bool operator > (GV a);
		void sap_xep(GV a[],int &n); 
};
void tieu_de()
{
	cout<<"| STT |       ho ten       |   tuoi   |    bang cap   |    chuyen nganh    |   bac luong   | luong co ban  |\n"; 
} 
ostream& operator << (ostream& out,GV a)
{
	out<<"|"<<setw(20)<<a.ho_ten
	   <<"|"<<setw(10)<<a.tuoi
	   <<"|"<<setw(15)<<a.bang_cap
	   <<"|"<<setw(20)<<a.chuyen_nganh
	   <<"|"<<setw(15)<<a.bac_luong
	   <<"|"<<setw(15)<<a.lcb
	   <<"|"<<endl;	
}
istream& operator >> (istream& in,GV &a)
{
	in.ignore(1); 
	cout<<"nhap ho ten: ";
	in.getline(a.ho_ten,30);
	
	cout<<"nhap tuoi: ";
	cin>>a.tuoi;
	
	in.ignore();
	cout<<"nhap bang cap: ";
	in.getline(a.bang_cap,15);
	
	cout<<"nhap chuyen nganh: ";
	in.getline(a.chuyen_nganh,20);
	
	cout<<"nhap bac luong: ";
	in>>a.bac_luong; 
}
void GV::nhap_ds(GV a[],int &n)
{
	cout<<"\n\t\t\tNHAP DANH SACH "<<n<<" GIAO VIEN\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n\t\t\tNHAP GIAO VIEN THU "<<i+1<<endl; 
		cin>>a[i]; 		
	}

} 
void GV ::tinh_lcb(GV a[],int &n)
{
	for(int i=0;i<n;i++)
		a[i].lcb=a[i].bac_luong*610 ;
} 
void GV ::xuat_ds(GV a[],int n)
{
	a[n].tinh_lcb(a,n); 
	cout<<"\n\t\t\tXUAT DANH SACH "<<n<<" GIAO VIEN\n";
	tieu_de(); 
	for(int i=0;i<n;i++)
	{
		cout<<"|"<<setw(4)<<i+1<<" "; 
		cout<<a[i];		
	}

} 
void GV::luong_nho(GV a[],int n)
{
	cout<<"\n\t\t\tXUAT CAC GIAO VIEN CO LUONG NHO HON 2000	\n"; 
	int check=0;
	for(int i=0;i<n;i++)
		if(a[i].lcb<2000)
		{
			++check;
			if(check==1)
				tieu_de();
			cout<<"|"<<setw(4)<<check<<" ";	
			cout<<a[i];	 
		}
} 
bool GV ::operator > (GV a)
{
	if(strcmp(this->chuyen_nganh,a.chuyen_nganh)== 1)
		return true;
	return false;	 
} 
void GV ::sap_xep(GV a[],int &n)
{
	cout<<"\n\t\t\tDANH SACH DA DUOC SAP XEP THEO THU TU TANG DANH CUA CHUYEN NGANH TU A-Z\n";
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				GV tg= a[i];
				a[i]=a[j];
				a[j]=tg; 
			} 
} 
int main()
{
	int n;
	cout<<"nhap so luong giao vien co trong danh sach: "; 
	cin>>n;
	GV a[n]; 
	a[n].nhap_ds(a,n);
	a[n].xuat_ds(a,n);
	a[n].luong_nho(a,n);
	a[n].sap_xep(a,n);
	a[n].xuat_ds(a,n);
	return 0;
}
