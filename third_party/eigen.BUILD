load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "eigen",
    hdrs = glob([
        "Eigen/*",
        "Eigen/**/*.h",
        "unsupported/Eigen/*",
        "unsupported/Eigen/**/*",
    ]),
    defines = ["EIGEN_MPL2_ONLY"],
    includes = ["."],
    visibility = ["//visibility:public"],
)
