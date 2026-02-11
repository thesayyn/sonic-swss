load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "mclagsyncd_binary",
    srcs = ["mclagsyncd"],
)

cc_binary(
    name = "mclagsyncd",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = add_debug_to_copts(),
    deps = [
        "//warmrestart:warmrestartassist_lib",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-nf-3",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/swsscommon:swsscommon",
    ],
)
