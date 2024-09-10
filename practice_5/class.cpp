#include <iostream>
using namespace std;
class myarray{
	int n=0;
	double *a=nullptr;
public:	
	myarray(double *a=nullptr ,int n=0 ){
		this->n = n;
		this->a = new double[this->n];
		static int tedade_cons=0;
		for(auto i=0;i<this->n;i++){
			this->a[i] = a[i];
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
	
	void copy(const myarray& k){
		n=k.n;
		a= new double[n];
		for(auto i=0;i<n;i++){
			a[i]= k.a[i];
		}
	}
	int setsize(const int k){
		if((this -> n)>k){
			return this -> n;
		}
		else{
			return k;
		}
	}
	myarray& operator =(const myarray& k){
		static int tedade_entesab=0;
		copy(k);
		tedade_entesab++;
		cout<<"entesab : "<<tedade_entesab<<endl;
		return *this;
		}
	myarray operator +(const myarray& k){
		cout<<"add :" <<endl;
		int m=setsize(k.n);
		myarray c;
        c.n=m;
		if(m == k.n){
			for (auto i=0;i<n;i++){
				c.a[i] = a[i] + k.a[i];
			}
			for(auto i=n;i<k.n;i++){
				c.a[i] = 0;
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
		cout<<"sub :" <<endl;
		int m = setsize(k.n);
		myarray c;
		c.n = m;
		if(m == k.n){
			for (auto i=0;i<n;i++){
				c.a[i] = a[i] - k.a[i];
			}
			for(auto i=n;i<k.n;i++){
				c.a[i] = 0;
			}
	    }
	    else{
			for (auto i=0;i<k.n;i++){
				c.a[i] = a[i] - k.a[i];
			}
			for(auto i=k.n;i<n;i++){
				c.a[i]=0;
			}
		}
		return c;
	}
	myarray operator *(const myarray& k){
		cout<<"mul :" <<endl;
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
void f1 (void){
	int n;
	n= getmemory();
	double *x = new double [n];
	input(x,n);
	myarray a(x,n);	
	myarray b;
	myarray c=a;
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
