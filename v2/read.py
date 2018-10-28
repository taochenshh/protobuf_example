# import sys
# sys.path.insert(0, './proto/build')
# import addressbook_pb2
import proto.build.addressbook_pb2 as addressbook_pb2

sqt = addressbook_pb2.SearchRequest()
try:
  f = open('./build/log1', "rb")
  sqt.ParseFromString(f.read())
  f.close()
except IOError:
  print(": Could not open file")
print('query:', sqt.query)
print('page number:', sqt.page_number)
print('corpus:', sqt.corpus)

srp = addressbook_pb2.SearchResponse()
try:
  f = open('./build/log2', "rb")
  srp.ParseFromString(f.read())
  f.close()
except IOError:
  print("Could not open file")
for result in srp.results:
    print(result.title, result.url)