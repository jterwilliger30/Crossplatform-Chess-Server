# Use this file to compile the .proto file in the protobuf folder
protoc -I=./ --cpp_out=./ schema.proto