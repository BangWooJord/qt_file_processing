#include "../headers/file_related.h"

std::atomic<long double> data_var;

int binary_write(std::string const &filename, std::filesystem::path &path){
    path /= filename;
    std::filesystem::create_directories(path.parent_path());
    std::ofstream file_write(path, std::ios::binary | std::ios::app);

    if(!file_write) return ERROR_OPENING_OFILE;
    for(auto i = 0; i < 60077770; ++i){
        long double wr = rand()%77777*i;
        file_write.write((char*)&wr, sizeof(wr));
    }
    file_write.close();
    return 0;
}
int binary_read(std::string const &path, long double &data){
    std::ifstream file_read(path.c_str(), std::ios::binary);
    if(!file_read) return ERROR_OPENING_IFILE;
    file_read.seekg (0, std::ifstream::beg);
    while(file_read.read((char*)&data, sizeof(data))){
        if(data > data_var) data_var = data;
    }
    file_read.close();
    return 0;
}