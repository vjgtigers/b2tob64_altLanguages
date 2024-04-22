#include<map>
#include<string>
#include<iostream>
#include <chrono>
#include <ctime>
#include <experimental/random>
#include <vector>
#include <unordered_map>

using namespace std;


string b2tob64(const string& str1, unordered_map<string, string>& b2tob64_B_A) {
    int str_len = str1.length();
    int str_rem = str_len%6;
    string str_new;
    for (int i = 0; i <= str_len-str_rem-6; i +=6) {
        str_new +=b2tob64_B_A[str1.substr(i, 6)];
    }
    switch (str_rem) {
        case 1: str_new += b2tob64_B_A["00000"+str1.substr(str_len-1)] + "_";break;
        case 2: str_new += b2tob64_B_A["0000"+str1.substr(str_len-2)] + "A";break;
        case 3: str_new += b2tob64_B_A["000"+str1.substr(str_len-3)]+"B";break;
        case 4: str_new += b2tob64_B_A["00"+str1.substr(str_len-4)]+"C";break;
        case 5: str_new += b2tob64_B_A["0"+str1.substr(str_len-5)]+"D" ;break;
        case 0: str_new +="E"; break;
        default: exit(1);
    }
    return str_new;
}



string b64tob2(const string &str1_, unordered_map<char, string>& b2tob64_A_B, unordered_map<char, int>& short1) {
    string str_new;
    int str_len = str1_.length();
    if (str1_.substr(str_len-1) == "E") {
        // cout << "INHERE" << endl;
        for (int i = 0; i < str_len-1; ++i) {
            str_new += b2tob64_A_B[str1_[i]];
        }
    }
    else {
        for (int i = 0; i < str_len-2; ++i) {
            str_new += b2tob64_A_B[str1_[i]];
        }
        str_new += b2tob64_A_B[str1_[str_len-2]]
        .substr(6 - short1[str1_[(str_len-1)]]);
    }
    return str_new;
}




int main() {
    //TODO change maps to unordered_map if its faster
    unordered_map<char, int> b2tob64_short_flip;
    b2tob64_short_flip['_'] = 1;
    b2tob64_short_flip['A'] = 2;
    b2tob64_short_flip['B'] = 3;
    b2tob64_short_flip['C'] = 4;
    b2tob64_short_flip['D'] = 5;



    unordered_map<string, string> b2tob64_B_A;
    b2tob64_B_A["000000"] = "_";
    b2tob64_B_A["000001"] = "A";
    b2tob64_B_A["000010"] = "B";
    b2tob64_B_A["000011"] = "C";
    b2tob64_B_A["000100"] = "D";
    b2tob64_B_A["000101"] = "E";
    b2tob64_B_A["000110"] = "F";
    b2tob64_B_A["000111"] = "G";
    b2tob64_B_A["001000"] = "H";
    b2tob64_B_A["001001"] = "I";
    b2tob64_B_A["001010"] = "J";
    b2tob64_B_A["001011"] = "K";
    b2tob64_B_A["001100"] = "L";
    b2tob64_B_A["001101"] = "M";
    b2tob64_B_A["001110"] = "N";
    b2tob64_B_A["001111"] = "O";
    b2tob64_B_A["010000"] = "P";
    b2tob64_B_A["010001"] = "Q";
    b2tob64_B_A["010010"] = "R";
    b2tob64_B_A["010011"] = "S";
    b2tob64_B_A["010100"] = "T";
    b2tob64_B_A["010101"] = "U";
    b2tob64_B_A["010110"] = "V";
    b2tob64_B_A["010111"] = "W";
    b2tob64_B_A["011000"] = "X";
    b2tob64_B_A["011001"] = "Y";
    b2tob64_B_A["011010"] = "Z";
    b2tob64_B_A["011011"] = "a";
    b2tob64_B_A["011100"] = "b";
    b2tob64_B_A["011101"] = "c";
    b2tob64_B_A["011110"] = "d";
    b2tob64_B_A["011111"] = "e";
    b2tob64_B_A["100000"] = "f";
    b2tob64_B_A["100001"] = "g";
    b2tob64_B_A["100010"] = "h";
    b2tob64_B_A["100011"] = "i";
    b2tob64_B_A["100100"] = "j";
    b2tob64_B_A["100101"] = "k";
    b2tob64_B_A["100110"] = "l";
    b2tob64_B_A["100111"] = "m";
    b2tob64_B_A["101000"] = "n";
    b2tob64_B_A["101001"] = "o";
    b2tob64_B_A["101010"] = "p";
    b2tob64_B_A["101011"] = "q";
    b2tob64_B_A["101100"] = "r";
    b2tob64_B_A["101101"] = "s";
    b2tob64_B_A["101110"] = "t";
    b2tob64_B_A["101111"] = "u";
    b2tob64_B_A["110000"] = "v";
    b2tob64_B_A["110001"] = "w";
    b2tob64_B_A["110010"] = "x";
    b2tob64_B_A["110011"] = "y";
    b2tob64_B_A["110100"] = "z";
    b2tob64_B_A["110101"] = "0";
    b2tob64_B_A["110110"] = "1";
    b2tob64_B_A["110111"] = "2";
    b2tob64_B_A["111000"] = "3";
    b2tob64_B_A["111001"] = "4";
    b2tob64_B_A["111010"] = "5";
    b2tob64_B_A["111011"] = "6";
    b2tob64_B_A["111100"] = "7";
    b2tob64_B_A["111101"] = "8";
    b2tob64_B_A["111110"] = "9";
    b2tob64_B_A["111111"] = "-";

    unordered_map<char, string> b2tob64_A_B;
    b2tob64_A_B['_'] = "000000";
    b2tob64_A_B['A'] = "000001";
    b2tob64_A_B['B'] = "000010";
    b2tob64_A_B['C'] = "000011";
    b2tob64_A_B['D'] = "000100";
    b2tob64_A_B['E'] = "000101";
    b2tob64_A_B['F'] = "000110";
    b2tob64_A_B['G'] = "000111";
    b2tob64_A_B['H'] = "001000";
    b2tob64_A_B['I'] = "001001";
    b2tob64_A_B['J'] = "001010";
    b2tob64_A_B['K'] = "001011";
    b2tob64_A_B['L'] = "001100";
    b2tob64_A_B['M'] = "001101";
    b2tob64_A_B['N'] = "001110";
    b2tob64_A_B['O'] = "001111";
    b2tob64_A_B['P'] = "010000";
    b2tob64_A_B['Q'] = "010001";
    b2tob64_A_B['R'] = "010010";
    b2tob64_A_B['S'] = "010011";
    b2tob64_A_B['T'] = "010100";
    b2tob64_A_B['U'] = "010101";
    b2tob64_A_B['V'] = "010110";
    b2tob64_A_B['W'] = "010111";
    b2tob64_A_B['X'] = "011000";
    b2tob64_A_B['Y'] = "011001";
    b2tob64_A_B['Z'] = "011010";
    b2tob64_A_B['a'] = "011011";
    b2tob64_A_B['b'] = "011100";
    b2tob64_A_B['c'] = "011101";
    b2tob64_A_B['d'] = "011110";
    b2tob64_A_B['e'] = "011111";
    b2tob64_A_B['f'] = "100000";
    b2tob64_A_B['g'] = "100001";
    b2tob64_A_B['h'] = "100010";
    b2tob64_A_B['i'] = "100011";
    b2tob64_A_B['j'] = "100100";
    b2tob64_A_B['k'] = "100101";
    b2tob64_A_B['l'] = "100110";
    b2tob64_A_B['m'] = "100111";
    b2tob64_A_B['n'] = "101000";
    b2tob64_A_B['o'] = "101001";
    b2tob64_A_B['p'] = "101010";
    b2tob64_A_B['q'] = "101011";
    b2tob64_A_B['r'] = "101100";
    b2tob64_A_B['s'] = "101101";
    b2tob64_A_B['t'] = "101110";
    b2tob64_A_B['u'] = "101111";
    b2tob64_A_B['v'] = "110000";
    b2tob64_A_B['w'] = "110001";
    b2tob64_A_B['x'] = "110010";
    b2tob64_A_B['y'] = "110011";
    b2tob64_A_B['z'] = "110100";
    b2tob64_A_B['0'] = "110101";
    b2tob64_A_B['1'] = "110110";
    b2tob64_A_B['2'] = "110111";
    b2tob64_A_B['3'] = "111000";
    b2tob64_A_B['4'] = "111001";
    b2tob64_A_B['5'] = "111010";
    b2tob64_A_B['6'] = "111011";
    b2tob64_A_B['7'] = "111100";
    b2tob64_A_B['8'] = "111101";
    b2tob64_A_B['9'] = "111110";
    b2tob64_A_B['-'] = "111111";











//TESTING FOR FUNCTIONS BELOW HERE
   //
   //
   //
   //  
   //  string str1 = "1010010101000011110000001101010100101011010100101011010";
   //
   //
   //  string b2tob64_B_A2 = "ao110100";
   //
   //
   //  //cout << b2tob64_B_A[b2tob64_B_A2.substr(2,6)] <<endl;
   //
   //  //cout << str_new << endl;
   //  const string aa = "1000010111001010101011100111001";
   //  string bb = b2tob64(aa, b2tob64_B_A);
   //  const string cc = b64tob2(bb, b2tob64_A_B, b2tob64_short_flip);
   //  if (cc == aa) {cout << "EQUAL" << endl;}
   //  //cout << time(0) << endl;
   //  //const auto start{std::chrono::steady_clock::now()};
   //  //Sleep(50);
   //  //const auto end{std::chrono::steady_clock::now()};
   //  //const std::chrono::duration<double> elapsed_seconds{end - start};
   //  //cout << elapsed_seconds << '\n';
   //  cout << time(0) << endl;
   //
   //  srand(2);
   //  int randd = std::experimental::randint(0,999999999);
   //
   //  // cout <<rand() << " my rand";
   //  // cout <<randd << " my rand";
   //
   //  string st_ = "";
   //  int ln_;
   //  int run_times = 10000;
   //  string intit_con;
   //  string sec_pass;
   // std::experimental::reseed(10100110101011);
   //
   //  for (int i = 0; i < run_times ; ++i) {
   //      st_ = "";
   //      ln_ = std::experimental::randint(0,100);
   //      for (int j = 0; j < ln_; ++j) {
   //          st_ += to_string(std::experimental::randint(0,1));
   //      }
   //
   //      intit_con = b2tob64(st_, b2tob64_B_A);
   //      sec_pass = b64tob2(intit_con, b2tob64_A_B, b2tob64_short_flip);
   //
   //      if (sec_pass != st_) {
   //          cout << "FAIL " << st_ <<  " "  << intit_con << " " << sec_pass <<endl;
   //          exit(1);
   //      }
   //  }
   //
   //
   //  const auto start{std::chrono::steady_clock::now()};
   //  cout << "hello" << endl;
   //  vector<int> b;
   //  string j = "1010010101000011110000001101010100101011010100101011010";
   //  run_times = 10000000;
   //  string a;
   //  string a_;
   //  for (int i =0; i < run_times; ++i) {
   //      // cout << i << " tenst" << endl;
   //       a = b2tob64(j, b2tob64_B_A);
   //       a_ = b64tob2(a, b2tob64_A_B, b2tob64_short_flip);
   //      if (j != a_) {
   //      cout << a <<" " << a_  << endl;
   //
   //      exit(1);
   //      }
   //
   //      b.push_back(a_.length());
   //      // b.push_back(5);
   //  }
   //
   //  cout << b[888888] << " aoeu" <<endl;
   //  const auto end{std::chrono::steady_clock::now()};
   //  const std::chrono::duration<double> elapsed_seconds{end - start};
   //  cout << elapsed_seconds << '\n';
    return 0;
}
