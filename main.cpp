#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "split.h"

using namespace std;
/*
void rand_idx(int len, int ras[]) {
  int two_rands[2];
  //int remain_len = 0;
  int half_len = len / 2;
  two_rands[0] = rand() % len;
  //remain_len = len - two_rands[0];
  
  if(two_rands[0] >= half_len) {
    two_rands[1] = two_rands[0];
    two_rands[0] = rand() % two_rands[0];
  }else{
    two_rands[1] = half_len + rand() % half_len;
  }

  ras[0] = two_rands[0];
  ras[1] = two_rands[1];
   
}
*/

void rand_idx(int len, int ras[]) {
  int a = 0, b = 0;
  int tmp = 0;
  a = rand() % len;
  b = rand() % len;

  if( a > b ){
      tmp = b;
      b = a;
      a = tmp; 
  }
 
  if( a == b ) {
    if( a == 0 ) {
      b = rand() % (len - 1) + 1;
    }else{
      a = rand() % (b - 1) ;
    }
  }

  ras[0] = a;
  ras[1] = b;
   
}

void read_file(const string& fen, const string& fch) {
	ifstream ifs_en(fen.c_str());
	ifstream ifs_ch(fch.c_str());
	if (ifs_en && ifs_ch) {
		string buf_en;
		string buf_ch;
                string out_sen = "";
                vector<string> en_words;
                vector<string> ch_words;

                Csplit spl;

		while(getline(ifs_en, buf_en) && getline(ifs_ch, buf_ch)) {
                  int ra_sen = rand() % 2;  
                  int ra_idxs[2] = {0,0};
                  en_words = spl.split(buf_en, " ");
                  ch_words = spl.split(buf_ch, " ");
                  
                  if(ra_sen == 0) {
                        rand_idx(en_words.size(), ra_idxs);
                        out_sen = en_words[ra_idxs[0]] + " " + en_words[ra_idxs[1]];
                        en_words[ra_idxs[0]] = "_W1_";
                        en_words[ra_idxs[1]] = "_W2_";
                        string tmp_en;
                        tmp_en = spl.join(en_words, " ");
			cout << tmp_en << endl;
                  }else{
                        rand_idx(ch_words.size(), ra_idxs);
                        out_sen = ch_words[ra_idxs[0]] + " " + ch_words[ra_idxs[1]];
                        ch_words[ra_idxs[0]] = "_W1_";
                        ch_words[ra_idxs[1]] = "_W2_";
                        string tmp_ch;
                        tmp_ch = spl.join(ch_words, " ");
                        cout << tmp_ch << endl;
                  }
                        cout << "out_sen: " << out_sen << endl;
		}	
	}
}



int main(int argc, char **argv) {
	
	if (argc != 3) {
		cout << "use: ./" << argv[0] << " en.txt" << " ch.txt" << endl;
		return 1;
	}

        srand(time(NULL));

	string fen;
        string fch;
	
	fen = argv[1];
        fch = argv[2];
        
        /*      
        int rands[2];
        rand_idx(10, rands);
        cout << "rand[0] " << rands[0] << endl;
        cout << "rand[1] " << rands[1] << endl;
        */
	read_file(fen, fch);
		
	return 0;
}
