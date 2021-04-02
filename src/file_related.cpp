#include "../headers/file_related.h"

int binary_write(std::string const &filename, std::filesystem::path &path){
    path /= filename;
    std::filesystem::create_directories(path.parent_path());
    std::ofstream file_write(path, std::ios::binary | std::ios::app);

    if(!file_write) return ERROR_OPENING_OFILE;
    for(auto i = 0; i < 99999; ++i){
        long double wr = rand()%1000;
        file_write.write((char*)&wr, sizeof(wr));
    }
    file_write.close();
    return 0;
}
int binary_read(std::string const &path, 
    std::mutex &buffer_mtx, std::queue<long double> buffer_q, 
    std::condition_variable &buffer_cv)
{
    std::ifstream file_read(path.c_str(), std::ios::binary);
    if(!file_read) return ERROR_OPENING_IFILE;
    long double _data;
    while(file_read.read((char*)&_data, sizeof(_data))){
        std::unique_lock<std::mutex> lck(buffer_mtx);
        buffer_q.push(_data);
        buffer_cv.notify_one();
    }
    file_read.close();
    return 0;
}