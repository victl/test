load("@bazel_tools//tools/build_defs/repo:git.bzl",
"git_repository",)

new_local_repository(
    name = "ceres",
    path = "/usr/include",
    build_file = "third_party/ceres.BUILD",
)

new_local_repository(
    name = "glog",
    path = "/usr/include",
    build_file = "third_party/glog.BUILD",
)

new_local_repository(
    name = "eigen",
    path = "/usr/include/eigen3",
    build_file = "third_party/eigen.BUILD",
)

git_repository(
    name = "absl",
    remote = "git://github.com/abseil/abseil-cpp.git",
    commit = "0f3bb466b868b523cf1dc9b2aaaed65c77b28862",
    shallow_since = "1603283562 -0400",
)