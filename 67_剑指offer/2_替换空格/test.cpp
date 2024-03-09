#include<iostream>
// " " -> "%20"：增加了2*空格数的长度
int replaceSpace(char* str, int length){

    // 获取空格数目
    int spaceLength=0;
    for(int i=0; i<length; ++i){
        if(str[i]==' ') ++spaceLength;
    }
    // 结果字符串长度
    int resultLength=spaceLength*2+length;
    // 直接在原字符串上操作
    for(int i=length-1, j=resultLength-1; i>=0 && j!=i; --i, --j)  // j==i说明空格已经全部替换完成
    {
        if(str[i]!=' ') str[j]=str[i];                    // 不是空格直接复制
        else{
            str[j]='0';
            str[--j]='2';
            str[--j]='%';
        }

    }
    str[resultLength]='\0'; // 字符串结尾标志
    return resultLength;

}

void print_str(char* str, int length){
    for(int i=0;i<length;i++){
        std::cout<<str[i];
    }
    std::cout<<std::endl;   
}

int main(){
    char str[10]="1  2 3";
    int length=6;
    print_str(str,length);
    int result_length=replaceSpace(str,length);
    print_str(str,result_length);

}