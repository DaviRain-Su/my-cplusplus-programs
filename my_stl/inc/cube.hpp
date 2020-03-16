/*===========================================
 *
 * 文件名：cube.hpp
 * 
 * 文件描述：
 *
 * 创建人：　Copyright 2020 Snow-lake, Inc
 *           suyinrong, 2020/3/13
 *
 * email: davirain.yin@gmail.com
 * 
 * 版本：1.0
 *
 * 修改记录：
 *
 * ======================================== */

#include <vector>
#include "plane.hpp"

namespace snowlake {

template<typename t_DataType>
class cube
    : public plane<t_DataType>
{
public:
    cube();
    ~cube();

private:
    std::vector<plane<t_DataType> > m_cube;
}; // cube

} // snowlake
