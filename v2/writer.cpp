#include <iostream>
#include <string>
#include <fstream>
#include "addressbook.pb.h"
using namespace std;
int main() {
  test::SearchRequest rqt_msg;
  std::string query("test");
  rqt_msg.set_query(query);
  rqt_msg.set_page_number(20);
  test::SearchRequest::Corpus cop(test::SearchRequest_Corpus_IMAGES);
  rqt_msg.set_corpus(cop);


  test::SearchResponse rsp_msg;
  test::Result* rst = rsp_msg.add_results();
  rst->set_title("rst_test");
  rst->set_url("www.google.com");
  test::Result* rst2 = rsp_msg.add_results();
  rst2->set_title("rst2_test");
  rst2->set_url("2/www.google.com");

  fstream output1("./log1", ios::out | ios::trunc | ios::binary);
  if (!rqt_msg.SerializeToOstream(&output1)) {
    cerr << "Failed to write msg." << endl;
    return -1;
  }
  fstream output2("./log2", ios::out | ios::trunc | ios::binary);
  if (!rsp_msg.SerializeToOstream(&output2)) {
    cerr << "Failed to write msg." << endl;
    return -1;
  }
  return 0;
}