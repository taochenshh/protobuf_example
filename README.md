# Cmake Protobuf Example

## First way (v1)
### Build
```bash
cd v1
mkdir build
cd build
cmake ..
make -j8
```
### Run
```bash
./write_protobuf
./read_protobuf
```


## Second Way (V2)
```bash
cd v2
cd proto
mkdir build
protoc --cpp_out=./build --python_out=./build ./addressbook.proto 
cd ..
mkdir build && cd build
cmake .. 
make
```

