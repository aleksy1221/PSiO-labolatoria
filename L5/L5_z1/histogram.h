#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>
using Bin = int;
using Frequency = int;

template <typename T>
class Histogram
{
private:
    std::map<T, Frequency> bins_;

    friend std::ostream& operator<<(std::ostream & out,
                                    const Histogram& histogram);

    friend std::ofstream& operator<<(std::ofstream & out,
                                     const Histogram& histogram);

    friend std::istream& operator>>(std::istream & in,
                                    Histogram& histogram);
public:
    Histogram()
    {

    }

    Histogram(const std::vector<T> &data) {

        for (const auto value : data) {
            bins_[value]++;
        }
    }


    void emplace(const T& value){
        bins_[value]++;
    }
    void emplace(const std::vector<T>& values){
        for (const auto value : values) {
            bins_[value]++;
        }
    }
    void clear(){
        Histogram::bins_.clear();
    }

    bool read_csv(const std::string &filename, char delim, int column_idx){
        std::ifstream myFile(filename);
        std::vector<std::pair<std::string, std::vector<int>>> result;
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");
        std::string line, colname;
        int val;
        if(myFile.good())
        {
            std::getline(myFile, line);
            std::stringstream ss(line);

            while(std::getline(ss, colname, delim)){
            }
        }
        while(std::getline(myFile, line))
        {
            std::stringstream ss(line);
            int colIdx = 0;
            while(ss >> val){

                // Add the current integer to the 'colIdx' column's values vector
                result.at(colIdx).second.push_back(val);
                if(colIdx==column_idx){
                    emplace(val);
                }

                if(ss.peek() == ',') ss.ignore();
                colIdx++;
            }
        }

        // Close file
        myFile.close();

        return true;
    }

    bool from_csv(const std::string &filename, char delim, int column_idx){

        std::fstream wej(filename,std::ios::in);
        if(wej.good()){
            std::string line, word;
            std::vector<std::string> row;
            while(!wej.eof()){
                std::getline(wej, line);
                std::stringstream s(line);
                int pom=0;
                while (getline(s, word, delim)) {
                    if(pom==column_idx){
                        emplace(std::stoi(word));
                    }
                    pom++;
                }
            }
            wej.close();
        }
        else{
            return false;
        }
        return true;
    }

    std::pair<T, T> range() const{
        std::pair<T, T> w;
        auto min=std::min_element(bins_.begin(),bins_.end());
        auto max=std::max_element(bins_.begin(),bins_.end());
        for(auto it =bins_.begin(); it !=bins_.end(); it++){
            if(it==min){
                w.first=it->first;
            }
            if(it==max){
                w.second=it->first;
            }
        }
        return w;
    }

    std::pair<T, int> max() const{
        std::pair<T, int> w(0, 0);
        for(auto it =bins_.begin(); it != bins_.end(); it++){
            if(it->second>w.second){
                w.second=it->second;
                w.first=it->first;
            }
        }
        return w;
    }

    std::vector<T> unique_bins() const{
        std::vector<T> w;
        for(auto it =bins_.begin(); it != bins_.end(); it++){
            w.push_back(it->first);
        }
        return w;

    }

    using BinsVector = std::vector<std::pair<T, Frequency>>;
    BinsVector unique_items() const{
        BinsVector w;
        for(auto it =bins_.begin(); it != bins_.end(); it++){
            std::pair<T, int> p(it->first,it->second);
            w.push_back(p);
        }
        return w;
    }

    Histogram& operator<<(T value) {
        emplace(value);
        return *this;
    }

    static Histogram generate(int min, int max, int count);// tworzy histogram zawierający wartości losowe, gdzie kolejne argumenty oznaczają wartość minimalną, maksymalną, liczbę elementów

    T operator[](T v) const{
        for(auto it =bins_.begin(); it != bins_.end(); it++){
            if(v==it->first){
                return it->second;
            }
        }
        return -1;

        // operator BinsVector(); // operator konwersji na typ `BinsVector` (`std::vector<std::pair<int, int>>`)




    }};
template<typename T>
std::ostream& operator<<(std::ostream & out, const Histogram<T>& histogram) {
    out << "Size: " << histogram.bins_.size() << '\n';
    for(auto [bin, frequency] : histogram.bins_) {
        out << bin << ": " << frequency <<'\n';
    }
    return out;
}


template<typename T>
std::istream& operator>>(std::istream & in, Histogram<T>& histogram) {
    std::size_t n;
    in >> n;
    for (std::size_t index = 0; index < n; ++index) {
        T value;
        in >> value;
        histogram.emplace(value);
    }
    return in;
}


#endif // HISTOGRAM_H
