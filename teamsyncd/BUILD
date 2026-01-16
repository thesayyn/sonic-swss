load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "teamsyncd",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = add_debug_to_copts(),
    deps = [
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "@local_libteam//:libteam",
        "//bazel/swsscommon:swsscommon",
    ],
)
