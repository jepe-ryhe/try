#include<iostream>
using namespace std;
template<class T>
class Array{
public:
	int fl,f,l,s;
	T * d;
	Array(int t){
		d = new T[t];
		fl = 0;
		f = l = 0;
		s = t;
	}
	bool in(T item){
        if(f == l && fl != 0)
            return false;
        if(fl == 0)
            fl = 1;
        d[l] = item;
        l = (l+1)%s;
        return true;
	}
	bool out(T & item){
	    if(fl == 0)
            return false;
        item = d[f];
        f = (f+1)%s;
        if(f == l)
            fl = 0;
        return true;
	}
	void show(){
	    if(fl == 0)
            return;
        int i = f;
        if(f == l){
            cout<<d[i]<<'\t';
            i++;
        }
        while(i%s != l){
            cout<<d[i]<<'\t';
            i++;
        }
        cout<<endl;
	}
};
int main(){
    Array<int> a(3);
    int b;
    a.show();
    a.in(1);
    a.in(2);
    a.in(3);
    a.in(4);
    a.show();
    a.out(b);a.show();
    a.in(5);a.show();
    a.out(b);a.show();
    a.out(b);a.show();
    return 0;
}
