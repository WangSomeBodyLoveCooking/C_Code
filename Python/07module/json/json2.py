#coding=utf-8
import json

dic = {'name':'张大仙', 'age':18, 'salary':3.5, 'married':False, 'hobbies':['可乐', '厕所', '烫头']}
json_res = json.dumps(dic)
print(json_res, type(json_res))
# {"name": "\u5f20\u5927\u4ed9", "age": 18, "salary": 3.5, "married": false, "hobbies": ["\u53ef\u4e50", "\u5395\u6240", "\u70eb\u5934"]} <class 'str'>

json_res1 = json.dumps(dic, ensure_ascii=False)
print(json_res1, type(json_res1))
# {"name": "张大仙", "age": 18, "salary": 3.5, "married": false, "hobbies": ["可乐", "厕所", "烫头"]} <class 'str'>

with open ('test.json', mode='wt', encoding='utf-8') as w:
    w.write(json_res)

# 反序列化
with open('test.json', mode='rt', encoding='utf-8') as f:
    json_res = f.read()

dic = json.loads(json_res)
print(dic, type(dic))

#{'name': '张大仙', 'age': 18, 'salary': 3.5, 'married': False, 'hobbies': ['可乐', '厕所', '烫头']} <class 'dict'>


# 序列化2：
dic = {'name':'张大仙', 'age':18, 'salary':3.5, 'married':False, 'hobbies':['可乐', '厕所', '烫头']}
with open('test2.json', mode='wt', encoding='utf-8') as w:
    json.dump(dic, w, ensure_ascii=False)

# 反序列化2：
with open('test2.json', mode='rt', encoding='utf-8') as f:
    json_res = json.load(f)
    print(json_res, type(json_res))
    # {'name': '张大仙', 'age': 18, 'salary': 3.5, 'married': False, 'hobbies': ['可乐', '厕所', '烫头']} <class 'dict'>

json.dumps({1,2,3})