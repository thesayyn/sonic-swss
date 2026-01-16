load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "portsyncd_srcs",
    srcs = [
        "linksync.cpp",
        "linksync.h",
    ],
)

cc_library(
    name = "portsyncd_lib",
    srcs = ["linksync.cpp"],
    hdrs = ["linksync.h"],
    copts = add_debug_to_copts(),
    deps = [
        "//cfgmgr:shellcmd",
        "//lib:lib_utils",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/swsscommon:swsscommon",
    ],
)

cc_binary(
    name = "portsyncd",
    srcs = ["portsyncd.cpp"],
    copts = add_debug_to_copts(),
    deps = [
        ":portsyncd_lib",
        "//cfgmgr:shellcmd",
        "//lib:lib_utils",
    ],
)
