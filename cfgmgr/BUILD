package(default_visibility = ["//visibility:public"])

DEBUG_COPTS = select({
    "//:debug_mode": ["-ggdb -DDEBUG"],
    "//conditions:default": ["-g -DNDEBUG"],
})

DEFAULT_COPTS = [] + DEBUG_COPTS

DEFAULT_LINKOPTS = ["-lpthread"]

cc_library(
    name = "shellcmd",
    srcs = ["shellcmd.h"],
    hdrs = ["shellcmd.h"],
    deps = [
        "//bazel/swsscommon:swsscommon",
    ],
)

filegroup(
    name = "confg_mgr_data",
    # TODO BL: This probably wasn't meant to allow empty
    srcs = glob(
        ["*.json"],
        allow_empty = True,
    ),
)

filegroup(
    name = "cfgmgr_lua_scripts",
    srcs = glob(["*.lua"]),
)

cc_binary(
    name = "vlanmgrd",
    srcs = [
        "vlanmgr.cpp",
        "vlanmgr.h",
        "vlanmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "teammgrd",
    srcs = [
        "portmgr.h",
        "teammgr.cpp",
        "teammgr.h",
        "teammgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "portmgrd",
    srcs = [
        "portmgr.cpp",
        "portmgr.h",
        "portmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "intfmgrd",
    srcs = [
        "intfmgr.cpp",
        "intfmgr.h",
        "intfmgrd.cpp",
        "portmgr.h",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "buffermgrd",
    srcs = [
        "buffermgr.cpp",
        "buffermgr.h",
        "buffermgrd.cpp",
        "buffermgrdyn.cpp",
        "buffermgrdyn.h",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "vrfmgrd",
    srcs = [
        "vrfmgr.cpp",
        "vrfmgr.h",
        "vrfmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "nbrmgrd",
    srcs = [
        "nbrmgr.cpp",
        "nbrmgr.h",
        "nbrmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "vxlanmgrd",
    srcs = [
        "vxlanmgr.cpp",
        "vxlanmgr.h",
        "vxlanmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "sflowmgrd",
    srcs = [
        "portmgr.h",
        "sflowmgr.cpp",
        "sflowmgr.h",
        "sflowmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "coppmgrd",
    srcs = [
        "coppmgr.cpp",
        "coppmgr.h",
        "coppmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "switchmgrd",
    srcs = [
        "switchmgr.cpp",
        "switchmgr.h",
        "switchmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "fabricmgrd",
    srcs = [
        "fabricmgr.cpp",
        "fabricmgr.h",
        "fabricmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "tunnelmgrd",
    srcs = [
        "tunnelmgr.cpp",
        "tunnelmgr.h",
        "tunnelmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

cc_binary(
    name = "macsecmgrd",
    srcs = [
        "macsecmgr.cpp",
        "macsecmgr.h",
        "macsecmgrd.cpp",
    ],
    copts = DEFAULT_COPTS,
    linkopts = DEFAULT_LINKOPTS,
    deps = [
        "//cfgmgr:shellcmd",
        "//orchagent:orchagent_lib_impl",
    ],
)

# -------------- Base lib to use in external targets -------------

cc_library(
    name = "cfgmgr_base_lib",
    srcs = [
        "buffermgrdyn.cpp",
        "buffermgrdyn.h",
        "coppmgr.cpp",
        "coppmgr.h",
        "intfmgr.cpp",
        "intfmgr.h",
        "portmgr.cpp",
        "portmgr.h",
        "sflowmgr.cpp",
        "sflowmgr.h",
        "teammgr.cpp",
        "teammgr.h",
    ],
    deps = [
        "//cfgmgr:shellcmd",
        "//lib:lib_utils",
        "//orchagent:orchagent_lib",
        "//warmrestart:warmrestarthelper_lib",
        "//bazel/hiredis:hiredis",
        "//bazel/libnl3:libnl-genl-3",
        "//bazel/libnl3:libnl-route-3",
        "//bazel/libnl3:libnl3",
        "@local_saivs//:saivs",
        "//bazel/swsscommon:swsscommon",
        "//bazel/zmq:zmq",
    ],
)
