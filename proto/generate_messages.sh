#! /bin/bash

THIS_DIR=$(dirname -- "${BASH_SOURCE[0]}")
pushd $THIS_DIR
protoc --cpp_out=lite:. comms/*.proto
mv comms/*.pb.cc ../src/comms
mv comms/*.pb.h ../include/comms
popd
