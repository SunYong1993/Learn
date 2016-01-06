//
//  main.cpp
//  智能指针练习
//
//  Created by student on 15-12-22.
//  Copyright (c) 2015年 student. All rights reserved.
//

#include <iostream>
using namespace std;

class Point
{  //基础对象类，要做一个对Point类的智能指针
public:
    Point(int xVal = 0,int yVal =0):x(xVal),y(yVal){}
    int getX()const{return x;}
    int getY()const{return y;}
    void setX(int xVal){x = xVal;}
    void setY(int yVal){y = yVal;}
private:
    int x,y;
};
class SmartPtr;
class RefPtr  //辅助类
{//该类成员访问权限全部为private，因为不想让用户直接使用该类
    friend class SmartPtr;//定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
    RefPtr(Point *ptr):p(ptr),count(1){}
    ~RefPtr(){delete p;}
    
    int count;
    Point *p;
};

class SmartPtr //智能指针类
{
public:
    SmartPtr(Point *ptr):rp(new RefPtr(ptr)){}//构造函数
    SmartPtr(const SmartPtr &sp):rp(sp.rp){++rp->count;}//复制构造函数
    SmartPtr& operator=(const SmartPtr& rhs)//重载赋值操作符
    {
        ++rhs.rp->count;//首先将右操作数引用计数加1
        if (--rp->count==0) {//然后引用计数减1，可以应对自赋值
            delete rp;
        }
        rp=rhs.rp;
        return *this;
    }
    ~SmartPtr(){//析构函数
        if (--rp->count==0) {//当引用计数为0时，删除辅助类对象，从而删除基础对象.
            delete rp;
        }
    }
    
private:
    RefPtr * rp;//辅助类对象指针
};

int main(int argc, const char * argv[])
{
    Point * p1 = new Point(10,8);
    SmartPtr sp1(p1); //此时sp1.rp->count = 1
    SmartPtr sp2(p1); //首先将sp1.rp->count赋给sp2.rp->count,之后sp2.rp->count++,这时sp1,sp2的rp是同一个对象
    Point * p2 =new Point(5,5);
    SmartPtr sp3(p2);
    sp3 = sp1;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

