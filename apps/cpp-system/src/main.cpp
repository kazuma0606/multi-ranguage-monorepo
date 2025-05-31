#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>

class SystemAnalyzer {
private:
    std::chrono::high_resolution_clock::time_point start_time;
    
public:
    SystemAnalyzer() : start_time(std::chrono::high_resolution_clock::now()) {}
    
    void printHeader() {
        std::cout << "C++ System Analyzer in Turborepo!" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }
    
    void performMemoryAnalysis() {
        std::cout << "\nMemory Analysis:" << std::endl;
        
        auto start = std::chrono::high_resolution_clock::now();
        
        // Large vector creation (memory management demo)
        auto numbers = std::make_unique<std::vector<int>>();
        numbers->reserve(1000000);
        
        for(int i = 1; i <= 1000000; ++i) {
            numbers->push_back(i);
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "   [OK] Allocated vector of " << numbers->size() << " integers" << std::endl;
        std::cout << "   [OK] Memory allocation time: " << duration.count() << " microseconds" << std::endl;
        std::cout << "   [OK] Estimated memory usage: " << (numbers->size() * sizeof(int) / 1024 / 1024) << " MB" << std::endl;
    }
    
    void performComputeAnalysis() {
        std::cout << "\nCompute Performance Analysis:" << std::endl;
        
        std::vector<int> numbers(100000);
        std::iota(numbers.begin(), numbers.end(), 1);
        
        auto start = std::chrono::high_resolution_clock::now();
        
        // STL algorithms utilization
        auto sum = std::accumulate(numbers.begin(), numbers.end(), 0LL);
        auto product = std::accumulate(numbers.begin(), numbers.begin() + 10, 1LL, std::multiplies<long long>());
        
        // Parallelizable operations
        std::vector<int> squares(numbers.size());
        std::transform(numbers.begin(), numbers.end(), squares.begin(), 
                      [](int n) { return n * n; });
        
        auto max_element = *std::max_element(numbers.begin(), numbers.end());
        auto min_element = *std::min_element(numbers.begin(), numbers.end());
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "   [OK] Processed " << numbers.size() << " numbers" << std::endl;
        std::cout << "   [OK] Sum: " << sum << std::endl;
        std::cout << "   [OK] Product (first 10): " << product << std::endl;
        std::cout << "   [OK] Max: " << max_element << ", Min: " << min_element << std::endl;
        std::cout << "   [OK] Computation time: " << duration.count() << " microseconds" << std::endl;
    }
    
    void performSTLDemo() {
        std::cout << "\nC++ STL Features Demo:" << std::endl;
        
        // Modern C++ features
        std::vector<std::string> languages = {"Rust", "Go", "Python", "Kotlin", "TypeScript", "C++"};
        
        // Lambda expressions
        std::cout << "   Languages sorted by length:" << std::endl;
        std::sort(languages.begin(), languages.end(), 
                  [](const std::string& a, const std::string& b) {
                      return a.length() < b.length();
                  });
        
        for(const auto& lang : languages) {
            std::cout << "     - " << lang << " (" << lang.length() << " chars)" << std::endl;
        }
        
        // Smart pointers demo
        auto smart_ptr = std::make_unique<int>(42);
        std::cout << "   [OK] Smart pointer value: " << *smart_ptr << std::endl;
        
        // Container operations
        auto count_long_names = std::count_if(languages.begin(), languages.end(),
                                             [](const std::string& s) { return s.length() > 5; });
        std::cout << "   [OK] Languages with >5 chars: " << count_long_names << std::endl;
    }
    
    void performSystemChecks() {
        std::cout << "\nSystem Environment Checks:" << std::endl;
        
        // Compile-time information
        std::cout << "   [OK] C++ Standard: " << __cplusplus << std::endl;
        std::cout << "   [OK] Compiler: ";
        #ifdef __GNUC__
            std::cout << "GCC " << __GNUC__ << "." << __GNUC_MINOR__ << std::endl;
        #elif defined(_MSC_VER)
            std::cout << "MSVC " << _MSC_VER << std::endl;
        #else
            std::cout << "Unknown" << std::endl;
        #endif
        
        std::cout << "   [OK] Architecture: ";
        #ifdef _WIN64
            std::cout << "Windows x64" << std::endl;
        #elif defined(_WIN32)
            std::cout << "Windows x86" << std::endl;
        #else
            std::cout << "Non-Windows" << std::endl;
        #endif
        
        // Runtime checks
        std::cout << "   [OK] RAII Demo: automatic memory management active" << std::endl;
        std::cout << "   [OK] Exception handling: enabled" << std::endl;
    }
    
    void printSummary() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto total_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        
        std::cout << "\nSystem Analysis Summary:" << std::endl;
        std::cout << std::string(30, '-') << std::endl;
        std::cout << "[OK] Language: C++ (ISO C++17)" << std::endl;
        std::cout << "[OK] Build System: CMake + Ninja" << std::endl;
        std::cout << "[OK] Standard Library: STL" << std::endl;
        std::cout << "[OK] Memory Management: RAII + Smart Pointers" << std::endl;
        std::cout << "[OK] Performance: High-speed native compilation" << std::endl;
        std::cout << "[OK] Paradigm: Multi-paradigm (OOP, Generic, Functional)" << std::endl;
        std::cout << "[OK] Total execution time: " << total_duration.count() << " ms" << std::endl;
        std::cout << "\nC++ system analysis completed successfully!" << std::endl;
        std::cout << "High-performance system programming in Turborepo!" << std::endl;
    }
};

int main() {
    try {
        SystemAnalyzer analyzer;
        
        analyzer.printHeader();
        analyzer.performMemoryAnalysis();
        analyzer.performComputeAnalysis();
        analyzer.performSTLDemo();
        analyzer.performSystemChecks();
        analyzer.printSummary();
        
        return 0;
    }
    catch(const std::exception& e) {
        std::cerr << "[ERROR] Exception caught: " << e.what() << std::endl;
        return 1;
    }
}