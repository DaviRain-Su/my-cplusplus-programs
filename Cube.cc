#include <iostream>
#include <vector>

using std::vector;

#define CUBE_SIZE 8

static int HEIGHT = CUBE_SIZE;
static int WIDTH = CUBE_SIZE;
static int DEPTH = CUBE_SIZE;

int main()
{

    vector<vector<vector<int>>> m_cube(HEIGHT);
    for(int i = 0; i < HEIGHT; ++i)
    {
        m_cube[i].resize(WIDTH); // 一维
        
        for(int j = 0; j < WIDTH; ++j)
            m_cube[i][j].resize(DEPTH);
    }


    int tmp = 0; 
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            for(int k = 0; k < DEPTH; ++k)
                m_cube[i][j][k] = tmp++;
        }
    }
    /*lambda expression*/
    auto Print = [m_cube](){
        for(int i = 0; i < HEIGHT; ++i){
            for(int j = 0; j < WIDTH; ++j){
                for(int k = 0; k < DEPTH; ++k)
                    std::cout << m_cube[i][j][k] << " ";
                std::cout << std::endl;
            }
            std::cout << "--------------" << std::endl;
            std::cout << std::endl;
        }
    };
    
    Print();

    return 0;
}

