# Use this file to compile the .proto file in the protobuf folder
protoc -I=./protobuf --cpp_out=./Qt-Chess/proto_build schema.proto;