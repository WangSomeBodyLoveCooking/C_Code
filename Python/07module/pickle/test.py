import pickle

dic = {'name': '张大仙', 'age': 18, 'salary': 3.5,
       'married': False, 'hobbies': ['可乐', '厕所', '烫头'],
       'school':{1,2,3}}

# 序列化1,2
pickle_res = pickle.dumps(dic, protocol=0)
print(pickle_res, type(pickle_res))
# b'\x80\x03}q\x00(X\x04\x00\x00\x00nameq\x01X\t\x00\x00\x00\xe5\xbc\xa0\xe5\xa4\xa7\xe4\xbb\x99q\x02X\x03\x00\x00\x00ageq\x03K\x12X\x06\x00\x00\x00salaryq\x04G@\x0c\x00\x00\x00\x00\x00\x00X\x07\x00\x00\x00marriedq\x05\x89X\x07\x00\x00\x00hobbiesq\x06]q\x07(X\x06\x00\x00\x00\xe5\x8f\xaf\xe4\xb9\x90q\x08X\x06\x00\x00\x00\xe5\x8e\x95\xe6\x89\x80q\tX\x06\x00\x00\x00\xe7\x83\xab\xe5\xa4\xb4q\neX\x06\x00\x00\x00schoolq\x0bcbuiltins\nset\nq\x0c]q\r(K\x01K\x02K\x03e\x85q\x0eRq\x0fu.' <class 'bytes'>
with open('data.pickle', mode='wb') as w:
    w.write(pickle_res)

with open('data2.pickle', mode='wb') as w:
    pickle.dump(dic, w, protocol=0)

# 反序列化1，2
with open('data.pickle', mode='rb') as r:
    pickle_res = pickle.loads(r.read())
    print(pickle_res)

with open('data2.pickle', mode='rb') as r:
    pickle_res = pickle.load(r)
    print(pickle_res)
