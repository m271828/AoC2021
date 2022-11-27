#include <vector>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>

class Bingo {
private:
    class BingoBoard {
    private:
        typedef struct Square_t {
            int number;
            bool called;
            Square_t(int n) {
                called = false;
                number = n;
            }
            Square_t() {
                called = false;
                number = -1;
            }
        } Square;

        std::vector<std::vector<Square> > board;

        bool checkForHorizontalWins() {
            for(int i = 0; i < 5; i++) {
                if(board[i][0].called && board[i][1].called && board[i][2].called && board[i][3].called && board[i][4].called) {
                    // std::cout << "Found horizontal win" << std::endl;
                    return true;
                }
            }
            return false;
        }

        bool checkForVerticalWins() {
            for(int j = 0; j < 5; j++) {
                if(board[0][j].called && board[1][j].called && board[2][j].called && board[3][j].called && board[4][j].called) {
                    // std::cout << "Found vertical win" << std::endl;
                    return true;
                }
            }
            return false;
        }

        bool checkForDiagonalWins() {
            if(board[0][0].called && board[1][1].called && board[2][2].called && board[3][3].called && board[4][4].called) {
                // std::cout << "Found diagonal win" << std::endl;
                return true;
            } else if(board[0][4].called && board[1][3].called && board[2][2].called && board[3][1].called && board[4][0].called) {
                // std::cout << "Found diagonal win" << std::endl;
                return true;
            }
            return false;
        }

    public:
        BingoBoard(std::vector<std::vector<int> > values)  {
            if(values.size() != 5) {
                throw new std::exception();
            }
            for(int i = 0; i < 5; i++) {
                std::vector<Square> row;
                if(values[i].size() != 5) {
                    throw new std::exception();
                }
                for(int j = 0; j < 5; j++) {
                    Square val(values[i][j]);
                    row.push_back(val);
                }
                board.push_back(row);
            }
        }

        bool addValueAndCheckForWin(int val) {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(board[i][j].number == val) {
                        board[i][j].called = true;
                    }
                }
            }

            return checkForHorizontalWins() || checkForVerticalWins() || checkForDiagonalWins();
        }

        int score() {
            int sum = 0;
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(!board[i][j].called) {
                        sum += board[i][j].number;
                    }
                }
            }
            return sum;
        }

        void print() {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    std::cout << board[i][j].number << " ";
                }
                std::cout << std::endl;
            }
        }

        void printCalled() {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    std::cout << board[i][j].called << " ";
                }
                std::cout << std::endl;
            }
        }
    };

    std::vector<BingoBoard> boards;
    std::vector<int> calls;
    bool finished;
    std::vector<int> winners;
    size_t call_index;

public:
    Bingo(std::string fileName) {
        std::ifstream file(fileName);
        std::string line;
        
        std::getline(file, line);
        
        std::string callTemp = "";
        for(size_t i = 0; i < line.size(); i++) {
            if(line[i] != ',' && line[i] != ' ') {
                callTemp += line[i];
            } else if(line[i] == ',') {
                calls.push_back(stoi(callTemp));
                callTemp = "";
            }
        }
        calls.push_back(stoi(callTemp));

        while(std::getline(file, line)) {
            if(line == "") {
                continue;
            }
            std::vector<std::vector<int> > board;
            for(size_t i = 0; i < 5; i++) {
                std::vector<int> row;
                std::string temp;
                for(size_t j = 0; j < line.size(); j++) {
                    if(isspace(line[j]) && temp != "") {
                        row.push_back(stoi(temp));
                        temp = "";
                    } else if(isnumber(line[j])) {
                        temp += line[j];
                    }
                }
                row.push_back(stoi(temp));
                board.push_back(row);
                std::getline(file, line);
            }
            boards.push_back(BingoBoard(board));
        }

        finished = false;
        call_index = 0;
    }
    
    void nextCall() {
        int value = calls[call_index];
        call_index++;

        for(int i = 0; i < boards.size(); i++) {
            bool won = boards[i].addValueAndCheckForWin(value);
            if(won) {
                finished = true;
                bool found = false;
                for(int j = 0; j < winners.size(); j++) {
                    if(winners[j] == i) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    winners.push_back(i);
                    std::cout << "Board " << i << " just won with score " << boards[i].score()*value << std::endl;
                }
            }
        }
    }

    bool isWinner() {
        return finished;
    }

    int score(){
        int maxScore = -1;
        std::cout << "There are " << winners.size() << " matches cards this round." << std::endl;
        for(int i = 0; i < winners.size(); i++) {
            int score = boards[winners[i]].score();
            if(score > maxScore) {
                maxScore = score;
            }
        }
        return maxScore*calls[call_index-1];
    }

    bool moreCalls() {
        return call_index < calls.size();
    }

    void printBoards() {
        for(int i = 0; i < boards.size(); i++) {
            std::cout << "Board " << i << std::endl;
            boards[i].print();
            boards[i].printCalled();
        }
    }
};