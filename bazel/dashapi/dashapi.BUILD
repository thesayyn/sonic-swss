package(default_visibility = ["//visibility:public"])

cc_import(
    name = "dashapi",
    hdrs = [],  # see cc_library rule above
    shared_library = "bazel/dashapi/dashapi_so/libdashapi.so",
    deps = [
        ":dashapi_headers"
    ]
)

# trick to export headers in a convenient way
# cc_library(
#     name = "dashapi_headers",
#     hdrs = glob([
#         "bazel/dashapi/dashapi_hdrs/dashapi*.h",
#         "bazel/dashapi/dashapi_hdrs/dashapi*.hpp",
#     ]),
#     includes = [
#         "bazel/dashapi/dashapi_hdrs",
#     ],
#     strip_include_prefix = "bazel/dashapi/dashapi_hdrs",
# )

