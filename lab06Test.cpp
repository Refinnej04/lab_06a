#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
#include "WordCount.h" 

using namespace std;

int main() {
	WordCount wc;
  cout<<"test case one"<<endl;
  wc.addAllWords("Sentence is a sentence");
  ostringstream abc;
  wc.dumpWordsSortedByWord(abc);
  ASSERT_EQUALS("sentence,2\nis,1\na,1\n",abc.str());

    cout<<"test case two"<<endl;
    ostringstream abc1;
    WordCount wc1;
    wc1.addAllWords("Sentence is a fun fun sentence" );
    wc1.dumpWordsSortedByOccurence(abc1);
  
  ASSERT_EQUALS("a,1\nis,1\nfun,2\nsentence,2\n",abc1.str());  

  
}
