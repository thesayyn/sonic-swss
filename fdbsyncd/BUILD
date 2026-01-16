load("//:swss_helpers.bzl", "add_debug_to_copts", "add_gcovpreload_to_linkopts")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "fdbsyncd",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = add_debug_to_copts(),
    linkopts = add_gcovpreload_to_linkopts(),
    deps = [
        "//warmrestart:warmrestartassist_lib",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/swsscommon:swsscommon",
    ],
)
