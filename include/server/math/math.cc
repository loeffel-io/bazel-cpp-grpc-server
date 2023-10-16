#include "math.h"
#include "iostream"
#include <grpc++/grpc++.h>
#include "../../../include/calculator/calculator.h"
#include "../../../proto/math/v1/math.pb.h"
#include "../../../proto/math/v1/math.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using proto::math::v1::AddRequest;
using proto::math::v1::AddResponse;
using proto::math::v1::MathService;

Status MathServiceImpl::Add(ServerContext *context, const AddRequest *request, AddResponse *response) {
    response->set_res(add(request->x(), request->y()));
    return Status::OK;
}