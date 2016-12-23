#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack{
private:
    int maxS;
    int top;
    T *st;
public:
    Stack(int size){
        maxS = size;
        top = -1;
        st = new T[maxS];
    }
    ~Stack(){
        delete [] st;
    }
    bool push(const T k){
        if(top == maxS-1){
            return false;
        }else{
            top++;
            st[top] = k;
            return true;
        }
    }
    T pop(){
        if(top == -1){
            return 0;
        }else{
            top--;
            return st[top+1];
        }
    }
    bool ise(){
        if(top == -1)return true;
        else return false;
    }
};
int main(){
    string str;
    Stack<int> l(10),m(10),s(10);
    cin>>str;
    int i=0;
    while(str[i] != '\0'){
        switch (str[i]){
        case '(':
            s.push(1);i++;
            break;
        case '[':
            m.push(1);i++;
            break;
        case '{':
            l.push(1);i++;
            break;
        case ')':
            s.pop();i++;
            break;
        case ']':
            m.pop();i++;
            break;
        case '}':
            l.pop();i++;
            break;
        default:
            i++;
            break;
        }
    }
    if(l.ise()&&m.ise()&&s.ise())cout<<"true";
    else cout<<"false";
    return 0;
}
