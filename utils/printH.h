#include <iostream>
#include <vector>

void printVector3D(const std::vector<std::vector<std::vector<int>>>& input) {
    std::cout<<"["<<std::endl;
    for (auto& v1: input) {
        std::cout<<"["<<std::endl;
        for (auto& v2 : v1) {
            for(auto& v3: v2) {
                std::cout<<v3<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<"]"<<std::endl;
    }
    std::cout<<"]"<<std::endl;
}

void printVector1D(const std::vector<int>& input) {
    for(auto& i:input) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}