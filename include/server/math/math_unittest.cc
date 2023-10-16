#include "math.h"

#include "../../../include/calculator/calculator.h"
#include "gtest/gtest.h"
#include "iostream"

using grpc::ServerContext;
using grpc::Status;
using proto::math::v1::AddRequest;
using proto::math::v1::AddResponse;
using proto::math::v1::MathService;
using std::string;

AddRequest* req(int x, int y) {
  AddRequest* request = new AddRequest();
  request->set_x(x);
  request->set_y(y);

  return request;
}

AddResponse* resp(int res) {
  AddResponse* resp = new AddResponse();
  resp->set_res(res);

  return resp;
}

TEST(MathService, Add) {
  struct Test {
    string name;
    ServerContext* context;
    AddRequest* request;
    AddResponse* response;
  };

  Test tests[2] = {{.name = "abc", .request = req(2, 3), .response = resp(5)},
                   {.name = "abc", .request = req(1, 2), .response = resp(3)}};

  for (Test test : tests) {
    MathServiceImpl service;
    AddResponse* response = new AddResponse();

    service.Add(test.context, test.request, response);

    EXPECT_EQ(response->res(), test.response->res());
  }
}