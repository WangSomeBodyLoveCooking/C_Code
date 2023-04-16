// 模板的局限性：函数模板的通用性不是万能的；
// 例如比较两个数是否相同的函数，实参可以传入两个数组地址；
// 为解决这一问题，c++为特定类型提供了具体化的模板

#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        Person(string name, int age)
        {
            this->name = name;
            this->age = age;
        }

        int getAge()
        {
            return this->age;
        }

        string getName()
        {
            return this->name;
        }

    private:
        string name;
        int age;
};

template <typename T>
bool compareFunc(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }

    return false;
}

//C++为特定类型提供了具体化模板
template<> bool compareFunc(Person &a, Person  &b)  //需要指定特定类型
{
    if(a.getAge() == b.getAge() && a.getName() == b.getName())
    {
        return true;
    }

    return false;
}


void test()
{
    int a = 10;
    int b = 10;
    Person person1("TOM", 20);
    Person person2 = Person("TOM", 20);

    bool c1 = compareFunc(a, b); //可以实现
    bool c2 = compareFunc(person1, person2);  //无法实现

    cout << c1 << c2 << endl;
}



int main()
{
    test();
    system("pause");
    return 0;
}