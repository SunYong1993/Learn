//
//  main.cpp
//  C++11练习
//
//  Created by student on 15-12-21.
//  Copyright (c) 2015年 student. All rights reserved.
//

#include <iostream>
//using namespace std;

//class SomeType{
//protected:
//    int number=10;
//    string name;
//    SomeType(int i,string&s):number(i),name(s){}
//public:
//    SomeType(string&s):SomeType(1,s){}
//};
//
//class BaseClass{
//public:
//    BaseClass(){
//        cout<<"Default Constructor"<<endl;
//    }
//    BaseClass(int iValue){
//        cout<<"Base Constructor"<<endl;
//    }
//};
//
//class DerivedClass : public BaseClass{
//public:
//    using BaseClass::BaseClass;
//    //当使用using BaseClass::BaseClass时候，相当于在派生类中生成了 derived(args):base(args){}的代码
//};
//
////防止隐士的类型转换
//class SomeClass{
//public:
//    SomeClass(){cout<<"SomeClass"<<endl;}
//    explicit SomeClass(int iNewValua):iValua(iNewValua){cout<<"iNewValua"<<endl;}
//public:
//    int iValua = 5;//这种写法比较好
//};
//
//typedef function<int(int,int)> test;
//
//int main(int argc, const char * argv[])
//{
////    string s = "sss";
////    SomeType *aaa = new SomeType(s);
////    
////    DerivedClass *sss = new DerivedClass();
////    SomeClass p;
//    //因为没有实际参数，此处的小括号可省略
//    //这就是C++lanbada表达方式：[capturws](params)->ret{Statments}
////    function<void()> myfun=[](){std::cout<<"GG"<<endl;};
////    myfun();
////    int x = 8;
////    int y = 10;
////    function<int()> f=[x,y](){
////        return x+y;
////    };
////    cout<<f()<<endl;
//    //值传递的方式,修改无法在外部生效
//    int x = 10;
//    int y = 3;
//    int z;
//    z = [=]()mutable throw ()->int{
//        int n=x+y;
//        x=y;
//        y=n;
//        return n;}();
//    cout<<z<<endl;
//    cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
////运行结果：    13
////            x:10 	y:3
////            Program ended with exit code: 0
//    //引用传递
//    int a = 10;
//    int b = 3;
//    int c;
//    c = [&,b]()mutable throw() -> int{
//        int c = a+b;
//        a = b;
//        b = c;
//        return c;
//    }();
//    cout<<c<<endl;
//    cout<<"a:"<<a<<"\t"<<"b:"<<b<<endl;
//    
//    function<int(int)> func1 = [](int i){return i+4;};
//    std::cout<<"func1:"<<func1(6)<<endl;
//    
//    auto func2 = [](int i){return  i+4;};
//    std::cout<<"func2:"<<func2(6)<<'\n';
//    
//    auto f = [](int x,int y){return  x+y;};
//    cout<<"f:"<<f(21,12)<<endl;
//    
//    test func3 = [](int i,int j){return i+j;};
//    cout<<"func3:"<<func3(8,8)<<endl;
//                              
//    return 0;
//}
#include <functional>
//using namespace std::placeholders;
//void f5(int i,int j,int k){
//    printf("i=%d,j=%d,k=%d\t",i,j,k);
//    if (i<j) {
//        cout<<i<<endl;
//    }else{
//        cout<<j<<endl;
//    }
//}
//function<void(int,int,int)> f_bind = std::bind(f5,placeholders::_2,20,placeholders::_1);
//placeholders::_1 传进来的第一个参数 占位符
//placeholders::_2 传进来的第二个参数 占位符
typedef std::function<void(int)> fp;
class A{
    virtual void f(int a)
    {
        cout<<a<<endl;
        cout<<"A::f()"<<endl;
    }
    void init()
    {//std::bind表现出多态行为
        auto f=std::bind(&A::f, this,std::placeholders::_1);
        f(10);
    }
};
int main(int argc,const char * argv[]){
    
   // f_bind(36,24,75);
}
