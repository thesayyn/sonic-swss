load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

cc_test(
    name = "tests",
    srcs = [
        # TODO BL: Files don't exist anymore
        # "blackhole_counters_ut.cpp",
        # "congestion_counters_ut.cpp",
        "quoted_ut.cpp",
        "request_parser_ut.cpp",
        "swssnet_ut.cpp",
        # TODO BL: Surely we need to add more tests here, for all the python files
    ],
    copts = add_debug_to_copts(),
    linkopts = [
        "-lpthread",
    ],
    deps = [
        "//cfgmgr:shellcmd",
        "//lib:lib_utils",
        "//orchagent:orchagent_lib",
        "//orchagent:request_parser_lib",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-genl-3",
        "//bazel/saimetadata:saimeta",
        "//bazel/swsscommon:swsscommon",
    ],
)
