#include <iostream>
#include <cstdlib>
using namespace std;
class complex {
    double real,imag;
public:    
    complex(double x=0,double y=0){
        real=x;
        imag=y;
        if(x!=0 && y==0){
			real=x;
			imag=x;
		}
    }
    complex (const complex& k){
        real =k.real;
        imag =k.imag;
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
    bool operator ==(const complex& k) const {
        bool c;
        if(imag==k.imag){
            if(real ==k.real){
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
    bool operator !=(const complex& k) const {
        bool c;
        if(imag == k.imag){
            if(real == k.real){
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
    bool operator <=(const complex& k) const {
		bool c;
		if(imag <= k.imag){
			if(real <= k.real){
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
	bool operator >=(const complex& k) const {
		bool c;
		if(imag >= k.imag){
			if(real >= k.real){
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
	bool operator <(const complex& k) const {
		bool c;
		if(imag < k.imag){
			if(real < k.real){
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
	bool operator >(const complex& k) const {
		bool c;
		if(imag > k.imag){
			if(real > k.real){
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
   double& operator [](int n){
		return real;
		return imag;
   } 
    void input (int i){
            cout<<"meghdarie ke mikhahid be real a["<<i<<"].real bedahid vard konid:"<<endl;
            cin>>real;
            cout<<"meghdarie ke mikhahid be imag a["<<i<<"].imag bedahid vard konid:"<<endl;
            cin>>imag;
         }
   /* void print(int i){
            cout << "haghigie a["<<i<<"] = "<<real<<endl;
            cout << "mohomie a["<<i<<"] = "<<imag<<endl;
        }*/
        friend ostream& operator<<(ostream& out,const complex& k);    
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
		n=1;
		a=new complex[1];
		a[0]=k;
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
        static int tedade_entesab=0;
        copy(k);
        tedade_entesab++;
        cout<<"entesab : "<<tedade_entesab<<endl;
        return *this;
    }
    myarray operator -(const myarray& k)const{
        cout<<"sub :"<<endl;
        int m=setsize(k.n);
        myarray c;
        if(m == k.n){
			c=k;
            for (auto i=0;i<n;i++){
                c.a[i] = a[i] - k.a[i];
            }
        }
        else{
			c=*this;
            for (auto i=0;i<k.n;i++){
                c.a[i] = a[i] * k.a[i];
            }
        }
        return c;
    }
    myarray operator *(const myarray& k)const{
        cout<<"mul :"<<endl;
        int m=setsize(k.n);
        myarray c;
        if(m == k.n){
			c=k;
            for (auto i=0;i<n;i++){
                c.a[i] = a[i] * k.a[i];
            }
        }
        else{
			c=*this;
            for (auto i=0;i<k.n;i++){
                c.a[i] = a[i] * k.a[i];
            }
        }
        return c;
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
    friend ostream& operator <<(ostream& out,const myarray& k); 
    friend myarray operator +(const myarray& k,const myarray& j);
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
int getmemory(void){
    int n;
    cout<<"tedad azaye arrayera ke mikhahid bedahid vard konid:"<<endl;
    cin>>n;
    return n;
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
ostream& operator<<(ostream& out,const myarray& k){
	out << "n = " << k.n << endl;
  for(int i = 0; i < k.n ; i++)
    out << "a[" << i << "] :" <<endl<< k.a[i] << endl;
  return out;
}
ostream& operator<<(ostream& out,const complex& k){
    out << "imag = " <<k.imag << endl;
    out<<"real = "<<k.real;
  return out;
}
void f1 (void){
    int n;
    n= getmemory();
    complex *x = new complex [n];
    for(auto i=0;i<n;i++)
        x[i].input(i);
    myarray a(x,n); 
    myarray b;
    myarray c(x,n);
    b=a;
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
    a = a + 5;
    cout << a;
}
