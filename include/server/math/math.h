#ifndef BAZEL_CPP_GRPC_SERVER_MATH_H
#define BAZEL_CPP_GRPC_SERVER_MATH_H

#include <grpc++/grpc++.h>

#include "../../../proto/math/v1/math.grpc.pb.h"
#include "../../../proto/math/v1/math.pb.h"
#include "iostream"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using proto::math::v1::AddRequest;
using proto::math::v1::AddResponse;
using proto::math::v1::MathService;

class MathServiceImpl final : public MathService::Service {
 public:
  Status Add(ServerContext *context, const AddRequest *request,
             AddResponse *response);
};

#endif  // BAZEL_CPP_GRPC_SERVER_MATH_H