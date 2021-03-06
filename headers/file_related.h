#ifndef QT_FILE_PROCESSING_FILE_RELATED_H
#define QT_FILE_PROCESSING_FILE_RELATED_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <mutex>
#include <filesystem>
#include <random>
#include <queue>
#include "ERR_ENUM.h"

//writing random numbers into binary file
int binary_write(std::string const &filename, std::filesystem::path &path);
//reads binary file, and processes its data
int binary_read(std::string const &path,
	std::mutex& buffer_mtx, std::queue<long double> buffer_q, 
	std::condition_variable& buffer_cv);

#endif //QT_FILE_PROCESSING_FILE_RELATED_H
