template <int N>
void combination(std::string &str, std::string strset) {
    if (N == str.size()) {
        std::cout << str << std::endl;
    }
    for (int i = 0; i < strset.size(); i++) {
        str.push_back(strset[i]);
        combination<N>(str, strset.substr(i + 1, strset.size() - 1));
        str.pop_back();
    }
}
