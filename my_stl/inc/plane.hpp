/*===============================================
 * 
 * 文件名：plane.hpp
 * 
 * 文件描述：
 *
 * 创建人：　Copyright 2020 Snow-lake, Inc
 *           suyinrong, 2020/3/13
 *
 * email:davirain.yin@gmail.com
 * 
 * 版本：1.0
 *
 * 修改记录：
 *
 *
 *============================================*/

#ifndef  _PLANE_HPP_
#define  _PLANE_HPP_

#include "line.hpp"
#include <vector>

namespace  snowlake{

template <typename t_DataType>
class plane
    : public Line<t_DataType>
{
public:
    plane() {}
    ~plane() {}

private:
    std::vector<Line<t_DataType>> m_plane;    
}; // class plane

}//namespace snowlake
#endif
