//图书管理系统 孙广宇 20180200920 计科1804  编码：utf-8
/*25. 图书管理系统
要求：
（1）该系统主要处理图书馆中的图书信息以及供应商供应图书的信息。
（2）图书信息主要包括：图书编号、图书名称、图书类型、作者、出版社、库存等内容。
（3）供应商信息包括：供应商编号、供应商名称、供书类型、地址、电话等。
（4）其中的如数类型和供书类型都是书籍类型，如信息类、建筑类、化学类、生物类等
（5）完成以下操作：实现图书信息和图书供应商信息以及书籍类型信息的添加、修改、删除和查询，
    供应商向图书馆供应图书的情况查询、统计
提示：
建立书籍类型类、图书类、供应商类。
书籍类型、图书信息、供应商的初始化。
书籍类型、图书信息、供应商的添加、修改、删除、查找。
书籍类型、图书信息、供应商的的输出
对图书信息按编号、书名排序。
将图书信息和供应商信息保存为文件。*/
#include <iostream>
#include <string.h>  //string字符串
#include <fstream>   //文件输入输出
#include <windows.h> //Sleep函数
using namespace std;

void menu()
{
    system("cls"); //                                                
    cout << "**********************************" << endl;
    cout << "*-----欢迎使用图书管理系统v1.0---*" << endl;
    cout << "*---------1.按序查找图书---------*" << endl;
    cout << "*---------2.管理图书信息---------*" << endl;
    cout << "*---------3.书籍类型管理---------*" << endl;
    cout << "*---------4.供应商管理-----------*" << endl;
    cout << "*---------5.统计供书情况---------*" << endl;
    cout << "*---------6.保存-----------------*" << endl;
    cout << "*---------7.退出-----------------*" << endl;
    cout << "**********************************" << endl;
    cout << "请输入1-7:";
}
//menu1-4为二级菜单
void menu1()
{
    system("cls");
    cout << "**********************************" << endl;
    cout << "*-----------书籍类型管理---------*" << endl;
    cout << "*---------1.按书号排序-----------*" << endl;
    cout << "*---------2.按书名排序-----------*" << endl;
    cout << "*---------3.返回-----------------*" << endl;
    cout << "**********************************" << endl;
    cout << "请输入1-3:";
}
void menu2()
{
    system("cls");
    cout << "**********************************" << endl;
    cout << "*-----------图书信息管理---------*" << endl;
    cout << "*---------1.添加新的图书---------*" << endl;
    cout << "*---------2.修改图书信息---------*" << endl;
    cout << "*---------3.删除图书信息---------*" << endl;
    cout << "*---------4.按照书号查找---------*" << endl;
    cout << "*---------5.查看所有图书---------*" << endl;
    cout << "*---------6.返回-----------------*" << endl;
    cout << "**********************************" << endl;
    cout << "请输入1-6:";
}
void menu3()
{
    system("cls");
    cout << "**********************************" << endl;
    cout << "*-----------书籍类型管理---------*" << endl;
    cout << "*---------1.添加书籍类型---------*" << endl;
    cout << "*---------2.修改书籍类型---------*" << endl;
    cout << "*---------3.删除书籍类型---------*" << endl;
    cout << "*---------4.查找书籍类型---------*" << endl;
    cout << "*---------5.查看所有类型---------*" << endl;
    cout << "*---------6.返回-----------------*" << endl;
    cout << "**********************************" << endl;
    cout << "请输入1-6:";
}

void menu4()
{
    system("cls");
    cout << "**********************************" << endl;
    cout << "*-----------供应商管理-----------*" << endl;
    cout << "*---------1.添加供应商-----------*" << endl;
    cout << "*---------2.修改供应商-----------*" << endl;
    cout << "*---------3.删除供应商-----------*" << endl;
    cout << "*---------4.查找供应商-----------*" << endl;
    cout << "*---------5.所有供应商-----------*" << endl;
    cout << "*---------6.返回-----------------*" << endl;
    cout << "**********************************" << endl;
    cout << "请输入1-6:";
}
//统计已输入的类型、图书、供应商个数
int typesum;
int booksum;
int suppliersum;

class Type //图书类型
{
public:
    string leixing;
    void input_leixing() //添加类型
    {
        cout << "请输入类型名:";
        cin >> leixing;
    }
    string get_leixing() //获取类型
    {
        return leixing;
    }
} type[20];

class Book //图书
{
private:
    string bnum;      //书号
    string bname;     //书名
    string writer;    //作者
    string publisher; //供应商
    int store;        //库存
    Type type;        //类型

public:
    Book() {}
    Book(string a, string b, string c, string d, int e, string f)
    {
        string bnum = a;
        string bname = b;
        string writer = c;
        string publisher = d;
        int store = e;
        type.leixing = f;
    }

    string get_bnum() { return bnum; }
    string get_bname() { return bname; }
    string get_writer() { return writer; }
    string get_publisher() { return publisher; }
    int get_store() { return store; }
    string get_leixing() { return type.get_leixing(); }
    void input_book()
    {
        cout << "请输入书号:";
        cin >> bnum;
        cout << "请输入书名:";
        cin >> bname;
        cout << "请输入类型:";
        cin >> type.leixing;
        cout << "请输入作者:";
        cin >> writer;
        cout << "请输入出版商:";
        cin >> publisher;
        cout << "请输入库存:";
        cin >> store;
    }
    void display_book() //显示图书信息
    {
        cout << "书号:" << bnum << endl;
        cout << "书名:" << bname << endl;
        cout << "类型:" << type.leixing << endl;
        cout << "作者:" << writer << endl;
        cout << "出版商:" << publisher << endl;
        cout << "库存:" << store << endl;
    }

    void change_book() //修改图书信息
    {

        cout << "1.修改书号" << endl;
        cout << "2.修改书名" << endl;
        cout << "3.修改类型" << endl;
        cout << "4.修改作者" << endl;
        cout << "5.修改出版社" << endl;
        cout << "6.修改库存" << endl;
        cout << "请选择要进行的修改:";
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "请输入修改后的书号:" << endl;
            cin >> bnum;
            break;
        case 2:
            cout << "请输入修改后的书名:" << endl;
            cin >> bname;
            break;
        case 3:
            cout << "请输入修改后的类型:" << endl;
            cin >> type.leixing;
            break;
        case 4:
            cout << "请输入修改后的作者:" << endl;
            cin >> writer;
            break;
        case 5:
            cout << "请输入修改后的出版社:" << endl;
            cin >> publisher;
            break;
        case 6:
            cout << "请输入修改后的库存:" << endl;
            cin >> store;
            break;
        default:
            break;
        }
        cout << "修改成功";
        Sleep(1000);
    }
} book[1000];

class Supplier //供应商
{
private:
    string snum;    //供应商编号
    string sname;   //供应商名称
    string address; //地址
    string phone;   //电话
    Type type;      //类型
public:
    Supplier() {}
    Supplier(string a, string b, string c, string d, string e, string f)
    {
        string snum = a;
        string sname = b;
        string leixing = c;
        string address = d;
        string phone = e;
        type.leixing = f;
    }
    string get_snum() { return snum; }
    string get_sname() { return sname; }
    string get_address() { return address; }
    string get_phone() { return phone; }
    string get_leixing() { return type.leixing; }
    void input_supplier()
    {
        cout << "请输入供应商编号:";
        cin >> snum;
        cout << "请输入供应商名称:";
        cin >> sname;
        cout << "请输入供书类型:";
        cin >> type.leixing;
        cout << "请输入供应商地址:";
        cin >> address;
        cout << "请输入电话:";
        cin >> phone;
    }
    void display_supplier() //显示供应商信息
    {
        cout << "编号:" << snum << endl;
        cout << "名称:" << sname << endl;
        cout << "类型:" << type.leixing << endl;
        cout << "地址:" << address << endl;
        cout << "电话:" << phone << endl;
    }
    void change_supplier() //修改供应商信息
    {
        cout << "1.修改编号" << endl;
        cout << "2.修改名称" << endl;
        cout << "3.修改类型" << endl;
        cout << "4.修改地址" << endl;
        cout << "5.修改电话" << endl;
        cout << "请选择要进行的修改:";
        int b;
        cin >> b;
        switch (b)
        {
        case 1:
            cout << "请输入修改后的编号:" << endl;
            cin >> snum;
            break;
        case 2:
            cout << "请输入修改后的名称:" << endl;
            cin >> sname;
            break;
        case 3:
            cout << "请输入修改后的类型:" << endl;
            cin >> type.leixing;
            break;
        case 4:
            cout << "请输入修改后的地址:" << endl;
            cin >> address;
            break;
        case 5:
            cout << "请输入修改后的电话:" << endl;
            cin >> phone;
            break;
        default:
            break;
        }
        cout << "修改成功";
        Sleep(1000);
    }
} supplier[20];

class Supply : public Book, public Supplier //供书情况  继承自书和供应商
{
private:
    int i, j, k;

    string a;
    string sbook[1000]; //sbook为每个供应商所对应的图书

public:
    void tongji()
    {
        cout << "请输入要查找的图书类型:";
        cin >> a;

        for (j = 0; j < booksum; j++)
        {
            for (i = 0; i < booksum - j - 1; i++)
            {
                if (a.compare(book[j].get_leixing()) == 0)
                {
                    sbook[i] = book[j].get_bname();
                }
                else
                {
                    break;
                }
            }
        }
    }
    void get_sbook()
    {
        for (i = 0; i < booksum; i++)
        {
            cout << sbook[1] << endl;
        }
        system("pause");
    }
} sp;

void sort_book_num() //按编号对图书排序
{
    int i, j;
    Book temp1;
    for (i = 0; i < booksum; i++)
    {
        for (j = 0; j < booksum - i - 1; j++)
        {
            if (book[j].get_bnum() > book[j + 1].get_bnum())
            {
                temp1 = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp1;
            }
        }
    }
    for (i = 0; i < booksum; i++)
    {
        cout << "--------------------" << endl;
        book[i].display_book();
        cout << "--------------------" << endl;
    }
    system("pause");
}
void sort_book_name() //按书名对图书排序
{
    int i, j;
    Book temp2;
    for (i = 0; i < booksum; i++)
    {
        for (j = 0; j < booksum - i - 1; j++)
        {
            if (book[j].get_bname() > book[j + 1].get_bname())
            {
                temp2 = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp2;
            }
        }
    }
    for (i = 0; i < booksum; i++)
    {
        cout << "--------------------" << endl;
        book[i].display_book();
    }
    system("pause");
}
int keyin1() //对图书排序menu1选择函数
{
    Book books;
    int key1 = 0;
    cin >> key1;
    switch (key1)
    {
    case 1:
        sort_book_num();
        break;
    case 2:
        sort_book_name();
        break;
    case 3:
        break;
    default:
        cout << "输入错误，请重试" << endl;
    }
    return key1;
}

int keyin2(Book book[]) //图书信息管理menu2选择函数
{
    int key2 = 0;
    int a, i, j, flag;
    flag = 0;
    string s, m, n, o; //s:查询  m:修改 //n:删除
    cin >> key2;
    switch (key2)
    {
    case 1:
        book[booksum].input_book();
        booksum++;
        cout << "添加成功" << endl;
        Sleep(1000);
        break;
    case 2:
        cout << "请输入要修改的书号:";
        cin >> m;
        for (i = 0; i < 1000; i++)
            if (m.compare(book[i].get_bnum()) == 0)
            {
                flag = 1;
                book[i].change_book();
            }
        if (0 == flag)
        {
            cout << "该书号不存在!";
            Sleep(1000);
            break;
        }
        break;
    case 3: //删除图书
        cout << "请输入要删除的书号:";
        cin >> n;
        for (j = 0; j < booksum; j++)
        {
            if (n.compare(book[j].get_bnum()) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (0 == flag)
        {
            cout << "该书号不存在!";
            Sleep(1000);
            break;
        }
        for (i = j; i < booksum; i++)
        {
            book[i] = book[i + 1];
        }
        booksum--;
        break;
    case 4:
        cout << "请输入要查询的书号:";
        cin >> s;
        for (i = 0; i < 1000; i++)
            if (s.compare(book[i].get_bnum()) == 0)
            {
                flag = 1;
                cout << "--------------------" << endl;
                book[i].display_book();
                cout << "--------------------" << endl;
            }
        if (0 == flag)
        {
            cout << "该书号不存在!";
            Sleep(1000);
            break;
        }
        system("pause");
        break;
    case 5: //显示所有图书
        int i;
        for (i = 0; i < booksum; i++)
        {
            cout << "--------------------" << endl;
            book[i].display_book();
            cout << "--------------------" << endl;
        }
        system("pause");
        break;
    case 6:
        break;
    default:
        cout << "输入错误，请重试" << endl;
        Sleep(1000);
        break;
    }
    return key2;
}

int keyin3(Type type[]) //图书类型管理menu3选择函数
{
    int i, j;
    int key3 = 1;
    cin >> key3;
    switch (key3)
    {
    case 1: //添加书籍类型
        type[typesum].input_leixing();
        typesum++;
        break;
    case 2: //按序号修改类型
        cout << "请输入要修改的类型序号(1--20):";
        cin >> i;
        if (i > typesum)
        {
            cout << "该序号不存在!";
            Sleep(1000);
            break;
        }
        type[i - 1].input_leixing();
        cout << "修改成功";
        Sleep(1000);
        break;
    case 3: //删除类型
        cout << "请输入要删除的类型序号(1--20):";
        cin >> j;
        if (j > typesum)
        {
            cout << "该序号不存在!";
            Sleep(1000);
            break;
        }
        for (i = j; i < typesum; i++)
        {
            type[i - 1] = type[i];
        }
        typesum--;
        break;
    case (4): //按序号查找类型
        cout << "请输入类型序号(1--20):";
        cin >> i;
        if (i > typesum)
        {
            cout << "该序号不存在!";
            Sleep(1000);
            break;
        }
        cout << "类型" << i << ":" << type[i - 1].get_leixing() << endl;
        system("pause");
        break;
    case (5): //显示所有类型
        int i;
        for (i = 0; i < typesum; i++)
        {
            cout << "类型" << i + 1 << ":" << type[i].get_leixing() << endl;
        }
        system("pause");
        break;
    case (6): //返回
        break;
    default:
        cout << "输入错误，请重试" << endl;
    }
    return key3;
}

int keyin4(Supplier supplier[]) //供应商管理menu4选择函数
{
    int key4 = 0;
    int i, j, flag;
    flag = 0;
    string s, m, n;
    cin >> key4;
    switch (key4)
    {
    case (1):
        supplier[suppliersum].input_supplier();
        suppliersum++;
        break;
    case (2):
        cout << "请输入要修改的书号:";
        cin >> m;
        for (i = 0; i < 20; i++)
            if (m.compare(supplier[i].get_snum()) == 0)
            {
                flag = 1;
                supplier[i].change_supplier();
            }
        if (0 == flag)
        {
            cout << "该供应商编号不存在!";
            Sleep(1000);
            break;
        }
        break;
    case (3):
        cout << "请输入要删除的供应商编号:";
        cin >> n;
        for (j = 0; j < booksum; j++)
        {
            if (n.compare(supplier[j].get_snum()) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (0 == flag)
        {
            cout << "该供应商编号不存在!";
            Sleep(1000);
            break;
        }
        for (i = j; i < suppliersum; i++)
        {
            supplier[i] = supplier[i + 1];
        }
        suppliersum--;
        break;
    case (4):
        cout << "请输入要查询的供应商编号:" << endl;
        cin >> s;
        for (i = 0; i < 20; i++)
            if (s.compare(supplier[i].get_snum()) == 0)
            {
                flag = 1;
                cout << "--------------------" << endl;
                supplier[i].display_supplier();
                cout << "--------------------" << endl;
                break;
            }
        if (0 == flag)
        {
            cout << "该编号不存在!";
            Sleep(1000);
            break;
        }
        system("pause");
        break;
    case (5):
        int i;
        for (i = 0; i < suppliersum; i++)
        {
            cout << "--------------------" << endl;
            supplier[i].display_supplier();
            cout << "--------------------" << endl;
        }
        system("pause");
        break;
    case (6):
        break;
    default:
        cout << "输入错误，请重试" << endl;
        break;
    }
    return key4;
}

void keyin(Type type[], Book book[], Supplier supplier[]) //主菜单选择
{
    int key = 0;
    cin >> key;
    switch (key)
    {
    case 1:
        while (1)
        {
            menu1();
            int flag1 = keyin1();
            if (flag1 == 3) //在 menu1 选择3时 返回
                break;
            //system("pause");
        }
        break;
    case 2:
        while (1)
        {
            menu2();
            int flag2 = keyin2(book);
            if (flag2 == 6) //在 menu2 选择6时 返回
                break;
            //system("pause");
        }
        break;
    case 3:
        while (1)
        {
            menu3();
            int flag3 = keyin3(type);
            if (flag3 == 6) //在 menu3 选择6时 返回
                break;
            //system("pause");
        }
        break;
    case 4:
        while (1)
        {
            menu4();
            int flag4 = keyin4(supplier);
            if (flag4 == 6) //在 menu3 选择6时 返回
                break;
            //system("pause");
        }
        break;
    case 5:
        sp.tongji();
        sp.get_sbook();
        system("pause");
        break;
    case 6:
        break;
    case 7:
        exit(0);
        break;
    default:
        cout << "输入错误，请重试" << endl;
    }
}

int main()
{
    while (1)
    {
        menu();                      //显示主菜单
        keyin(type, book, supplier); //对主菜单进行选择
        system("cls");
    }
    system("pause");
    return 0;
}
