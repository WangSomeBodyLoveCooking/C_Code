#coding=utf-8
import time

# 1.时间戳---1970-01-01 00:00:00开始到现在的秒数
print(time.time())
# 1752066661.4252708

# 2.格式化时间字符串
print(time.strftime('%Y-%m-%d %H:%M:%S %A'))    # %A表示星期
print(time.strftime('%Y-%m-%d %X %A'))
print(time.strftime('%x %X %A'))
# 2025-07-09 21:11:01 Wednesday
# 2025-07-09 21:11:01 Wednesday
# 07/09/25 21:11:01 Wednesday

# 3.结构化时间
res = time.localtime()
print(res)
#time.struct_time(tm_year=2025, tm_mon=7, tm_mday=9, tm_hour=21, tm_min=15, tm_sec=37, tm_wday=2, tm_yday=190, tm_isdst=0)
print(res.tm_year)
print(res.tm_mday)
# 2025
# 9


import datetime
res = datetime.datetime.now()
print(res)
print(res.replace(microsecond=0))
# 2025-07-09 21:20:45.363899
# 2025-07-09 21:20:45

res = datetime.datetime.now() + datetime.timedelta(days=365)
print(res.replace(microsecond=0))
# 2026-07-09 21:23:25

res = datetime.datetime.now() + datetime.timedelta(days=-365)
print(res.replace(microsecond=0))
# 2024-07-09 21:24:00



# 时间戳   localtime/gmtime  --->    结构化时间      strftime--->        格式化字符串时间
# 时间戳   <---mktime                结构化时间      <---strptime        格式化字符串时间
print(time.localtime(time.time()))
print(time.gmtime(time.time()))
# time.struct_time(tm_year=2025, tm_mon=7, tm_mday=9, tm_hour=21, tm_min=30, tm_sec=9, tm_wday=2, tm_yday=190, tm_isdst=0)
# time.struct_time(tm_year=2025, tm_mon=7, tm_mday=9, tm_hour=13, tm_min=30, tm_sec=9, tm_wday=2, tm_yday=190, tm_isdst=0)

print(time.strftime('%Y-%m-%d %X', time.localtime(11111111)))
# 1970-05-09 22:25:11

res = '1970-05-09 22:25:11'
print(time.strptime(res, '%Y-%m-%d %X'))
# time.struct_time(tm_year=1970, tm_mon=5, tm_mday=9, tm_hour=22, tm_min=25, tm_sec=11, tm_wday=5, tm_yday=129, tm_isdst=-1)

res = time.strptime(res, '%Y-%m-%d %X')
print(time.mktime(res))
# 11111111.0

time.sleep(1)
print(time.asctime())
print(time.ctime(time.time()))
# Wed Jul  9 21:41:22 2025
# Wed Jul  9 21:41:22 2025

print(datetime.datetime.utcnow())
print(datetime.datetime.fromtimestamp(time.time())) # 时间戳转为字符串
# 2025-07-09 13:42:56.772486
# 2025-07-09 21:42:56.772486