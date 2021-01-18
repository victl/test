load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "ceres",
  hdrs = glob(["ceres/**"]),
  includes = ["."],
  visibility = ["//visibility:public"],
  linkopts = ["-lceres"],
)