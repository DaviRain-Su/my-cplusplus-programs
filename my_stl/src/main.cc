#include <iostream>
#include "../inc/stack.hpp"
#include "../inc/readBin.hpp"
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <fstream>

using std::ifstream;
using std::endl;
using std::cout;

int main()
{
    int fd;
    const char* filename = "../data/v2dt2.dat";
    fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    struct stat sb;
    if(-1 == fstat(fd, &sb))
    {
        perror("lastat");
        exit(EXIT_FAILURE);
    }
    cout << "File size: " << sb.st_size << endl;
//    printf("File size:\t %lld bytes\n", (long long) sb.st_size);
    
    ifstream file(filename, ios::binary);
    file.unsetf(ios::skipws);
    std::streampos fileSize;
    file.seekg(0, ios::end);
    fileSize = file.tellg();
 //   printf("File size:\t %ld ", fileSize);
    cout << "File size: " << fileSize << endl;
    
    vector<float> vec;

    readBin(filename, fileSize, vec);
    int cnt = 0;
    for(auto iter : vec){
        std::cout << iter << " ";
        cnt++;
    }

    std::cout << std::endl;
    cout << "cnt = " << cnt << endl;
    cout << "File size: " << fileSize << endl;
    return 0;
}

