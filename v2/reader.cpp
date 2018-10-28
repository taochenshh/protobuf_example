#include <iostream>
#include <string>
#include <fstream>
#include "addressbook.pb.h"
using namespace std;
void ListMsg(const test::SearchRequest & msg) {
  cout << msg.query() << endl;
  cout << msg.page_number() << endl;
  cout << msg.corpus() << endl;
}
void ListMsg(const test::SearchResponse & msg) {
  int rst_num = msg.results_size();
  for(int i=0; i < rst_num; i++){
    test::Result rst = msg.results(i);
    cout << rst.title() << endl;
    cout << rst.url() << endl;
  }
}
int main() {
  test::SearchRequest msg1;
  fstream input1("./log1", ios::in | ios::binary);
  if (!msg1.ParseFromIstream(&input1)) {
    cerr << "Failed to parse address book." << endl;
    return -1;
  }
  ListMsg(msg1);

  test::SearchResponse msg2;
  fstream input2("./log2", ios::in | ios::binary);
  if (!msg2.ParseFromIstream(&input2)) {
    cerr << "Failed to parse address book." << endl;
    return -1;
  }
  ListMsg(msg2);

  return 0;
}
