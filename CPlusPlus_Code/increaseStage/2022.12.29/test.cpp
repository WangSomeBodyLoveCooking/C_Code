#include <iostream>

using namespace std;

class DoDrink
{
    public:
        virtual void BoilWater() = 0;
        virtual void AddLiao() = 0;
        virtual void DaoBei() = 0;
        virtual void AddPeiLiao() = 0;

        void DoDrinking()
        {
            //´í´í´í
            // void BoilWater();
            // void AddLiao();
            // void DaoBei();
            // void AddPeiLiao();
            BoilWater();
            AddLiao();
            DaoBei();
            AddPeiLiao();
        }
};

class DoCoffee : public DoDrink
{
    public:
        void BoilWater()
        {
            cout << "ÖóË®" << endl;
        }
        void AddLiao()
        {
            cout << "¼Ó¿§·È" << endl;
        }
        void DaoBei()
        {
            cout << "µ¹Ë®" << endl;
        } 
        void AddPeiLiao()
        {
            cout << "¼ÓÌÇºÍÅ£ÄÌ" << endl;
        }
};

class DoTea : public DoDrink
{
    public:
        void BoilWater()
        {
            cout << "ÖóÅ©·òÉ½Èª" << endl;
        }
        void AddLiao()
        {
            cout << "¼Ó²èÒ¶" << endl;
        }
        void DaoBei()
        {
            cout << "µ¹ÈªË®" << endl;
        } 
        void AddPeiLiao()
        {
            cout << "¼ÓÄûÃÊ" << endl;
        }
};

void Do(DoDrink * drinking)
{
    drinking->DoDrinking();
}

void test1()
{
    Do(new DoCoffee);
    cout << "------------------------------" << endl;
    Do(new DoTea);
}

int main()
{
    test1();
    system("pause");
    return 0;
}