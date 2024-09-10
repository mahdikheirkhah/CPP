#include <iostream>
#include <cstdlib>
using namespace std;
class complex {
    double real,imag;
public:    
    complex(double x=0,double y=0){
        real=x;
        imag=y;
    }
    complex (const complex& k){
        real =k.real;
        imag =k.imag;
    }
    complex operator -(void){
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
   complex  operator ++(void) {
       imag++;
       real++;
       return *this;
       }
    complex  operator ++(int) {
       complex k(*this);
       imag++;
       real++;
       return k;
       }
    complex  operator --(void) {
       imag--;
       real--;
       return *this;
       }
    complex  operator --(int) {
       complex k(*this);
       imag--;
       real--;
       return k;
   }
   bool operator !(void){
	   bool c = false;
	   if(imag == 0 && real == 0)
		   c = true;
		return c;
	}   
	   
   /* void input (int i){
            cout<<"meghdarie ke mikhahid be real  bedahid vard konid:"<<endl;
            cin>>real;
            cout<<"meghdarie ke mikhahid be imag  bedahid vard konid:"<<endl;
            cin>>imag;
         }
   void print(int i){
            cout << "haghigie a["<<i<<"] = "<<real<<endl;
            cout << "mohomie a["<<i<<"] = "<<imag<<endl;
        }*/
        friend ostream& operator<<(ostream& out,const complex& k);
        friend istream& operator>>(istream& in,complex& k);
		friend complex operator +(const complex& k,const complex& j);
	    friend complex operator -(const complex& k,const complex& j);
        friend complex operator *(const complex& k,const complex& j);    
        friend bool operator ==(const complex& k,const complex& j);
		friend bool operator !=(const complex& k,const complex& j);
		friend bool operator <=(const complex& k,const complex& j);
		friend bool operator >=(const complex& k,const complex& j);
		friend bool operator <(const complex& k,const complex& j);
		friend bool operator >(const complex& k,const complex& j);
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
    myarray(const double& k){
		cout<<"myarray double"<<endl;
		n = 1;
		a = new complex[1];
		complex c(k,k);
		a[0] = c;
	}
    myarray(const myarray& k){
        static int tedade_copycons=0;
        copy(k);
        tedade_copycons++;
        cout<<"copy constructor : "<<tedade_copycons<<endl;
    }
        int setsize(const int k)const{
        if((this -> n)>k){
            return this -> n;
        }
        else{
            return k;
        }
    }
     void copy(const myarray&k){
        n=k.n;
        a= new complex[n];
        for(auto i=0;i<n;i++){
            a[i]=k.a[i];
        }
    }
    myarray& operator =(const myarray &k){
        copy(k);
        return *this;
    }
    myarray operator -(void){
        cout<<"neg :"<<endl;
        myarray c(*this);
        for (auto i=0;i<n;i++){
            c.a[i] = -a[i] ;
        }
        return c;
    }
   myarray operator ++(void){
		for(int i=0;i<n;i++)
			++a[i];
		return *this;
	}		
    myarray operator ++(int){
		myarray c(*this);
		for(int i=0;i<n;i++)
			++a[i];
		return c;
	}
	myarray operator --(void){
		for(int i=0;i<n;i++)
			--a[i];
		return *this;
	}
	myarray operator --(int){
		myarray c(*this);
		for(int i=0;i<n;i++)
			--a[i];
		return c;
	}
	complex& operator [](int n) const{
		if(n >= this->n){
			cout<<"out of range"<<endl;
			exit(0);
		}
		return a[n];
	}
	bool operator !(void){
		bool c = true ;
		if( n != 0){
			int i;
			for(i=0;i<n;i++)
				if(!!a[i])
					break;
			if(i < n - 1)
				c = false;
		}	
		return c;
	}
   /*void print (void){
        cout <<"n = "<<n<<endl;
        for (auto i=0;i<n;i++){
            a[i].print(i);
        }
    }*/
    ~ myarray(){
        static int tedade_deconstructor=0;
        tedade_deconstructor++;
        cout<<"deconstrucor : "<<tedade_deconstructor<<endl;
    }
    friend istream& operator>>(istream& in, myarray& k);
    friend ostream& operator <<(ostream& out,const myarray& k); 
    friend myarray operator +(const myarray& k,const myarray& j);
	friend myarray operator -(const myarray& k,const myarray& j);
	friend myarray operator *(const myarray& k,const myarray& j);
	friend	bool operator ==(const myarray& k,const myarray& j);
	friend	bool operator !=(const myarray& k,const myarray& j);
	friend  bool operator <=(const myarray& k,const myarray& j);
	friend  bool operator >=(const myarray& k,const myarray& j);
	friend	bool operator >(const myarray& k,const myarray& j);
	friend  bool operator <(const myarray& k,const myarray& j);
};
//complex :
ostream& operator<<(ostream& out,const complex& k);
istream& operator>>(istream& in, complex& k);
complex operator +(const complex& k,const complex& j);
complex operator -(const complex& k,const complex& j);
complex operator *(const complex& k,const complex& j);
bool operator ==(const complex& k,const complex& j);
bool operator !=(const complex& k,const complex& j);
bool operator <=(const complex& k,const complex& j);
bool operator >=(const complex& k,const complex& j);
bool operator <(const complex& k,const complex& j);
bool operator >(const complex& k,const complex& j);
//myarray :
istream& operator>>(istream& in, myarray& k);
ostream& operator <<(ostream& out,const myarray& k);
myarray operator +(const myarray& k,const myarray& j);
myarray operator -(const myarray& k,const myarray& j);
myarray operator *(const myarray& k,const myarray& j);
bool operator ==(const myarray& k,const myarray& j);
bool operator !=(const myarray& k,const myarray& j);
bool operator <=(const myarray& k,const myarray& j);
bool operator >=(const myarray& k,const myarray& j);
bool operator >(const myarray& k,const myarray& j);
bool operator <(const myarray& k,const myarray& j);
void f1 (void);
int main(int argc, char **argv)
{
    f1();
    return 0;
}
//complex :
ostream& operator<<(ostream& out,const complex& k){
    out << "real = " <<k.real<< endl;
    out << "imag = " <<k.imag ;
	return out;
}
istream& operator>>(istream& in, complex& k){
	cout << "real :" << endl;
	in >> k.real;
	cout << "imag :" << endl;
	in >> k.imag;
	return in;
}
complex operator +(const complex& k,const complex& j){
    complex c;
    c.real=j.real+ k.real;
    c.imag=j.imag+ k.imag;
    return c; 
}
complex operator -(const complex& k,const complex& j){
    complex c;
    c.real=j.real-k.real;
    c.imag=j.imag-k.imag;
    return c;
}
complex operator *(const complex& k,const complex& j){
	complex c;
    c.real=(j.real*k.real)-(j.imag*k.imag);
    c.imag=(j.real*k.imag)+(j.imag*k.real);
    return c;
}
bool operator ==(const complex& k,const complex& j){
     bool c;
     if(k.imag == j.imag){
          if(k.real == j.real){
              c=true;
            }
          else{
            c=false;
         }
       }
     else{
         c=false;
       }
     return c;
}
bool operator !=(const complex& k,const complex& j){
     bool c;
     if(k.imag == j.imag){
          if(k.real == j.real){
              c = false;
          }
          else{
              c = true;
          }
      }
      else{ 
		 c = true;
     }
     return c;
}
bool operator <=(const complex& k,const complex& j){
	bool c;
	if(k.imag <= j.imag){
		if(k.real <= j.real){
			c=true;
		}
		else{
			c=false;
		}
	}
	else{
		c=false;
	}
	return c;
}
bool operator >=(const complex& k,const complex& j){
	bool c;
	if(k.imag >= j.imag){
		if(k.real >= j.real){
			c=true;
		}
		else{
			c=false;
		}
	}
	else{
		c=false;
	}
	return c;
}
bool operator <(const complex& k,const complex& j){
	bool c;
	if(k.imag < j.imag){
		if(k.real < j.real){
			c=true;
		}
		else{
			c=false;
		}
	}
	else{
		c=false;
	}
	return c;
}
bool operator >(const complex& k,const complex& j){
	bool c;
	if(k.imag > j.imag){
		if(k.real > j.real){
			c=true;
		}
		else{
			c=false;
		}
	}
	else{
		c=false;
	}
	return c;
}
//myarray :
istream& operator>>(istream& in, myarray& k){
	cout<<"n :"<<endl;
	in>>k.n;
	for(auto i=0;i<k.n;i++){
		cout<<"a["<<i<<"] :"<<endl;
        in >> k.a[i];
	}
	 return in;
 }
ostream& operator<<(ostream& out,const myarray& k){
	out << "n = " << k.n << endl;
	for(int i = 0; i < k.n ; i++)
		out << "a[" << i << "] :" <<endl<< k.a[i] << endl;
	return out;
}
myarray operator +(const myarray& k,const myarray& j){
        cout<<"add :"<<endl;
        int m = j.n>k.n?j.n:k.n;
        myarray c;
        if(m == k.n){
			c=k;
            for (auto i=0;i<j.n;i++){
                c.a[i] = j.a[i]+ k.a[i];
            }
        }
        else{
			c=j;
            for (auto i=0;i<k.n;i++){
                c.a[i] = j.a[i] + k.a[i];
            }
        }
        return c;
}
myarray operator -(const myarray& k,const myarray& j){
	cout<<"sub :"<<endl;
	myarray c;
	if(k.n > j.n ){
			c=k;
			for (auto i=0;i<j.n;i++){
				c.a[i] = k.a[i] - j.a[i];
			}
		}
	else{
			c=j;
			for (auto i=0;i<k.n;i++){
				c.a[i] = k.a[i] - j.a[i];
			}
	}
	return c;
}
myarray operator *(const myarray& k,const myarray& j){
     cout<<"mul :"<<endl;
     myarray c;
     if(k.n > j.n){
		c=k;
        for (auto i=0;i<j.n;i++){
             c.a[i] = j.a[i] * k.a[i];
            }
        }
     else{
		 c=j;
         for (auto i=0;i<k.n;i++){
              c.a[i] = j.a[i] * k.a[i];
         }
     }
     return c;
}
bool operator ==(const myarray& k,const myarray& j){
	bool c;
	if(k.n==j.n){
		int n = j.n;
		for(auto i=0;i<n;i++){
			if(k.a[i] != j.a[i]){
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
bool operator !=(const myarray& k,const myarray& j){
	bool c;
	if(k == j)
		c=false;
	else
		c=true;
	return c;	
}
bool operator <=(const myarray& k,const myarray& j){
	bool c;
	if(k.n==j.n){
		int n = j.n;
		for(auto i=0;i<n;i++){
			if(k.a[i] > j.a[i]){
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
bool operator >=(const myarray& k,const myarray& j){
	bool c;
	if(k.n==j.n){
		int n = j.n;
		for(auto i=0;i<n;i++){
			if(k.a[i] < j.a[i]){
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
bool operator >(const myarray& k,const myarray& j){
	bool c;
	if(k.n==j.n){
		int n = j.n;
		for(auto i=0;i<n;i++){
			if(k.a[i] <= j.a[i]){
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
bool operator <(const myarray& k,const myarray& j){
	bool c;
	if(k.n==j.n){
		int n = j.n;
		for(auto i=0;i<n;i++){
			if(k.a[i] >= j.a[i]){
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
void f1 (void){
    myarray a,b,c,d;
    cin>>a;
    cout<<a<<endl;
    cin>>b;
    c=a+b;
    cout<<c;
    c=a-b;
    cout<<c;
    c=a*b;
    cout<<c;
    c=-a;
    cout<<c;
    c = a++;
    cout<<c;
    cout<<a;
    a=b;
    c = --a;
    cout<<c;
    cout<<a; 
    if(!d)
		cout<<"not"<<endl;
	a=a+5;
	cout<<a;	
}
