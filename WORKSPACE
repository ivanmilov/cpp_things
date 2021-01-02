load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "gtest",
    branch = "v1.10.x",
    remote = "https://github.com/google/googletest",
)

git_repository(
    name = "gbenchmark",
    commit = "d8254bb9eb5f6deeddee639d0b27347e186e0a84",  # master at 2021.01.02
    # branch = "master",
    remote = "https://github.com/google/benchmark",
    shallow_since = "1608630873 +0000",
)
