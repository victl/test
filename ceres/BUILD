load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
  name = "hello_world",
  srcs = ["hello_world.cc"],
  deps = [
    "@ceres",
    "@eigen",
    "@glog",
    ],
)

cc_binary(
  name = "powell",
  srcs = ["powell.cc"],
  deps = [
    "@ceres",
    "@eigen",
    "@glog",
    "@absl//absl/strings:str_format",
    ],
)

cc_binary(
  name = "curve_fitting",
  srcs = ["curve_fitting.cc"],
  deps = [
    "@ceres",
    "@eigen",
    "@glog",
    ],
)
