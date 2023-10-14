#include "iostream"
#include <grpc++/grpc++.h>
#include <grpc++/health_check_service_interface.h>
#include <grpc++/ext/proto_server_reflection_plugin.h>
#include "include/math/math.h"
#include "proto/math/v1/math.pb.h"
#include "proto/math/v1/math.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using proto::math::v1::MathService;
using proto::math::v1::AddRequest;
using proto::math::v1::AddResponse;

class MathServiceImpl final : public MathService::Service {
public:
    Status Add(ServerContext *context, const AddRequest *request, AddResponse *response) override {
        response->set_res(add(request->x(), request->y()));
        return Status::OK;
    }
};

int main() {
    std::string server_address("0.0.0.0:50030");
    MathServiceImpl mathService;

    // grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&mathService);
    std::unique_ptr <Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();

    return 0;
}