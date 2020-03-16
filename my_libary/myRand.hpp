/*===========================================
 * 文件名：myRand.hpp
 * 
 * 文件描述：随机生成库文件
 *
 * 创建人：Copyright 2020 Snow-lake, Inc
 *          suyinrong, 2020/3/16
 *
 * email: davarain.yin@gmail.com
 * 
 * 版本：1.0
 *
 * 修改记录：
 * 
 * ======================================== */

#ifndef __MY_RAND__HPP__
#define __MY_RAND__HPP__

namespace  snowlake {

#include <iomanip>
#include <ctime>

/*===========================================
 *
 * 函数名：GenerateFloat
 *
 * 参数:
 *  const DataSize datasize : 生成序列的长度
 *  const t_DataType begin　：　生成的范围的起始端
 *  const t_DataType end　: 生成的范围的尾端
 *
 * 功能: 生成给定范围大小的一个（泛型t_DataType)随机序列
 *  
 * 返回值: void
 *
 * 抛出异常：
 *
 * 创建人：suyinrong 2020/3/16
 *
 *========================================================= */
template<typename t_DataType, typename  DataSize = int>
std::vector<t_DataType> GenerateFloat(const DataSize datasize,
                                      const t_DaTaType begin, 
                                      const t_DataType end)
{
    std::vector<t_DataType> _FloatVec;
    _FloatVec.resize(datasize);
    
    /* setting random float point */
    std::default_random_engine e(time(NULL));
    std::uniform_real_distribution<t_DaTaType> Unifom(begin, end);
    /*构造dataType vec*/
    for(decltype(DataSize) i = 0; i < datasize; ++i){
        _FloatVec[i] = Unifom(e);
    }
    
    return std::move(_FloatVec);
}// GenerateFloat

}; // namespace snowlake

#endif
