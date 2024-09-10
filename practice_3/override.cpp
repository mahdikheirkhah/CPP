#include <iostream>
using namespace std;
struct myarray{
	int n=0;
	double *a=nullptr;
	myarray(double *ma,int k){
		n=k;
		a= new double[n];
		static int tedade_cons=0;
		for(auto i=0;i<k;i++){
			a[i]= ma[i];
		}
		tedade_cons++;
		cout<<"constructor : "<<tedade_cons<<endl;
	}
	myarray(const myarray& k){
		copy(k);
		static int tedade_copycons=0;
		tedade_copycons++;
		cout<<"copy constructor : "<<tedade_copycons<<endl;
		}
	void operator =(const myarray& k){
		static int tedade_entesab=0;
		copy(k);
		tedade_entesab++;
		cout<<"entesab : "<<tedade_entesab<<endl;
		}
	void copy(const myarray& k){
		n=k.n;
		a= new double[n];
		for(auto i=0;i<n;i++){
			a[i]= k.a[i];
		}
	}
	myarray add(const myarray& k){
		cout<<"add :" <<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i] + k.a[i];
		}
		return c;
	}
	myarray sub(const myarray& k){
		cout<<"sub :" <<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i] - k.a[i];
		}
		return c;
	}
	myarray mul(const myarray& k){
		cout<<"mul :" <<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i] * k.a[i];
		}
		return c;
	}
	myarray neg(void){
		cout<<"neg :" <<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = -1 * a[i];
		}
		return c;
	}
	void print (void){
		cout << "n = "<<n<<endl;
		for (auto i=0;i<n;i++){
			cout << "a["<<i<<"] = "<<a[i]<<endl;
		}
	}	
	~myarray(){
		static int tedade_deconstructor=0;
		tedade_deconstructor++;
		cout<<"deconstrucor : "<<tedade_deconstructor<<endl;
	}
};
void f1 (void);
void input (double *p,int n);
int getmemory(void);
myarray sort(myarray a); 
int main(int argc, char **argv)
{
	f1();
	return 0;
}
void input (double *p,int n){
	for(auto i=0;i<n;i++){
		cout<<"meghdarie ke mikhahid be ozve a["<<i<<"] bedahid vard konid"<<endl;
		cin>>p[i];
	}
}
int getmemory(void){
	int n;
	cout<<"tedad azaye arrayera ke mikhahid bedahid vard konid:"<<endl;
	cin>>n;
	return n;
}
myarray sort(myarray k){
	for(int i=0;i<k.n-1;i++){
		if(k.a[i]>k.a[i+1]){
			double temp = k.a[i];
			k.a[i]=k.a[i+1];
			k.a[i+1]=temp;
		}
	}
	return k;
}
void f1 (void){
	int n;
	n= getmemory();
	double *x = new double [n];
	input(x,n);
	myarray a(x,n);	
	myarray b(x,n);
	myarray c=a;//copyconstruct 1
	a=sort(a);//copyconstruct 2
	//copyconstruct 3: ba return shodan k dar tabe sort va entesab aan be a eijad mishavad.
	b=a;
    c=a.add(b);
    c.print();
    c=a.sub(b);
    c.print();
    c=a.mul(b);
    c.print();
    c=a.neg();
    c.print();
}   
