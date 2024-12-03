#include "fstream"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>


bool comp(int a, int b) {
    return b >= a;
}

int main() {
    std::ifstream rf("input1.txt");
    if (!rf.is_open()) {
        std:: cout << "Can't open file" << std::endl;
    }
    std::string line;

    std::vector<int> list1;
    std::vector<int> list2;
    int count = 0;
    while(getline(rf, line)) {
        line += " ";
        count += 1;
        std::string num_str;
        int a = 0;
        int b = 0;
        for (int i=0; i<line.length(); i++) {
            if (line[i] != ' ' || i == line.length()-2) {
                num_str += line[i];
            }
            else {
                if (num_str != "") {
                    if (a == 0) { a = std::stoi(num_str); list1.push_back(a);}
                    else { b = std::stoi(num_str);  list2.push_back(b);}
                  }
                num_str = "";
            }
        }
    }
    rf.close();
    std::sort(list1.begin(), list1.end(), comp);
    std::sort(list2.begin(), list2.end(), comp);

    int sum_of_diff = 0;
    for (int i=0; i<list1.size(); i++) {
        sum_of_diff += abs(list1[i] - list2[i]);
    }
    std:: cout << "Sum of difference: " << sum_of_diff << std::endl;
    return 0;
}
