"""libdash cc_import setup"""

def _impl(repository_ctx):
    # headers are at /usr/include/*.h
    hdrs_path = "/usr/include/libdashapi"
    repository_ctx.symlink(hdrs_path, "bazel/dashapi/dashapi_hdrs")
    so_path = "/usr/lib/libdashapi.so"
    repository_ctx.symlink(so_path, "bazel/dashapi/dashapi_so/libdashapi.so")

    repository_ctx.symlink(Label("//:bazel/dashapi/dashapi.BUILD"), "BUILD")

dashapi_configure = repository_rule(
    implementation = _impl,
    local = True,
)
