/*=======================================
 * 
 * 文件名：line.hpp
 * 
 * 文件描述：
 *
 * 创建人：Copyright 2020 snow-lake, Inc
 *          suyinrong, 2020/3/13
 *
 * email: davarain.yin@gmail.com
 * 
 * 版本：1.0
 *
 * 修改记录：
 *
 * ====================================*/

#include <vector>

#ifndef _LINE_HPP_
#define _LINE_HPP_

namespace  snowlake{

template < typename t_DataType>
class Line
{
public:
    Line();
    ~Line();
   
private:
    std::vector<t_DataType> m_line;
};// class Line


}//namespace snowlake
#endif
