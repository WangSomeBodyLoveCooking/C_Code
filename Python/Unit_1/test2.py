#coding=UTF-8
# 4.�ֵ����ͣ�ʹ�ô�����{ }��
### �ֵ��� + '=' {'key��' �� keyֵ}
dic = {
    'name' : '�Ŵ���', 
    'age' : 73, 
    'height' : 180,
    'salary' : 180
    }

print(type(dic))

#�ֵ�ȡֵ��ͨ��key��ȡֵ�����б�ͨ��������ȡֵ
### �ֵ���['key��']
print(dic['name'])
print(dic['age'])

# ע���ֵ���б���Ի��ʹ��
person = [
    {'name' : '�Ŵ���', 'age' : 28, 'hobby' : ['����Ϸ']},
    {'name' : '����', 'age' : 28, 'hobby' : ['��', '˯', '��']},
    {'name' : '������', 'age' : 29, 'hobby' : ['ѧϰ', '˯��']}
]

print(person[1]['hobby'][0])    # ��
print(person[1]['age'])     # 28
print(id(person[1]['hobby'][0]))        # 56842256
print(type(person[1]['hobby'][0]))      # str




# 5.��������bool
a = True;
b = False;
print(a)        # True
print(type(a))      # bool

c = None
print(type(c))      # NoneType