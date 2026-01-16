load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "bgp_eoiu_marker_py_src",
    srcs = [
        "bgp_eoiu_marker.py",
    ],
)

cc_library(
    name = "fpmsyncd_lib",
    srcs = [
        "fpmlink.cpp",
        "routesync.cpp",
    ],
    hdrs = glob([
        "*.h",
        "fpm/*.h",
    ]),
    copts = [
        "-Wno-reorder",
    ] + add_debug_to_copts(),
    deps = [
        "//warmrestart:warmrestarthelper_lib",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/swsscommon:swsscommon",
    ],
)

cc_binary(
    name = "fpmsyncd",
    srcs = glob([
        "*.cpp",
        "*.h",
        "fpm/*.h",
    ]),
    copts = [
        "-Wno-reorder",
    ] + add_debug_to_copts(),
    deps = [
        "//warmrestart:warmrestarthelper_lib",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "//bazel/swsscommon:swsscommon",
    ],
)
