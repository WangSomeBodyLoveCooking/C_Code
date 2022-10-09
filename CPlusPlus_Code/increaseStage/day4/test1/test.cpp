#include <iostream>

using namespace std;

class Person
{
    public:
        Person(int age, int height, int weight) : age(age), height(height), weight(weight)
        {

        }
        
        int getAge()
        {
            return age;
        }

        int getHeight()
        {
            return height;
        }

        int getWeight()
        {
            return weight;
        }

    private:
        int age;
        int height;
        int weight;
};

void fun()
{
    Person W(29, 170, 140);
    cout << W.getAge() << endl;
    cout << W.getHeight() << endl;
    cout << W.getWeight() << endl;
}

int main()
{
    fun();
    system("pause");
    return 0;
}
