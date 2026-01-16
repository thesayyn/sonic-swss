load("//:swss_helpers.bzl", "add_debug_to_copts")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "tlm_teamd",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = add_debug_to_copts(),
    local_defines = [
        "DRAIN_MMU_WHEN_APPLYING_BUFFER_CONFIG",
    ],
    deps = [
        "//lib:lib_utils",
        "//bazel/hiredis:hiredis",
        "//bazel/jansson:jansson",
        "@local_libteam//:libteamdctl",
        "//bazel/swsscommon:swsscommon",
    ],
)
