#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <algorithm>  // std::sort
#include <mutex>

std::mutex m;
int const NUM_THREADS = 4;

void solve_puzzle(std::vector<Puzzle> puzzles, std::vector<Solution>& solutions){
    for(auto puzzle : puzzles){
        for(std::string word : puzzle) {
            Solver solver{puzzle};
            Solution s = solver.solve(word);
            m.lock(); solutions.push_back(s); m.unlock();
        }
    }
}

int main(int argc, char* argv[]) {

    std::vector<std::vector<Puzzle>> puzzles;

    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            if(puzzles.size() < NUM_THREADS){
                std::vector<Puzzle> subset;
                subset.push_back(Puzzle{filename, ifs});
                puzzles.push_back(subset);
            }
            else{
                puzzles.at(i%NUM_THREADS).push_back(Puzzle{filename, ifs});
            }
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }

    std::array<std::thread, NUM_THREADS> threads;    

    std::vector<Solution> solutions;
    for (int i=0; i<NUM_THREADS; ++i)
            threads[i] = std::thread{solve_puzzle, puzzles.at(i), std::ref(solutions)};
    
    for (std::thread& t : threads) t.join();
   
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
    
