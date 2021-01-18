load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "glog",
  hdrs = glob(["glog/**"]),
  includes = ["."],
  visibility = ["//visibility:public"],
  linkopts = ["-lglog"],
)