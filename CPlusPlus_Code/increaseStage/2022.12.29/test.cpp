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
            //����
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
            cout << "��ˮ" << endl;
        }
        void AddLiao()
        {
            cout << "�ӿ���" << endl;
        }
        void DaoBei()
        {
            cout << "��ˮ" << endl;
        } 
        void AddPeiLiao()
        {
            cout << "���Ǻ�ţ��" << endl;
        }
};

class DoTea : public DoDrink
{
    public:
        void BoilWater()
        {
            cout << "��ũ��ɽȪ" << endl;
        }
        void AddLiao()
        {
            cout << "�Ӳ�Ҷ" << endl;
        }
        void DaoBei()
        {
            cout << "��Ȫˮ" << endl;
        } 
        void AddPeiLiao()
        {
            cout << "������" << endl;
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