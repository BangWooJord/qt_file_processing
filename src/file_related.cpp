#include "../headers/file_related.h"

std::atomic<long double> data_var = 123151321412414241241241241.2124244;

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
    std::random_device rd;
    std::mt19937_64 mt(rd());
    while(file_read.read((char*)&data, sizeof(data))){
            std::uniform_real_distribution<long double> uniform_dist(0, std::numeric_limits<long double>::max());
            data_var = data_var / uniform_dist(mt);
    }
    file_read.close();
    return 0;
}