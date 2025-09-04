# coding=utf-8
import csv
from datetime import datetime

# ①超4min的idel有多少个(22之后，下一条信令间隔4min)
# ②超过10min的idel有多少个
# ③基站数量个数（排重）
# ④含有多少个公网基站？
# ⑤含有多少个专网基站？
# ⑥有无乒乓
# ⑦轨迹总时长

def get_nMin_idel(unique_user_list, n):
    num = 0
    time1 = ''
    for i in unique_user_list:
        if i["procedure_type"] == '22':
            time1 = i["procedure_start_time_on_gw"]
        else:
            if len(time1) > 0:
                time2 = i["procedure_start_time_on_gw"]
                if get_total_second(time1, time2) > n * 60:
                    num+=1
                time1 = ''
    return num

def get_base_num(unique_user_list):
    cell_list = []
    is_pingpang = False
    pingpang_list = []
    for i in unique_user_list:
        cell_id = (int(i["cell_id"]) >> 12)
        cell_list.append(hex(cell_id))

    if len(cell_list) == 1:
        is_pingpang = False
    else:
        # 获取第1、3、5...位置的元素（索引0, 2, 4...）
        odd_pos_elements = cell_list[::2]
    # 获取第2、4、6...位置的元素（索引1, 3, 5...）
        even_pos_elements = cell_list[1::2]

    # 检查所有奇数位置元素是否相同
        all_odd_same = all(x == odd_pos_elements[0] for x in odd_pos_elements)
    # 检查所有偶数位置元素是否相同
        all_even_same = all(x == even_pos_elements[0] for x in even_pos_elements)

        is_pingpang = all_odd_same and all_even_same

    cell_list = set(cell_list)
    return len(cell_list), cell_list, is_pingpang

def get_total_second(small_time1,big_time2):
    time_format = "%Y-%m-%d %H:%M:%S.%f"
    time1 = datetime.strptime(small_time1, time_format)
    time2 = datetime.strptime(big_time2, time_format)
    time_diff = time2 - time1
    total_time = time_diff.total_seconds()
    return total_time

def get_data(unique_user_list):
    beyond_4min_num = get_nMin_idel(unique_user_list, 4)
    beyond_10min_num = get_nMin_idel(unique_user_list, 10)
    base_num, cell_list, is_pingpang = get_base_num(unique_user_list)

    common_base_num = 0
    personal_base_num = 0

    total_second_time = get_total_second(unique_user_list[0]["procedure_start_time_on_gw"], unique_user_list[len(unique_user_list)-1]["procedure_start_time_on_gw"])
    return beyond_4min_num, beyond_10min_num, base_num, common_base_num, personal_base_num, is_pingpang, total_second_time

user_list = []
unique_user_list = []
header = ['msisdn', 'B_4_idel', 'B_10_idel', 'cell_num', 'common_cell_num', 'personal_cell_num', 'is_pingpang', 'toal_time']
    
with open("data1.csv", 'r', encoding='utf-8') as f1, open("data2.csv", 'r', encoding='utf-8') as f2, open('result.csv', 'w', encoding='utf-8', newline='') as w:
    i1 = csv.DictReader(f1)
    i2 = csv.DictReader(f2)
    w = csv.DictWriter(w, header)
    w.writeheader()
    for x in i1:
        user_list.clear()
        unique_user_list.clear()
        for y in i2:
            if x['msisdn'] == y['msisdn']:
                user_list.append(y)
        # 去重逻辑
        for i in user_list:
            if i not in unique_user_list:
                unique_user_list.append(i)
        
        beyond_4min_num, beyond_10min_num, base_num, common_base_num, personal_base_num, is_pingpang, total_second_time = get_data(unique_user_list)
        data = {'msisdn':x['msisdn'],"B_4_idel":beyond_4min_num, "B_10_idel":beyond_10min_num, 
               "cell_num":base_num, "common_cell_num":common_base_num, "personal_cell_num":personal_base_num,"is_pingpang":is_pingpang, "toal_time":total_second_time}
        
        w.writerow(data)    


# from datetime import datetime

# # 定义两个时间字符串
# time_str1 = "2025-06-23 10:00:24.142"
# time_str2 = "2025-06-26 10:04:27.544"

# # 解析时间字符串为datetime对象
# time_format = "%Y-%m-%d %H:%M:%S.%f"
# time1 = datetime.strptime(time_str1, time_format)
# time2 = datetime.strptime(time_str2, time_format)

# # 计算时间差
# time_diff = time2 - time1

# # 输出结果
# print(f"两个时间的差值为: {time_diff}")
# print(f"总秒数: {time_diff.total_seconds()}秒")
# print(f"天数: {time_diff.days}天")
# print(f"秒数: {time_diff.seconds}秒")
# print(f"微秒数: {time_diff.microseconds}微秒")
