/* c header */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* c++ header */
#include <vector> //vector
#include <iostream> // cout , endl
#include <random> //default_random_engine , uniform_real_distribution
#include <ctime> // time(NULL)
#include <fstream> //ifstream, ofstream
#include <iomanip> //setiosflags
#include <algorithm>

//using std::swap;
using std::vector;
using std::endl;
using std::cout;

/*=======================================
 *
 * 函数名：Print
 * 
 * 参数：const vector<T>& vec
 *
 * 功能：打印泛型的向量
 *　
 * 返回值：void
 * 
 * 抛出异常：
 *
 * 创建人：suyinrong 2020/3/16
 *
 * =====================================*/
template <typename  T>
void Print(const vector<T>& vec)
{
    auto fn = [vec](){
        for(auto item : vec){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    };
    
    fn();
}
/*===========================================
 *
 * 函数名：GenerateFloat
 * 
 * 参数：
 *  const DataSize datasize;
 *  const t_DataType begin;
 *  const t_DataType end;
 *
 * 功能：生成给定范围大小的一个(泛型t_DataType)随机序列
 * 　datasize 为生成的序列长度
 *   begin 为生成的范围的起始端
 *   end　为生成的范围的尾端
 *
 * 返回值：vector<t_DataType>
 *
 * 抛出异常：
 *
 * 创建人：suyinrong 2020/3/16
 *
 * ========================================*/
template<typename t_DataType, typename DataSize = int>
std::vector<t_DataType>  GenerateFloat(const DataSize datasize, const t_DataType begin, const t_DataType end)
{
    std::vector<t_DataType> _FloatVec;
    _FloatVec.resize(datasize);

    /*setting random float point */
    std::default_random_engine e(time(NULL));
    std::uniform_real_distribution<t_DataType> Unifom(begin, end);
    /* 构造 dataType vec */
    for(int i = 0; i < datasize; ++i){
        _FloatVec[i] = Unifom(e);
    }

    return std::move(_FloatVec);
}
/*===============================================
 *
 * 函数名：MakeHexFloat
 * 
 * 参数：const t_DataType item;
 *  std::vector<HexType>& hexitem; 改变了hexitem的大小并赋值了其中的数据
 *
 * 功能：用于将一个浮点数转化为一个的整数并且是大小为４的大小的整数数组
 *       如果时double类型，就是将一个double转化为一个大小为８的整数数组
 *
 * 返回值：void
 *  
 * 抛出异常：
 *
 * 作者：suyinrong 2020/3/16
 * 
 *================================================== */
template<typename t_DataType, typename Int>
void MakeHexFloat(const t_DataType item, std::vector<Int>& hexitem)
{
    size_t hexitemSize = sizeof(t_DataType);
    hexitem.resize(hexitemSize); /*setting hexitem size */
    
    const size_t Size = sizeof(t_DataType) / sizeof(Int);

    unsigned char blist[Size];
    unsigned char* btemp = (unsigned char*)&item;
    
    for( size_t i = 0; i < Size; i++)
    {
        blist[i] = *(btemp + i);
    }

    /* litter endian*/
    for( int i = 3; i >= 0; i-- ) {
        hexitem[ i ] = blist[ i ];
    }

}
/*=======================================
 *
 * 函数名：SwapVec
 * 
 * 参数：　vector<T>& vec
 * 
 * 功能：
 *  交换输入中向量，交换的时头尾元素。
 *  这样就得到了，一个反转后的向量。
 *
 * 返回值：void
 *
 * 抛出异常：
 *
 * 创建人：suyinrong 2020/3/16
 *
 * ========================================*/
template<typename T>
void SwapVec(std::vector<T>& vec)
{
    for(size_t i = 0; i != vec.size()/2; ++i)
        swap(vec[i], vec[vec.size()-1 - i]);
}
/*============================================
 *
 * 函数名：writeBin
 *
 * 参数: const string filename;
 *      vector<t_DataType>& DataTypeVec1;
 *      vector<t_DataType>& DataTypeVec2;
 *      const DataSize datasize = 2048
 * 功能：
 *  将输入的两个t_DataType向量，的数据写入到文件中，
 *  以交错的形式存储数据，例如先存储v1中的item, 紧跟着存储
 *  v2的item.(这里做了一些变换，将输入的数据，以小端明文的方式存储下来)
 *
 *  返回值：void
 *  
 *  抛出异常：
 *
 *  作者：suyinrong 2020/3/16
 *
 *============================================*/
template<typename t_DataType, typename DataSize = int>
void writeBin(const std::string filename, 
              std::vector<t_DataType>& DataTypeVec1, 
              std::vector<t_DataType>&  DataTypeVec2, 
              const DataSize dataSize = 2048)
{
    std::ofstream outfile(filename, std::ios::binary);
    if(!outfile){
        std::cerr << "can't open outfile \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < dataSize; i++)
    {
        std::vector<char> temp1, temp2;
        MakeHexFloat<float, char>(DataTypeVec1[i], temp1);
        MakeHexFloat<float, char>(DataTypeVec2[i], temp2);

        outfile.write(reinterpret_cast<char*>(temp1.data()), temp1.size());
        outfile.write(reinterpret_cast<char*>(temp2.data()), temp2.size());
    }
    outfile.close();
}

template<typename t_DataType, typename DataSize = int>
void writeBin(const std::string filename, 
              std::vector<t_DataType>& DataTypeVec1, 
              std::vector<t_DataType>&  DataTypeVec2, 
              std::vector<t_DataType>& DataTypeVec3, 
              const DataSize dataSize = 2048)
{
    std::ofstream outfile(filename, std::ios::binary);
    if(!outfile){
        std::cerr << "can't open outfile \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < dataSize; i++)
    {
        std::vector<char> temp1, temp2, temp3;
        MakeHexFloat<float, char>(DataTypeVec1[i], temp1);
        MakeHexFloat<float, char>(DataTypeVec2[i], temp2);
        MakeHexFloat<float, char>(DataTypeVec3[i], temp3);
#if 0
        for(auto item : temp1)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
#endif 

#if 0
        for(size_t i = 0; i < temp1.size(); i++)
        {
            if(temp1[i] < 16)
                cout  << std::setiosflags(std::ios::uppercase) << std::hex << "0" << (int)temp1[i] << "";
            else 
                cout << std::setiosflags(std::ios::uppercase) << std::hex << (int)temp1[i] << "";
        }
        for(size_t i = 0; i < temp2.size(); i++)
        {
            if(temp2[i] < 16)
                cout << std::setiosflags(std::ios::uppercase) << std::hex << "0" << (int)temp2[i] << "";
            else 
                cout << std::setiosflags(std::ios::uppercase) << std::hex << (int)temp2[i] << "";
        }
        dec(cout);
        cout << endl;
#endif

#if 0
        char t1[4];
        char t2[4];
        for(int i = 0; i < 4 ; i++)
        {
            t1[i] = temp1[i];
            t2[i] = temp2[i];
        }
        outfile.write(t1, 4);
        outfile.write(t2, 4);
#endif 
//        SwapVec<char>(temp1);
//        SwapVec<char>(temp2);
        outfile.write(reinterpret_cast<char*>(temp1.data()), temp1.size());
        outfile.write(reinterpret_cast<char*>(temp2.data()), temp2.size());
        outfile.write(reinterpret_cast<char*>(temp3.data()), temp3.size());
    }
    outfile.close();
}

int main()
{

    const int FloatSize = 2048;
    const float Begin = -1.0;
    const float End = 1.0;
    vector<float> A;
    A = GenerateFloat<float>(FloatSize, Begin, End);
    sleep(10);
//    Print<float>(A);
    vector<float> B;
    B = GenerateFloat<float>(FloatSize, Begin, End);
    sleep(10);
//    Print<float>(B);
    vector<float> C;
    C = GenerateFloat<float>(FloatSize, Begin, End);
    
    const std::string filenameAB = "floatAB.bin";
    const std::string filenameABC = "floatABC.bin";
    writeBin<float>(filenameAB, A, B, FloatSize);
    writeBin<float>(filenameABC, A, B, C, FloatSize);

    //Print<float>(result);
    //cout << RAND_MAX << endl;

    return 0;
}

