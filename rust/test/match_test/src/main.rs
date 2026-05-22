fn main() {
    test1(8);
    test2(100);
    test3((0,0));
    test4(("wzx",28,"男"));
    test5(DeviceState::On);
    test6(msg::Num(10));
    test6(msg::Text("10".to_string()));
    test7(Some(10));
    test8();
}

// 基础数值匹配
fn test1(x:u8){
    match x{
        1 => println!("星期一"),
        2 => println!("星期二"),
        3 => println!("星期三"),
        _ => println!("未知日期")
    }
}

// 范围模式匹配（成绩评级）
fn test2(s:u8){
    match s{
        90..=100 => println!("优秀"),
        80..=89 => println!("良好"),
        70..=79 => println!("中等"),
        60..=69 => println!("及格"),
        0..=59 => println!("不及格"),
        other => println!("未知成绩{other}"),
    }
}

// 元组解构匹配
fn test3(point:(i32,i32)){
    match point{
        (0,0) => println!("原点"),
        (0,_) => println!("Y轴"),
        (_,0) => println!("X轴"),
        _ => println!("普通坐标"),
    }
}

// 单值忽略匹配
fn test4(X:(&str,u8,&str)){
    match X{
        (_,18,_) => println!("年龄True"),
        _ => println!("年龄false")
    }
}

// 枚举 + 模式匹配（状态判断）
#[derive(Debug)]
enum DeviceState {
    On,
    Off,
    Sleep,
}

fn test5(state:DeviceState){
    match state{
        DeviceState::On => println!("设备正常运行"),
        DeviceState::Off => println!("设备已关闭"),
        DeviceState::Sleep => println!("设备进入休眠"),
    }
}

// 枚举带值匹配
enum msg{
    Text(String),
    Num(i32)
}
fn test6(m:msg){
    match m{
        msg::Text(s) => println!("Strint:{s}"),
        msg::Num(s) => println!("Num:{s}"),
    }
}

// ** if let 简化匹配 **
fn test7(x:Option<i32>){
    if let Some(a) = x{
        println!("the num is {a}");
    }

    let none_num: Option<i32> = None;
    if let None = none_num {
        println!("空值");
    } else {
        println!("有值");
    }
}

// while let 循环匹配
fn test8(){
    let mut v = vec![1,2,3,4,5,6];
    while let Some::<i32>(x) = v.pop(){
    // while let i32 = v.pop(){ error!会死循环
        println!("yes{x}");
    }
}