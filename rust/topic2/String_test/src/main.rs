#![allow(unused_variables)]
fn main() {
    let s = String::from("hello world");

    let hello = &s[0..=5];
    let world = &s[6..11];

    let len = s.len();
    
    let slice = &s[4..len];
    let slice = &s[4..];
    println!("{}", slice);

    let slice = &s[0..len];
    let slice = &s[..];
    println!("{}", slice);

    // 注意
    // let s = "中国人";
    // let a = &s[0..2];
    // println!("{}",a);

    let mut s = String::from("hello world");

    let word = first_word(&s);

    s.clear(); // error!    可变与不可变引用同时存在

    // println!("the first word is: {}", word);    


    // 2. String和&str的相互转换
    // String转&str
    let s = String::from("hello,world!");
    // &s;
    // &s[..];
    // s.as_str();

    // s.as_str();

    // 3. rust不支持字符串索引
    let str = "中国人民";
    let h = &str[3..6];
    // let h = str[1]; // error
    println!("{}",h);

    // 4. 字符串操作
    // 4.1 追加--原地修改
    let mut s = String::from("Hello ");

    s.push_str("rust");
    println!("追加字符串 push_str() -> {}", s);

    s.push('!');
    println!("追加字符 push() -> {}", s);

    // 4.2 插入---原地修改
    let mut s = String::from("Hello rust!");
    s.insert(5, ',');
    println!("插入字符 insert() -> {}", s);
    s.insert_str(6, " I like");
    println!("插入字符串 insert_str() -> {}", s);

    // 4.3 替换
    // replace() 返回新值；适用String和&str；全替换
    let string_replace = String::from("I like rust. Learning rust is my favorite!");
    let new_string_replace = string_replace.replace("rust", "RUST");
    dbg!(new_string_replace);

    // replacen 返回新值；n替换；适用String和&str
    let string_replace = "I like rust. Learning rust is my favorite!";
    let new_string_replace = string_replace.replacen("rust", "RUST", 1);
    dbg!(new_string_replace);

    // replace_range()  原地修改；只使用String；要可变
    let mut string_replace_range = String::from("I like rust!");
    string_replace_range.replace_range(7..8, "R");
    dbg!(string_replace_range);
}

fn first_word(s: &String) -> &str {
    &s[..1]
}