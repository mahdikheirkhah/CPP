#include <iostream>
#include <cstdlib>
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
	myarray(const double& k){
		n=1;
		a=new double[1];
		a[0]=k;
	}
	void copy(const myarray& k){
		n=k.n;
		a= new double[n];
		for(auto i=0;i<n;i++){
			a[i]= k.a[i];
		}
	}
	int setsize(const int& k){
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
	
	myarray operator -(const myarray& k){
		cout<<"sub :" <<endl;
		int m = setsize(k.n);
		myarray c;
		c.n = m;
		if(m == k.n){
			c=k;
			for (auto i=0;i<n;i++)
				c.a[i] = a[i] - k.a[i];
	    }
	    else{
			c=*this;
			for (auto i=0;i<k.n;i++)
				c.a[i] = a[i] - k.a[i];
		}
		return c;
	}
	myarray operator *(const myarray& k){
		cout<<"mul :" <<endl;
		int m=setsize(k.n);
		myarray c;
		c.n=m;
		if(m == k.n){
			c=k;
			for (auto i=0;i<n;i++)
				c.a[i] = a[i] * k.a[i];
	    }
	    else{
			c=*this;
			for (auto i=0;i<k.n;i++)
				c.a[i] = a[i] * k.a[i];
		}
		return c;
	}
	myarray operator -(void){
		cout<<"neg :" <<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = -1 * a[i];
		}
		return c;
	}
	myarray operator ++(void){
		 for (auto i=0;i<n;i++)
			a[i]++;
		return *this;
	}
	myarray operator ++(int){
		myarray c(*this);
		for (auto i=0;i<n;i++)
			a[i]++;
		return c;
	}	
	myarray operator --(void){
		 for (auto i=0;i<n;i++)
			a[i]--;
		return *this;
	}
	myarray operator --(int){
		myarray c(*this);
		for (auto i=0;i<n;i++)
			a[i]--;
		return c;
	}	
	bool operator ==(const myarray& k){
		bool c;
		if(k.n==n){
			for(auto i=0;i<n;i++){
				if(a[i] != k.a[i]){
					c=false;
					break;
				}
				else if(i == n - 1){	
					c=true;	
				}
			}
		}
		else{
			c=false;
		}
		return c;
	}
	bool operator !=(const myarray& k){
		bool c;
		if(*this == k)
			c=false;
		else
			c=true;
		return c;	
		}
	bool operator <=(const myarray& k){
		bool c;
		if(k.n==n){
			for(auto i=0;i<n;i++){
				if(a[i] > k.a[i]){
					c=false;
					break;
				}
				else if(i == n - 1){	
					c=true;	
				}
			}
		}
		else{
			c=false;
		}
		return c;
	}
	bool operator >=(const myarray& k){
		bool c;
		if(k.n==n){
			for(auto i=0;i<n;i++){
				if(a[i] < k.a[i]){
					c=false;
					break;
				}
				else if(i == n - 1){	
					c=true;	
				}
			}
		}
		else{
			c=false;
		}
		return c;
	}
	bool operator >(const myarray& k){
		bool c;
		if(k.n==n){
			for(auto i=0;i<n;i++){
				if(a[i] < k.a[i]){
					c=false;
					break;
				}
				else if(i == n - 1){	
					c=true;	
				}
			}
		}
		else{
			c=false;
		}
		return c;
	}
	bool operator <(const myarray& k){
		bool c;
		if(k.n==n){
			for(auto i=0;i<n;i++){
				if(a[i] > k.a[i]){
					c=false;
					break;
				}
				else if(i == n - 1){	
					c=true;	
				}
			}
		}
		else{
			c=false;
		}
		return c;
	}
	double& operator [](int n){
		if(n >= this->n){
			cout<<"out of range"<<endl;
			exit(0);
		}
		return a[n];
	}
	/*void print (void){
		cout << "n = "<<n<<endl;
		for (auto i=0;i<n;i++){
			cout << "a["<<i<<"] = "<<a[i]<<endl;
		}
	}*/	
	~myarray(){
		static int tedade_deconstructor=0;
		tedade_deconstructor++;
		cout<<"deconstrucor : "<<tedade_deconstructor<<endl;
	}
	friend myarray operator +(const myarray& k,const myarray& j);
	friend ostream& operator <<(ostream& out,const myarray& k);
};
ostream& operator <<(ostream& out,const myarray& k);
myarray operator +(const myarray& k,const myarray& j);
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
myarray operator +(const myarray& k,const myarray& j){
	cout<<"add :" <<endl;
	int m = j.n>k.n?j.n:k.n;
	myarray c;
	if(m == k.n){
		c=k;
		for (auto i=0;i<j.n;i++)
				c.a[i] = j.a[i] + k.a[i];
    }
    else{
		c=j;
		for (auto i=0;i<k.n;i++)
				c.a[i] = j.a[i] + k.a[i];
	}
	    
		return c;
	}
ostream& operator <<(ostream& out,const myarray& k){
	out << "n = " << k.n << endl;
  for(int i = 0; i < k.n ; i++)
    out << "a[" << i << "]= " << k.a[i] << endl;
  return out;
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
	a=a+7;
	a=7+a;
	cout<< a;
    c=a+b;
    cout<< c;
    c=a-b;
    cout<< c;
    c=a*b;
    cout<< c;
    c=-a;
    cout<< c;
    c=a++;
    cout<< c;
    c=++a;
    cout<< c;
    cout<< a;
}   
