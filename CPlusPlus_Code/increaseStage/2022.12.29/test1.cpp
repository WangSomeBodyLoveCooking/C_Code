#include <iostream>

using namespace std;

/*
***********************
��̬ʵ��3��������װ
***********************
*/
class CPU
{
    public:
       virtual void caculate() = 0;
};

class VedioCard
{
    public:
       virtual void display() = 0;
};

class Memory
{
    public:
       virtual void storage() = 0;
};

class Computer
{
    public:
        Computer(CPU *cpu, VedioCard *vedioCard, Memory *memory)
        {
            m_Cpu = cpu;
            m_VedioCard = vedioCard;
            m_Memory = memory;
        }

        void doWork()
        {
            m_Cpu->caculate();
            m_VedioCard->display();
            m_Memory->storage();
        }

        ~Computer()
        {
            if(m_Cpu != NULL)
            {
                delete m_Cpu;
                m_Cpu = NULL;
            }

            if(m_VedioCard != NULL)
            {
                delete m_VedioCard;
                m_VedioCard = NULL;
            }

            if(m_Memory != NULL)
            {
                delete m_Memory;
                m_Memory = NULL;
            }
        }

    public:
        CPU *m_Cpu;
        VedioCard *m_VedioCard;
        Memory *m_Memory;
};

class IntelCpu : public CPU
{
    virtual void caculate()
    {
        cout << "IntelCpu��ʼ����" << endl;
    }
};

class IntelVedioCard : public VedioCard
{
    virtual void display()
    {
        cout << "Intel�Կ���ʼ��ʾ" << endl;
    }
};

class IntelMemory : public Memory
{
    virtual void storage()
    {
        cout << "Intel�ڴ濪ʼ�洢" << endl;
    }
};

class LenenoCpu : public CPU
{
    virtual void caculate()
    {
        cout << "LenenoCpu��ʼ����" << endl;
    }
};

class LenenoVedioCard : public VedioCard
{
    virtual void display()
    {
        cout << "Leneno�Կ���ʼ��ʾ" << endl;
    }
};

class LenenoMemory : public Memory
{
    virtual void storage()
    {
        cout << "Leneno�ڴ濪ʼ�洢" << endl;
    }
};

void test1()
{
    CPU *cpu = new IntelCpu;
    VedioCard *vedioCard = new IntelVedioCard;
    Memory *memory = new IntelMemory;
    Computer * computer = new Computer(cpu, vedioCard, memory);
    computer->doWork();
    delete computer;
}

void test2()
{
    Computer *computer = new Computer(new LenenoCpu, new LenenoVedioCard, new LenenoMemory);
    computer->doWork();
    delete computer;
}

void test3()
{
    Computer *computer = new Computer(new IntelCpu, new LenenoVedioCard, new LenenoMemory);
    computer->doWork();
    delete computer;
}

int main()
{
    // test1();
    // test2();
    test3();
    system("pause");
    return 0;
}