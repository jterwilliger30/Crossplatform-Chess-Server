# Use this file to compile the .proto file in the protobuf folder
./externals/protobuf/protoc -I=./protobuf --cpp_out=./protobuf schema.proto;