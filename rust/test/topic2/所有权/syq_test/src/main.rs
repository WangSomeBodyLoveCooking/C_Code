// 进阶8 函数传参所有权与借用选择
// 分别实现：拿走所有权打印、借用打印两种函数调用方式。
fn test_top_8(){
    let mut s = String::from("value");
    func8_2(&s);
    s = func8_1(s);
    println!("{:?}", s);
}

fn func8_1(s:String)->String{
    println!("{:?}",s);
    s
}

fn func8_2(s:&str){
    println!("{:?}",s);
}

// 进阶9 切片借用避免所有权转移
// 截取字符串后半段，使用切片引用，不消耗原字符串所有权。
fn test_top_9(){
    let s = "string";
    func8_2(&s[3..]);
    println!("{:?}", s);
}

// 进阶10 结构体内部字段借用
// 定义包含 String 字段的结构体，编写方法借用内部字段返回切片。
#[derive(Debug)]
struct User{
    name:String,
    age:u8
}

fn test_top_10(){
    let u1 = User{name:"rust".to_string(), age:20};
    let u1_name = func10(&u1.name[1..]);
    println!("{:?}", u1);
    // _func10_2(u1);
    println!("{:?}", u1_name);
}

fn func10(s:&str)->&str{
    s
}

fn _func10_2(u:User){
    println!();
}



fn main() {
    test_top_8();
    test_top_9();
    test_top_10();
}
