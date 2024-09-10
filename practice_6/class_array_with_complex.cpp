#include <iostream>
using namespace std;
class complex {
	double real,imag;
public:	
	complex(double x=0,double y=0){
		real=x;
		imag=y;
	}
	void input(void){
		cout<<"meghdar ghesmat hagheigheie adad ra vard konid: "<<endl;
		cin>>real;
		cout<<"meghdar ghesmat moohemi adad ra vard konid: "<<endl;
		cin>>imag;
	}
	complex operator +(const complex& k){
		complex c;
		c.real=real+ k.real;
		c.imag=imag+ k.imag;
		return c; 
	}
	complex operator -(const complex& k){
		complex c;
		c.real=real-k.real;
		c.imag=imag-k.imag;
		return c;
	}
	complex operator *(const complex& k){
		complex c;
		c.real=(real*k.real)-(imag*k.imag);
		c.imag=(real*k.imag)+(imag*k.real);
		return c;
	}
	complex neg(void){
		complex c;
		c.real=(real)* -1;
		c.imag=(imag)* -1;
		return c;
	}
	complex& operator =(const complex& k ){
		imag=k.imag;
		real=k.real;
		return *this;
	}
	void input (int i){
			cout<<"meghdarie ke mikhahid be real a["<<i<<"].real bedahid vard konid:"<<endl;
			cin>>real;
			cout<<"meghdarie ke mikhahid be imag a["<<i<<"].imag bedahid vard konid:"<<endl;
			cin>>imag;
		 }
	void print(int i){
			cout << "haghigie a["<<i<<"] = "<<real<<endl;
			cout << "mohomie a["<<i<<"] = "<<imag<<endl;
		}
};
class myarray{
	int n = 0; 
	complex *a  =  nullptr;
public:	
	myarray(complex *a=nullptr,int n=0){
		this ->n = n;
		this ->a = new complex [this ->n];
		static int tedade_cons=0;
		for(auto i=0;i<this -> n ;i++){
			this -> a[i] = a[i];
		}
		tedade_cons++;
		cout<<"constructor : "<<tedade_cons<<endl;
	}
	myarray(const myarray& k){
		static int tedade_copycons=0;
		copy(k);
		tedade_copycons++;
		cout<<"copy constructor : "<<tedade_copycons<<endl;
	}
		int setsize(const int k){
		if((this -> n)>k){
			return this -> n;
		}
		else{
			return k;
		}
	}
	myarray& operator =(const myarray &k){
		static int tedade_entesab=0;
		copy(k);
		tedade_entesab++;
		cout<<"entesab : "<<tedade_entesab<<endl;
		return *this;
	}	
	void copy(const myarray&k){
		n=k.n;
		a= new complex[n];
		for(auto i=0;i<n;i++){
			a[i]=k.a[i];
		}
	}
	myarray operator +(const myarray& k){
		cout<<"add :"<<endl;
		int m=setsize(k.n);
		myarray c;
		c.n=m;
		if(m == k.n){
			for (auto i=0;i<n;i++){
				c.a[i] = a[i]+ k.a[i];
			}
			for(auto i=n;i<k.n;i++){
				c.a[i]=0;
			}
	    }
	    else{
			for (auto i=0;i<k.n;i++){
				c.a[i] = a[i] + k.a[i];
			}
			for(auto i=k.n;i<n;i++){
				c.a[i]=0;
			}
		}
		return c;
	}
	myarray operator -(const myarray& k){
		cout<<"sub :"<<endl;
		int m=setsize(k.n);
		myarray c;
		c.n=m;
	    if(m == k.n){
			for (auto i=0;i<n;i++){
				c.a[i] = a[i] - k.a[i];
			}
			for(auto i=n;i<k.n;i++){
				c.a[i]=0;
			}
	    }
	    else{
			for (auto i=0;i<k.n;i++){
				c.a[i] = a[i] * k.a[i];
			}
			for(auto i=k.n;i<n;i++){
				c.a[i]=0;
			}
		}
		return c;
	}
	myarray operator *(const myarray& k){
		cout<<"mul :"<<endl;
		int m=setsize(k.n);
		myarray c;
		c.n=m;
		if(m == k.n){
			for (auto i=0;i<n;i++){
				c.a[i] = a[i] * k.a[i];
			}
			for(auto i=n;i<k.n;i++){
				c.a[i]=0;
			}
	    }
	    else{
			for (auto i=0;i<k.n;i++){
				c.a[i] = a[i] * k.a[i];
			}
			for(auto i=k.n;i<n;i++){
				c.a[i]=0;
			}
		}
		return c;
	}
	myarray neg(void){
		cout<<"neg :"<<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i].neg();
		}
		return c;
	}
	void print (void){
		cout <<"n = "<<n<<endl;
		for (auto i=0;i<n;i++){
			a[i].print(i);
		}
	}
	~ myarray(){
		static int tedade_deconstructor=0;
		tedade_deconstructor++;
		cout<<"deconstrucor : "<<tedade_deconstructor<<endl;
	}
};
void f1 (void);
void input (double *p,int n);
int getmemory(void);
int main(int argc, char **argv)
{
	f1();
	return 0;
}
int getmemory(void){
	int n;
	cout<<"tedad azaye arrayera ke mikhahid bedahid vard konid:"<<endl;
	cin>>n;
	return n;
}
void f1 (void){
	int n;
	n= getmemory();
	complex *x = new complex [n];
	for(auto i=0;i<n;i++)
		x[i].input(i);
	myarray a(x,n); 
	myarray b(x,n);
	myarray c(x,n);
	b=a;
    c=a+b;
    c.print();
    c=a-b;
    c.print();
    c=a*b;
    c.print();
    c=a.neg();
    c.print();
}   
